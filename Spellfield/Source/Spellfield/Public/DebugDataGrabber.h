// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Structs/CardStats.h"
#include "DebugDataGrabber.generated.h"

/**
 * 
 */
USTRUCT()
struct FDebugPlayerCardData : public FTableRowBase
{
	GENERATED_BODY()
	
	int TimesCardPicked = 0;
	int TimesWonWithCard = 0;
};

USTRUCT()
struct FCurrentCardsDisplayed
{
	GENERATED_BODY()
	TArray<FString> CardsAvailable;
};


USTRUCT(BlueprintType)
struct FDebugLogData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int PlayerID = -1;
	
	UPROPERTY(BlueprintReadWrite)
	int RoundsWon = 0;

	UPROPERTY(BlueprintReadWrite)
	TArray<int> PlayerScore;

	UPROPERTY(BlueprintReadWrite)
	TArray<int> PositionInGame;
	
	UPROPERTY(BlueprintReadWrite)
	FCardStats Stats;

	//card is the key and value is the number of times won with card
	UPROPERTY(BlueprintReadWrite)
	TMap<FString, FDebugPlayerCardData> PlayerCards;

	UPROPERTY()
	TArray<FString> CurrentCardPickedAtRound;
	
};

UCLASS()
class SPELLFIELD_API UDebugDataGrabber : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	
	private:

	int WinnerID = 0;

	UFUNCTION(BlueprintCallable)
	void SetWinnerID(int ID);
	
	UPROPERTY()
	FDebugLogData DebugData[4]; //array set to match max player count of 4

	UPROPERTY()
	TMap<FString, FDebugPlayerCardData> OverallCardsChosen;

	UPROPERTY()
	int RoundCounter = 0;

	//use roundcounter-1 to index
	UPROPERTY()
	TArray<FString> GameModesPlayed;

	//Make new function for when cards are displayed to them get the data

	UFUNCTION(BlueprintCallable)
	void SetGameModeName(FString GameModeName);
	
	//int is roundCount-1
	UPROPERTY()
	TMap<int,FCurrentCardsDisplayed> CardsAvailableAtEachRound;

	UPROPERTY()
	FCurrentCardsDisplayed CardsDisplayed;

	UPROPERTY()
	int GameCount = 1;

	UFUNCTION(BlueprintCallable)
	void AddCardThatCanBeSelected_DEBUG(FString AvailableCard);
	
	/**Do Not Use*/
	UFUNCTION(BlueprintCallable)
	void LogDebugData(FDebugLogData DataToPull);

	/**Writes all debug data to a specified file
	* @param FileName specifies the file the data should be saved as
	*/
	UFUNCTION(BlueprintCallable)
	void WriteAllSavedDebugDataToFile();

	/**Clears all data from the debug variables*/
	UFUNCTION(BlueprintCallable)
	void ClearLogSavedData();

	/**Updates all card information associated to each player*/
	UFUNCTION(BlueprintCallable)
	void UpdateCardDataForPlayerOnRoundBasis(FCardStats Card, int PlayerID, bool PlayerWon);

	UFUNCTION(BlueprintCallable)
	void OnGameEndPrintAllData();

	UFUNCTION()
	void FetchAllAvailableDebugData();

	UFUNCTION(BlueprintCallable)
	void SetPlayerScore_DEBUG(int ID, int Score);

	UFUNCTION(BlueprintCallable)
	void SetPlayerPosInGame_DEBUG(int ID, int Pos);
	
	
};
