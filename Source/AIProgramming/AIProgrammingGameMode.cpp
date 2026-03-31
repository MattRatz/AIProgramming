// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIProgrammingGameMode.h"
#include "AIProgrammingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAIProgrammingGameMode::AAIProgrammingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
