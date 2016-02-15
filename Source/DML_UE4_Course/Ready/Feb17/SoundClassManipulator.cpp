// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "SoundClassManipulator.h"
#include "AudioDevice.h"
#include "Sound/SoundClass.h"

void USoundClassManipulator::ChangeVolumeForClass(FString DesiredSoundClass, float NewVolume)
{
	FAudioDevice* Device = GEngine->GetMainAudioDevice();

	if (!Device)
	{
		return;
	}

	USoundClass* SoundClass = NULL;

	for (TMap<USoundClass*, FSoundClassProperties>::TIterator It(Device->SoundClasses); It; ++It)
	{
		USoundClass* tmp = It.Key();

		if (tmp->GetName() == DesiredSoundClass)
		{
			tmp->Properties.Volume = NewVolume;
			break;
		}
	}

}