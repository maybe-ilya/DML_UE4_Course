// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTDecorator.h"
#include "MyBTDecorator.generated.h"

/**
 *
 */
UCLASS()
class DML_UE4_COURSE_API UMyBTDecorator : public UBTDecorator
{
	GENERATED_BODY()

public:
	UMyBTDecorator(const FObjectInitializer& ObjectInitializer);
	UPROPERTY(EditAnywhere, Category = "Test Decorator")
	struct FBlackboardKeySelector BooKey;

	virtual FString GetStaticDescription() const override;

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;

	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
