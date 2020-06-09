// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IkComponent.generated.h"

class ACharacter;

const int kFootOffset = 5.0f;

USTRUCT()
struct FIkTraceInfo
{
	GENERATED_USTRUCT_BODY()

	float Offset;  //�ش� bone�� ������� offset�� ������ �� �ִ°� �Ǻ�
	FVector ImpactNormal; //��� ��ġ�� Normal
	FVector ImpactLocation; 
};

USTRUCT(Atomic, BlueprintType)
struct FIkAnimComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator CurrentLeftFootRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator CurrentRightFootRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float FeetRotateInterpolationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HipOffset; //���� HipOffset�� ���� Blueprint���� �����ϱ� ����.


	FIkAnimComponent()
	{
		CurrentLeftFootRotation = FRotator(0.0f, 0.0f, 0.0f);
		CurrentRightFootRotation = FRotator(0.0f, 0.0f, 0.0f);
		FeetRotateInterpolationSpeed = 30.0f;
	}
};



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class IK2_API UIkComponent : public UActorComponent
{
	GENERATED_BODY()



public:	
	// Sets default values for this component's properties
	UIkComponent();

private:

	ACharacter* OwnerCharacter;
	float CapsuleHalfHeight;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK")
		float IkTraceDistance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK")
		FName LeftFootSocketName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK")
		FName RightFootSocketName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK")
		FIkAnimComponent AnimComp;
	UPROPERTY(EditAnywhere, Category = "IK")
		FIkTraceInfo LeftFootTraceInfo;
	UPROPERTY(EditAnywhere, Category = "IK")
		FIkTraceInfo RightFootTraceInfo;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	void IK_Update(float Deltatime);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	FIkTraceInfo IK_FootTrace(float TraceDistance, FName FootSocketName);
	FRotator NormalToRotator(FVector& Norm);
	void IK_UpdateAnkleRotation(float DeltaTime, FRotator TargetRotater, FRotator* CurrentRotator, float InterpSpeed);
	/*��� ���� �������� ��, ���� ��ġ�� ���߸� Capsule�� �Ӹ� ������ ���´�.(�� ������ ĸ���� �� ��´�) �׸� �����ϱ� ���� ũ�⸦ �� �ٿ��ش�*/
	void IK_UpdateCapsuleHalfHeight(float deltaTime, float HipsOffset, bool bResetDefault);
	/*��� ���� �������� ��, ������ ��ġ�� ��ܿ� �°� �����ش�. currentValue�� ���� hipoffset��(��ġ������), ���� ������ blueprint����
	�̷� ����, Pelvis(Hip) ��ġ�� ��������.(ĸ���� ����ġ �״�α� ������-ũ�⸸�۾���   ĸ������ �߸� �������´�)*/
	void IK_UpdateHipOffset(float DeltaTime, float TargetValue, float* CurrentValue, float InterpSpeed);
	

public:
	FORCEINLINE FIkAnimComponent GetAnimCompValue() { return AnimComp; }

		
};
