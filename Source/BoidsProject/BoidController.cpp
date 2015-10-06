// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidsProject.h"
#include "BoidController.h"
#include "Boid.h"

ABoidController::ABoidController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void ABoidController::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();

	numOfBoids = 10;
	boidArray[numOfBoids] = { };

	GenerateBoids();
	
}


// Called every frame
void ABoidController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ABoidController::GenerateBoids() {
	//box where boids will be spawned
	FVector spawnBoxMin = FVector(0, 50, 20);
	FVector spawnBoxMax = FVector(-120, -50, 200);
	FBox spawnBox = FBox(spawnBoxMin, spawnBoxMax);

	FVector boidLocation = FVector();
	FRotator boidRotation = FRotator();

	for (int i = 0; i < numOfBoids; i++) {
		//randomise spawn point and rotation
		boidLocation = FMath::RandPointInBox(spawnBox);
		boidRotation = FRotator(FMath::RandRange(-90, 90), FMath::RandRange(-180, 180), FMath::RandRange(-180, 180));

		//spawn boid
		ABoid* boid = GetWorld()->SpawnActor<ABoid>(ABoid::StaticClass(), boidLocation, boidRotation);

		//add boid to array for boid algorithm calculations
		boidArray[i] = boid;
	}
}

