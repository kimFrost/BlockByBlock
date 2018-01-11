// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Block.generated.h"


class UBoxComponent;


UCLASS()
class BLOCKBYBLOCK_API ABlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlock();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resources")
	bool bLockedInPlace;

	int32 Index;

	UBoxComponent* CollisionComp;

	//UFUNCTION(BlueprintCallable, Category = "Ship")
	//void ParseOrderQue();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
