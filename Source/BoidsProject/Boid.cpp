// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidsProject.h"
#include "Boid.h"


// Sets default values
ABoid::ABoid(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// static mesh for visualisation
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("StaticMesh'/Game/Meshes/paperplane0_0.paperplane0_0'"));
	if (CubeMeshAsset.Succeeded())
	{
		PrimaryActorTick.bCanEverTick = true;
		BoidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoidMesh"));
		BoidMesh->SetStaticMesh(CubeMeshAsset.Object);
		RootComponent = BoidMesh;
		SetActorEnableCollision(true);
	}

	// attach sphere for detecting nearby boids
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->AttachTo(RootComponent);
	SphereComponent->InitSphereRadius(40.0f);
	SphereComponent->SetCollisionProfileName("BoidCollider");
}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();
	
	// scale to be more easily visible
	SetActorScale3D(FVector(10, 10, 10));

	//initialise velocity
	velocity = FVector(0, 0, 0);

	//initialise rotation
	rotation = FRotator(0.0, 0.0, 0.0);
	
}

// Called every frame
void ABoid::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	SetActorLocationAndRotation(GetActorLocation() + velocity, GetActorRotation() + rotation);
}

void ABoid::SetVelocity(FVector newVelocity) {
	velocity = newVelocity;
}

FVector ABoid::CalculateBoidVelocity()
{	
	TArray<UPrimitiveComponent*> nearbyComponents;
	GetOverlappingComponents(nearbyComponents);

	std::vector<FVector> nearbyBoidLocations = { };
	std::vector<FRotator> nearbyBoidRotations = { };

	// iterate over components to find only the boids
	for (int i = 0; i < nearbyComponents.Num(); i++) 
	{
		UPrimitiveComponent* collidingComponent = nearbyComponents[i];
		AActor* colliderOwner = collidingComponent->GetOwner();

		if (colliderOwner->IsA(ABoid::StaticClass()))
		{
			FRotator colliderOwnerRotation = colliderOwner->GetActorRotation();
			nearbyBoidRotations.push_back(colliderOwnerRotation);

			FVector colliderOwnerLocation = colliderOwner->GetActorLocation();
			nearbyBoidLocations.push_back(colliderOwnerLocation);
		}
	}

	FVector separation = SeparateBoid(nearbyBoidLocations);
	FVector alignment = AlignBoid();
	FVector cohesion = CohereBoid();
	
	return (separation / 3) + (alignment / 3) + (cohesion / 3);
}

FVector ABoid::SeparateBoid(std::vector<FVector> nearbyBoidLocations)
{
	FVector separationSteer = FVector(0, 0, 0);

	for (int i = 0; i < nearbyBoidLocations.size(); i++) {
		FVector diff = - GetActorLocation() - nearbyBoidLocations[i];

		separationSteer += diff;
	}
	
	//average out the steer
	return separationSteer / nearbyBoidLocations.size();
}

FVector ABoid::AlignBoid()
{
	return FVector(0, 0, 0);
}

FVector ABoid::CohereBoid()
{
	return FVector(0, 0, 0);
}

