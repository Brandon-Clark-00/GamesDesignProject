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
	bool turnTaken = false;
	while (!turnTaken)
	{
		int tile = rand() % 170;
		if (AI->getPlayerTiles()[tile]->getCurrentImprovement()->getImprovementID() != 0)
		{
			continue;
		}
		else
		{
			AI->updateResources(AI->getPlayerTiles()[tile]->getResource(),AI->getPlayerTiles()[tile]->getImprovementInfo());
			turnTaken = true;
		}
	}
}
void AMyFunctionalTestLevelScript::gameLoop()
{
	setTurnNum(getTurnNum() + 1);
	getPlayer()->genPlayerDoc("player");
	if (turnNum != turnLimit && !gameOver)
	{
		if (getAIPlayers().IsValidIndex(0))
		{

			for (int i = 0; i < getAIPlayers().Num(); i++)
			{
				takeAITurn(getAIPlayers()[i]);
				getAIPlayers()[i]->genPlayerDoc(FString::FromInt(i));
				UE_LOG(LogTemp, Warning, TEXT("Done an AI"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AI Players empty"));
		}
	}
		


		
	
}

UFUNCTION(BlueprintCallable, Category = "CoreLogic")
void AMyFunctionalTestLevelScript::genAI(int AINum)
{
	UPlayerClass* temp;
	TArray<UPlayerClass*> tempArr = getAIPlayers();
	TArray<FresourcesList> tempStructArr;
	TArray<UTileInfo*> tempTiles;
	for (int i = 0; i < AINum; i++)
	{
		temp = NewObject<UPlayerClass>();
		temp->genPlayerClass(i+1,50,5,5,5,5,5,5,5,5,tempStructArr,genAITiles());
		tempArr.Add(temp);
	}
	
	setAIPlayers(tempArr);

}

TArray<UTileInfo*> AMyFunctionalTestLevelScript::genAITiles()
{
	TArray<UTileInfo*> output;
	UTileInfo* tile;
	UResourceInfo* resource;
	UImprovementInfo* improvement;
	TArray<int> grid;
	grid.Add(0);
	grid.Add(0);
	for (int i = 0; i < 170; i++) {
		tile = NewObject<UTileInfo>();
		resource = NewObject<UResourceInfo>();
		improvement = NewObject<UImprovementInfo>();
		improvement->genImprovementInfo(0, 0, "Null", 0, 0, 0);
		int tileType = (rand() % 8) + 1;
		tile->genTileInfo(i, tileType , grid, 0, 0, 0, improvement);
		tile->setTileResource(genTileResource(tileType));
		UE_LOG(LogTemp, Warning, TEXT("The resource is %s"), *tile->getResource()->getResourceName());
		output.Add(tile);
	}
	return output;
}

UResourceInfo* AMyFunctionalTestLevelScript::genTileResource(int tileType)
{
	UResourceInfo* resource = NewObject<UResourceInfo>();
	int subchoice = rand() % 3;
	int sub2 = rand() % 4;
	switch (tileType)
	{
		
	case 0:
		resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
		UE_LOG(LogTemp, Warning, TEXT("Case 0"));
		break;
	case 1:
		switch (subchoice)
		{
		case 0:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		case 1:
			resource->genResourceInfo(0, 1, (rand() % 3) + 1, 8, 0, 0, 0);
			break;
		case 2:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		case 3:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		default:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		}
		UE_LOG(LogTemp, Warning, TEXT("Case 1"));
		break;
	case 2:
		switch (subchoice)
		{
		case 0:
			resource->genResourceInfo(0, 6, (rand() % 3) + 1, 0, 0, 0, 2);
			break;
		case 1:
			resource->genResourceInfo(0, 7, (rand() % 3) + 1, 0, 0, 0, 4);
			break;
		case 2:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		case 3:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		default:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		}
		UE_LOG(LogTemp, Warning, TEXT("Case 2"));
		break;
	case 3:
		switch (sub2)
		{
		case 0:
			resource->genResourceInfo(0, 3, (rand() % 3) + 1, 8, 0, 0, 0);
			break;
		case 1:
			resource->genResourceInfo(0, 2, (rand() % 3) + 1, 2, 3, 0, 0);
			break;
		case 2: 
			resource->genResourceInfo(0, 2, (rand() % 3) + 1, 0, 0, 0, 4);
			break;
		case 3:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		case 4:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		default:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		}
		UE_LOG(LogTemp, Warning, TEXT("Case 3"));
		break;
	case 4:
		switch (subchoice)
		{
		case 0:
			resource->genResourceInfo(0, 1, (rand() % 3) + 1, 8, 0, 0, 0);
			break;
		case 1:
			resource->genResourceInfo(0, 5, (rand() % 3) + 1, 3, 0, 0, 6);
			break;
		case 2:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		case 3:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		default:
			break;
		}
		UE_LOG(LogTemp, Warning, TEXT("Case 4"));
		break;
	case 5:
		switch (sub2)
		{
		case 0:
			resource->genResourceInfo(0, 2, (rand() % 3) + 1, 2, 3, 0, 0);
			break;
		case 1:
			resource->genResourceInfo(0, 3, (rand() % 3) + 1, 8, 0, 0, 0);
			break;
		case 2:
			resource->genResourceInfo(0, 4, (rand() % 3) + 1, 6, 0, 0, 0);
			break;
		case 3:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		case 4:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		default:
			break;
		}
		UE_LOG(LogTemp, Warning, TEXT("Case 5"));
		break;
	case 6:
		switch (subchoice)
		{
		case 0:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		case 1:
			resource->genResourceInfo(0, 5, (rand() % 3) + 1, 3, 0, 0, 0);
			break;
		case 2:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		case 3:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		default:
			break;
		}
		UE_LOG(LogTemp, Warning, TEXT("Case 6"));
		break;
	case 7:
		switch (sub2)
		{
		case 0:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		case 1:
			resource->genResourceInfo(0, 7, (rand() % 3) + 1, 0, 0, 0, 4);
			break;
		case 2:
			resource->genResourceInfo(0, 8, (rand() % 3) + 1, 4, 0, 0, 4);
			break;
		case 3:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;
		case 4:
			resource->genResourceInfo(0, 0, 0, 0, 0, 0, 0);
			break;

		default:
			break;
		}
		UE_LOG(LogTemp, Warning, TEXT("Case 7"));
		break;
	default:
		break;
	}
	return resource;
}
