// Fill out your copyright notice in the Description page of Project Settings.

#include "Connector.h"
#include "BlockByBlock.h"
#include "DataHolder.h"
//#include "Kismet/KismetSystemLibrary.h"
#include "Path.h"




// Sets default values
UConnector::UConnector()
{
	ConnectionType = EConnectionType::Rail;
	SphereRadius = 5.f;
	Path = nullptr;
}




/******************** Update *************************/
void UConnector::Update()
{
	if (Path == nullptr)
	{
		ConnectorRoutes.Empty();

		// Add siblings of same connector types to connector routes
		ParentActor = Cast<AActor>(GetOwner());
		if (ParentActor)
		{
			// Update world location variable
			//WorldLocation = GetRelativeTransform().GetLocation() + ParentActor->GetActorLocation();
			WorldLocation = K2_GetComponentLocation();

			TArray<UActorComponent*> ConnectorComponents = ParentActor->GetComponentsByClass(UConnector::StaticClass());
			for (auto& Component : ConnectorComponents)
			{
				UConnector* ConnectorComponent = Cast<UConnector>(Component);
				if (ConnectorComponent)
				{
					if (ConnectorComponent != this)
					{
						if (ConnectorComponent->ConnectionType == ConnectionType)
						{
							ConnectorRoutes.Add(ConnectorComponent);
						}
					}
				}
			}
		}

		// Add overlapping of same connection type to connector routes
		TArray<UPrimitiveComponent*> OverlappingConnectors;
		GetOverlappingComponents(OverlappingConnectors);
		for (auto& Connector : OverlappingConnectors)
		{
			UConnector* OtherConnector = Cast<UConnector>(Connector);
			if (OtherConnector)
			{
				if (OtherConnector->ConnectionType == ConnectionType)
				{
					ConnectorRoutes.Add(OtherConnector);
					//ConnectedTo = OtherConnector;
				}
			}
		}

		// Look for path in connector routes
		for (auto& Connector : ConnectorRoutes)
		{
			if (IsValid(Connector))
			{
				if (IsValid(Connector->Path))
				{
					Path = Connector->Path;
					break;
				}
			}
		}

		// If no path has been found
		if (IsValid(Path))
		{
			// Add self to path
			Path->AddConnector(this);
		}
		else
		{
			// Create path
			if (IsValid(ParentActor))
			{
				UWorld* const World = ParentActor->GetWorld();
				if (World)
				{
					FRotator Rotation;
					Rotation.Yaw = 0.f;
					Rotation.Pitch = 0.f;
					Rotation.Roll = 0.f;
					FVector Location = WorldLocation;

					FActorSpawnParameters SpawnParameters;
					SpawnParameters.bNoFail = true;
					SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

					APath* SpawnedPath = World->SpawnActor<APath>(APath::StaticClass(), Location, Rotation);
					if (SpawnedPath)
					{
						Path = SpawnedPath;
						// Add self to path
						Path->AddConnector(this);
					}
				}
			}
		}

		// Call update on all connector routes
		for (auto& Connector : ConnectorRoutes)
		{
			if (Connector)
			{
				Connector->Update();
			}
		}
	}

		
	/*
	UOrderSpawnModule* Order = NewObject<UOrderSpawnModule>();
	if (Order)
	{
	}
	*/

	// Update other connector of same parent actor
		// - add connector to path connector list	

	// Update overlapping connectors
		// - add connector to path connect list

}


/******************** CreateSpline *************************/
void UConnector::CreateSpline()
{

}




// Called when the game starts or when spawned
void UConnector::BeginPlay()
{
	Super::BeginPlay();
	
	Update();
}

/*
// Called every frame
void UConnector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/

