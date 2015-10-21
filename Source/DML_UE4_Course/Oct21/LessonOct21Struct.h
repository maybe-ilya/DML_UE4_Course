// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "LessonOct21Struct.generated.h"
/**
 *
 */
USTRUCT(BlueprintType)
struct FLessonOct21Struct
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Struct")
		float MyX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Struct")
		float MyY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Struct")
		float MyZ;

	//static FLessonOct21Struct Add(FLessonOct21Struct A, FLessonOct21Struct B);
};
