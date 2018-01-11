// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABlockManager.generated.h"


class UHierarchicalInstancedStaticMeshComponent;
class ABlock;

UCLASS()
class BLOCKBYBLOCK_API ABlockManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockManager();

	UHierarchicalInstancedStaticMeshComponent* HISMComp;

	TArray<ABlock*> Blocks;

	void CreateBlocks();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
