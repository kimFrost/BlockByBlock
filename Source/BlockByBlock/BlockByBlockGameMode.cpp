// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BlockByBlock.h"
#include "BlockByBlockCharacter.h"
#include "BasePlayerController.h"
#include "GameFramework/HUD.h"
#include "BlockByBlockGameMode.h"


ABlockByBlockGameMode::ABlockByBlockGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	

	//~~ Set the default PlayerController ~~ //
	static ConstructorHelpers::FClassFinder<ABasePlayerController> PlayerControllerBPClass(TEXT("/Game/Blueprint/Controllers/PC_PlayerController"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
	else
{	
		PlayerControllerClass = ABasePlayerController::StaticClass();
	}

	//~~ Set the default HUD ~~ //
	static ConstructorHelpers::FClassFinder<AHUD> HudBPClass(TEXT("/Game/UI/HUD_Main"));
	if (HudBPClass.Class != NULL)
	{
		HUDClass = HudBPClass.Class;
	}
}


/******************** AddPoints *************************/
int ABlockByBlockGameMode::AddPoints(int Points)
{
	PlayerPoints += Points;
	return PlayerPoints;
}


/******************** RemovePoints *************************/
int ABlockByBlockGameMode::RemovePoints(int Points)
{
	PlayerPoints -= Points;
	return PlayerPoints;
}
