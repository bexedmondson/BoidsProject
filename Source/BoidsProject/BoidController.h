// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "BoidController.generated.h"

/**
 * 
 */
UCLASS()
class BOIDSPROJECT_API ABoidController : public AAIController
{
	GENERATED_BODY()
	
public:
	ABoidController(const FObjectInitializer& ObjectInitializer);
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UWorld* World;

};
