// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "RayCastCharacter.h"

ARayCastCharacter::ARayCastCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RayDistance = 1500.f;

	GetCapsuleComponent()->SetNotifyRigidBodyCollision(true);

// 	this->OnActorHit.AddDynamic(this, &ARayCastCharacter::OnHit);
// 	this->OnActorBeginOverlap.AddDynamic(this, &ARayCastCharacter::OnBeginOverlap);
// 	this->OnActorEndOverlap.AddDynamic(this, &ARayCastCharacter::OnEndOverlap);

}

void ARayCastCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAction("Ray", IE_Pressed, this, &ARayCastCharacter::ThrowRay);
}

void ARayCastCharacter::ThrowRay()
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, "Throw Ray Cast");

	// Âû÷èñëÿåì êîíåö íàøåãî ëó÷à
	FVector TraceEnd = GetActorLocation() + GetActorForwardVector()*RayDistance;

	// Èíèöàëèçèðóåì ñòðóêòóðó, êîòîðàÿ ïîñëå ñòîëêíîâåíèÿ áóäåò õðàíèòü äàííûå î ñòîëêíîâåíèè
	FHitResult TraceHit;

	// Ïàðàìåòðû äëÿ ðýé êàñòèíãà
	FCollisionQueryParams TraceParams(FName("Ray Cast"), true, this);

	// Îáû÷íûé ðýé êàñò ïî òðåéñ êàíàëó, êîòîðûé îñòàíîâèòñÿ, êîãäà âñòðåòèò õîòÿ á îäíî ïðåïÿòñòâèå
	GetWorld()->LineTraceSingleByChannel(
		TraceHit,
		GetActorLocation(),
		TraceEnd,
		COLLISION_TEST_TRACE,
		TraceParams);




	// Èíèöèàëèçàöèÿ òèïîâ îáúåêòîâ, ñ êîòîðûìè ðåéêàñò áóäåò âçàèìîäåéñòâîâàòü
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

	/*GetWorld()->SweepSingleByChannel(	// Ðåéêàñò ïðè ïîìîùè ôèçè÷åñêèõ ïðèìèòèâîâ
		TraceHit,
		GetActorLocation(),
		TraceEnd,
		FQuat::Identity,	// äëÿ Ñâèïà íåîáõîäèì Rotation, âûðàæåííûé ÷åðåç FQuat. FQuat::Identity ñàì îïðåäåëÿåò ïîâîðîò íà îñíîâå äâóõ äàííûé òî÷åê. Íî âû òàêæå ìîæåòå óêàçàòü åãî âðó÷íóþ
		COLLISION_TEST_TRACE,
		FCollisionShape::MakeBox(FVector(0, 100, 100)),	// Äåëàåò ôîðìó, ïî êîòîðîé áóäåò äåëàòü ñâèï. Â ýòîé ñòðîêå ýòî - êîðîáêà
		FCollisionShape::MakeSphere(25.0f),	// Çäåñü - ñôåðà
		FCollisionShape::MakeCapsule(50.f, 100.f),	// À òóò - êàïñóëà. Äëÿ Âûçîâà ðåéêàñòà ðàñêîìåíòü òîëüêî îäíó èç ýòèõ òðåõ ñòðî÷åê
		TraceParams);*/




	//TArray<FHitResult> TraceHits;	// Íèæå ïðèâåäåí ðåéêàñò äëÿ ìíîæåñòâåííûõ îáúåêòîâ. Ðàçíèöà â òîì, ÷òî âìåñòî îäíîãî FHitResult, íåîáõîäèìî ïîäàâàòü ìàññèâ èç íèõ

	//GetWorld()->LineTraceMultiByChannel(
	//	TraceHits,
	//	GetActorLocation(),
	//	TraceEnd,
	//	COLLISION_TEST_TRACE,
	//	TraceParams);




	// Îòðèñîâêà íàøåãî ëó÷à
	DrawDebugLine(
		GetWorld(),
		GetActorLocation(),
		TraceEnd,
		FColor::Cyan,
		false,	// áóäåò ëè íàø ëó÷ îòðèñîâûâàòüñÿ ïîñòîÿííî
		3.0f,	// ñêîëüêî âðåìåíè îí áóäåò îòðèñîâûâàòüñÿ
		0,
		5.0f);	// Òîëùèíà ëó÷à. Äîñòóïíà íå äëÿ âñåõ ôóíêöèé

	if (TraceHit.GetActor())	// Ïðîâåðêà, óäàðèëè ëè ìû êàêîãî-ëèáî àêòåðà
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, "YAY!!!");

		/*ARayCastCharacter* Ray = Cast<ARayCastCharacter>(TraceHit.GetActor());

		if (Ray)
		{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "It's Ray!!!");
		}*/

		if (TraceHit.GetActor()->GetClass()->ImplementsInterface(ULessonOct28Interface::StaticClass())) 
		// Ïðîâåðêà íà òî, ðåàëèçóåò ëè êëàññ äàííîãî îáúåêòà óêàçàííûé èíòåðôåéñ. 
		// Íåîáõîäèìî åå äåëàòü îáÿçàòåëüíî, áåç íåå êîìïèëÿöèÿ ïðîéäåò, à âîò ïðèëîæåíèå êðàøíåòñÿ.
		{
			ILessonOct28Interface::Execute_Test(TraceHit.GetActor());	//Ïîñëàíèå ñîîáùåíèÿ íà âûïîëíåíèå ôóíêöèè
			// Åñëè ó ìåòîäà âàøåãî åñòü ïàðàìåòðû, â Execute_MethodName íóæíî èõ ïîäàâàòü ñðàçó ïîñëå óêàçàíèÿ àêòåðà äëÿ èñïîëíåíèÿ
			// Íàïðèìåð: ITestInterface::Execute_TestMethod(TestActor, Param1, Param2); Êîëè÷åñòâî ïàðàìåòðîâ çíà÷åíèÿ íå èìååò.
		}


	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, "No hit...");
	}


}

void ARayCastCharacter::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
// 	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Magenta, "Actor Hit");
}

void ARayCastCharacter::OnBeginOverlap(AActor* OtherActor)
{
// 	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Actor Begin Overlap");
}

void ARayCastCharacter::OnEndOverlap(AActor* OtherActor)
{
// 	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, "Actor End Overlap");
}

void ARayCastCharacter::Test_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "Interface Method Call");
}