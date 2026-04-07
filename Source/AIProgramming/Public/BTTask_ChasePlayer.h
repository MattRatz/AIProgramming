// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "AIController.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_ChasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class AIPROGRAMMING_API UBTTask_ChasePlayer : public UBTTaskNode
{
	GENERATED_BODY()
	UBTTask_ChasePlayer(); 
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override; 
	

};
