// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockByBlock.h"
#include "DataHolder.h"
//#include "Kismet/KismetSystemLibrary.h"
#include "Path.h"
#include "Connector.h"



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
	ConnectorRoutes.Empty();

	// Add siblings of same connector types to connector routes
	SiblingConnectors.Empty();
	ParentActor = Cast<AActor>(GetOwner());
	if (ParentActor)
	{
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
			if (ConnectionType == OtherConnector->ConnectionType)
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
				FVector Location = GetComponentLocation();

				FActorSpawnParameters SpawnParameters;
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

		/*
		UOrderSpawnModule* Order = NewObject<UOrderSpawnModule>();
		if (Order)
		{
		}
		*/

	}




		
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

