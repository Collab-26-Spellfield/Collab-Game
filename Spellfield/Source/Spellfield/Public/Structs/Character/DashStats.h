// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DashStats.generated.h"

USTRUCT(BlueprintType)
struct FDashStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DashStats")
	float DashSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DashStats")
	float DashCount = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DashStats")
	float DashDistance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DashStats")
	float DashCooldownLength = 0.0f;
};