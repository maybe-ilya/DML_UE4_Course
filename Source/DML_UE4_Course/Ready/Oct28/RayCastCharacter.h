// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Oct14/PlayableCharacter.h"
#include "Lesson/Oct28/LessonOct28Interface.h"
#include "RayCastCharacter.generated.h"

/**
 *
 */
UCLASS()
class DML_UE4_COURSE_API ARayCastCharacter : public APlayableCharacter, public ILessonOct28Interface
{
	GENERATED_BODY()

public:
	ARayCastCharacter(const FObjectInitializer& ObjectInitializer);
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ray Cast")
		float RayDistance;
	UFUNCTION(BlueprintCallable, Category = "Ray Cast")
		void ThrowRay();

	//UFUNCTION(BlueprintCallable, Category = "Ray Cast")
	//void OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	//void OnBeginOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//void OnEndOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
		void OnBeginOverlap(AActor* OtherActor);

	UFUNCTION()
		void OnEndOverlap(AActor* OtherActor);

	virtual void Test_Implementation() override;
};
