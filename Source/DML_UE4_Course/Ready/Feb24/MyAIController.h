// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
// Includes for Behavior Tree and Blackboard
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
// Includes for Perception
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig.h"
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
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "AI Components")
		UAIPerceptionComponent* PerceptionComp;
	// Perception senses
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI Sense")
		UAISenseConfig_Hearing* HearingSense;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI Sense")
		UAISenseConfig_Sight* SightSense;

public:
	UFUNCTION(Category = "Perception Testing")
		void OnActorPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
	UFUNCTION(Category = "Perception Testing")
		void OnPerceptionUpdated(TArray<AActor*> UpdatedActors);
};
