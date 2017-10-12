// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SammysGreatAdventureGameMode.h"
#include "SammysGreatAdventureCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASammysGreatAdventureGameMode::ASammysGreatAdventureGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Sammy/Blueprints/BP_Sammy"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
