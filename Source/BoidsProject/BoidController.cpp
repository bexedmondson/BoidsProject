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

	FVector boidLocation = FVector(180, 30, 80);
	FRotator boidRotation = FRotator(0.0f);

	for (int i = 0; i < numOfBoids; i++) {
		boidLocation += FVector(0, 10, 0);

		ABoid* boid = GetWorld()->SpawnActor<ABoid>(ABoid::StaticClass(), boidLocation, boidRotation);

		boidArray[i] = boid;
	}
	
}

