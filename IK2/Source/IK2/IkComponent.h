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

	float Offset;  //해당 bone이 어느정도 offset을 가지고 떠 있는가 판별
	FVector ImpactNormal; //닿는 위치의 Normal
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
		float HipOffset; //계산된 HipOffset을 직접 Blueprint에서 적용하기 위함.


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
	/*계단 등을 오르내릴 때, 발의 위치를 맞추면 Capsule의 머리 공간이 남는다.(발 부위엔 캡슐이 안 닿는다) 그를 보정하기 위해 크기를 좀 줄여준다*/
	void IK_UpdateCapsuleHalfHeight(float deltaTime, float HipsOffset, bool bResetDefault);
	/*계단 등을 오르내릴 때, 몸통의 위치를 계단에 맞게 맞춰준다. currentValue는 현재 hipoffset값(위치보정값), 실제 변경은 blueprint에서
	이로 인해, Pelvis(Hip) 위치가 내려간다.(캡슐은 그위치 그대로기 때문에-크기만작아짐   캡슐에서 발만 삐져나온다)*/
	void IK_UpdateHipOffset(float DeltaTime, float TargetValue, float* CurrentValue, float InterpSpeed);
	

public:
	FORCEINLINE FIkAnimComponent GetAnimCompValue() { return AnimComp; }

		
};
