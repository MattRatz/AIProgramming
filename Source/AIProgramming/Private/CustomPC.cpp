// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPC.h"

void ACustomPC::BeginPlay()
{
	
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay running from c++"));
	UE_LOG(LogTemp, Warning, TEXT("Controller class is %s"), *GetClass()->GetName()); 
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay running from c++"));
	UE_LOG(LogTemp, Warning, TEXT("Controller class is %s"), *GetClass()->GetName()); 
	
	BP_OnBeginPlay();
	
}

