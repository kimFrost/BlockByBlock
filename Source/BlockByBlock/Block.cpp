// Fill out your copyright notice in the Description page of Project Settings.

#include "Block.h"
#include "BlockByBlock.h"



// Sets default values
ABlock::ABlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bLockedInPlace = false;

	//CollisionComp = NewObject<UPrimitiveComponent>(this);
	//BoxComponent* MyNewBox = NewObject<UBoxComponent>(this);
	//CollisionComp = CreateDefaultSubobject<UPrimitiveComponent>(TEXT("CollisionComp"));
	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	CollisionComp->InitBoxExtent(FVector(50, 50, 50));
	//SetBoxExtent
	//bDynamicObstacle
	RootComponent = CollisionComp;
	//SphereVisual->SetupAttachment(RootComponent);

	/*
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
	}
	*/

	//https://docs.unrealengine.com/latest/INT/Programming/Tutorials/Components/1/
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlock::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

