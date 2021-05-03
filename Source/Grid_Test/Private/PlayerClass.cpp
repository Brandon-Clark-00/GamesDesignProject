// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerClass.h"

//UFUNCTION(BlueprintCallable, Category = "CoreLogic")
UPlayerClass::UPlayerClass()
{

	setMoneySupply(0);
	setMoneyDemand(0);
	setEnergySupply(0);
	setEnergyDemand(0);
	setWaterSupply(0);
	setWaterDemand(0);
	setFoodSupply(0);
	setFoodDemand(0);

}

UPlayerClass::~UPlayerClass()
{
}

UTileInfo* UPlayerClass::findTile(int y, int x)
{
	if (playerTiles.Num()== 0)
	{
		return nullptr;
	}
	for (int i = 0; i < playerTiles.Num(); i++) {
		if (playerTiles[i]->validateGrid(y,x))
		{
			return playerTiles[i];
		}
	}
	return nullptr;
}

UTileInfo* UPlayerClass::findIndexTile(int input)
{
	return getPlayerTiles()[input];
}

UFUNCTION(BlueprintCallable, Category = "Player")
void UPlayerClass::genPlayerClass(int iID,float iMoneySupply, float iMoneyDemand, float iEnergySupply, float iEnergyDemand, float iWaterSupply, float iWaterDemand, float iFoodSupply, float ifoodDemand, TArray<FresourcesList> resourcesList, TArray<UTileInfo*> iPlayerTiles) {
	setPlayerID(iID);
	
	setMoneySupply(iMoneySupply);
	setMoneyDemand(iMoneyDemand);
	setEnergySupply(iEnergySupply);
	setEnergyDemand(iEnergyDemand);
	setWaterSupply(iWaterSupply);
	setWaterDemand(iWaterDemand);
	setFoodSupply(iFoodSupply);
	setFoodDemand(ifoodDemand);
	setResourcesList(resourcesList);
	setPlayerTiles(iPlayerTiles);
}


UFUNCTION(BlueprintCallable, Category = "FileHandling")
FString UPlayerClass::genPlayerDoc() {
	FString docString;	
	cout << "Entered Doc" << endl;

	docString.Append(FString::FromInt(getPlayerID()));
	docString.Append(",");
	cout << "finished pID" << endl;

	docString.Append(FString::SanitizeFloat(getMoneySupply()));
	docString.Append(",");
	docString.Append(FString::SanitizeFloat(getMoneyDemand()));
	docString.Append(",");
	cout << "finished money" << endl;

	docString.Append(FString::SanitizeFloat(getEnergySupply()));
	docString.Append(",");
	docString.Append(FString::SanitizeFloat(getEnergyDemand()));
	docString.Append(",");
	cout << "finished energy" << endl;

	docString.Append(FString::SanitizeFloat(getWaterSupply()));
	docString.Append(",");
	docString.Append(FString::SanitizeFloat(getWaterDemand()));
	docString.Append(",");
	cout << "finished Water" << endl;

	docString.Append(FString::SanitizeFloat(getFoodSupply()));
	docString.Append(",");
	docString.Append(FString::SanitizeFloat(getFoodDemand()));
	docString.Append(",");
	cout << "finished Food" << endl;


	// Resources
	if (resources.IsValidIndex(0))
	{
		for (int i = 0; i < resources.Num(); i++)
		{
			docString.Append(FString::FromInt(resources[i].ID));
			docString.Append("-");
			docString.Append(resources[i].name);
			docString.Append("-");
			docString.Append(FString::FromInt(resources[i].count));

			if (i != resources.Num()-1)
			{
				docString.Append("]");
			}
		}
	}
	else
	{
		docString.Append("null");
	}
	docString.Append(",");
	cout << "finished Resources" << endl;


	if (playerTiles.IsValidIndex(0))
	{
		for (int i = 0; i < playerTiles.Num(); i++)
		{
			docString.Append(FString::FromInt(playerTiles[i]->getID()));
			docString.Append("-");

			docString.Append(FString::FromInt(playerTiles[i]->getTileType()));
			docString.Append("-");

			docString.Append(playerTiles[i]->getTileName());
			docString.Append("-");

			// Grid pos
			for (int j = 0; j < 2; j++)
			{
				docString.Append(FString::FromInt(playerTiles[i]->getGridPos()[j]));
				
				if (j <1 )
				{
					docString.Append("_");
				}
			}
			docString.Append("-");

			docString.Append(FString::SanitizeFloat(playerTiles[i]->getEnergyProduction()));
			docString.Append("-"); 

			docString.Append(FString::SanitizeFloat(playerTiles[i]->getWaterProduction()));
			docString.Append("-"); 

			docString.Append(FString::SanitizeFloat(playerTiles[i]->getFoodProduction()));
			docString.Append("-");

			// Tile resource

			if (playerTiles[i]->getResource() != nullptr)
			{
				docString.Append(FString::FromInt(playerTiles[i]->getResource()->getID()));
				docString.Append("_");

				docString.Append(FString::FromInt(playerTiles[i]->getResource()->getResourceType()));
				docString.Append("_");

				docString.Append(playerTiles[i]->getResource()->getResourceName());
				docString.Append("_");

				docString.Append(FString::FromInt(playerTiles[i]->getResource()->getResourceCount()));
				docString.Append("_");

				docString.Append(FString::SanitizeFloat(playerTiles[i]->getResource()->getCurrencyValue()));
				docString.Append("_");

				docString.Append(FString::SanitizeFloat(playerTiles[i]->getResource()->getEnergyValue()));
				docString.Append("_");

				docString.Append(FString::SanitizeFloat(playerTiles[i]->getResource()->getWaterValue()));
				docString.Append("_");

				docString.Append(FString::SanitizeFloat(playerTiles[i]->getResource()->getFoodValue()));

			}
			else
			{
				docString.Append("null");
			}

			docString.Append("-");
			UE_LOG(LogTemp, Warning, TEXT("Got to here"));
			// Improvement info
			if (playerTiles[i]->getImprovementInfo() != nullptr)
			{
				docString.Append(FString::FromInt(playerTiles[i]->getImprovementInfo()->getImprovementID()));
				docString.Append("_");

				docString.Append(FString::FromInt(playerTiles[i]->getImprovementInfo()->getImprovementType()));
				docString.Append("_");

				docString.Append(playerTiles[i]->getImprovementInfo()->getImprovementName());
				docString.Append("_");

				docString.Append(FString::SanitizeFloat(playerTiles[i]->getImprovementInfo()->getCost()));
				docString.Append("_");

				docString.Append(FString::SanitizeFloat(playerTiles[i]->getImprovementInfo()->getRunningCost()));
				docString.Append("_");

				docString.Append(FString::SanitizeFloat(playerTiles[i]->getImprovementInfo()->getValueIncrease()));
				docString.Append("_");

			}
			else
			{
				docString.Append("null");
			}

			if (i != resources.Num() - 1)
			{
				docString.Append("]");
			}
		}
	}
	cout << "finished tiles" << endl;

	UFileHandling* temp = NewObject<UFileHandling>();
	temp->savetoFile(docString);


	return docString;
}


UFUNCTION(BlueprintCallable, Category = "FileHandling")
FString UPlayerClass::readPlayerDoc()
{
	FString inputText;

	FString file = FPaths::ProjectConfigDir();
	file.Append(TEXT("player.txt"));

	// We will use this FileManager to deal with the file.
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	// Always first check if the file that you want to manipulate exist.
	if (FileManager.FileExists(*file))
	{
		// We use the LoadFileToString to load the file into
		if (FFileHelper::LoadFileToString(inputText, *file, FFileHelper::EHashOptions::None))
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Text From File: %s"), *inputText);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Did not load text from file"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: ERROR: Can not read the file because it was not found."));
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Expected file location: %s"), *file);
	}

	UFileHandling* temp = NewObject<UFileHandling>();
	

	//genPlayerClass();

	TArray<FString> results= temp->split(inputText,',');
	genPlayerClass(FCString::Atoi(*results[0]), FCString::Atof(*results[1]), FCString::Atof(*results[2]), FCString::Atof(*results[3]), FCString::Atof(*results[4]), FCString::Atof(*results[5]), FCString::Atof(*results[6]), FCString::Atof(*results[7]), FCString::Atof(*results[8]),createResourcesList(results[9]),createPlayerTiles(results[10]));


	return inputText;
}

TArray<FresourcesList> UPlayerClass::createResourcesList(FString input)
{

	UFileHandling* temp = NewObject<UFileHandling>();
	TArray<FresourcesList> tempListArray;
	FresourcesList tempList;
	if (input == "null")
	{
		tempListArray.Add(tempList);
		return tempListArray;
	}
	TArray<FString> list= temp->split(input, ']');
	TArray<FString> subList;
	for (int i = 0; i < list.Num(); i++)
	{
		subList.Empty();
		subList = temp->split(list[i], '-');
		tempList.ID = FCString::Atoi(*subList[0]);
		tempList.name = subList[1];
		tempList.count = FCString::Atoi(*subList[2]);
		tempListArray.Add(tempList);
	}
	

	return tempListArray;
}

TArray<UTileInfo*> UPlayerClass::createPlayerTiles(FString input)
{
	UFileHandling* fileHandler = NewObject<UFileHandling>();
	TArray<UTileInfo*> output;
	UTileInfo* temp = NewObject<UTileInfo>();

	if (input == "null")
	{
		output.Add(temp);
		return output;
	}

	TArray<FString> splitList = fileHandler->split(input, ']');
	TArray<FString> subSplitList;
	for (int i = 0; i < splitList.Num(); i++)
	{
		subSplitList.Empty();
		subSplitList = fileHandler->split(splitList[i], '-');
		TArray<FString> sGrid = fileHandler->split(subSplitList[3], '_');
		TArray<int> grid;
		for (int j = 0; j < sGrid.Num(); j++) {
			grid.Add(FCString::Atoi(*sGrid[j]));
		}
		UImprovementInfo* tempImprovement = NewObject<UImprovementInfo>();
		if (subSplitList[6] != "null")
		{
			TArray<FString> improvementString = fileHandler->split(subSplitList[7], '_');
			tempImprovement->genImprovementInfo(FCString::Atoi(*improvementString[0]), FCString::Atoi(*improvementString[1]), improvementString[2], FCString::Atof(*improvementString[3]), FCString::Atof(*improvementString[4]), FCString::Atof(*improvementString[5]));
			
		}

		temp->genTileInfo(FCString::Atoi(*subSplitList[0]), FCString::Atoi(*subSplitList[1]), grid, FCString::Atof(*subSplitList[4]), FCString::Atof(*subSplitList[5]), FCString::Atof(*subSplitList[6]),tempImprovement);

		UResourceInfo* tempResource = NewObject<UResourceInfo>();
		TArray<FString> resourceSplit = fileHandler->split(subSplitList[7], '_');
		tempResource->genResourceInfo(FCString::Atoi(*resourceSplit[0]), FCString::Atoi(*resourceSplit[1]), FCString::Atoi(*resourceSplit[3]), FCString::Atoi(*resourceSplit[4]), FCString::Atoi(*resourceSplit[5]), FCString::Atoi(*resourceSplit[6]), FCString::Atoi(*resourceSplit[7]));





		temp->setTileResource(tempResource);



		UE_LOG(LogTemp, Warning, TEXT("Success"));
		output.Add(temp);
		temp = NewObject<UTileInfo>();
	}
	return output;
}
;

