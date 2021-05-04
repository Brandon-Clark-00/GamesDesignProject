// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include <iostream>
#include <vector>
#include <string>
#include "Components/ActorComponent.h"
#include "Math/TransformNonVectorized.h"
#include "Containers/Array.h"
#include "ResourceInfo.h"
#include "ImprovementInfo.h"
#include "TileInfo.generated.h"

using namespace std;



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRID_TEST_API UTileInfo : public UActorComponent
{
	GENERATED_BODY()


public:
	// Sets default values for this component's properties
	UTileInfo();
	UTileInfo(int iID, int iTileType, FTransform itileLocation, float iEProduction, float iWProduction, float iFProduction, UResourceInfo* iTileResource, UImprovementInfo* iImprovements);

	UPROPERTY()
		int ID;
	int tileType;
	FString tileName;
	TArray<int> gridPos;
	/*TArray<int> currentUtilities;*/
	/*FTransform tileLocation;*/
	float energyProduction;
	float moneyProduction;
	float foodProduction;
	UPROPERTY()
		UResourceInfo* tileResource;
	UPROPERTY()
		UImprovementInfo* improvements;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//mutators and accessors

	UFUNCTION(BlueprintCallable, Category = "Tile")
		int getID() {
		return ID;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		void setID(int input) {
		ID = input;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		int getTileType() {
		return tileType;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		void setTileType(int input) {
		tileType = input;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		FString getTileName() {
		return tileName;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		void setTileName(FString input) {
		tileName = input;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		UImprovementInfo* getCurrentImprovement() {
		return improvements;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		void setCurrentImprovement(UImprovementInfo* input) {
		improvements = input;
	};

	/*UFUNCTION(BlueprintCallable, Category = "Tile")
		TArray<int> getcurrentUtilities() {
		return currentUtilities;
	};*/

	UFUNCTION(BlueprintCallable, Category = "Tile")
		void setGridPos(TArray<int> input) {
		gridPos = input;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		TArray<int> getGridPos() {
		return gridPos;
	};

	//UFUNCTION(BlueprintCallable, Category = "Tile")
	//	void setcurrentUtilities(TArray<int> input) {
	//	currentUtilities = input;
	//};

	//UFUNCTION(BlueprintCallable, Category = "Tile")
	//	FTransform getTileLocation() {
	//	return tileLocation;
	//};

	//UFUNCTION(BlueprintCallable, Category = "Tile")
	//	void setTileLocation(FTransform input) {
	//	tileLocation = input;
	//};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		float getEnergyProduction() {
		return energyProduction;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		void setEnergyProduction(float input) {
		energyProduction = input;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		float getMoneyProduction() {
		return moneyProduction;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		void setMoneyProduction(float input) {
		moneyProduction = input;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		float getFoodProduction() {
		return foodProduction;
	};

	UFUNCTION(BlueprintCallable, Category = "Tile")
		void setFoodProduction(float input) {
		foodProduction = input;
	};

	//UFUNCTION(BlueprintCallable, Category = "Tile")
	//	void addTransport(int input);

	UFUNCTION(BlueprintCallable,Category = "Tile")
		UResourceInfo* getResource() {
		return tileResource;
	}

	UFUNCTION(BlueprintCallable, Category = "Tile")
		void setTileResource(UResourceInfo* referenceInput) {
		tileResource = referenceInput;
	}

	UFUNCTION(BlueprintCallable, Category = "Tile")
		UImprovementInfo* getImprovementInfo() {
		return improvements;
	}

	UFUNCTION(BlueprintCallable, Category = "Tile")
		void setImprovementStruct(UImprovementInfo* referenceInput) {
		improvements = referenceInput;
	}

	UFUNCTION(BlueprintCallable, Category = "Tile")
		bool validateGrid(int x, int y);

	FString genTileName(int input);


	UFUNCTION(BlueprintCallable, Category = "Tile")
		void genTileInfo(int iID, int iTileType, TArray<int> iGridPos, /*FTransform itileLocation,*/ float iEProduction, float iWProduction, float iFProduction, UImprovementInfo* iImprovements);

};


	//{
	//docString.Append(FString::FromInt(playerTiles[i]->getImprovementInfo()->getImprovementID()));
	//docString.Append("_");

	//docString.Append(FString::FromInt(playerTiles[i]->getImprovementInfo()->getImprovementType()));
	//docString.Append("_");

	//docString.Append(playerTiles[i]->getImprovementInfo()->getImprovementName());
	//docString.Append("_");

	//docString.Append(FString::SanitizeFloat(playerTiles[i]->getImprovementInfo()->getCost()));
	//docString.Append("_");

	//docString.Append(FString::SanitizeFloat(playerTiles[i]->getImprovementInfo()->getRunningCost()));
	//docString.Append("_");

	//docString.Append(FString::SanitizeFloat(playerTiles[i]->getImprovementInfo()->getValueIncrease()));
	//docString.Append("_");