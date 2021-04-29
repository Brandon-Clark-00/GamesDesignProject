// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>

using namespace std;




/**
 * 
 */
class GRID_TEST_API PlayerClass
{


public:
	
	int playerID;
	//Resources
	float moneySupply;
	float moneyDemand;
	float energySupply;
	float energyDemand;
	float waterSupply;
	float waterDemand;
	float foodSupply;
	float foodDemand;

	struct resourcesList
	{
		int ID;
		string name;
		int count;
	};
	resourcesList resources;
protected:

public:
	PlayerClass();
	~PlayerClass();
public:
    int getPlayerID() const { return playerID; }
    void setPlayerID(int iPlayerID) { this->playerID = iPlayerID; }

    float getMoneySupply() const { return moneySupply; }
    void setMoneySupply(float iMoneySupply) { this->moneySupply = iMoneySupply; }

    float getMoneyDemand() const { return moneyDemand; }
    void setMoneyDemand(float iMoneyDemand) { this->moneyDemand = iMoneyDemand; }

    float getEnergySupply() const { return energySupply; }
    void setEnergySupply(float iEnergySupply) { this->energySupply = iEnergySupply; }

    float getEnergyDemand() const { return energyDemand; }
    void setEnergyDemand(float iEnergyDemand) { this->energyDemand = iEnergyDemand; }

    float getWaterSupply() const { return waterSupply; }
    void setWaterSupply(float iWaterSupply) { this->waterSupply = iWaterSupply; }

    float getWaterDemand() const { return waterDemand; }
    void setWaterDemand(float iWaterDemand) { this->waterDemand = iWaterDemand; }

    float getFoodSupply() const { return foodSupply; }
    void setFoodSupply(float iFoodSupply) { this->foodSupply = iFoodSupply; }

    float getFoodDemand() const { return foodDemand; }
    void setFoodDemand(float iFoodDemand) { this->foodDemand = iFoodDemand; }

	resourcesList getResourcesList() { return resources; }
	void setResourcesList(resourcesList resourcesList) { this->resources = resourcesList; }
};
