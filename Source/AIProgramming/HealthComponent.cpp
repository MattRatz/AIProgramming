// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay(); 
	if (CurrentHealth != MaxHealth)
	{
		CurrentHealth = MaxHealth; 
		UE_LOG(LogTemp, Warning, TEXT("CurrentHealth is %i"), CurrentHealth);
		UE_LOG(LogTemp, Warning, TEXT("MaxHealth is %i"), MaxHealth);
	}
}

// Called when the game startsPlea

void UHealthComponent::TakeDamage(int32 DamageIncoming)
{
	CurrentHealth -= DamageIncoming;
	if (CurrentHealth <= 0)
	{
		OnDeath(); 
	}
	UE_LOG(LogTemp, Log, TEXT("Boss health is %i"), CurrentHealth);
	OnHealthUpdated.Broadcast(CurrentHealth, this);
}

void UHealthComponent::GainHealth(int32 HealthIncoming)
{
	CurrentHealth += HealthIncoming;
	if (CurrentHealth > MaxHealth)
	{
		int32 OverHealHealth = MaxHealth - CurrentHealth; 
		CurrentHealth -= OverHealHealth; 
	}
	// I am passing through HealthIncoming here for an edge case in my damage indicator WBP
	OnHealthUpdated.Broadcast(HealthIncoming, this);
}

void UHealthComponent::OnDeath()
{
	OnHealthUpdated.Broadcast(CurrentHealth, this);
	OnCharacterDeath.Broadcast(); 
	IsDead = true; 
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

