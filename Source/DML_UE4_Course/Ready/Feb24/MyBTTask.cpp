// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "MyBTTask.h"

UMyBTTask::UMyBTTask(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Try to Execute this Task!";

	//ActorKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UMyBTTask, ActorKey), AActor::StaticClass());
	ActorKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UMyBTTask, ActorKey), ATargetPoint::StaticClass());
}

FString UMyBTTask::GetStaticDescription() const
{
	return MyDescription.IsEmpty() ? "Try to rewrite Description" : ActorKey.SelectedKeyName.ToString();
}

EBTNodeResult::Type UMyBTTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* CurrentBlackboard = OwnerComp.GetBlackboardComponent();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), FoundActors);

	if (FoundActors.Num() <= 0)
	{
		return EBTNodeResult::Failed;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%d Target Points"), FoundActors.Num());

		AActor* TestValue = FoundActors[FMath::RandRange(0, FoundActors.Num() - 1)];

		CurrentBlackboard->SetValue<UBlackboardKeyType_Object>(ActorKey.SelectedKeyName, TestValue);

		if (ExplosionEmitter)
		{
			UGameplayStatics::SpawnEmitterAtLocation(
				GetWorld(),
				ExplosionEmitter,
				OwnerComp.GetOwner()->GetActorLocation(),
				FRotator::ZeroRotator,
				true);
		}
		if (ExplosionSound)
		{
			UGameplayStatics::PlaySoundAtLocation(
				GetWorld(),
				ExplosionSound,
				OwnerComp.GetOwner()->GetActorLocation(),
				1.0f,
				1.0f,
				0.0f);
		}

		return EBTNodeResult::Succeeded;
	}
}




