// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "ExampleGameSession.h"

AExampleGameSession::AExampleGameSession(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	OnCreateSessionCompleteDelegate = FOnCreateSessionCompleteDelegate::CreateUObject(this, &AExampleGameSession::OnCreateSessionComplete);
	OnStartSessionCompleteDelegate = FOnStartSessionCompleteDelegate::CreateUObject(this, &AExampleGameSession::OnStartSessionComplete);
	OnFindSessionsCompleteDelegate = FOnFindSessionsCompleteDelegate::CreateUObject(this, &AExampleGameSession::OnFindSessionsComplete);
	OnJoinSessionCompleteDelegate = FOnJoinSessionCompleteDelegate::CreateUObject(this, &AExampleGameSession::OnJoinSessionComplete);
	OnDestroySessionCompleteDelegate = FOnDestroySessionCompleteDelegate::CreateUObject(this, &AExampleGameSession::OnDestroySessionComplete);
}

bool AExampleGameSession::HostSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLAN, bool bIsPresence, int32 MaxNumPlayers)
{
	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();

		if (Sessions.IsValid() & UserId.IsValid())
		{
			SessionSettings = MakeShareable(new FOnlineSessionSettings());

			SessionSettings->bIsLANMatch = bIsLAN;
			SessionSettings->bUsesPresence = bIsPresence;
			SessionSettings->NumPublicConnections = MaxNumPlayers;
			SessionSettings->NumPrivateConnections = 0;
			SessionSettings->bAllowInvites = true;
			SessionSettings->bAllowJoinInProgress = true;
			SessionSettings->bShouldAdvertise = true;
			SessionSettings->bAllowJoinViaPresence = true;
			SessionSettings->bAllowJoinViaPresenceFriendsOnly = false;

			SessionSettings->Set(SETTING_MAPNAME, FString("EmptyMap"), EOnlineDataAdvertisementType::ViaOnlineService);

			OnCreateSessionCompleteDelegate_Handle = Sessions->AddOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegate);

			return Sessions->CreateSession(*UserId, SessionName, *SessionSettings);
		}
	}
	else
	{

	}
	return false;
}

void AExampleGameSession::OnCreateSessionComplete(FName SessionName, bool bIsSuccessful)
{
	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();

		if (Sessions.IsValid())
		{
			Sessions->ClearOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegate_Handle);
			if (bIsSuccessful)
			{
				GEngine->AddOnScreenDebugMessage(
					-1,
					10.f,
					FColor::Blue,
					TEXT("Session has created"));
				OnStartSessionCompleteDelegate_Handle = Sessions->AddOnStartSessionCompleteDelegate_Handle(OnStartSessionCompleteDelegate);

				Sessions->StartSession(SessionName);
			}
		}
	}
}

void AExampleGameSession::OnStartSessionComplete(FName SessionName, bool bIsSuccessful)
{
	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();

		if (Sessions.IsValid())
		{
			Sessions->ClearOnStartSessionCompleteDelegate_Handle(OnStartSessionCompleteDelegate_Handle);


		}
	}

	if (bIsSuccessful)
	{
		UGameplayStatics::OpenLevel(GetWorld(), "fy_ziganshin_a68_BSP", true, "listen");
		GEngine->AddOnScreenDebugMessage(
			-1,
			10.f,
			FColor::Green,
			TEXT("Session has started"));
	}
}

void AExampleGameSession::FindSessions(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLAN, bool bIsPresence)
{
	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();

		if (Sessions.IsValid() & UserId.IsValid())
		{
			SessionSearch = MakeShareable(new FOnlineSessionSearch());

			SessionSearch->bIsLanQuery = bIsLAN;
			SessionSearch->MaxSearchResults = 20;
			SessionSearch->PingBucketSize = 50;

			if (bIsPresence)
			{
				SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, bIsPresence, EOnlineComparisonOp::Equals);
			}

			TSharedRef<FOnlineSessionSearch> SearchSettingsRef = SessionSearch.ToSharedRef();

			OnFindSessionsCompleteDelegate_Handle = Sessions->AddOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegate);

			Sessions->FindSessions(*UserId, SearchSettingsRef);
		}
	}
	else
	{
		OnFindSessionsComplete(false);
	}
}

void AExampleGameSession::OnFindSessionsComplete(bool bIsSuccessful)
{
	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();

		if (Sessions.IsValid())
		{
			Sessions->ClearOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegate_Handle);

			/*if (SessionSearch->SearchResults.Num() > 0)
			{
				for (int32 SearchIndex = 0; SearchIndex < SessionSearch->SearchResults.Num(); SearchIndex++)
				{

				}
			}*/
			if (bIsSuccessful)
			{
				GEngine->AddOnScreenDebugMessage(
					-1,
					10.f,
					FColor::Yellow,
					FString::Printf(
						TEXT("Search has been successful. Found sessions: %d"),
						SessionSearch->SearchResults.Num()));
			}
		}
	}
}

bool AExampleGameSession::JoinSessionGame(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, FOnlineSessionSearchResult& SearchResult)
{
	bool bIsSuccessful = false;

	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();

		if (Sessions.IsValid() & UserId.IsValid())
		{
			OnJoinSessionCompleteDelegate_Handle = Sessions->AddOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegate);

			bIsSuccessful = Sessions->JoinSession(*UserId, SessionName, SearchResult);
		}
	}

	return bIsSuccessful;
}

void AExampleGameSession::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();

		if (Sessions.IsValid())
		{
			Sessions->ClearOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegate_Handle);

			/*if (Result == EOnJoinSessionCompleteResult::Success)
			{*/
				APlayerController* const PlayerController = this->GetWorld()->GetGameInstance()->GetFirstLocalPlayerController();

				FString TravelURL;

				GEngine->AddOnScreenDebugMessage(
					-1,
					10.f,
					FColor::Magenta,
					TEXT("Client has joined session"));

				if (PlayerController && Sessions->GetResolvedConnectString(SessionName, TravelURL))
				{
					PlayerController->ClientTravel(TravelURL, ETravelType::TRAVEL_Absolute);
				}
			//}
		}
	}
}

void AExampleGameSession::OnDestroySessionComplete(FName SessionName, bool bIsSuccessful)
{
	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();

		if (Sessions.IsValid())
		{
			Sessions->ClearOnDestroySessionCompleteDelegate_Handle(OnDestroySessionCompleteDelegate_Handle);

			if (bIsSuccessful)
			{
				UGameplayStatics::OpenLevel(GetWorld(), "Polygon", true);
			}
		}
	}
}