// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Lesson/Oct14/MyCharacter.h"
#include "Lesson/Oct21/LessonOct21Enum.h"
#include "Lesson/Oct21/LessonOct21Struct.h"

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

	void MoveRight(float Step);

	void Turn(float Step);

	void DoCharacterJump();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Playable Character Camera")
		USpringArmComponent* CameraBoom;	// Компонент стойки, на которую в дальнейшем повесим камеру
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Playable Character Camera")
		UCameraComponent* FollowCamera;		// Компонент камеры

	// Переменные типов данных, написанных на занятии
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "October 21 Lesson")
		ELessonOct21Enum LessonState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "October 21 Lesson")
		FLessonOct21Struct LessonVector;
};
