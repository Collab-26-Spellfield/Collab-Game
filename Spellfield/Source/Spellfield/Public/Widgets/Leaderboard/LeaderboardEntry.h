// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Structs/Leaderboard/LeaderboardInfoStruct.h"
#include "LeaderboardEntry.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLeaderboardEntrySetUp, ULeaderboardEntry*, SetUpEntry);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLeaderboardEntryCleanUp, ULeaderboardEntry*, CleanUpEntry);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLeaderboardEntryHovered, ULeaderboardEntry*, HoveredEntry);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLeaderboardEntryUnhovered, ULeaderboardEntry*, HoveredEntry);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLeaderboardEntryPressed, ULeaderboardEntry*, HoveredEntry);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLeaderboardEntryReleased, ULeaderboardEntry*, HoveredEntry);

UCLASS()
class SPELLFIELD_API ULeaderboardEntry : public UUserWidget
{
	GENERATED_BODY()
	
	public:
	//Delegates
	UPROPERTY(BlueprintAssignable)
	FOnLeaderboardEntrySetUp OnLeaderboardEntrySetUp;

	UPROPERTY(BlueprintAssignable)
	FOnLeaderboardEntryCleanUp OnLeaderboardEntryCleanUp;

	UPROPERTY(BlueprintAssignable)
	FOnLeaderboardEntryHovered OnLeaderboardEntryHovered;

	UPROPERTY(BlueprintAssignable)
	FOnLeaderboardEntryUnhovered OnLeaderboardEntryUnhovered;

	UPROPERTY(BlueprintAssignable)
	FOnLeaderboardEntryPressed OnLeaderboardEntryPressed;

	UPROPERTY(BlueprintAssignable)
	FOnLeaderboardEntryReleased OnLeaderboardEntryReleased;

	//Functions
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void InitializeEntry(FLeaderboardInfo EntryParameters);
	void InitializeEntry_Implementation(FLeaderboardInfo EntryParameters);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetUp();
	void SetUp_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void CleanUp();
	void CleanUp_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void EntryHovered();
	void EntryHovered_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void EntryUnhovered();
	void EntryUnhovered_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void EntryPressed();
	void EntryPressed_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void EntryReleased();
	void EntryReleased_Implementation();

	private:

	UPROPERTY()
	FLeaderboardInfo EntryData; 

};
