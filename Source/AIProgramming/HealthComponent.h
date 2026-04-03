// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthUpdated, int32, NewHealth, UHealthComponent*, OwnerComponentToUpdate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AIPROGRAMMING_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	int32 MaxHealth; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	int32 CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	bool IsDead = false; 
	UPROPERTY(BlueprintAssignable, Category = "Health Functions")
	FOnHealthUpdated OnHealthUpdated; 

	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void TakeDamage(int32 DamageIncoming); 
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void GainHealth(int32 HealthIncoming); 
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void OnDeath();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
