// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttackStats.generated.h"

USTRUCT(BlueprintType)
struct FAttackStats
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackStats")
	float AttackCooldown = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackStats")
	float MovementSpeedWhileCharging = 0.0f;
};