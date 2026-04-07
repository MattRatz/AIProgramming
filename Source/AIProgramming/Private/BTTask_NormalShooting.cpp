// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_NormalShooting.h"

UBTTask_NormalShooting::UBTTask_NormalShooting()
{
	NodeName = "NormalShooting"; 
	bCreateNodeInstance = true; 
}

EBTNodeResult::Type UBTTask_NormalShooting::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	CachedOwnerComp = &OwnerComp; 
	AAIController* Controller = OwnerComp.GetAIOwner();
	UWorld* World = OwnerComp.GetWorld(); 

	if (!Controller)
	{
		UE_LOG(LogTemp, Warning, TEXT("No controller")); 
		return EBTNodeResult::Failed;
	}
	AActor* TargetPlayer = Cast<AActor>(Controller->GetBlackboardComponent()->GetValueAsObject(TEXT("TargetActor")));
	if (!TargetPlayer)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Actor")); 
		return EBTNodeResult::Failed;
	}
	APawn* Boss = Controller->GetPawn();
	FVector BossForwardVector = Boss->GetActorForwardVector(); 
	FVector BossLocation = Boss->GetActorLocation(); 
	FVector SpawnLocationFromBoss = BossLocation + (BossForwardVector * 200.f); 
	
	FVector TargetLocation = TargetPlayer->GetActorLocation();
	
	FVector ShotDirection = (TargetLocation - BossLocation).GetSafeNormal(); 
	//FRotator SpawnRotation = (TargetLocation - BossLocation).Rotation(); 
	FRotator SpawnRotation = UKismetMathLibrary::FindLookAtRotation(BossLocation, TargetLocation); 
	
	if (!EnemyBullet)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Bullet")); 
		return EBTNodeResult::Failed; 
	}
	RandomNumberOfShots = FMath::RandRange(1,7); 

	
	
	World->GetTimerManager().SetTimer(SpawnTimer, this, &UBTTask_NormalShooting::SpawnBullet, .5f, true); 
	
	return EBTNodeResult::InProgress;
	
}
void UBTTask_NormalShooting::SpawnBullet()
{
	UWorld* World = GetWorld(); 
	AAIController *Controller = CachedOwnerComp->GetAIOwner(); 
	if (!Controller)
	{
		FinishLatentTask(*CachedOwnerComp, EBTNodeResult::Failed);
	}
	APawn* Boss = Controller->GetPawn();
	if (!Boss)
	{
		FinishLatentTask(*CachedOwnerComp, EBTNodeResult::Failed);
	}
	if (!World)
	{
		FinishLatentTask(*CachedOwnerComp, EBTNodeResult::Failed);
	}
	
	AActor* TargetPlayer = Cast<AActor>(Controller->GetBlackboardComponent()->GetValueAsObject(TEXT("TargetActor")));
	
	if (!TargetPlayer)
	{
		FinishLatentTask(*CachedOwnerComp, EBTNodeResult::Failed);
	}
	
	
	FVector TargetLocation = TargetPlayer->GetActorLocation();
	FVector BossLocation = Boss->GetActorLocation(); 
	FRotator SpawnRotation = UKismetMathLibrary::FindLookAtRotation(BossLocation, TargetLocation); 
	float BulletSpread = 5.0f; 
	float RandomPitch = FMath::RandRange(-BulletSpread, BulletSpread);
	float RandomYaw = FMath::RandRange(-BulletSpread, BulletSpread);
	
	FRotator FinalRotation = SpawnRotation;
	FinalRotation.Yaw += RandomPitch;
	FinalRotation.Pitch += RandomPitch;
	
	RandomNumberOfShots--; 
	
	FActorSpawnParameters Params; 
	Params.Owner = Boss; 
	Params.Instigator = Boss; 
	
	

	
	AActor *SpawnedBullet = World->SpawnActor<AActor>(EnemyBullet, BossLocation, FinalRotation, Params);
	UE_LOG(LogTemp, Warning, TEXT("Tryna Spawn")); 
	if (RandomNumberOfShots <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimer); 
		
		FinishLatentTask(*CachedOwnerComp, EBTNodeResult::Succeeded);
	}
	UE_LOG(LogTemp, Warning, TEXT("Shots remaining: %d"), RandomNumberOfShots);

}
