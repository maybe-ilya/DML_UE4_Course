// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "BaseCharacterAnimation.h"
#include "Oct14/MyCharacter.h"

UBaseCharacterAnimation::UBaseCharacterAnimation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UBaseCharacterAnimation::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AMyCharacter* Char = Cast<AMyCharacter>(TryGetPawnOwner());

	// Прерывание выполнения функции, если указатель на персонажа пустой
	if (!Char)
	{
		return;
	}

	Speed = Char->GetVelocity().Size();
	bIsFalling = Char->GetCharacterMovement()->IsFalling();
}

void UBaseCharacterAnimation::BeginPunch()
{
	if (PunchMontage != NULL && !Montage_IsPlaying(PunchMontage))
	{
		Montage_Play(PunchMontage, 1.f);
	}
}

void UBaseCharacterAnimation::EndPunch()
{
	if (PunchMontage != NULL && Montage_IsPlaying(PunchMontage))
	{
		FName CurrentSection = Montage_GetCurrentSection(PunchMontage);

		if (CurrentSection == FName("Punch1"))
		{
			Montage_SetNextSection(CurrentSection, FName("End1"), PunchMontage);
		}
		else if (CurrentSection == FName("Punch2"))
		{
			Montage_SetNextSection(CurrentSection, FName("End2"), PunchMontage);
		}
	}
}