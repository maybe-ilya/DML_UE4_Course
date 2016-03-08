// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimInstance.h"
#include "BaseCharacterAnimation.generated.h"

/**
 * 
 */
UCLASS()
class DML_UE4_COURSE_API UBaseCharacterAnimation : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Character Animation")
		float Speed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Character Animation")
		bool bIsFalling;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Character Animation")
		UAnimMontage* PunchMontage;

public:
	UBaseCharacterAnimation(const FObjectInitializer& ObjectInitializer);

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "Base Character Animation")
	void BeginPunch();
	void BeginPunch_Implementation();
	
	
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "Base Character Animation")
	void EndPunch();
	void EndPunch_Implementation();
};
