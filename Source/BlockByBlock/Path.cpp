// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockByBlock.h"
#include "Components/SplineMeshComponent.h"
#include "Components/SplineComponent.h"
#include "Connector.h"
#include "Path.h"


// Sets default values
APath::APath(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SplinePath = nullptr;
	//bLockedInPlace = false;

	SplinePath = CreateDefaultSubobject<USplineComponent>(TEXT("SplinePath"));
	SplinePath->Mobility = EComponentMobility::Static;
	RootComponent = SplinePath;
}


/******************** AddConnector *************************/
void APath::AddConnector(UConnector * Connector)
{
	if (Connector)
	{
		if (!Connectors.Contains(Connector))
		{
			Connectors.Add(Connector);
			SortConnectorArray();
			UpdateSpline();
		}
	}
}


/******************** SortConnectorArray *************************/
void APath::SortConnectorArray()
{
	// Sort by x, then y
	Connectors.Sort([](const UConnector& c1, const UConnector& c2) {
		return c1.WorldLocation.X < c2.WorldLocation.X;

		//TODO check for Y as secondary
	});
	/*
	Connectors.Sort([](const UConnector& c1, const UConnector& c2) {
		return c1.WorldLocation.Y > c2.WorldLocation.Y;
	});
	*/
}


/******************** UpdateSpline *************************/
void APath::UpdateSpline()
{
	if (IsValid(SplinePath))
	{
		SplinePath->ClearSplinePoints(false);
		/*
		int NumberOfSplinePoints = SplinePath->GetNumSplinePoints();
		for (int i = 0; i < NumberOfSplinePoints - 1; i++)
		{
			SplinePath->RemoveSplinePoint(i, false);
		}
		*/
		for (auto& Connector : Connectors)
		{
			if (Connector)
			{
				SplinePath->AddSplinePoint(Connector->WorldLocation, ESplineCoordinateSpace::World, false);
			}
		}
		int NumberOfSplinePoints = SplinePath->GetNumberOfSplinePoints();
		for (int i = 0; i < NumberOfSplinePoints - 1; i++)
		{
			SplinePath->SetSplinePointType(i, ESplinePointType::Linear);
		}
		SplinePath->UpdateSpline();
	}

	//AddComponent
	// Create USplineMesh
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

