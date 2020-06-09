// Fill out your copyright notice in the Description page of Project Settings.


#include "IkComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/CapsuleComponent.h"
#include "Animation/AnimInstance.h"

// Sets default values for this component's properties
UIkComponent::UIkComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	

	// ...
}


// Called when the game starts
void UIkComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	CapsuleHalfHeight = OwnerCharacter->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

	RightFootSocketName = FName("foot_r");
	LeftFootSocketName = FName("foot_l");
	IkTraceDistance = 50.0f;
	
	// ...
	
}

void UIkComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// ...

}

FIkTraceInfo UIkComponent::IK_FootTrace(float TraceDistance, FName FootSocketName)
{
	FIkTraceInfo RetTraceInfo;

	FVector SocketLocation = OwnerCharacter->GetMesh()->GetSocketLocation(FootSocketName); //발에 소켓을 꽂거나, foot bone자체를 소켓으로 사용
	FVector LineStart = FVector(SocketLocation.X, SocketLocation.Y, OwnerCharacter->GetActorLocation().Z); //액터의 허리 부분부터 시작
	FVector LineEnd = FVector(SocketLocation.X, SocketLocation.Y, OwnerCharacter->GetActorLocation().Z - CapsuleHalfHeight - TraceDistance);
	//TraceDistance만큼 발 아래로 내리기

	FHitResult Result;

	EDrawDebugTrace::Type DebugTraceType = EDrawDebugTrace::ForOneFrame;

	bool bUseComplexCollison = true;
	TArray<AActor*> ActorsIgnore;
	ActorsIgnore.Add(GetOwner());

	bool bResult = UKismetSystemLibrary::LineTraceSingle(GetWorld(), LineStart, LineEnd, UEngineTypes::ConvertToTraceType(ECC_Visibility)
		, bUseComplexCollison, ActorsIgnore, DebugTraceType, Result, true);
	//허리부터 발 아래까지 레이트레이싱을 통해 바닥이 있는지를 체크한다.

	RetTraceInfo.ImpactNormal = Result.ImpactNormal; //바닥의 경사도를 Normal을 측정해서 적용하기 위함(발목 돌리기)
	RetTraceInfo.ImpactLocation = Result.ImpactPoint;
	
	/* 충돌이 일어난 경우(계단에 발이 닿은 경우) -> 닿은 곳에서 offset을 살짝 해주어 발을 위치시켜야 한다 */
	if (Result.IsValidBlockingHit() == true)
	{
		//충돌위치로부터 TraceEnd(선의 끝)까지 length를 구한다. 이것은 tracedistnace(총 라인트레이스 길이(start->end))에서 충돌위치까지를 빼서
		//(제대로 충돌이 일어난 경우 거의 0이 될 것이다) 
		//offset을 더하는 데 쓰인다. 그러면 바닥 위치 살짝 위(offset더한만큼) 를 targetPoint로 잡을 수 있다.
		float ImpactPointToTraceEndSize = (Result.ImpactPoint - Result.TraceEnd).Size();
		RetTraceInfo.Offset = kFootOffset + (ImpactPointToTraceEndSize - TraceDistance);
	}
	/*else : 충돌이 일어나지 않은 경우 (한발만 걸쳐서 나머지 발은 허공에 떠 있는 경우) ->
	offset을 주면 허공에서 발을 움츠리므로 부자연스러워 보인다*/
	else
		RetTraceInfo.Offset = 0.0f;


	return RetTraceInfo;
}


void UIkComponent::IK_Update(float Deltatime)
{
	LeftFootTraceInfo = IK_FootTrace(IkTraceDistance, LeftFootSocketName);
	RightFootTraceInfo = IK_FootTrace(IkTraceDistance, RightFootSocketName);

	IK_UpdateAnkleRotation(Deltatime, NormalToRotator(LeftFootTraceInfo.ImpactNormal), 
		&AnimComp.CurrentLeftFootRotation, AnimComp.FeetRotateInterpolationSpeed);

	IK_UpdateAnkleRotation(Deltatime, NormalToRotator(RightFootTraceInfo.ImpactNormal),
		&AnimComp.CurrentRightFootRotation, AnimComp.FeetRotateInterpolationSpeed);

}

// Called every frame
void UIkComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float MinFootOffset = UKismetMathLibrary::Min(LeftFootTraceInfo.Offset, RightFootTraceInfo.Offset);
	UE_LOG(LogTemp, Warning, TEXT("MinFootOffset : %f"), MinFootOffset);

	if (MinFootOffset > 0.0f) MinFootOffset = 0.0f;
	IK_UpdateCapsuleHalfHeight(DeltaTime, MinFootOffset, false);
	IK_UpdateHipOffset(DeltaTime, MinFootOffset, &AnimComp.HipOffset, 13.0f);


	// ...
}

FRotator UIkComponent::NormalToRotator(FVector& Norm)
{
	//pitch와 yaw를 구해서 rotator로 만든다. 이 방법이 제대로 된 방법인가?
	float Yaw = UKismetMathLibrary::DegAtan2(Norm.Y, Norm.Z);
	float Pitch = UKismetMathLibrary::DegAtan2(Norm.X, Norm.Z);
	Pitch *= -1.0f;

	//Norm.Rotation()에도 비슷한 식이 있던데 이걸 써도 괜찮을까
	
	return FRotator(Pitch, 0.0f, Yaw);
}

void UIkComponent::IK_UpdateAnkleRotation(float DeltaTime, FRotator TargetRotater, FRotator* CurrentRotator, float InterpSpeed)
{
	FRotator Interpolation = UKismetMathLibrary::RInterpTo(*CurrentRotator, TargetRotater, DeltaTime, InterpSpeed);
	*CurrentRotator = Interpolation;
}

void UIkComponent::IK_UpdateCapsuleHalfHeight(float deltaTime, float HipsOffset, bool bResetDefault)
{
	//HipOffset. 즉 다리가 계단 등에 의해서 양발간 차이가 발생할 때, 
	//Hip(Pelvis)를 낮추기 위한 값
	UCapsuleComponent* MyCapsule = OwnerCharacter->GetCapsuleComponent();
	float MyCapsuleHalfHeight = 0.0f;

	if (bResetDefault)
		MyCapsuleHalfHeight = CapsuleHalfHeight;
	else
	{
		float fHalfAbsSize = UKismetMathLibrary::Abs(HipsOffset) * 0.5f;
		//왜 반을 나누지? 그냥 낮추면 안 되나? : HalfHeight를 정하는 것이므로, offset도 반으로 깎아야 하는것으로 추정
		MyCapsuleHalfHeight = CapsuleHalfHeight - fHalfAbsSize;
	}

	float fCapsuleHalfHeight = MyCapsule->GetScaledCapsuleHalfHeight();
	float InterpValue = UKismetMathLibrary::FInterpTo(fCapsuleHalfHeight,
		MyCapsuleHalfHeight, deltaTime, 13.0f);

	MyCapsule->SetCapsuleHalfHeight(MyCapsuleHalfHeight, true);
}

void UIkComponent::IK_UpdateHipOffset(float DeltaTime, float TargetValue, float* CurrentValue, float InterpSpeed)
{
	float InterpValue = UKismetMathLibrary::FInterpTo(*CurrentValue, TargetValue, DeltaTime, InterpSpeed);
	*CurrentValue = InterpValue;
}
