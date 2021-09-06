// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "MyBlueprintFunctionLibrary.generated.h"


/**
 * 
 */
UCLASS()
class ZOOCHESS_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()public:
     
    UFUNCTION(BlueprintCallable, Category = "save")
        static bool FileSaveString(TArray<FString> SaveTextB, FString FileNameB);
 
    UFUNCTION(BlueprintPure, Category = "save")
        static bool FileLoadString(FString FileNameA, FString& SaveTextA);

    UFUNCTION(BluePrintCallable, Category="save")
        static bool SalvarArquivo(FString Texto, FString NomeArquivo);
};
