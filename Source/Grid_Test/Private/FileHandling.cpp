// Fill out your copyright notice in the Description page of Project Settings.


#include "FileHandling.h"

//UFUNCTION(BlueprintCallable, Category = "FileHandling")
 int UFileHandling::savetoFile(FString textInput, FString fileName)
{

     FString file = FPaths::ProjectConfigDir();
     file.Append(fileName);
     file.Append(".txt");

     IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();




     if (FileManager.FileExists(*file))
     {
         if (FFileHelper::SaveStringToFile(textInput, *file))
         {
             UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Successfuly Written: \"%s\" to the text file"), *textInput);
         }
         else
         {
             UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Failed to write FString to file."), *textInput);
         }
     }
     else
     {
         UE_LOG(LogTemp, Warning, TEXT("FileManipulation: ERROR: Can not read the file because it was not found."));
         UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Expected file location: %s"), *file);
     }
   

    return 1;
}

// Method to load a celluar automaton from a file
UFUNCTION(BlueprintCallable, Category = "FileHandling")
int UFileHandling::loadfromSave()
{
    //Opening up file stream
    ifstream FyallStream;

    string line;
    int height, width;

    //Opening file using filename
    FyallStream.open("player.txt");

    //Returns the first line of file to the line variable
    getline(FyallStream, line);

    //Converts and copies the value of line to height variable
    height = stoi(line);

    //Returns the next line of file to line variable
    getline(FyallStream, line);

    //Converts and copies the value of line to weight variable
    width = stoi(line);

    //Outputs height and width to console
    cout << height << " " << width << endl;

    if (FyallStream.is_open())
    {

        //Loops until end of file
        while (getline(FyallStream, line))
        {
            //Prints current line to console
            cout << line << endl;
        }

        //Closes fyallStream
        FyallStream.close();
    }
    else
    {
        //Closes fyallStream
        FyallStream.close();
    }

    cout << endl;
    return 1;
}

TArray<FString> UFileHandling::split(FString input, char delim)
{
    TArray<FString> output;
    stringstream ss(std::string(TCHAR_TO_UTF8(*input)));
    string item;

    while (getline(ss, item, delim))
    {
        output.Add(FString(item.c_str()));
    }

    return output;
}
