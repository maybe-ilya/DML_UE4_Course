// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "OnlineGameInstance.h"
#include "ExampleGameSession.h"

UOnlineGameInstance::UOnlineGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

AExampleGameSession* UOnlineGameInstance::GetExampleGameSession()
{
	UWorld* const World = GetWorld();
	if (World)
	{
		AGameMode* const Game = World->GetAuthGameMode();
		if (Game)
		{
			return Cast<AExampleGameSession>(Game->GameSession);
		}
	}
	return nullptr;
}

bool UOnlineGameInstance::HostOnlineGame(ULocalPlayer* LocalPlayer)
{
	AExampleGameSession* GameSession = GetExampleGameSession();
	if (GameSession)
	{
		/*return GameSession->HostSession()*/
		return GameSession->HostSession(LocalPlayer->GetPreferredUniqueNetId(), "This is Example Session game", true, true, 4);
	}
	return false;
}

void UOnlineGameInstance::HostOnlineGame_BP()
{
	ULocalPlayer* LocalPlayer = GetFirstGamePlayer();
	if (LocalPlayer)
	{
		bool Test = HostOnlineGame(LocalPlayer);

		if (Test)
		{
			UE_LOG(LogTemp, Warning, TEXT("Host OK? : TRUE"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Host OK? : FALSE"));
		}
	}
}

bool UOnlineGameInstance::JoinOnlineGame(ULocalPlayer* LocalPlayer)
{
	AExampleGameSession* GameSession = GetExampleGameSession();
	if (GameSession && (GameSession->SessionSearch.IsValid()))
	{
		if (GameSession->SessionSearch->SearchResults.Num() > 0)
		{
			return GameSession->JoinSessionGame(LocalPlayer->GetPreferredUniqueNetId(),
				"This is Example Session game",
				GameSession->SessionSearch->SearchResults[0]);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				10.f,
				FColor::Red,
				TEXT("There is no sessions"));
		}
	}
	return false;
}

void UOnlineGameInstance::JoinOnlineGame_BP()
{
	ULocalPlayer* LocalPlayer = GetFirstGamePlayer();
	if (LocalPlayer)
	{
		bool Test = JoinOnlineGame(LocalPlayer);

		if (Test)
		{
			UE_LOG(LogTemp, Warning, TEXT("Join OK? : TRUE"));
			GEngine->AddOnScreenDebugMessage(
				-1,
				10.f,
				FColor::Magenta,
				TEXT("Join OK? : TRUE"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Join OK? : FALSE"));
			GEngine->AddOnScreenDebugMessage(
				-1,
				10.f,
				FColor::Magenta,
				TEXT("Join OK? : FALSE"));
		}
	}
}

bool UOnlineGameInstance::SearchOnlineGame(ULocalPlayer* LocalPlayer)
{
	AExampleGameSession* GameSession = GetExampleGameSession();
	if (GameSession)
	{
		GameSession->FindSessions(LocalPlayer->GetPreferredUniqueNetId(), "This is Example Session game", true, true);
	}
	return true;
}

void UOnlineGameInstance::SearchOnlineGame_BP()
{
	ULocalPlayer* LocalPlayer = GetFirstGamePlayer();

	if (LocalPlayer)
	{
		bool Test = SearchOnlineGame(LocalPlayer);

		if (Test)
		{
			UE_LOG(LogTemp, Warning, TEXT("Search OK? : TRUE"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Search OK? : FALSE"));
		}
	}
}

