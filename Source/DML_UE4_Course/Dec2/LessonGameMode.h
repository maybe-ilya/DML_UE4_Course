// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "Dec2/CubeSpawner.h"
#include "LessonGameMode.generated.h"

/**
 *
 */
UCLASS()
class DML_UE4_COURSE_API ALessonGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ALessonGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Score")
		int32 GameScore;
public:

	UFUNCTION(BlueprintCallable, Category = "Game Score")
		void IncreaseScore();

protected:
	FTimerHandle SpawnHandle;

	ACubeSpawner* Spawner;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Deviation")
		float MinDeviation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Deviation")
		float MaxDeviation;

	UFUNCTION(BlueprintCallable, Category = "Spawn")
		void CallToSpawn();
};
