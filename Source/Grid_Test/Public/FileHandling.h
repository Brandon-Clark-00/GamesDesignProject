// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <typeinfo>
#include <string>
#include <fstream>
#include <sstream>
#include "Misc/FileHelper.h"
#include "UObject/NoExportTypes.h"
#include "FileHandling.generated.h"
using namespace std;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GRID_TEST_API UFileHandling : public UObject
{
	GENERATED_BODY()
public:

	int savetoFile(FString textInput, FString fileName);

	UFUNCTION(BlueprintCallable, Category = "FileHandling")
	int loadfromSave();

		TArray<FString> split(FString input, char delim);


};

