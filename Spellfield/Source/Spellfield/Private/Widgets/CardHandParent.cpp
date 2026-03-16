// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/CardHandParent.h"
#include "Widgets/New folder/UpgradeTarotCard.h"

void UCardHandParent::InitializeCardHand_Implementation(const TArray<FCardStats>& UpgradesToPresent)
{
	PopulateCardHand(UpgradesToPresent);
}

void UCardHandParent::UpdateCardHandLayout_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("UpdateCardHandLayout Not Imnplemented In Blueprint"));
}

void UCardHandParent::PopulateCardHand(TArray<FCardStats> DesiredUpgrades)
{
	for (const auto& Upgrade: DesiredUpgrades)
	{
		UCardParent* CreatedCardWidget = CreateWidget<UCardParent>(this, CreatedCardClass);

		if (UUpgradeTarotCard* CreatedTarotCard = Cast<UUpgradeTarotCard>(CreatedCardWidget))
		{
			CreatedTarotCard->InitializeCard(Upgrade);
		}

		HeldUpgradeCards.Add(CreatedCardWidget);
	}

	UpdateCardHandLayout();

	UpdateCardPositionsInHand();
}

void UCardHandParent::UpdateCardPositionsInHand()
{
	for (int i =0; i<HeldUpgradeCards.Num()-1; i++)
	{
		HeldUpgradeCards[i]->UpdateCardDesiredTransform(FindCardDesiredTransformInHand(i), CardDrawingTime);
	}
}

FWidgetTransform UCardHandParent::FindCardDesiredTransformInHand(int32 CardIndex)
{
	FWidgetTransform DesiredTransform;

	DesiredTransform.Shear = { FindCardDesiredXTranslation(CardIndex), FindCardDesiredYTranslation(CardIndex)};
	DesiredTransform.Scale = { 1.0f,1.0f };
	DesiredTransform.Shear = {0.0f,0.0f};
	DesiredTransform.Angle = FindCardDesiredAngle(CardIndex);

	return DesiredTransform;
}

float UCardHandParent::FindCardDesiredXTranslation(int32 CardIndex)
{
	return 0.0f;
}

float UCardHandParent::FindCardDesiredYTranslation(int32 CardIndex)
{
	return 0.0f;
}

float UCardHandParent::FindCardDesiredAngle(int32 CardIndex)
{
	return 0.0f;
}

