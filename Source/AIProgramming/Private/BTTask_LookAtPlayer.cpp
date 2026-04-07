// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_LookAtPlayer.h"

UBTTask_LookAtPlayer::UBTTask_LookAtPlayer()
{
	NodeName = "LookAtPlayer"; 
}

EBTNodeResult::Type UBTTask_LookAtPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController*Controller = OwnerComp.GetAIOwner();  
	if (!Controller)
	{
		return EBTNodeResult::Failed; 
	}
	AActor* PlayerActor = Cast<AActor>(Controller->GetBlackboardComponent()->GetValueAsObject(TEXT("TargetActor"))); 
	if (!PlayerActor)
	{
		return EBTNodeResult::Failed;
	}
	Controller->SetFocus(PlayerActor); 
	return EBTNodeResult::Succeeded;

	
}