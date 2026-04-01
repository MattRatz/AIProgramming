// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ShootPlayer.h"
#include "AIController.h"
#include "SNegativeActionButton.h"
#include "AIProgramming/TestBossEnemy.h"
#include "GameFramework/Character.h" 
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ShootPlayer::UBTTask_ShootPlayer()
{
	NodeName = "ShootPlayer"; 
}

EBTNodeResult::Type UBTTask_ShootPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UWorld* World = OwnerComp.GetWorld(); 
	APawn* EnemyBoss = OwnerComp.GetAIOwner()->GetPawn();
	ABossEnemy* Boss = Cast<ABossEnemy>(EnemyBoss);
	
	AAIController*Controller = OwnerComp.GetAIOwner();
	if (!Controller)
	{
		return EBTNodeResult::Failed;
	}
	
	
	AActor* Target = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TEXT("TargetActor"))); 
	if (!Target)
	{
		return EBTNodeResult::Failed;
	}

		FVector BossForwardVector = Boss->GetActorForwardVector(); 
		FVector BossLocation = Boss->GetActorLocation(); 
		FVector SpawnLocationFromBoss = BossLocation + (BossForwardVector * 200.f); 
	
		FVector PlayerLocation = Target->GetActorLocation(); 
		FVector PlayerVelocity = Target->GetVelocity(); 
		
		float ShotChargeTime = 1.5f; 
		FVector PredictedLocation = PlayerLocation + PlayerVelocity * ShotChargeTime; 
		FVector ShotDirection = (PredictedLocation - BossLocation).GetSafeNormal(); 
		FRotator SpawnRotation = (PredictedLocation - BossLocation).Rotation(); 
		UE_LOG(LogTemp, Log, TEXT("Current boss location %s"), *BossLocation.ToString()); 
		
		if (Boss->BeamShot)
		{
			FActorSpawnParameters Params; 
			Params.Owner = EnemyBoss; 
			Params.Instigator = EnemyBoss; 
			
			SpawnedBeam = World->SpawnActor<ABossBeamShot>(Boss->BeamShot, BossLocation, SpawnRotation, Params); 
			UE_LOG(LogTemp, Log, TEXT("Tryna shoot"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Beam Class Invalid"));
		}
		if (SpawnedBeam)
		{
			SpawnedBeam->InitializeBeam(BossLocation, PredictedLocation); 
			
		}
		return EBTNodeResult::Succeeded; 
		
	

	


	
	
	
}

