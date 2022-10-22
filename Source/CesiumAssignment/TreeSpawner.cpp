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

FTree ATreeSpawner::createTree()
{
	// Creates the structs based on 'external data'

	std::default_random_engine generator;
	std::uniform_real_distribution<float> positionDistribution(0.0, 100000.0);
	std::uniform_real_distribution<float> heightDistribution(2.0, 10000.0);
	std::uniform_real_distribution<float> canopyRadiusDistribution(1.0, 5000.0);


	FTree createdTree{
			positionDistribution(generator),
			positionDistribution(generator),
			positionDistribution(generator),
			heightDistribution(generator),
			canopyRadiusDistribution(generator)
	};
	

	return createdTree;
}

void ATreeSpawner::spawnTrees()
{
	// Clean up any old spawned components before spawning new ones
	TArray<UActorComponent*> currentICs = this->GetInstanceComponents();
	for (UActorComponent* ic : currentICs)
		ic->DestroyComponent();

	// Initialize array of tree structs
	TArray<FTree> trees;
	
	// Create each struct based on 'external' data
	for (int32 i = 0; i < treesToCreate; i++)
	{
		// Creates Tree Structs
		FTree newTree = createTree();

		// Adds Structs to a Templated Array
		trees.Add(newTree);
		
		// Creates Transform Elements to place Tree and scale it as necessary
		FRotator rotation(0, 0, 0);
		FVector location(newTree.positionX, newTree.positionY, newTree.positionZ);
		FVector scale(newTree.canopyRadius, newTree.canopyRadius, newTree.height);

		FTransform treeTransform(rotation, location, scale);

		// Creates the static mesh component in instances for the Tree
		UInstancedStaticMeshComponent* ISMComp = NewObject<UInstancedStaticMeshComponent>(this);
		ISMComp->RegisterComponent();
		ISMComp->SetStaticMesh(treeMesh);
		ISMComp->SetFlags(RF_Transactional);
		this->AddInstanceComponent(ISMComp);
		ISMComp->AddInstance(treeTransform);
	};
}
