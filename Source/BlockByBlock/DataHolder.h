// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "DataHolder.generated.h"






//~~~~~ FORWARD DECLATIONS ~~~~~//
class AShipModule;



//~~~~~ ENUMS ~~~~~//

UENUM(BlueprintType)
enum class EConnectionType : uint8
{
	Rail UMETA(DisplayName = "Rail")
};

UENUM(BlueprintType)
enum class EShipModuleType : uint8
{
	BlockSquare UMETA(DisplayName = "BlockSquare"),
	BlockCore UMETA(DisplayName = "BlockCore"),
	BlockCorner UMETA(DisplayName = "BlockCorner"),
	TurretLaser UMETA(DisplayName = "TurretLaser"),
	Engine UMETA(DisplayName = "Engine"),
	MODULE_Test UMETA(DisplayName = "Test")
};


//~~~~~ STRUCTS ~~~~~//

USTRUCT(BlueprintType)
struct FST_ShipModule
{
	GENERATED_USTRUCT_BODY()
public:
	FST_ShipModule(
		FString Title = "",
		EShipModuleType Type = EShipModuleType::BlockSquare,
		float Rotation = 0.f,
		FVector Position = FVector{0, 0, 0})
		: Title(Title)
		, Type(Type)
		, Rotation(Rotation)
		, Position(Position)
	{}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
	FString Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
	EShipModuleType Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
	float Rotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
	FVector Position;
};


//~~~~~ DATA IMPORT ~~~~~//

USTRUCT(BlueprintType)
struct FST_Ship : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	FST_Ship(FString Id = "", TArray<FST_ShipModule> Modules = TArray<FST_ShipModule>())
		: Id(Id)
		, Modules(Modules)
	{}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
	FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
	TArray<FST_ShipModule> Modules;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
	//FST_ShipModule TestStruct;
};



UCLASS()
class BLOCKBYBLOCK_API UDataHolder : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
};
