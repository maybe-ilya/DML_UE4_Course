// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "MyBTService.h"

UMyBTService::UMyBTService(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "This is My service";

	bNotifyBecomeRelevant = true;
	bNotifyCeaseRelevant = true;
}

FString UMyBTService::GetStaticDescription() const
{
	return "Try something else";
}

void UMyBTService::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green,
		FString::Printf(TEXT("This is Service. It's ticking with %f deviation"), DeltaSeconds));
}

void UMyBTService::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8 * NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
	GEngine->AddOnScreenDebugMessage(-1,
		1.0f,
		FColor::Cyan,
		"Start Task");

	UE_LOG(LogTemp, Warning, TEXT("Start Service"));
}

void UMyBTService::OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8 * NodeMemory)
{
	Super::OnCeaseRelevant(OwnerComp, NodeMemory);
	GEngine->AddOnScreenDebugMessage(-1,
		1.0f,
		FColor::Cyan,
		"Stop Task");

	UE_LOG(LogTemp, Error, TEXT("Stop Service"));
}