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

	//to be removed
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 6.f, FColor::Blue, TEXT("We are using BoidController.cpp!"));
	}

	World = GetWorld();

	ABoid* boid = GetWorld()->SpawnActor<ABoid>(ABoid::StaticClass(), FVector(180,30,80), FRotator(0.0f));

	
}

