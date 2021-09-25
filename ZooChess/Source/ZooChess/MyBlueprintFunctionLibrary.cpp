// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueprintFunctionLibrary.h"
#include "ZooChess.h"
#include <algorithm>
#include <string>
#include <type_traits>

 bool UMyBlueprintFunctionLibrary::FileSaveString(TArray<FString> SaveTextB, FString FileNameB)
 {
    /*FString FinalString = "{";

    FinalString += TEXT("\"Turno\":\"%d\"", Turno);

    FinalString += "\"Movimentos\":\"[";
    
    for(FString& Each: SaveTextB)
    {
        FinalString += Each;        
    }

    FinalString += "]}";

    return FFileHelper::SaveStringToFile(FinalString, *(FPaths::ProjectDir() + FileNameB));

    for(FString& Each: SaveTextB)
    {
        FinalString += Each;
        FinalString += LINE_TERMINATOR;
    }
    
    return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::ProjectDir() + FileNameB));*/

    FString FinalString = "";

    for(FString& Each: SaveTextB)
    {
        FinalString += Each;
        FinalString += LINE_TERMINATOR;
    }

    return FFileHelper::SaveStringToFile(FinalString, *(FPaths::ProjectDir() + FileNameB));
 }
 
 bool UMyBlueprintFunctionLibrary::FileLoadString(FString FileNameA, FString& SaveTextA)
 {
     return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::ProjectDir() + FileNameA));
 }

 bool UMyBlueprintFunctionLibrary::SalvarArquivo(FString Texto, FString NomeArquivo)
 {
    /*FString FinalString = "[";
    
    for(FString& Each: Texto)
    {
        FinalString += Each;        
    }

    FinalString += "]";    

    std::string s(TCHAR_TO_UTF8(*FinalString));;
    std::replace(s.begin(), s.end(), "},]", "}]"); // replace all 'x' to 'y'*/
    

    /*FString FinalString = "{";

    FinalString += "\"Turno\":\"" + FString::FromInt(Turno) + "\"," ;

    FinalString += "\"Movimentos\":[";
    
    for(FString& Each: Texto)
    {
        FinalString += "\"" + Each + "\",";        
    }

    FinalString += "\"\"]}";*/

    return FFileHelper::SaveStringToFile(Texto, *(FPaths::ProjectDir() + NomeArquivo));
 }

