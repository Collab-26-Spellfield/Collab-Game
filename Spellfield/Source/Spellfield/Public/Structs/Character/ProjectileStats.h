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
	float ProjectileSpeedBonus = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float ProjectileRangeBonus = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float ProjectileSizeMultiplier = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float RicochetCountBonus = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float ExplosionRadiusMultiplier = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float KnockbackRecievedBonus = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	float LifeStealPercentageBonus = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	bool Penetration = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	bool SlowOnHit = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	bool Lifesteal = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileStats")
	int32 MultishotBonus = 0;
};