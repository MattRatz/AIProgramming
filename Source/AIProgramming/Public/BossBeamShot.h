// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BossBeamShot.generated.h"

UCLASS()
class AIPROGRAMMING_API ABossBeamShot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABossBeamShot();
	
	UFUNCTION(BlueprintImplementableEvent)
	void InitializeBeam(FVector StartLocation, FVector EndLocation);
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
