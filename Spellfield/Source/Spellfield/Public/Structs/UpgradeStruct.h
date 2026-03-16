// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Enums/UpgradeRarity.h"
#include "UpgradeStruct.generated.h"

USTRUCT(BlueprintType)
struct FUpgrade : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UpgradeParameters | Rarity")
	EUpgradeRarity Rarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UpgradeParameters | Rarity")
	float Weighting = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UpgradeParameters | Identifiers")
	FString UpgradeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UpgradeParameters | Identifiers")
	FString FlavorText;

;


};