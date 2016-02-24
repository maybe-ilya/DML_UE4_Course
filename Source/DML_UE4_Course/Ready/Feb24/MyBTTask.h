// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "MyBTTask.generated.h"

/**
 *
 */
UCLASS()
class DML_UE4_COURSE_API UMyBTTask : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UMyBTTask(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, Category = "Test Task")
	struct FBlackboardKeySelector ActorKey;

	UPROPERTY(EditAnywhere, Category = "Try to rewrite Description")
		FString MyDescription;

	UPROPERTY(EditAnywhere, Category = "Explosion")
		UParticleSystem* ExplosionEmitter;
	UPROPERTY(EditAnywhere, Category = "Explosion")
		USoundBase* ExplosionSound;

	virtual FString GetStaticDescription() const override;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
