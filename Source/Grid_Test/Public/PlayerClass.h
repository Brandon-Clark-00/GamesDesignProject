// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include "TileInfo.h"
#include "ResourceInfo.h"
#include "ImprovementInfo.h"
#include "FileHandling.h"
#include "Containers/UnrealString.h"
#include "PlayerClass.generated.h"

using namespace std;

USTRUCT(BlueprintType)
struct FresourcesList
{
	GENERATED_BODY()
public:
	UPROPERTY()
	int ID;
	UPROPERTY()
	FString name;
	UPROPERTY()
	int count;
};


/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GRID_TEST_API UPlayerClass: public UObject
{
	GENERATED_BODY()

public:
	
	int playerID;
	//Resources
	float moneySupply=1;
	float moneyDemand=2;
	float energySupply=3;
	float energyDemand=4;
	float waterSupply=5;
	float waterDemand=6;
	float foodSupply=7;
	float foodDemand=8;
	TArray<FresourcesList> resources;
	TArray<UTileInfo*> playerTiles;
protected:

public:
	UPlayerClass();
	~UPlayerClass();
public:
	UFUNCTION(BlueprintCallable, Category = "Player")
    int getPlayerID() const { return playerID; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    void setPlayerID(int iPlayerID) { this->playerID = iPlayerID; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    float getMoneySupply() const { return moneySupply; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    void setMoneySupply(float iMoneySupply) { this->moneySupply = iMoneySupply; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    float getMoneyDemand() const { return moneyDemand; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    void setMoneyDemand(float iMoneyDemand) { this->moneyDemand = iMoneyDemand; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    float getEnergySupply() const { return energySupply; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    void setEnergySupply(float iEnergySupply) { this->energySupply = iEnergySupply; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    float getEnergyDemand() const { return energyDemand; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    void setEnergyDemand(float iEnergyDemand) { this->energyDemand = iEnergyDemand; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    float getWaterSupply() const { return waterSupply; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    void setWaterSupply(float iWaterSupply) { this->waterSupply = iWaterSupply; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    float getWaterDemand() const { return waterDemand; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    void setWaterDemand(float iWaterDemand) { this->waterDemand = iWaterDemand; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    float getFoodSupply() const { return foodSupply; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    void setFoodSupply(float iFoodSupply) { this->foodSupply = iFoodSupply; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    float getFoodDemand() const { return foodDemand; }

	UFUNCTION(BlueprintCallable, Category = "Player")
    void setFoodDemand(float iFoodDemand) { this->foodDemand = iFoodDemand; }

	UFUNCTION(BlueprintCallable, Category = "Player")
	TArray<FresourcesList> getResourcesList() { return resources; }

	UFUNCTION(BlueprintCallable, Category = "Player")
	void setResourcesList(TArray<FresourcesList> resourcesList) { this->resources = resourcesList; }

	UFUNCTION(BlueprintCallable, Category = "Player")
		TArray<UTileInfo*> getPlayerTiles() { return playerTiles; }

	UFUNCTION(BlueprintCallable, Category = "Player")
		void setPlayerTiles(TArray<UTileInfo*> playerTilesList) { this->playerTiles = playerTilesList; }

	UFUNCTION(BlueprintCallable, Category = "Player")
		bool isPlayerTilesEmpty()
	{
		if (playerTiles.IsValidIndex(0))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	UFUNCTION(BlueprintCallable, Category = "Player")
		void addToPlayerTiles(UTileInfo* input) {
		playerTiles.Add(input);
	}

	UFUNCTION(BlueprintCallable, Category = "Player")
		UTileInfo* findTile(int y, int x);
	UFUNCTION(BlueprintCallable, Category = "Player")
	UTileInfo* findIndexTile(int input);

	UFUNCTION(BlueprintCallable, Category = "Player")
		void genPlayerClass(int iID, float iMoneySupply,	float iMoneyDemand,	float iEnergySupply, float iEnergyDemand, float iWaterSupply, float iWaterDemand, float iFoodSupply, float ifoodDemand, TArray<FresourcesList> resourcesList, TArray<UTileInfo*> iPlayerTiles);


	UFUNCTION(BlueprintCallable, Category = "FileHandling")
		FString genPlayerDoc();

	UFUNCTION(BlueprintCallable, Category = "FileHandling")
		FString readPlayerDoc();

	TArray<FresourcesList> createResourcesList(FString input);

	TArray<UTileInfo*> createPlayerTiles(FString input);
};
