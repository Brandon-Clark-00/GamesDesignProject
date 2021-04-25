// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/TransformNonVectorized.h"
#include <iostream>

using namespace std;

int ID;
int tileType;
string tileName;
int currentImprovement;
int currentTransport[3] = {};
FTransform tileLocation;



/**
 * 
 */
class GRID_TEST_API TileDetails
{
public:
	TileDetails();
	~TileDetails();
};
