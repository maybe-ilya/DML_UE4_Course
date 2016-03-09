// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "MyAIController.h"

AMyAIController::AMyAIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Blackboard = BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, "Blackboard Component");

	BrainComponent = BehaviorTreeComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, "Behavior Tree Component");
	BrainComponent->bAutoActivate = false;

	PerceptionComp = ObjectInitializer.CreateDefaultSubobject<UAIPerceptionComponent>(this, "Perception Component");
	SetPerceptionComponent(*PerceptionComp);
	// Configuration of senses. I've tried to create them just like
	// ordinary UObject (with NewObject and CreateObject), but failed.
	HearingSense = ObjectInitializer.CreateDefaultSubobject<UAISenseConfig_Hearing>(this, "Hearing Sense");
	HearingSense->DetectionByAffiliation.bDetectEnemies = true;
	HearingSense->DetectionByAffiliation.bDetectFriendlies = true;
	HearingSense->DetectionByAffiliation.bDetectNeutrals = true;
	HearingSense->HearingRange = 1000.f;
	PerceptionComp->ConfigureSense(*HearingSense);

	SightSense = ObjectInitializer.CreateDefaultSubobject<UAISenseConfig_Sight>(this, "Sight Sense");
	SightSense->DetectionByAffiliation.bDetectEnemies = true;
	SightSense->DetectionByAffiliation.bDetectFriendlies = true;
	SightSense->DetectionByAffiliation.bDetectNeutrals = true;
	SightSense->PeripheralVisionAngleDegrees = 65.f;
	SightSense->SightRadius = 1000.f;
	SightSense->LoseSightRadius = 1500.f;
	//SightSense->MaxAge = 0.1f;
	PerceptionComp->ConfigureSense(*SightSense);

	PerceptionComp->SetDominantSense(SightSense->GetSenseImplementation());

	PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &AMyAIController::OnActorPerceptionUpdated);
	PerceptionComp->OnPerceptionUpdated.AddDynamic(this, &AMyAIController::OnPerceptionUpdated);
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	if (BehaviorTreeComp &&
		BlackboardComp &&
		BehaviorTreeAsset &&
		BehaviorTreeAsset->BlackboardAsset)
	{
		BlackboardComp->InitializeBlackboard(*BehaviorTreeAsset->BlackboardAsset);
		BehaviorTreeComp->StartTree(*BehaviorTreeAsset);
	}
}

void AMyAIController::Possess(class APawn* Pawn)
{
	Super::Possess(Pawn);

	if (BehaviorTreeComp &&
		BlackboardComp &&
		BehaviorTreeAsset &&
		BehaviorTreeAsset->BlackboardAsset)
	{
		BlackboardComp->InitializeBlackboard(*BehaviorTreeAsset->BlackboardAsset);
		BehaviorTreeComp->StartTree(*BehaviorTreeAsset);
	}
}

void AMyAIController::OnActorPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	////UE_LOG(LogTemp, Warning, TEXT("Stimulus ID: %d"), Stimulus.Type);
	TSubclassOf<UAISense> tmp = UAIPerceptionSystem::GetSenseClassForStimulus(GetWorld(), Stimulus);
	UE_LOG(LogTemp, Warning, TEXT("received stimulus from %s"), *(tmp->GetName()));
}

void AMyAIController::OnPerceptionUpdated(TArray<AActor*> UpdatedActors)
{

}