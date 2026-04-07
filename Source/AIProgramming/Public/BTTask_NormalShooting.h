// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_NormalShooting.generated.h"

/**
 * 
 */
UCLASS()
class AIPROGRAMMING_API UBTTask_NormalShooting : public UBTTaskNode
{
	GENERATED_BODY()
	UBTTask_NormalShooting(); 
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override; 
	
	UPROPERTY(EditAnywhere, Category = "Defaults|Attacks")
	TSubclassOf<AActor> EnemyBullet;
	
	UBehaviorTreeComponent* CachedOwnerComp;
	FTimerHandle SpawnTimer; 
	int32 RandomNumberOfShots = FMath::RandRange(1,7); 
	
	UFUNCTION()
	void SpawnBullet(); 
	

};
