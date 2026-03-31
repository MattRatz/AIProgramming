// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BossBeamShot.h"
#include "BTTask_ShootPlayer.generated.h"

/**
 * 
 */
UCLASS()
class AIPROGRAMMING_API UBTTask_ShootPlayer : public UBTTaskNode
{
	GENERATED_BODY()
	UBTTask_ShootPlayer(); 
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override; 
	
	UPROPERTY(EditAnywhere, Category = "Defaults|Attack") 
	TSubclassOf<ABossBeamShot> BeamClass; 
	
	UPROPERTY()
	ABossBeamShot* SpawnedBeam; 
	
	
};
