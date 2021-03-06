// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidsProject.h"
#include "BoidGameMode.h"
#include "BoidController.h"
#include "Boid.h"

ABoidGameMode::ABoidGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void ABoidGameMode::StartPlay()
{
	Super::StartPlay();

	StartMatch();

	ABoidController* boidController = GetWorld()->SpawnActor<ABoidController>(ABoidController::StaticClass());

}


