// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyAIController.generated.h"

/**
 *
 */
UCLASS()
class DML_UE4_COURSE_API AMyAIController : public AAIController
{
	GENERATED_BODY()
public:
	AMyAIController(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	virtual void Possess(class APawn* Pawn) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI Assets")
		UBehaviorTree* BehaviorTreeAsset;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI Components")
		UBehaviorTreeComponent* BehaviorTreeComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI Components")
		UBlackboardComponent* BlackboardComp;
};
