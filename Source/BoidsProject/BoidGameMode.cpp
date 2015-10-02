// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidsProject.h"
#include "BoidGameMode.h"
#include "Boid.h"

ABoidGameMode::ABoidGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void ABoidGameMode::StartPlay()
{
	Super::StartPlay();

	StartMatch();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HELLO WORLD"));
	}
}


