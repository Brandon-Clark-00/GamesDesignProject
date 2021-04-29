// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <vector>
#include <string>
#include "Components/ActorComponent.h"
#include "Math/TransformNonVectorized.h"
#include "TileDetailClass.generated.h"

using namespace std;

//int ID;
//int tileType;
//string tileName;
//int currentImprovement;
//vector<int> currentTransport;
//FTransform tileLocation;
//float energyProduction;
//float waterProduction;
//float foodProduction;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRID_TEST_API UTileDetailClass : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTileDetailClass();
	


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	

		
};
