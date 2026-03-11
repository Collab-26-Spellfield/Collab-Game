// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovementStats.generated.h"

USTRUCT(BlueprintType)
struct FMovementStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementStats")
	float MovementSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementStats")
	float KnockbackRecieved = 0.0f;
};
