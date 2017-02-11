// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Path.generated.h"


class UConnector;


UCLASS()
class BLOCKBYBLOCK_API APath : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APath();


	UPROPERTY(BlueprintReadWrite, Category = "Connection")
	TArray<UConnector*> Connectors;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resources")
	//bool bLockedInPlace;


	//UFUNCTION(BlueprintCallable, Category = "Ship")
	//void ParseOrderQue();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
