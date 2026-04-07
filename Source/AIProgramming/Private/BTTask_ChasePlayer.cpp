// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ChasePlayer.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ChasePlayer::UBTTask_ChasePlayer()
{
	NodeName = TEXT("ChasePlayer");
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_ChasePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController*Controller = OwnerComp.GetAIOwner(); 
	UBehaviorTreeComponent* CachedOwnerComp = &OwnerComp; 
	
	if (!Controller)
	{
		return EBTNodeResult::Failed;
	}
	APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(Pawn->GetWorld());
	if (!NavSystem || !Pawn) 
	{
		return EBTNodeResult::Failed;
	}

	
	FVector BossLocation = Pawn->GetActorLocation();
	float Radius = 1000.f; 
	
	FNavLocation RandomLocation; 
	
	NavSystem->GetRandomReachablePointInRadius(BossLocation, Radius, RandomLocation); 
	Controller->MoveToLocation(RandomLocation.Location);


	return EBTNodeResult::Succeeded; 
	
	//AActor* Target = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TEXT("TargetActor"))); 
	//if (!Target)
	//{
		//return EBTNodeResult::Failed; 
	//}
	//Controller->MoveToActor(Target, 200.f); 
	//return EBTNodeResult::Succeeded; 

	

}

