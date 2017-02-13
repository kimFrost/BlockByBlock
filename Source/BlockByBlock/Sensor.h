// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "Block.h"
#include "Sensor.generated.h"


//~~ DELEGATES ~~//
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlockSensored, ABlock*, Block);


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BLOCKBYBLOCK_API USensor : public UBoxComponent
{
	GENERATED_BODY()
	

public:
	// Sets default values for properties
	USensor();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sensor")
	bool bShouldSensorBlock;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sensor")
	bool bShouldSensorPlayer;

	UFUNCTION(BlueprintCallable, Category = "Sensor")
	void SensorTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);


	UPROPERTY(BlueprintAssignable, Category = "Sensor|Module")
	FBlockSensored OnBlockSensored;
	


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
