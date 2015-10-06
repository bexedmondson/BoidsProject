// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Boid.generated.h"

UCLASS()
class BOIDSPROJECT_API ABoid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoid(const FObjectInitializer& ObjectInitializer);



	/** Boid movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	FVector velocity;

	/** Boid rotation component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	FRotator rotation;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


protected:
	UStaticMeshComponent* BoidMesh;

	void SetVelocity(FVector newVelocity);

};
