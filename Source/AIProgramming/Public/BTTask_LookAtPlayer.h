// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_LookAtPlayer.generated.h"

/**
 * 
 */
UCLASS()
class AIPROGRAMMING_API UBTTask_LookAtPlayer : public UBTTaskNode
{
	GENERATED_BODY()
	UBTTask_LookAtPlayer(); 
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override; 
	
};
