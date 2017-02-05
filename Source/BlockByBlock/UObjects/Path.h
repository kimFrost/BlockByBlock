// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "Path.generated.h"


/*** Forward declarations ***/
class UConnector;




UCLASS()
class BLOCKBYBLOCK_API UPath : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, Category = "Connection")
	TArray<UConnector*> Connectors;

	/*
	UPROPERTY(BlueprintReadWrite, Category = "Connection")
	USplineMeshComponent* PathSpline;

	UPROPERTY(BlueprintReadWrite, Category = "Connection")
	TArray<AActor*> ConnectedVehicles;
	*/

	//OnPathChanged   Connector bind to path change

};
