// Fill out your copyright notice in the Description page of Project Settings.


#include "BossEnemy.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.h"


// Sets default values
ABossEnemy::ABossEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception")); 
	AIControllerClass = ABossAIController::StaticClass(); 
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned; 
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("CustomHealthComponent")); 


}

// Called when the game starts or when spawned
void ABossEnemy::BeginPlay()
{
	Super::BeginPlay();
	//FVector CurrentLocation = GetActorLocation(); 
	OnPhaseChanged(1);
	//HealthComponent->TakeDamage(20);
	//FindPathToTarget(GetActorLocation() + FVector(500.f,0.f,0.f));
	BossInitialized(HealthComponent);
	
	
}
void ABossEnemy::DrawSphere()
{
	DrawDebugSphere(GetWorld(), GetActorLocation(), DetectionRadius, 10, FColor::Magenta, true, 5.0f, 0, 1.0f); 
}

// Called every frame
void ABossEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ABossEnemy::FindPathToTarget(FVector TargetLocation)
{
	//Get UE5's nav system - it manages the nav mesh
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld()); 

	//Always Null check engine system before using them 
	if (!NavSystem)
	{
		return; 
	}

	//This is the A* call
	//UE5 runs A* through the nav mesh, and returns the path                       Start Postiion      End-goal Position
	UNavigationPath* Path = NavSystem->FindPathToLocationSynchronously(GetWorld(), GetActorLocation(), TargetLocation); 

	//Path->PathPoints is a TArray <FVector> of waypoints. 

	//ALWAYS check IsValid() before using PathPoints
	//Path will be null or invalid if either location is off the NavMesh
	if (Path && Path->IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Path Found! %d waypoints."), Path->PathPoints.Num());

		for (int32 i = 0; i < Path->PathPoints.Num(); i++)
		{
			DrawDebugSphere(GetWorld(), Path->PathPoints[i], 20.f, 8, FColor::MakeRandomColor(), false, 5.f);

			//Draw a line from this waypoint to the next
			//Stop one before the end, Last point has no "next waypoint" 
			if (i < Path->PathPoints.Num() - 1)
			{
				DrawDebugLine(GetWorld(), Path->PathPoints[i], Path->PathPoints[i + 1], FColor::MakeRandomColor(), false, 5.f, 0, 2.f); 
			}
		}
	}
}
