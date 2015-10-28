// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "RayCastCharacter.h"

ARayCastCharacter::ARayCastCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RayDistance = 1500.f;

	GetCapsuleComponent()->SetNotifyRigidBodyCollision(true);

	this->OnActorHit.AddDynamic(this, &ARayCastCharacter::OnHit);
	this->OnActorBeginOverlap.AddDynamic(this, &ARayCastCharacter::OnBeginOverlap);
	this->OnActorEndOverlap.AddDynamic(this, &ARayCastCharacter::OnEndOverlap);


	/*this->OnActorHit.AddDynamic(this, &ARayCastCharacter::OnHit)*/
}

void ARayCastCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAction("Ray", IE_Pressed, this, &ARayCastCharacter::ThrowRay);
}

void ARayCastCharacter::ThrowRay()
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, "Throw Ray Cast");

	// Вычисляем конец нашего луча
	FVector TraceEnd = GetActorLocation() + GetActorForwardVector()*RayDistance;

	// Иницализируем структуру, которая после столкновения будет хранить данные о столкновении
	FHitResult TraceHit;

	// Параметры для рэй кастинга
	FCollisionQueryParams TraceParams(FName("Ray Cast"), true, this);

	// Обычный рэй каст по трейс каналу, который остановится, когда встретит хотя б одно препятствие
	GetWorld()->LineTraceSingleByChannel(
		TraceHit,
		GetActorLocation(),
		TraceEnd,
		COLLISION_TEST_TRACE,
		TraceParams);




	// Инициализация типов объектов, с которыми рейкаст будет взаимодействовать
	/*TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(EObjectTypeQuery(ECC_Pawn));
	ObjectTypes.Add(EObjectTypeQuery(ECC_WorldStatic));
	ObjectTypes.Add(EObjectTypeQuery(ECC_WorldDynamic));
	FCollisionObjectQueryParams ObjectParams(ObjectTypes);

	GetWorld()->LineTraceSingleByObjectType(
	TraceHit,
	GetActorLocation(),
	TraceEnd,
	ObjectParams,
	TraceParams);*/




	/*GetWorld()->SweepSingleByChannel(	// Рейкаст при помощи физических примитивов
	TraceHit,
	GetActorLocation(),
	TraceEnd,
	FQuat::Identity,	// для Свипа необходим Rotation, выраженный через FQuat. FQuat::Identity сам определяет поворот на основе двух данный точек. Но вы также можете указать его вручную
	COLLISION_TEST_TRACE,
	FCollisionShape::MakeBox(FVector(0, 100, 100)),	// Делает форму, по которой будет делать свип
	TraceParams);*/




	/*TArray<FHitResult> TraceHits;	// Ниже приведен рейкаст для множественных объектов. Разница в том, что вместо одного FHitResult, необходимо подавать массив из них

	GetWorld()->LineTraceMultiByChannel(
	TraceHits,
	GetActorLocation(),
	TraceEnd,
	COLLISION_TEST_TRACE,
	TraceParams);*/




	// Отрисовка нашего луча
	DrawDebugLine(
		GetWorld(),
		GetActorLocation(),
		TraceEnd,
		FColor::Cyan,
		false,	// будет ли наш луч отрисовываться постоянно
		3.0f,	// сколько времени он будет отрисовываться
		0,
		5.0f);	// Толщина луча. Доступна не для всех функций

	if (TraceHit.GetActor())	// Проверка, ударили ли мы какого-либо актера
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, "YAY!!!");
		ARayCastCharacter* Ray = Cast<ARayCastCharacter>(TraceHit.GetActor());

		if (Ray)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Cyan, "It's Ray!!!");
		}
	}
	else
	{
		//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, "No hit...");
	}


}

void ARayCastCharacter::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Magenta, "Actor Hit");
}

void ARayCastCharacter::OnBeginOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Cyan, "Actor Begin Overlap");
}

void ARayCastCharacter::OnEndOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, "Actor End Overlap");
}