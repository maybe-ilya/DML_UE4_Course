// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTService.h"
#include "MyBTService.generated.h"

/**
 *
 */
UCLASS()
class DML_UE4_COURSE_API UMyBTService : public UBTService
{
	GENERATED_BODY()

public:
	UMyBTService(const FObjectInitializer& ObjectInitializer);

	virtual FString GetStaticDescription() const override;

	virtual void TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds) override;

	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
