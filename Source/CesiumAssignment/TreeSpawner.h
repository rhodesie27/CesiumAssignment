/* Created by Austin Rhodes for Cesium Candidate Project -- 10/21/2022
*/


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TreeSpawner.generated.h"
#include <random>
#include <vector>

UCLASS()
class CESIUMASSIGNMENT_API ATreeSpawner : public AActor
{
	GENERATED_BODY()
	
private:
	// Private Properties


	/* The included trees.h file for the project would not import properly and would not be found for includes so I added the info as components of the spawner class to solve the issue
	* of improper imports
	*/
	struct Tree {
		// Values are in standard Unreal Engine coordinates (centimeters)
		float positionX;
		float positionY;
		float positionZ;
		float height;
		float canopyRadius;
	};

	std::vector<Tree> treeGroup;

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
	inline void createTrees(size_t numberToCreate) {
		std::default_random_engine generator;
		std::uniform_real_distribution<float> positionDistribution(0.0, 100000.0);
		std::uniform_real_distribution<float> heightDistribution(2.0, 10000.0);
		std::uniform_real_distribution<float> canopyRadiusDistribution(1.0, 5000.0);

		std::vector<Tree> result(numberToCreate);

		for (size_t i = 0; i < numberToCreate; ++i) {
			result[i] = Tree{
				positionDistribution(generator),
				positionDistribution(generator),
				positionDistribution(generator),
				heightDistribution(generator),
				canopyRadiusDistribution(generator)
			};
		}
		 
		treeGroup = result;
	};

	UFUNCTION(BlueprintCallable, CallInEditor)
	virtual void spawnTrees();


};
