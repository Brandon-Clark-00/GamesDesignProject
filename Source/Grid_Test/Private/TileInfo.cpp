// Fill out your copyright notice in the Description page of Project Settings.

#include "TileInfo.h"


// Sets default values for this component's properties
UTileInfo::UTileInfo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	ID = -1;
	tileType = 20;
	tileName = genTileName(tileType);
	addTransport(0);
	tileLocation;
	energyProduction = 0;
	waterProduction = 0;
	foodProduction = 0;

	// ...
}

UFUNCTION(BlueprintCallable, Category = "Tile")
void UTileInfo::genTileInfo(int iID, int iTileType, TArray<int> iGridPos, FTransform itileLocation, float iEProduction, float iWProduction, float iFProduction, UImprovementInfo* iImprovements)
{
	ID = iID;
	tileType = iTileType;
	tileName = genTileName(getTileType());
	improvements = iImprovements;
	gridPos = iGridPos;
	addTransport(0);
	addTransport(0);
	tileLocation = itileLocation;
	energyProduction = iEProduction;
	waterProduction = iWProduction;
	foodProduction = iFProduction;
};

// Called when the game starts
void UTileInfo::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTileInfo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UFUNCTION(BlueprintCallable, Category = "Tile")
void UTileInfo::addTransport(int input)
{
	TArray<int> temp = getcurrentUtilities();
	temp.Add(input);
	setcurrentUtilities(temp);
}

FString UTileInfo::genTileName(int input)
{
	switch (input)
	{
	case 1:
		return "Sand";
	case 2:
		return "Grasslands";
	case 3:
		return "Swamp";
	case 4:
		return "Deep Sea";
	case 5:
		return "Rocky mountains";
	default:
		return "Blank";
		break;
	}
};