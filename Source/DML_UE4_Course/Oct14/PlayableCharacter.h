// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Oct14/MyCharacter.h"
#include "PlayableCharacter.generated.h"

/**
 *
 */
UCLASS()
class DML_UE4_COURSE_API APlayableCharacter : public AMyCharacter
{
	GENERATED_BODY()

public:
	APlayableCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void MoveForward(float Step);

	void LookUp(float Step);
};
