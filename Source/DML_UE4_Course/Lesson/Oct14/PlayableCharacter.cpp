// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "Lesson/Oct14/PlayableCharacter.h"

APlayableCharacter::APlayableCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = ObjectInitializer.CreateDefaultSubobject<USpringArmComponent>(this, "Camera Boom");	// Создание компонента Spring Arm, на который повесим камеру
	CameraBoom->AttachTo(RootComponent);	// Добавляем Стойку к Корневому компоненту Персонажа
	CameraBoom->bUsePawnControlRotation = true;	// Для стойки включаем копирование Ротатора Контроллера нашего Персонажа
	CameraBoom->bInheritPitch = false;	// Но не используем Наклон
	CameraBoom->bInheritRoll = false;	// И не используем Вращение
	CameraBoom->bInheritYaw = true;		// А копируем только Поворот

	FollowCamera = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, "Follow Camera");	// Создаем компонент камеры
	FollowCamera->AttachTo(CameraBoom);	// Добавляем к Стойке, для обзора вокруг персонажа
}


void APlayableCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &APlayableCharacter::MoveForward);
	InputComponent->BindAxis("LookUp", this, &APlayableCharacter::LookUp);
	InputComponent->BindAxis("MoveRight", this, &APlayableCharacter::MoveRight);
	InputComponent->BindAxis("Turn", this, &APlayableCharacter::Turn);

	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayableCharacter::DoCharacterJump);
	//InputComponent->BindAction("Jump", IE_Released, this, &APlayableCharacter::StopCharacterJump);	// На случай, если вам нужно выполнять действия на отжатие клавиш
}

void APlayableCharacter::MoveForward(float Step)
{
	/*
	const FRotator rot = GetControlRotation();	// Получаем Rotator контроллера
	const newRot = FRotator(0, rot.Yaw, 0);		// Но нам не нужен весь Ротатор, а только поворот(Yaw)
	const FVector dir = FRotationMatrix(newRot)::GetUnitAxis(EAxis::X);	// Выделяем из нового Ротатора вектор вперед Персонажа
	AddMovementInput(dir, Step);	// и добавляем движение на этот вектор
	 */

	const FVector direction = FRotationMatrix(FRotator(0, GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::X);
	AddMovementInput(direction, Step);
}

void APlayableCharacter::LookUp(float Step)
{
	AddControllerPitchInput(Step);
}

/*	Метод из домашнего задания
 *	Здесь мы делаем ровным счетом то же самое, что и в методе MoveForward, 
 *	с разницей в том, что получаем вектор вправо Персонажа (вправо в Unreal'e - ось Y)
 */
void APlayableCharacter::MoveRight(float Step)
{
	const FVector direction = FRotationMatrix(FRotator(0, GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::Y);
	AddMovementInput(direction, Step);
}
/*	Метод из домашнего задания
	Мы просто добавляем шаг поворота(Yaw) контроллеру, а не наклона(Pitch) как в прошлом методе
 */
void APlayableCharacter::Turn(float Step)
{
	AddControllerYawInput(Step);
}

void APlayableCharacter::DoCharacterJump()
{
	GetCharacterMovement()->DoJump(true);
}