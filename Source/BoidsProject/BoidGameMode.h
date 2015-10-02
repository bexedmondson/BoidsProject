// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "BoidGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BOIDSPROJECT_API ABoidGameMode : public AGameMode
{
	GENERATED_BODY()

		virtual void StartPlay() override;
	
	
};
