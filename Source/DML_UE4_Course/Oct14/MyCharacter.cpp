// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "MyCharacter.h"


// Sets default values
AMyCharacter::AMyCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultHealth = 100;
	Health = DefaultHealth;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{

	Super::BeginPlay();

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AMyCharacter::SetHealth(int32 NewHealth)
{
	Health = NewHealth;
}

int32 AMyCharacter::GetHealth() const
{
	return Health;
}