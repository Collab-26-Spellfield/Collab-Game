// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"

#include "Structs/UpgradeStruct.h"
#include "Structs/Character/HealthStats.h"
#include "Structs/Character/AttackStats.h"
#include "Structs/Character/BlockStats.h"
#include "Structs/Character/DashStats.h"
#include "Structs/Character/MovementStats.h"
#include "Structs/Character/ProjectileStats.h"

#include "CardStats.generated.h"


USTRUCT(BlueprintType)
struct FCardStats : public FTableRowBase
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardStats")
  FUpgrade UpgradeParameters;
	
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardStats")
  FHealthStats HealthParameters;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardStats")
  FAttackStats AttackParameters;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardStats")
  FBlockStats BlockParameters;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardStats")
  FDashStats DashParameters;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardStats")
  FMovementStats MovementParameters;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardStats")
  FProjectileStats ProjectileParameters;
};

