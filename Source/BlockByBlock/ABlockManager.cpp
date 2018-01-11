// Fill out your copyright notice in the Description page of Project Settings.

#include "ABlockManager.h"
#include "Block.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"


// Sets default values
ABlockManager::ABlockManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HISMComp = NewObject<UHierarchicalInstancedStaticMeshComponent>(this);
	HISMComp->RegisterComponent();  
	//HISMComp->AttachTo()
	//HISMComp->SetStaticMesh(YourStaticMesh);
	HISMComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	HISMComp->SetFlags(RF_Transactional);
	AddInstanceComponent(HISMComp);
}


void ABlockManager::CreateBlocks()
{
	for (int32 Y = 0; Y < 100; Y++)
	{
		for (int32 X = 0; X < 100; X++)
		{
			FRotator Rotation = FRotator(0, 0, 0);
			FVector Location = FVector(X * 100, 0, Y * 100);
			FTransform Transform = FTransform(Rotation, Location);
			int32 Index = HISMComp->AddInstance(Transform);

			UWorld* World = GetWorld();
			if (World)
			{
				FActorSpawnParameters SpawnParameters;
				SpawnParameters.bNoFail = true;
				SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

				ABlock* SpawnedBlock = World->SpawnActor<ABlock>(ABlock::StaticClass(), Location, Rotation);
				if (SpawnedBlock)
				{
					SpawnedBlock->Index = Index;
					Blocks.Insert(SpawnedBlock, Index);
				}
			}
		}
	}
}

// Called when the game starts or when spawned
void ABlockManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlockManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

