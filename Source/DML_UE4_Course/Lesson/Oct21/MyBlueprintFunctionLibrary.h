// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Lesson/Oct21/LessonOct21Struct.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class DML_UE4_COURSE_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "October 21 Lesson")
		static FLessonOct21Struct AddStructs(FLessonOct21Struct A, FLessonOct21Struct B);
};
