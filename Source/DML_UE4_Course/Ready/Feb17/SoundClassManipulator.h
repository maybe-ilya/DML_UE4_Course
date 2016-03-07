// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "SoundClassManipulator.generated.h"

/**
 *
 */
UCLASS()
class DML_UE4_COURSE_API USoundClassManipulator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Sound Class Manipulation")
		static void ChangeVolumeForClass(FString DesiredSoundClass, float NewVolume);
};
