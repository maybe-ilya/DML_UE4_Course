// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "NetworkRayCastCharacter.h"

ANetworkRayCastCharacter::ANetworkRayCastCharacter ( const FObjectInitializer& ObjectInitializer ) : Super ( ObjectInitializer )
{
    NetworkHealth = 600.f;
    JumpHeight = 420.f;
}

void ANetworkRayCastCharacter::SetupPlayerInputComponent ( UInputComponent* InputComponent )
{
    Super::SetupPlayerInputComponent ( InputComponent );
    InputComponent->BindAction ( "Ray", IE_Pressed, this, &ANetworkRayCastCharacter::ShootRay );
    InputComponent->BindAction ( "Explode", IE_Pressed, this, &ANetworkRayCastCharacter::Trigger );
}

float ANetworkRayCastCharacter::TakeDamage ( float DamageAmount, struct FDamageEvent const & DamageEvent, AController* EventInstigator, AActor* DamageCauser )
{
	NetworkHealth -= DamageAmount;
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

void ANetworkRayCastCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ANetworkRayCastCharacter::Tick ( float DeltaSeconds )
{
    Super::Tick ( DeltaSeconds );
}

void ANetworkRayCastCharacter::UpdateJumpHeight_Implementation ( float step )
{
    JumpHeight += step;
// 	OnRep_JumpHeight();
}

bool ANetworkRayCastCharacter::UpdateJumpHeight_Validate ( float step )
{
    if ( step > 50.f ) {
        return false;
    }
    return true;
}

void ANetworkRayCastCharacter::OnRep_JumpHeight_Implementation()
{
    UE_LOG ( LogTemp, Warning, TEXT ( "JumpHeight updated to %f" ), JumpHeight );
}

void ANetworkRayCastCharacter::Trigger()
{
    FHitResult Hit;
    FCollisionQueryParams AttackParams ( FName ( "Attack" ), true, this );
    GetWorld()->LineTraceSingleByChannel (
        Hit,
        GetActorLocation(),
        GetActorLocation() + GetActorForwardVector() * 500.f,
        ECC_Camera,
        AttackParams
    );
	DrawDebugLine(
		GetWorld(),
		GetActorLocation(),
        GetActorLocation() + GetActorForwardVector() * 500.f,
		FColor::Yellow,
		false,
		15.f,
		0,
		5.f
	);
    if ( Hit.bBlockingHit && Hit.GetActor()) {
// 		TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());  
//             FDamageEvent DamageEvent(ValidDamageTypeClass);
// 		Hit.GetActor()->TakeDamage(
// 			100.f,
// 			DamageEvent,
// 			GetController(),
// 			this
// 		);
		UGameplayStatics::ApplyDamage(
			Hit.GetActor(),
			100.f,
			GetController(),
			this,
			UDamageType::StaticClass()
		);
        MakeBoom();
    }
}

void ANetworkRayCastCharacter::ShootRay_Implementation()
{
    DrawDebugLine (
        GetWorld(),
        GetActorLocation(),
        GetActorLocation() + GetActorForwardVector() * 250.f,
        FColor::Red,
        false,
        5.0f,
        0,
        5.f
    );

    UE_LOG ( LogTemp, Warning, TEXT ( "%s RED RAY!!!!" ), * ( this->GetName() ) );
}

void ANetworkRayCastCharacter::Explode_Implementation()
{
    if ( ExplodeAsset ) {
        UGameplayStatics::SpawnEmitterAtLocation (
            GetWorld(),
            ExplodeAsset,
            GetActorLocation(),
            FRotator::ZeroRotator,
            true );
    }
    UE_LOG ( LogTemp, Warning, TEXT ( "%s BOOOOM!!!!" ), * ( this->GetName() ) );
}

void ANetworkRayCastCharacter::GetLifetimeReplicatedProps ( TArray< FLifetimeProperty > & OutLifetimeProps ) const
{
    Super::GetLifetimeReplicatedProps ( OutLifetimeProps );

    // always replicate variable
    DOREPLIFETIME ( ANetworkRayCastCharacter, NetworkHealth );

    // but this property will replicated for everyone except owner
    // because his update this locally
    DOREPLIFETIME_CONDITION ( ANetworkRayCastCharacter, JumpHeight, COND_SkipOwner );
}


void ANetworkRayCastCharacter::MakeBoom_Implementation()
{
    if ( Role == ROLE_Authority ) {
        ShootRay();
        Explode();
    }
}

bool ANetworkRayCastCharacter::MakeBoom_Validate()
{
    return true;
}

