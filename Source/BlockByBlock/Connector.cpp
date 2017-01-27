// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockByBlock.h"
#include "DataHolder.h"
//#include "Kismet/KismetSystemLibrary.h"
#include "Connector.h"



// Sets default values
UConnector::UConnector()
{
	ConnectionType = EConnectionType::Rail;
	SphereRadius = 5.f;
}




/******************** Update *************************/
void UConnector::Update()
{
	//TArray<UConnector*> OverlappingConnectors;
	//TArray <AActor*> & ActorsToIgnore
	//UKismetSystemLibrary::ComponentOverlapComponents_NEW(this, this->GetRelativeTransform, , this->StaticClass(), ActorsToIgnore, OverlappingConnectors);

	TArray<UPrimitiveComponent*> OverlappingConnectors;
	GetOverlappingComponents(OverlappingConnectors);
	for (auto& Connector : OverlappingConnectors)
	{
		UConnector* OtherConnector = Cast<UConnector>(Connector);
		if (OtherConnector)
		{
			if (ConnectionType == OtherConnector->ConnectionType)
			{
				//OtherConnector->GetOwner;
				AActor* ParentActor = Cast<AActor>(GetOwner());
				//AActor* ParentActor = Cast<AActor>(GetParentActor());
				if (ParentActor)
				{
					ConnectedTo = ParentActor;
					break;
				}
			}
		}
	}
}





// Called when the game starts or when spawned
void UConnector::BeginPlay()
{
	Super::BeginPlay();

	AActor* ParentActor = Cast<AActor>(GetOwner());
	if (ParentActor)
	{
		ConnectedFrom = ParentActor;
	}

	Update();
}

/*
// Called every frame
void UConnector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/

