// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FunctionalTestLevelScript.h"
#include "PlayerClass.h"
#include "TileInfo.h"
#include "ResourceInfo.h"
#include "ImprovementInfo.h"
#include "MyFunctionalTestLevelScript.generated.h"

/**
 * 
 */
UCLASS()
class GRID_TEST_API AMyFunctionalTestLevelScript : public AFunctionalTestLevelScript
{
	GENERATED_BODY()
public:
	virtual void OnConstruction(const FTransform& Transform) override;
	AMyFunctionalTestLevelScript();
	

	UPROPERTY()
		int turnNum;
	UPROPERTY()
		int turnLimit;
	UPROPERTY()
		bool gameOver = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) 
		UPlayerClass* Player = nullptr;




	UPROPERTY()
		TArray<UPlayerClass*> AIPlayers;

	
public:

	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
		int getTurnNum() const { return turnNum; }

	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
		void setTurnNum(int iTurnNum) { this->turnNum = iTurnNum; }

	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
    UPlayerClass* getPlayer() const { return Player; }

	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
    void setPlayer(UPlayerClass* iPlayer) { this->Player = iPlayer; }

	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
    TArray<UPlayerClass*> getAIPlayers() const { return AIPlayers; }
    
	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
	void setAIPlayers(TArray<UPlayerClass*> iAIPlayers) { this->AIPlayers = iAIPlayers; }

	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
	int getTurnLimit() const { return turnLimit; }

	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
	void setTurnLimit(int iTurnLimit) { this->turnLimit = iTurnLimit; }

	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
	bool getGameOver() const { return gameOver; }

	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
	void setGameOver(bool iGameOver) { this->gameOver = iGameOver; }

	void takeAITurn(UPlayerClass* AI);

	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
	void gameLoop();

	UFUNCTION(BlueprintCallable, Category = "CoreLogic")
	void genAI(int AINum);

	TArray<UTileInfo*> genAITiles();

	UResourceInfo* genTileResource(int tileType);
	

    

   
};
