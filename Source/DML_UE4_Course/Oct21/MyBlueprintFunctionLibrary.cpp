// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "MyBlueprintFunctionLibrary.h"

FLessonOct21Struct UMyBlueprintFunctionLibrary::AddStructs(FLessonOct21Struct A, FLessonOct21Struct B)
{
	return FLessonOct21Struct::Add(A, B);
}