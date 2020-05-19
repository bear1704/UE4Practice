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
	const TArray<AActor*> ActorsIgnore;

	bool bResult = UKismetSystemLibrary::LineTraceSingle(GetWorld(), LineStart, LineEnd, UEngineTypes::ConvertToTraceType(ECC_Visibility)
		, bUseComplexCollison, ActorsIgnore, DebugTraceType, Result, true);

	RetTraceInfo.ImpactNormal = Result.ImpactNormal;
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


// Called every frame
void UIkComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

