// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
// Includes for Behavior Tree and Blackboard
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
// Includes for Perception
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"

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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI Components")
		UAIPerceptionComponent* PerceptionComp;
	// Perception senses
	UAISenseConfig_Hearing* HearingSense;
	UAISenseConfig_Sight* SightSense;

public:
	UFUNCTION(Category = "Perception Testing")
		void OnActorPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
	UFUNCTION(Category = "Perception Testing")
		void OnPerceptionUpdated(TArray<AActor*> UpdatedActors);
};
