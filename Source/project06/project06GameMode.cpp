// Copyright Epic Games, Inc. All Rights Reserved.

#include "project06GameMode.h"
#include "project06Character.h"
#include "UObject/ConstructorHelpers.h"

Aproject06GameMode::Aproject06GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
