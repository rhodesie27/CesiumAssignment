/* Created by Austin Rhodes for Cesium Candidate Project -- 10/21/2022
*/


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <random>
#include <vector>
#include "Components/InstancedStaticMeshComponent.h"
#include "TreeSpawner.generated.h"




/* The included trees.h file for the project would not import properly and would not be found for includes so I added the info as components of the spawner class to solve the issue
* of improper imports
*/
USTRUCT(BlueprintType)
struct FTree {

	GENERATED_BODY()

	// Values are in standard Unreal Engine coordinates (centimeters)

	float positionX;
	float positionY;
	float positionZ;
	float height;
	float canopyRadius;

	UPROPERTY()
	UObject* SafeObjectPointer;
};

UCLASS()
class CESIUMASSIGNMENT_API ATreeSpawner : public AActor
{
	GENERATED_BODY()

	
	
private:

	bool bInitialSpawnSet;
	

public:	
	// Sets default values for this actor's properties
	ATreeSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Public Variables

	// This mesh is to represent the trees spawned throughout the level
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* treeMesh;

	// This variable represents the number of trees to be randomly placed through the level
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 treesToCreate;

	// This variable represents whether or not we should spawn trees as a default in the level simulating external data being loaded into the createTrees function
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsShippingBuild;

	// Public Functions

	UFUNCTION(BlueprintCallable)
	FTree createTree();

	UFUNCTION(BlueprintCallable, CallInEditor)
	virtual void spawnTrees();

	UFUNCTION(BlueprintCallable)
	virtual void spawnSingleTree(FTransform treeData);

};
