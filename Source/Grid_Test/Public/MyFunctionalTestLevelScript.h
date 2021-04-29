// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FunctionalTestLevelScript.h"
#include "MyFunctionalTestLevelScript.generated.h"

/**
 * 
 */
UCLASS()
class GRID_TEST_API AMyFunctionalTestLevelScript : public AFunctionalTestLevelScript
{
	GENERATED_BODY()
public:
	UPROPERTY()
		int turnNum;

	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
		int returnTurnNum() {
		return turnNum;
	}
};
