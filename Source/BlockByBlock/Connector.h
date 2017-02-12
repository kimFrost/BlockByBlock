// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "Components/SplineMeshComponent.h"
#include "DataHolder.h"
#include "Path.h"
#include "Connector.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
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

	FVector WorldLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connection")
	EConnectionType ConnectionType;

	//AActor* ConnectedFrom;

	//AActor* ConnectedTo;

	UConnector* ConnectedTo;

	AActor* ParentActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connection")
	TArray<UConnector*> ConnectorRoutes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connection")
	APath* Path;

	UFUNCTION(BlueprintCallable, Category = "Connection")
	void Update();

	void CreateSpline();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	//virtual void Tick(float DeltaSeconds) override;

};
