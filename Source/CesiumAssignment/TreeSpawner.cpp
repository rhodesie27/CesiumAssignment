// Fill out your copyright notice in the Description page of Project Settings.


#include "TreeSpawner.h"

// Sets default values
ATreeSpawner::ATreeSpawner()
{
 	// Actor can be called every frame on the tick, but in this case, we do not need a tick event, so this is disabled.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATreeSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATreeSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

