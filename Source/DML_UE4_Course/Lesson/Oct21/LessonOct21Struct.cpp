// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "LessonOct21Struct.h"

FLessonOct21Struct::FLessonOct21Struct()
{
	MyX = 0.0f;
	MyY = 0.0f;
	MyZ = 0.0f;
}
FLessonOct21Struct::FLessonOct21Struct(float x, float y, float z)
{
	MyX = x;
	MyY = y;
	MyZ = z;
}

FLessonOct21Struct FLessonOct21Struct::Add(FLessonOct21Struct A, FLessonOct21Struct B)
{
	return FLessonOct21Struct(A.MyX + B.MyX, A.MyY + B.MyY, A.MyZ + B.MyZ);
}