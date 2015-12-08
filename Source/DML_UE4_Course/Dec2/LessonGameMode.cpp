// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "LessonGameMode.h"
#include "Kismet/KismetMathLibrary.h"

ALessonGameMode::ALessonGameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	GameScore = 0;

	MinDeviation = 3.0f;
	MaxDeviation = 10.0f;
}

void ALessonGameMode::BeginPlay()
{
	TArray<AActor*> SearchParty;
	UGameplayStatics::GetAllActorsOfClass(
		GetWorld(),
		ACubeSpawner::StaticClass(),
		SearchParty);

	ACubeSpawner* tmp = Cast<ACubeSpawner>(SearchParty[0]);

	if (tmp)
	{
		Spawner = tmp;
		UE_LOG(LogTemp, Warning, TEXT("Success"));
		CallToSpawn();
	}
}

void ALessonGameMode::Tick(float DeltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("My Score is %d"), GameScore);
}

void ALessonGameMode::IncreaseScore()
{
	GameScore += 1;
}

void ALessonGameMode::CallToSpawn()
{
	if (Spawner)
	{
		Spawner->SpawnTargetActor();

		GetWorld()->GetTimerManager().SetTimer(
			SpawnHandle,
			this,
			&ALessonGameMode::CallToSpawn,
			UKismetMathLibrary::RandomFloatInRange(MinDeviation, MaxDeviation),
			false);
	}
}


