// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DebugDataGrabber.generated.h"

struct FCardStats;
/**
 * 
 */
USTRUCT()
struct FDebugLogData : public FTableRowBase
{
	GENERATED_BODY()

	int8 playerIDAsIndex;
	int8 playerIDThatWon;
	
	UObject* ObjectData;
	int8 RoundsWon;
	int8 RoundCounter;

	//rounds/times picked (pick rate)
	int8 NumberOfTimesCardPicked;
	
	//rounds won/times
	int8 NumberOfTimesWonWithCard;
	FCardStats* Stats;
	

	
	
};


UCLASS()
class SPELLFIELD_API UDebugDataGrabber : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	FDebugLogData* DebugData[3]; //array set to match max player count of 4
	
	UFUNCTION(BlueprintCallable)
	void LogDebugData(FDebugLogData DataToPull, int PlayerID);

	UFUNCTION(BlueprintCallable)
	void WriteAllSavedDebugDataToFile(FString FileName);

	UFUNCTION()
	void ClearLogSavedData();
};
