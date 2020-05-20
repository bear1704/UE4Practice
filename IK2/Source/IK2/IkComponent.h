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

	USTRUCT(EditAnywhere, BlueprintReadWrite)
		FRotator CurrentLeftFootRotation;
	USTRUCT(EditAnywhere, BlueprintReadWrite)
		FRotator CurrentRightFootRotation;
	USTRUCT(EditAnywhere, BlueprintReadWrite)
		float FeetRotateInterpolationSpeed;


	FIkAnimComponent()
	{
		CurrentLeftFootRotation = FRotator(0.0f, 0.0f, 0.0f);
		CurrentRightFootRotation = FRotator(0.0f, 0.0f, 0.0f);
		FeetRotateInterpolationSpeed = 5.0f;
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
	

		
};
