// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidsProject.h"
#include "Boid.h"


// Sets default values
ABoid::ABoid(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use a NavMovementComponent to govern the boid's movement
	BoidMovement = ObjectInitializer.CreateDefaultSubobject<UNavMovementComponent>(this, TEXT("BoidComp"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("StaticMesh'/Game/Meshes/paperplane0_0.paperplane0_0'"));
	if (CubeMeshAsset.Succeeded())
	{
		PrimaryActorTick.bCanEverTick = true;
		BoidVisualComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoidVisualComponent"));
		BoidVisualComponent->SetStaticMesh(CubeMeshAsset.Object);
		RootComponent = BoidVisualComponent;
		SetActorEnableCollision(true);
	}
}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("We are using Boid.cpp!"));
	}
	
}

// Called every frame
void ABoid::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


