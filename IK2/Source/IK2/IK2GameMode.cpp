// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "IK2GameMode.h"
#include "IK2Character.h"
#include "UObject/ConstructorHelpers.h"

AIK2GameMode::AIK2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
