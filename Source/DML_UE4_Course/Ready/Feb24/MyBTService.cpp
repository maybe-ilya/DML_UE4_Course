// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "MyBTService.h"

UMyBTService::UMyBTService(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "This is My service";
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