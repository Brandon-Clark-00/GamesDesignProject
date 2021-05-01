// Fill out your copyright notice in the Description page of Project Settings.


#include "ImprovementInfo.h"

// Sets default values for this component's properties
UImprovementInfo::UImprovementInfo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UImprovementInfo::BeginPlay()
{
	Super::BeginPlay();
	improvementID = 0;
	improvementType = 0;
	improvementName = 0;
	cost = 0;
	runningCost = 0;
	valueIncrease = 0;
	// ...
	
}


// Called every frame
void UImprovementInfo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UFUNCTION(BlueprintCallable, Category = "Improvements")
	void UImprovementInfo::genImprovementInfo(int iImprovementID, int iImprovementType, FString iImprovementName, float iCost, float iRunningCost, float iValueIncrease/*, TArray<int> iValidTiles, TArray<int> iValidResources*/) {
	improvementID = iImprovementID;
	improvementType = iImprovementType;
	improvementName = iImprovementName;
	cost = iCost;
	runningCost = iRunningCost;
	valueIncrease = iValueIncrease;
	//validTiles = iValidTiles;
	//validResources = iValidResources;
}

UFUNCTION(BlueprintCallable, Category = "Improvements")
FString UImprovementInfo::genImprovementName(int iImprovementType)
{
	return FString();
}
;

//UFUNCTION(BlueprintCallable, Category = "Improvements")
//bool UImprovementInfo::improvementValid(int tileType, int resourceType) {
//	/*TArray<int> tiles = getValidTiles();
//	TArray<int> resources = getValidResources();*/
//
//	if (tiles.Contains(tileType) == true && resources.Contains(resourceType))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//};


