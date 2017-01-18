// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "BlockByBlockGameMode.generated.h"

UCLASS(minimalapi)
class ABlockByBlockGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABlockByBlockGameMode();


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	int PlayerPoints;


	// FUNCTIONS

	UFUNCTION(BlueprintCallable, Category = Grid)
	int AddPoints(int Points);

	UFUNCTION(BlueprintCallable, Category = Grid)
	int RemovePoints(int Points);
};



