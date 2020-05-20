// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "IK2AnimInstance.generated.h"

class AIK2Character;

/**
 * 
 */
UCLASS()
class IK2_API UIK2AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:


	
public:
	UIK2AnimInstance();
	virtual ~UIK2AnimInstance();


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AIK2Character* MyCharacter;

	void SetCharacter(AIK2Character* Char);

};
