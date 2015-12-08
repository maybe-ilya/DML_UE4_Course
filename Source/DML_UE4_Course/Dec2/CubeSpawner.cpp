// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "CubeSpawner.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ACubeSpawner::ACubeSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	BoxSpawner = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, "Box Spawner");
	RootComponent = BoxSpawner;
}

// Called when the game starts or when spawned
void ACubeSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubeSpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACubeSpawner::SpawnTargetActor()
{
	if (TargetActor != nullptr)
	{
		FVector Origin;
		FVector Extends;

		this->GetActorBounds(true, Origin, Extends);

		const FVector TargetSpawnPoint = UKismetMathLibrary::RandomPointInBoundingBox(Origin, Extends);

		GetWorld()->SpawnActor(TargetActor, &TargetSpawnPoint, &FRotator::ZeroRotator);
	}
}