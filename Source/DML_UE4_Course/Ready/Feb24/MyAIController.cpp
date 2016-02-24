// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "MyAIController.h"

AMyAIController::AMyAIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, "Blackboard Component");

	BrainComponent = BehaviorTreeComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, "Behavior Tree Component");
	BrainComponent->bAutoActivate = false;
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AMyAIController::Possess(class APawn* Pawn)
{
	Super::Possess(Pawn);

	if (BehaviorTreeComp && BehaviorTreeAsset->BlackboardAsset)
	{
		BlackboardComp->InitializeBlackboard(*BehaviorTreeAsset->BlackboardAsset);
		BehaviorTreeComp->StartTree(*BehaviorTreeAsset);
	}
}