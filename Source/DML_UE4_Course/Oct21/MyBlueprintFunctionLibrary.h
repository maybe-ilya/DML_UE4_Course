// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "LessonOct21Struct.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class DML_UE4_COURSE_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	public:
		UMyBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, BlueprintPure ,Category = "My Vector Operations")
	static float Dist(FLessonOct21Struct A, FLessonOct21Struct B);
};
