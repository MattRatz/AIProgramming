// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"
#include "BossAIController.h" 
#include "HealthComponent.h" 
#include "NavigationSystem.h" 
#include "NavigationPath.h"
#include "BossEnemy.generated.h"


UCLASS()
class AIPROGRAMMING_API ABossEnemy : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABossEnemy();

	UPROPERTY(EditAnywhere, Category = "Defaults|AI")
	float DetectionRadius; 
	UPROPERTY(EditAnywhere, Category = "Defaults|Attacks")
	float Damage; 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Defaults|Health")
	UHealthComponent* HealthComponent; 
	UPROPERTY(EditAnywhere, Category = "Defaults|Attacks")
	UActorComponent*AttackManager;
	UPROPERTY(EditAnywhere, Category = "Defaults|Attacks")
	TSubclassOf<AActor> BeamShot; 
	



	UFUNCTION(BlueprintImplementableEvent, Category = "Boss Phase")
	void OnPhaseChanged(int32 NewPhase);
	UFUNCTION(BlueprintCallable, Category = "Boss Phase")
	void DrawSphere(); 
	UFUNCTION(BlueprintCallable, Category = "Boss|AI")
	void FindPathToTarget(FVector TargetLocation);




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
