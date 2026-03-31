// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolActor.generated.h"

UCLASS()
class AIPROGRAMMING_API APatrolActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UPROPERTY(EditAnywhere, Category = "Patrol")
	float PatrolSpeed = 300;
	UPROPERTY(EditAnywhere, Category = "Patrol")
	float DetectionRange = 250; 
	UPROPERTY(EditAnywhere, Category = "Patrol")
	bool isAgressive;
	UPROPERTY(EditAnywhere, Category = "Patrol")
	TArray<FVector> WaypointArray; 
	
	UFUNCTION(BlueprintCallable, Category = "Patrol")
	void StartPatrol(); 
	APatrolActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
