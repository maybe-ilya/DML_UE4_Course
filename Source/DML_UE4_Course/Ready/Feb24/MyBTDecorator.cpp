// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "MyBTDecorator.h"

UMyBTDecorator::UMyBTDecorator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Azaza";

	BooKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UMyBTDecorator, BooKey));
}

FString UMyBTDecorator::GetStaticDescription() const
{
	return "Boo";
}

bool UMyBTDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* CurrentBlackboard = OwnerComp.GetBlackboardComponent();

	return CurrentBlackboard->GetValue<UBlackboardKeyType_Bool>(BooKey.GetSelectedKeyID());
}
