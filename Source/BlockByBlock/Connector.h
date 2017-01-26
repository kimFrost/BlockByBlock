// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "DataHolder.h"
#include "Connector.generated.h"

/**
 * 
 */
UCLASS()
class BLOCKBYBLOCK_API UConnector : public USphereComponent
{
	GENERATED_BODY()
	
	
public:
	// Sets default values for properties
	UConnector();
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connector")
	//AShipModuleConnector* BoundTo;

	// Connection Type
	
	// Multiple allowed connection types?

	EConnectionType ConnectionType;

	AActor* ConnectedFrom;

	AActor* ConnectedTo;

	void Update();

	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	// Called every frame
	//virtual void Tick(float DeltaSeconds) override;

};
