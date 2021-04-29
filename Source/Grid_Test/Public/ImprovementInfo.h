// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ImprovementInfo.generated.h"

using namespace std;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRID_TEST_API UImprovementInfo : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UImprovementInfo();

	UPROPERTY()
		int improvementID;
	UPROPERTY()
		int improvementType;
	UPROPERTY()
		FString improvementName;
	UPROPERTY()
		float cost;
	UPROPERTY()
		float runningCost;
	UPROPERTY()
		float valueIncrease;
	UPROPERTY()
		TArray<int> validTiles;
	UPROPERTY()
		TArray<int> validResources;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, Category = "Improvements")
		int getImprovementID() {
		return improvementID;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		void setImprovementID(int input) {
		improvementID = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		int getImprovementType() {
		return improvementType;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		void setImprovementType(int input) {
		improvementType = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		FString getImprovementName() {
		return improvementName;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		void setImprovementName(FString input) {
		improvementName = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		float getCost() {
		return cost;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		void setCost(float input) {
		cost = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		float getRunningCost() {
		return runningCost;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		void setRunningCost(float input) {
		runningCost = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		float getValueIncrease() {
		return valueIncrease;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		void setValueIncreased(float input) {
		valueIncrease = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		TArray<int> getValidTiles() {
		return validTiles;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		void setValidTiles(TArray<int> input) {
		validTiles = input;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		TArray<int> getValidResources() {
		return validResources;
	}

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		void setValidResources(TArray<int> input) {
		validResources = input;
	}
	UFUNCTION(BlueprintCallable, Category = "Improvements")
	void genImprovementInfo(int iImprovementID, int iImprovementType, FString iImprovementName, float iCost, float iRunningCost, float iValueIncrease, TArray<int> iValidTiles, TArray<int> iValidResources);

	FString genImprovementName(int iImprovementType);

	UFUNCTION(BlueprintCallable, Category = "Improvements")
		bool improvementValid(int tileType, int resourceType);
};
