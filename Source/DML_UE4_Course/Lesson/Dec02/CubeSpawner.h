// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CubeSpawner.generated.h"

UCLASS()
class DML_UE4_COURSE_API ACubeSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeSpawner(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Collision")
		UBoxComponent* BoxSpawner;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn")
		UClass* TargetActor;

	UFUNCTION(BlueprintCallable, Category = "Spawn")
		void SpawnTargetActor();
	
};
