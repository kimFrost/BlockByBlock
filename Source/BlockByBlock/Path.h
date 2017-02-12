// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/SplineMeshComponent.h"
#include "Components/SplineComponent.h"
#include "Path.generated.h"


class UConnector;


UCLASS()
class BLOCKBYBLOCK_API APath : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APath(const FObjectInitializer &ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connection")
	USplineComponent* SplinePath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connection")
	TArray<UConnector*> Connectors;


	void AddConnector(UConnector* Connector);

	void SortConnectorArray();

	void UpdateSpline();

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resources")
	//bool bLockedInPlace;


	//UFUNCTION(BlueprintCallable, Category = "Ship")
	//void ParseOrderQue();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
