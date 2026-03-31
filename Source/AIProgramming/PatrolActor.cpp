// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolActor.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APatrolActor::APatrolActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh); 
	//First create mesh for actor
	//after mesh created, assign mesh as root component
}

void APatrolActor::StartPatrol()
{
	UE_LOG(LogTemp, Log, TEXT("%s started patrolling at speed %f"), *GetName(), PatrolSpeed); 
}

// Called when the game starts or when spawned
void APatrolActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APatrolActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

