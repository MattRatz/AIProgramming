// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomPC.generated.h"

/**
 * 
 */
UCLASS()
class AIPROGRAMMING_API ACustomPC : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override; 
	
	UFUNCTION(BlueprintImplementableEvent, Category = "GameSetup")
	void BP_OnBeginPlay();
	
};
