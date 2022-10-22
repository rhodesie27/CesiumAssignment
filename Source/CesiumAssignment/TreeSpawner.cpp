/* Created by Austin Rhodes for Cesium Candidate Project -- 10/21/2022
*/

#include "TreeSpawner.h"

// Sets default values
ATreeSpawner::ATreeSpawner()
{
 	// Actor can be called every frame on the tick, but in this case, we do not need a tick event, so this is disabled.
	PrimaryActorTick.bCanEverTick = false;

	// Set our default values for basic testing, assuming this is a development build and not a simulated or shipping build
	bIsShippingBuild = false;
	treesToCreate = 10;

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

void ATreeSpawner::createTrees(int32 numberToCreate)
{

}

void ATreeSpawner::spawnTrees()
{
}
