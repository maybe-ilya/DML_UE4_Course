// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameSession.h"
#include "ExampleGameSession.generated.h"

/**
 *
 */
UCLASS()
class DML_UE4_COURSE_API AExampleGameSession : public AGameSession
{
	GENERATED_BODY()

public:
	AExampleGameSession(const FObjectInitializer& ObjectInitializer);

	bool HostSession(TSharedPtr<const FUniqueNetId> UserId,
		FName SessionName,
		bool bIsLAN,
		bool bIsPresence,
		int32 MaxNumPlayers);

	virtual void OnCreateSessionComplete(FName SessionName, bool bIsSuccessful);

	virtual void OnStartSessionComplete(FName SessionName, bool bIsSuccessful);

	void FindSessions(TSharedPtr<const FUniqueNetId> UserId,
		FName SessionName,
		bool bIsLAN,
		bool bIsPresence);

	virtual void OnFindSessionsComplete(bool bIsSuccessful);

	bool JoinSessionGame(TSharedPtr<const FUniqueNetId> UserId,
		FName SessionName,
		FOnlineSessionSearchResult& SearchResult);

	virtual void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	virtual void OnDestroySessionComplete(FName SessionName, bool bIsSuccessful);

	////
	//	Sessions Delegates and Handles
	////
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	FDelegateHandle OnCreateSessionCompleteDelegate_Handle;

	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;
	FDelegateHandle OnStartSessionCompleteDelegate_Handle;

	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
	FDelegateHandle OnFindSessionsCompleteDelegate_Handle;

	FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;
	FDelegateHandle OnJoinSessionCompleteDelegate_Handle;

	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;
	FDelegateHandle OnDestroySessionCompleteDelegate_Handle;

	////
	//	Sessions Variables
	////
	TSharedPtr<FOnlineSessionSettings> SessionSettings;

	TSharedPtr<FOnlineSessionSearch> SessionSearch;

};
