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
	int NumberOfTimesWonWithCard;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCardStats Stats;
	
};


UCLASS()
class SPELLFIELD_API UDebugDataGrabber : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	protected:
	UPROPERTY(EditAnywhere)
	FDebugLogData DebugData[3]; //array set to match max player count of 4
	
	UFUNCTION(BlueprintCallable)
	void LogDebugData(FDebugLogData DataToPull);

	UFUNCTION(BlueprintCallable)
	void WriteAllSavedDebugDataToFile(FString FileName);

	UFUNCTION()
	void ClearLogSavedData();
};
