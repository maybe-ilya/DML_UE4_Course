// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ready/Oct28/RayCastCharacter.h"
#include "NetworkRayCastCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DML_UE4_COURSE_API ANetworkRayCastCharacter : public ARayCastCharacter
{
	GENERATED_BODY()
	
public:
	ANetworkRayCastCharacter(const FObjectInitializer& ObjectInitializer);
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(Replicated, EditDefaultsOnly, BlueprintReadWrite, Category = "Testing Network")
	float NetworkHealth;
	UPROPERTY(ReplicatedUsing=OnRep_JumpHeight, BlueprintReadWrite, Category = "Testing Network")
	float JumpHeight;
	
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation ,Category = "Testing Network")
	void UpdateJumpHeight(float step);
	void UpdateJumpHeight_Implementation(float step);
	bool UpdateJumpHeight_Validate(float step);


	UFUNCTION(Client, Reliable)
	void OnRep_JumpHeight();
	void OnRep_JumpHeight_Implementation();
	
	// Example of Client function
	UFUNCTION(Client, Unreliable, BlueprintCallable, Category = "Testing Network")
	void ShootRay();
	void ShootRay_Implementation();
	
	
	UPROPERTY(EditDefaultsOnly, Category = "Testing Network")
	UParticleSystem* ExplodeAsset;
	// Example of Net-Multicast function
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "Testing Network")
	void Explode();
	void Explode_Implementation();
	
	void Trigger();
	
	// Example of Server function
	UFUNCTION(Server, Reliable, WithValidation)
	void MakeBoom();
	void MakeBoom_Implementation();
	bool MakeBoom_Validate();
	
	// Damage Handling
	virtual float TakeDamage(
		float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser) override;
};
