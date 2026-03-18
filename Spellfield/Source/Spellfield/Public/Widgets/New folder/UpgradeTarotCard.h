// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/CardParent.h"
#include "Structs/CardStats.h"
#include "UpgradeTarotCard.generated.h"

/**
 * 
 */
UCLASS()
class SPELLFIELD_API UUpgradeTarotCard : public UCardParent
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	FCardStats OwnedUpgrade;

	UFUNCTION(BlueprintCallable)
	 void InitializeCard(FCardStats CardUpgrade);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateUpradeTarotLayout(FCardStats UpgradeParameters);
	void UpdateUpradeTarotLayout_Implementation(FCardStats UpgradeParameters);

protected:

	virtual void CardHovered_Implementation() override;
	virtual void CardUnhovered_Implementation() override;

	virtual void CardPressed_Implementation() override;
	virtual void CardReleased_Implementation() override;
	
};
