// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlockStats.generated.h"

USTRUCT(BlueprintType)
struct FBlockStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlockStats")
	float BlockCooldownLength = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlockStats")
	float BlockRadius = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlockStats")
	float BlockDuration = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlockStats")
	float LifestealPercentageOnBlock = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlockStats")
	float BlockDamage = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlockStats")
	float ReflectedDamageMultiplier = 0.0f;
};