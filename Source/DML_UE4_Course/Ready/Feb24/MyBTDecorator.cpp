// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "MyBTDecorator.h"

UMyBTDecorator::UMyBTDecorator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Azaza";

	BooKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UMyBTDecorator, BooKey));

	bNotifyBecomeRelevant = true;
	bNotifyCeaseRelevant = true;
}

FString UMyBTDecorator::GetStaticDescription() const
{
	return "Boo";
}

bool UMyBTDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	/*UBlackboardComponent* CurrentBlackboard = OwnerComp.GetBlackboardComponent();*/

	/*return CurrentBlackboard->GetValue<UBlackboardKeyType_Bool>(BooKey.GetSelectedKeyID());*/
	return true;
}

void UMyBTDecorator::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8 * NodeMemory)
{
#if WITH_EDITOR
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
	GEngine->AddOnScreenDebugMessage(-1,
		1.0f,
		FColor::Cyan,
		"Start Task");

	UE_LOG(LogTemp, Warning, TEXT("Start Decorator"));
#endif
}

void UMyBTDecorator::OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8 * NodeMemory)
{
#if WITH_EDITOR
	Super::OnCeaseRelevant(OwnerComp, NodeMemory);
	GEngine->AddOnScreenDebugMessage(-1,
		1.0f,
		FColor::Cyan,
		"Stop Task");

	UE_LOG(LogTemp, Error, TEXT("Stop Decorator"));
#endif
}