// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "RunOrKillGameMode.h"
#include "RunOrKillHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARunOrKillGameMode::ARunOrKillGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behaviour/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ARunOrKillHUD::StaticClass();
}
