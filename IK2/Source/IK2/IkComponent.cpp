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

	FVector SocketLocation = OwnerCharacter->GetMesh()->GetSocketLocation(FootSocketName); //�߿� ������ �Ȱų�, foot bone��ü�� �������� ���
	FVector LineStart = FVector(SocketLocation.X, SocketLocation.Y, OwnerCharacter->GetActorLocation().Z); //������ �㸮 �κк��� ����
	FVector LineEnd = FVector(SocketLocation.X, SocketLocation.Y, OwnerCharacter->GetActorLocation().Z - CapsuleHalfHeight - TraceDistance);
	//TraceDistance��ŭ �� �Ʒ��� ������

	FHitResult Result;

	EDrawDebugTrace::Type DebugTraceType = EDrawDebugTrace::ForOneFrame;

	bool bUseComplexCollison = true;
	const TArray<AActor*> ActorsIgnore;

	bool bResult = UKismetSystemLibrary::LineTraceSingle(GetWorld(), LineStart, LineEnd, UEngineTypes::ConvertToTraceType(ECC_Visibility)
		, bUseComplexCollison, ActorsIgnore, DebugTraceType, Result, true);

	RetTraceInfo.ImpactNormal = Result.ImpactNormal;
	RetTraceInfo.ImpactLocation = Result.ImpactPoint;
	
	/* �浹�� �Ͼ ���(��ܿ� ���� ���� ���) -> ���� ������ offset�� ��¦ ���־� ���� ��ġ���Ѿ� �Ѵ� */
	if (Result.IsValidBlockingHit() == true)
	{
		//�浹��ġ�κ��� TraceEnd(���� ��)���� length�� ���Ѵ�. �̰��� tracedistnace(�� ����Ʈ���̽� ����(start->end))���� �浹��ġ������ ����
		//(����� �浹�� �Ͼ ��� ���� 0�� �� ���̴�) 
		//offset�� ���ϴ� �� ���δ�. �׷��� �ٴ� ��ġ ��¦ ��(offset���Ѹ�ŭ) �� targetPoint�� ���� �� �ִ�.
		float ImpactPointToTraceEndSize = (Result.ImpactPoint - Result.TraceEnd).Size();
		RetTraceInfo.Offset = kFootOffset + (ImpactPointToTraceEndSize - TraceDistance);
		
		
	}
	/*else : �浹�� �Ͼ�� ���� ��� (�ѹ߸� ���ļ� ������ ���� ����� �� �ִ� ���) ->
	offset�� �ָ� ������� ���� �������Ƿ� ���ڿ������� ���δ�*/
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

