// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "LessonOct28Interface.generated.h"
/**
 *
 */
UINTERFACE(Blueprintable)
class ULessonOct28Interface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class ILessonOct28Interface
{
	GENERATED_IINTERFACE_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Lesson Interface")
		void Test();
};
