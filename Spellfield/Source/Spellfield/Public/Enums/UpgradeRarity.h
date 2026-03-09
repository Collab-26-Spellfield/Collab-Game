// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UpgradeRarity.generated.h"

UENUM(BlueprintType)
enum class EUpgradeRarity : uint8
{
	Common =0,
	Uncommon,
	Rare
};
