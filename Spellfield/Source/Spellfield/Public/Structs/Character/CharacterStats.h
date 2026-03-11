// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"

#include "Structs/Character/HealthStats.h"
#include "Structs/Character/AttackStats.h"
#include "Structs/Character/BlockStats.h"
#include "Structs/Character/DashStats.h"
#include "Structs/Character/MovementStats.h"
#include "Structs/Character/ProjectileStats.h"

#include "CharacterStats.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStats : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStats")
	FHealthStats HealthParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStats")
	FAttackStats AttackParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStats")
	FBlockStats BlockParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStats")
	FDashStats DashParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStats")
	FMovementStats MovementParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStats")
	FProjectileStats ProjectileParameters;
};