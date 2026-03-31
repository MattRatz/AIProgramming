// Fill out your copyright notice in the Description page of Project Settings.


#include "BossAIController.h"
#include "Kismet/GameplayStatics.h"

void ABossAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	//IMPORTANT: Do NOT call MoveToLocation directly here. 
	//OnPossess fires before the character has fully settled on to the NavMesh
	//A move request issued this early is silently discarded(Not ran at all)
	//The fix is delay the command by one frame using - SetTimerForNextTick
	GetWorld()->GetTimerManager().SetTimerForNextTick([this, InPawn]()
	{
		AActor* PlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0); 
		if (BlackboardAsset)
		{
			UseBlackboard(BlackboardAsset, BlackboardComponent); 
			BlackboardComponent->SetValueAsObject(TEXT("TargetActor"), UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
			BlackboardComponent->SetValueAsInt(TEXT("CurrentPhase"), 1); 
		}
		if (BehaviorTreeAsset)
		{
			RunBehaviorTree(BehaviorTreeAsset);
		}
	
	
			UE_LOG(LogTemp, Log, TEXT("BossAIController: Move requested"));
	}); 
}

void ABossAIController::UpdateChase()
{

}
