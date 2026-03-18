// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Structs/CardStats.h"

#include "Widgets/CardParent.h"

#include "CardHandParent.generated.h"

/**
 * 
 */
UCLASS()
class SPELLFIELD_API UCardHandParent : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	TArray<FCardStats> StoredUpgrades;

	UPROPERTY(BlueprintReadOnly)
	TArray<UCardParent*> HeldUpgradeCards;

protected:



	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void InitializeCardHand(const TArray<FCardStats>& UpgradesToPresent);
	void InitializeCardHand_Implementation(const TArray<FCardStats>& UpgradesToPresent);

	UFUNCTION(BlueprintNativeEvent)
	void UpdateCardHandLayout();
	void UpdateCardHandLayout_Implementation();

private:

	UFUNCTION()
	void PopulateCardHand(TArray<FCardStats> DesiredUpgrades);

	UFUNCTION()
	void UpdateCardPositionsInHand();

	UFUNCTION()
	FWidgetTransform FindCardDesiredTransformInHand(int32 CardIndex);

	UFUNCTION()
	float FindCardDesiredXTranslation(int32 CardIndex);

	UFUNCTION()
	float FindCardDesiredYTranslation(int32 CardIndex);

	UFUNCTION()
	float FindCardDesiredAngle(int32 CardIndex);

	UFUNCTION()
	float GetCardIndexDistanceFromCentre(int32 CardIndex);

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCardParent> CreatedCardClass;

	//Layout parameters
	UPROPERTY(EditDefaultsOnly)
	float CardSpacing = 200.0f;

	UPROPERTY(EditDefaultsOnly)
	float CardDrawingTime = 1.0f;

	UPROPERTY(EditDefaultsOnly)
	float ArcHeight = 10.0f;

	UPROPERTY(EditDefaultsOnly)
	float CardXHoverDisplacement = 100.0f;

	UPROPERTY(EditDefaultsOnly)
	float CardYHoverDisplacememt = 50.0f;

	UPROPERTY(EditDefaultsOnly)
	float CardAngle = 3.0f;

	UPROPERTY(EditDefaultsOnly)
	float HandCentre = 0.0f;

	UPROPERTY(EditDefaultsOnly)
	float HandHeight = 20.0f;

	UPROPERTY()
	int32 HoveredCardIndex = -1;


};
