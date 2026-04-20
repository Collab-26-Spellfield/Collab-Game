// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LeaderboardInfoStruct.generated.h"

USTRUCT(BlueprintType)
struct FLeaderboardInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PlayerNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PlayerWins;

	bool operator==(const FLeaderboardInfo& Other) const
	{
		return PlayerNumber == Other.PlayerNumber &&
			PlayerWins == Other.PlayerWins;
	}
};
