// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BossAIController.generated.h"

/**
 * 
 */
UCLASS()
class AIPROGRAMMING_API ABossAIController : public AAIController
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, Category = "Defaults|AI")
	UBlackboardData*BlackboardAsset;
	
	UPROPERTY(EditDefaultsOnly)
	UBlackboardComponent*BlackboardComponent; 
	
	UPROPERTY(EditDefaultsOnly)
	UBehaviorTree*BehaviorTreeAsset;
	
	
	
	UFUNCTION()
	void UpdateChase(); 
	
	FTimerHandle ChaseTimer; 
	
protected:
virtual void OnPossess(APawn* InPawn) override; 
	
	
};
