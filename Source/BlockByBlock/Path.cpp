// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockByBlock.h"
#include "Path.h"


// Sets default values
APath::APath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//bLockedInPlace = false;
}


/******************** AddConnector *************************/
void APath::AddConnector(UConnector * Connector)
{
	if (Connector)
	{
		if (!Connectors.Contains(Connector))
		{
			Connectors.Add(Connector);

			// Update spline
		}
	}
}


// Called when the game starts or when spawned
void APath::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APath::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

