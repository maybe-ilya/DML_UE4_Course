// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "Lesson/Dec02/CubeSpawner.h"
#include "Kismet/KismetMathLibrary.h"
#include "Lesson/Oct14/MyCharacter.h"
#include "Lesson/Oct21/LessonOct21Struct.h"



// Sets default values
ACubeSpawner::ACubeSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	BoxSpawner = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, "Box Spawner");
	RootComponent = BoxSpawner;
}

// Called when the game starts or when spawned
void ACubeSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	FLessonOct21Struct A(1.f, 2.f, 3.f);
	FLessonOct21Struct B(1.1f, 2.f, 3.f);

	/*FString Result = A == B ? "True" : "False";

	GEngine->AddOnScreenDebugMessage(
		1,
		10.f,
		FColor::Orange,
		FString::Printf(
			TEXT("Is A equals B? %s"),
			*Result));*/

	FLessonOct21Struct C = A + B;
	GEngine->AddOnScreenDebugMessage(
		1,
		10.f,
		FColor::Yellow,
		FString::Printf(
			TEXT("C = MyX: %f MyY: %f MyZ: %f"),
			C.MyX,
			C.MyY,
			C.MyZ));

}

// Called every frame
void ACubeSpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACubeSpawner::SpawnTargetActor()
{
	if (TargetActor != nullptr)
	{
		FVector Origin;
		FVector Extends;

		this->GetActorBounds(true, Origin, Extends);

		const FVector TargetSpawnPoint = UKismetMathLibrary::RandomPointInBoundingBox(Origin, Extends);

		FActorSpawnParameters newParams;

		AMyCharacter* test = GetWorld()->SpawnActor<AMyCharacter>(TargetActor, TargetSpawnPoint, FRotator::ZeroRotator, newParams);
	}
}

void ACubeSpawner::MakeSomaMagic(class AMyCharacter Boo)
{

}