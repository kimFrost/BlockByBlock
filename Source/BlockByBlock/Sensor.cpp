// Fill out your copyright notice in the Description page of Project Settings.

#include "Sensor.h"
#include "BlockByBlock.h"
#include "Block.h"




// Sets default values
USensor::USensor()
{
	//SphereRadius = 5.f;
	bShouldSensorBlock = true;
	bShouldSensorPlayer = false;

	//BoxExtent = FVector(20.f, 20.f, 20.f);
	InitBoxExtent(FVector(20.f, 20.f, 20.f));
	//SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	//SetCollisionObjectType(ECC_WorldDynamic);
	SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Overlap); // Overlap BlockObjectChannel 
	SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel2, ECollisionResponse::ECR_Overlap); // Overlap BlockTraceChannel
	//SetCollisionProfileName();
	SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	SetHiddenInGame(false);

	//ECC_GameTraceChannel1
}




void USensor::SensorTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ABlock* Block = Cast<ABlock>(OtherActor);
	if (Block)
	{
		OnBlockSensored.Broadcast(Block);
	}
}

// Called when the game starts or when spawned
void USensor::BeginPlay()
{
	Super::BeginPlay();

	//FComponentBeginOverlapSignature, UPrimitiveComponent*, OverlappedComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, int32, OtherBodyIndex, bool, bFromSweep, const FHitResult &, SweepResult
	//Order->OnOrderResolved.AddUniqueDynamic(this, &AOrderVisualizer::OnOrderResolved);
	OnComponentBeginOverlap.AddDynamic(this, &USensor::SensorTriggered);
}