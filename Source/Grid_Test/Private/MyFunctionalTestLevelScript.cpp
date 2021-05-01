// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFunctionalTestLevelScript.h"


AMyFunctionalTestLevelScript::AMyFunctionalTestLevelScript() {
	Player = CreateDefaultSubobject<UPlayerClass>(TEXT("Player 1"));
}

UFUNCTION(BlueprintCallable, Category = "CoreLogic")
void AMyFunctionalTestLevelScript::OnConstruction(const FTransform& Transform)
{
	Player = NewObject<UPlayerClass>();
}









void AMyFunctionalTestLevelScript::takeAITurn(UPlayerClass* AI)
{
	
}
void AMyFunctionalTestLevelScript::gameLoop()
{
	setTurnNum(getTurnNum() + 1);
	if (turnNum != turnLimit && !gameOver)
	{
		for (int i = 0; i < getAIPlayers().Num(); i++)
		{
			takeAITurn(getAIPlayers()[i]);
		}
	}
		


		
	
}

void AMyFunctionalTestLevelScript::genAI()
{
	UPlayerClass temp;
	TArray<UPlayerClass*> tempArr = getAIPlayers();
	TArray<FresourcesList> tempStructArr;
	for (int i = 0; i < tempArr.Num(); i++)
	{
	/*	temp.genPlayerClass(0, 0, 0, 0, 0, 0, 0, 0, tempStructArr, );*/
		tempArr.Add(&temp);
	}
	
	setAIPlayers(tempArr);

}
