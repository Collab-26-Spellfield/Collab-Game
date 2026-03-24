// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Structs/CardStats.h"
#include "DebugDataGrabber.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FDebugLogData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int playerIDAsIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int playerIDThatWon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UObject* ObjectData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RoundsWon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RoundCounter;

	//rounds/times picked (pick rate)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NumberOfTimesCardPicked;
	
	//rounds won/times
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCardStats Stats;

	//card is the key and value is the number of times won with card
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString,int> PlayerCards;
	
};


UCLASS()
class SPELLFIELD_API UDebugDataGrabber : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	private:
	UPROPERTY(EditAnywhere)
	FDebugLogData DebugData[3]; //array set to match max player count of 4

	/**Do Not Use*/
	UFUNCTION(BlueprintCallable)
	void LogDebugData(FDebugLogData DataToPull);

	/**Writes all debug data to a specified file
	* @param FileName specifies the file the data should be saved as
	*/
	UFUNCTION(BlueprintCallable)
	void WriteAllSavedDebugDataToFile(FString FileName);

	/**Clears all data from the debug variables*/
	UFUNCTION(BlueprintCallable)
	void ClearLogSavedData();

	/**Updates all card information associated to each player*/
	UFUNCTION(BlueprintCallable)
	void UpdateCardDataForPlayerOnRoundBasis(FCardStats Card, int PlayerID, bool PlayerWon);
	
};
