// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS(abstract)
class DML_UE4_COURSE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "October_14_Lesson")
	int32 Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "October_14_Lesson")
	int32 DefaultHealth;

public:

	UFUNCTION(BlueprintCallable, Category = "October_14_Lesson")
	void SetHealth(int32 NewHealth);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "October_14_Lesson")
	int32 GetHealth() const;

protected:
	UFUNCTION(BlueprintCallable, Category = "November_18_Lesson")
		void BeginPunching();
	UFUNCTION(BlueprintCallable, Category = "November_18_Lesson")
		void EndPunching();
};
