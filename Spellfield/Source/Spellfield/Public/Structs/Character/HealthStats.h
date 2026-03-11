// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthStats.generated.h"

USTRUCT(BlueprintType)
struct FHealthStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthStats")
	float MaxHealth = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthStats")
	float HealthRegeneration = 0.0f;
};
