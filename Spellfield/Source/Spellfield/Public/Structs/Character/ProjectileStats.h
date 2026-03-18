// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Structs/Character/ProjectileDamageStats.h"

#include "ProjectileStats.generated.h"

USTRUCT(BlueprintType)
struct FProjectileStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	FProjectileDamageStats ProjectileDamageParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float ProjectileSpeedMultiplier = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float ProjectileRangeMultiplier = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float ProjectileSizeMultiplier = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float ProjectileSpreadBonus= 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float ExplosionRadiusMultiplier = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float KnockbackGivenMultiplier = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float LifeStealPercentage = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float SlowOnHit = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float Lifesteal = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float Penetration = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float RicochetCount = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float MultishotBonus = 0.0f;
};