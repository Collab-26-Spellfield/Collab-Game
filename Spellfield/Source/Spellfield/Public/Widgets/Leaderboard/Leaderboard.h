// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Structs/Leaderboard/LeaderboardInfoStruct.h"

#include "Widgets/Leaderboard/LeaderboardEntry.h"
#include "Leaderboard.generated.h"

UENUM(BlueprintType)
enum class ELeaderboardType : uint8
{
	Index =0,
	Wins
};

UENUM(BlueprintType)
enum class ELeaderboardOrder: uint8
{
	Ascending =0,
	Descending
};

UENUM(BlueprintType)
enum class ELeaderboardRevealOrder : uint8
{
	Ascending = 0,
	Descending
};

UCLASS()
class SPELLFIELD_API ULeaderboard : public UUserWidget
{
	GENERATED_BODY()

	public:
	UFUNCTION(BlueprintCallable)
	void InitializeLeaderboard(TArray<FLeaderboardInfo> LeaderboardEntries);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void NewLeaderBoardEntryConstructed(ULeaderboardEntry* NewEntryWidget);
	void NewLeaderBoardEntryConstructed_Implementation(ULeaderboardEntry* NewEntryWidget);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ClearLeaderboard();
	void ClearLeaderboard_Implementation();

	//Entry Widget Delegate Handlers
	UFUNCTION(BlueprintNativeEvent)
	void HandleOnEntrySetUp(ULeaderboardEntry* HoveredEntry);
	void HandleOnEntrySetUp_Implementation(ULeaderboardEntry* HoveredEntry);

	UFUNCTION(BlueprintNativeEvent)
	void HandleOnEntryCleanUp(ULeaderboardEntry* HoveredEntry);
	void HandleOnEntryCleanUp_Implementation(ULeaderboardEntry* HoveredEntry);

	UFUNCTION(BlueprintNativeEvent)
	void HandleOnEntryHovered(ULeaderboardEntry* HoveredEntry);
	void HandleOnEntryHovered_Implementation(ULeaderboardEntry* HoveredEntry);

	UFUNCTION(BlueprintNativeEvent)
	void HandleOnEntryUnhovered(ULeaderboardEntry* HoveredEntry);
	void HandleOnEntryUnhovered_Implementation(ULeaderboardEntry* HoveredEntry);

	UFUNCTION(BlueprintNativeEvent)
	void HandleOnEntryPressed(ULeaderboardEntry* HoveredEntry);
	void HandleOnEntryPressed_Implementation(ULeaderboardEntry* HoveredEntry);

	UFUNCTION(BlueprintNativeEvent)
	void HandleOnEntryReleased(ULeaderboardEntry* HoveredEntry);
	void HandleOnEntryReleased_Implementation(ULeaderboardEntry* HoveredEntry);

	private:
	//
	UPROPERTY()
	TArray<FLeaderboardInfo> OrderedLeaderboardEntries;


	//Scalar Customization Variables
	UPROPERTY(EditDefaultsOnly, Category = "Leaderboard Scalar Customisation")
	ELeaderboardType LeaderboardType = ELeaderboardType::Index;

	UPROPERTY(EditDefaultsOnly, Category = "Leaderboard Scalar Customisation")
	ELeaderboardOrder LeaderboardOrder = ELeaderboardOrder::Descending;

	UPROPERTY(EditDefaultsOnly, Category = "Leaderboard Scalar Customisation")
	ELeaderboardRevealOrder LeaderboardRevealOrder = ELeaderboardRevealOrder::Ascending;

	UPROPERTY(EditDefaultsOnly, Category = "Leaderboard Scalar Customisation")
	float RevealSpeedPerEntry = 1.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Leaderboard Scalar Customisation")
	float EntryYSpacing = 0.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Leaderboard Scalar Customisation")
	float EntryXSpacing = 0.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Leaderboard Layout Customisation")
	TSubclassOf<ULeaderboardEntry> LeaderboardEntryClass;

	//Sorting Functions
	TArray<FLeaderboardInfo> OrderLeaderboard(TArray<FLeaderboardInfo> LeaderboardToSort);

	//Entry Widget Creation Functions
	void EstablishNewEntryWidget();

	FWidgetTransform GetEntryTransform(int32 EntryIndex);

	UPROPERTY()
	FTimerHandle LeaderboardEntryCreationTimer;

	UPROPERTY()
	TArray<ULeaderboardEntry*> HeldEntryWidgets;	
};
