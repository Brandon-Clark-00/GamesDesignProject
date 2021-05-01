// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ResourceInfo.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRID_TEST_API UResourceInfo : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UResourceInfo();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
		int ID;
	UPROPERTY()
		int resourceType;
	UPROPERTY()
		FString resourceName;
	UPROPERTY()
		int resourceCount;
	UPROPERTY()
		float currencyValue;
	UPROPERTY()
		float energyValue;
	UPROPERTY()
		float waterValue;
	UPROPERTY()
		float foodValue;
	//UPROPERTY()
		//TArray<int> spawnTileTypes;

	UFUNCTION(BlueprintCallable, Category = "Resource")
		int getID() {
		return ID;
		}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		void setID(int input) {
		ID = input;
		}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		int getResourceType() {
		return resourceType;
		}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		void setResourceType(int input) {
		resourceType = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		FString getResourceName() {
		return resourceName; 
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		void setResourceName(FString input) {
		resourceName = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		int getResourceCount() {
		return resourceCount;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		void setResourceCount(int input) {
		resourceCount = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		float getCurrencyValue() {
		return currencyValue;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		void setCurrencyValue(float input) {
		currencyValue = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		float getEnergyValue() {
		return energyValue;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		void setEnergyValue(float input) {
		energyValue = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		float getWaterValue() {
		return waterValue;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		void setWaterValue(float input) {
		waterValue = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		float getFoodValue() {
		return foodValue;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		void setFoodValue(float input) {
		foodValue = input;
	}

	/*UFUNCTION(BlueprintCallable, Category = "Resource")
		TArray<int> getSpawnTileTypes() {
		return spawnTileTypes;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		void setSpawnTileTypes(TArray<int> input) {
		spawnTileTypes = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		void removeFromSpawnTileTypes(int index)
	{
		spawnTileTypes.RemoveAt(spawnTileTypes.Find(index));

	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		void addToSpawnTileTypes(int input) {
		spawnTileTypes.Add(input);
	}

	UFUNCTION(BlueprintCallable, Category = "Resource")
		void clearSpawnTileTypes() {
		spawnTileTypes.Empty();
	}*/
	
	UFUNCTION(BlueprintCallable, Category = "Resource")
	void genResourceInfo(int iID, int iResourceType, int iResourceCount, float iCurrencyValue, float iEnergyValue, float iWaterValue, float iFoodValue/*, TArray<int> iSpawnTileTypes*/);
	
	//UFUNCTION(BlueprintCallable, Category = "Resource")
	//	bool tileCompatile(int tileType);

	FString genResourceName(int input);

};
