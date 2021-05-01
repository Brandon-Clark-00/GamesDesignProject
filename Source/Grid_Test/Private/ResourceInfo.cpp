// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceInfo.h"

// Sets default values for this component's properties
UResourceInfo::UResourceInfo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UResourceInfo::BeginPlay()
{
	Super::BeginPlay();
	ID = 0;
	resourceType = 0;
	resourceName = genResourceName(0);
	resourceCount = 0;
	currencyValue = 0;
	energyValue = 0;
	waterValue = 0;
	foodValue = 0;
	// ...
	
}


// Called every frame
void UResourceInfo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UFUNCTION(BlueprintCallable, Category = "Resource")
void UResourceInfo::genResourceInfo(int iID, int iResourceType, int iResourceCount, float iCurrencyValue, float iEnergyValue, float iWaterValue, float iFoodValue/*, TArray<int> iSpawnTileTypes*/) {
	ID = iID;
	resourceType = iResourceType;
	resourceName = genResourceName(iResourceType);
	resourceCount = iResourceCount;
	currencyValue = iCurrencyValue;
	energyValue = iEnergyValue;
	waterValue = iWaterValue;
	foodValue = iFoodValue;
	/*spawnTileTypes = iSpawnTileTypes;*/

}



//bool UResourceInfo::tileCompatile(int tileType)
//{
//	TArray<int> temp;
//	temp = getSpawnTileTypes();
//	bool output = temp.Contains(tileType);
//		
//	return output;
//}

FString UResourceInfo::genResourceName(int input) {
	switch (input)
	{
	case 1:
		return "Oil";
	case 2:
		return "Coal";
	case 3:
		return "Iron";
	case 4:
		return "Silver";
	case 5:
		return "Fish";
	case 6:
		return "Wheat";
	case 7:
		return "Sheep";
	case 8:
		return "Wood";
	default:
		return "No resource";
		break;
	}
}

