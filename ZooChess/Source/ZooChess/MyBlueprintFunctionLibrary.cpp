// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueprintFunctionLibrary.h"
#include "GenericPlatform/GenericPlatformProcess.h"
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
 
 
 bool UMyBlueprintFunctionLibrary::ExecutaStockFish(FString Texto2)
 {	 
	//if(GEngine)
      //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
  
  
	//FPlatformProcess::CreateProc(TEXT("C:\\Users\\User\\Desktop\\Galaxian\\Chess\\Unreal\\ZooChess\\Python\\chess.exe"), nullptr, true, false, false, nullptr, 0, nullptr, nullptr);
	//FPlatformProcess::CreateProc(TEXT("C:\\Users\\User\\Desktop\\Galaxian\\Chess\\Unreal\\ZooChess\\Python\\chess.exe"), nullptr, false, false, false, nullptr, 0, nullptr, nullptr);
	//return true;
	 //FPlatformProcess::ExecProcess(TEXT("C:\\Users\\User\\Desktop\\Galaxian\\Chess\\Unreal\\ZooChess\\Python\\chess.exe"), nullptr, false, false, false);
	 
	 
		
	return FPlatformProcess::ExecProcess(TEXT("C:\\Users\\User\\Desktop\\Galaxian\\Chess\\Unreal\\ZooChess\\Python\\chess.exe"), nullptr, false, false, false); 
	//return true	 ;
     
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

