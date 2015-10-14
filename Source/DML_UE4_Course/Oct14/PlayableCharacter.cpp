// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "PlayableCharacter.h"

APlayableCharacter::APlayableCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}


void APlayableCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &APlayableCharacter::MoveForward);
	InputComponent->BindAxis("LookUp", this, &APlayableCharacter::LookUp);
}

void APlayableCharacter::MoveForward(float Step)
{
	/*
	const FRotator rot = GetControlRotation();
	const newRot = FRotator(0, rot.Yaw, 0);
	const FVector dir = FRotationMatrix(newRot)::GetUnitAxis(EAxis::X);
	AddMovementInput(dir, Step);*/

	const FVector direction = FRotationMatrix(FRotator(0, GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::X);
	AddMovementInput(direction, Step);
}

void APlayableCharacter::LookUp(float Step)
{
	AddControllerPitchInput(Step);
}