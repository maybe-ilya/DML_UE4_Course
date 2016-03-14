// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "OnlineGameInstance.generated.h"

/**
 *
 */
UCLASS()
class DML_UE4_COURSE_API UOnlineGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UOnlineGameInstance(const FObjectInitializer& ObjectInitializer);

	class AExampleGameSession* GetExampleGameSession();

	bool HostOnlineGame(ULocalPlayer* LocalPlayer);
	UFUNCTION(BlueprintCallable, Category = "C++ Session Wrappers", meta = (DisplayName = "Host C++ Session"))
		void HostOnlineGame_BP();

	bool JoinOnlineGame(ULocalPlayer* LocalPlayer);
	UFUNCTION(Blueprintcallable, Category = "C++ Session Wrappers", meta = (DisplayName = "Join C++ Session"))
		void JoinOnlineGame_BP();

	bool SearchOnlineGame(ULocalPlayer* LocalPlayer);
	UFUNCTION(Blueprintcallable, Category = "C++ Session Wrappers", meta = (DisplayName = "Search C++ Session"))
		void SearchOnlineGame_BP();
};
