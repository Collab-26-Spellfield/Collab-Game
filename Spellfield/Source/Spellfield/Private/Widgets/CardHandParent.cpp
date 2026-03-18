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
	for (int i =0; i<HeldUpgradeCards.Num(); i++)
	{
		HeldUpgradeCards[i]->UpdateCardDesiredTransform(FindCardDesiredTransformInHand(i), CardDrawingSpeed);

		UE_LOG(LogTemp, Warning, TEXT("Updating Card Desired Transform: %d"), i);
	}
}

FWidgetTransform UCardHandParent::FindCardDesiredTransformInHand(int32 CardIndex)
{
	FWidgetTransform DesiredTransform;

	//UE_LOG(LogTemp, Warning, TEXT("Card Index Is: %d"), CardIndex);

	DesiredTransform.Translation = { FindCardDesiredXTranslation(CardIndex), FindCardDesiredYTranslation(CardIndex)};
	DesiredTransform.Scale = { 1.0f,1.0f };
	DesiredTransform.Shear = {0.0f,0.0f};
	DesiredTransform.Angle = FindCardDesiredAngle(CardIndex);

	return DesiredTransform;
}

float UCardHandParent::FindCardDesiredXTranslation(int32 CardIndex)
{
	float XTranslation = 0.0f;

	//float HoverDisplacement = (HoveredCardIndex < CardIndex && HoveredCardIndex >= -1) ? CardXHoverDisplacement : 0.0f;
	//Card Width
	FVector2D CentrePosition = { HandCentre ,0.0f };

	if (HeldUpgradeCards.Num() % 2 == 0) CentrePosition.X = -CardSpacing / 2;

	float CardXPositionInHand = GetCardIndexDistanceFromCentre(CardIndex) * CardSpacing;
	;

	//UE_LOG(LogTemp, Warning, TEXT("Card Spaced Translation Is: %d"), FMath::RoundToInt32(CardXPositionInHand));

	XTranslation = CentrePosition.X + CardXPositionInHand;

	UE_LOG(LogTemp, Warning, TEXT("Card Spaced Translation Is: %d"), FMath::RoundToInt32(XTranslation));

	return XTranslation;
}

float UCardHandParent::FindCardDesiredYTranslation(int32 CardIndex)
{
	float YTranslation = 0.0f;

	float HoverDisplacement = (HoveredCardIndex < CardIndex && HoveredCardIndex >= -1) ? CardYHoverDisplacememt : 0.0f;
	float CardYPositionInHand = FMath::Abs(GetCardIndexDistanceFromCentre(CardIndex) * ArcHeight);

	YTranslation = HoverDisplacement + CardYPositionInHand - HandHeight;

	return YTranslation;
}

float UCardHandParent::FindCardDesiredAngle(int32 CardIndex)
{
	float NewAngle = 0.0f;

	NewAngle = GetCardIndexDistanceFromCentre(CardIndex) * CardAngle;

	return NewAngle;
}

float UCardHandParent::GetCardIndexDistanceFromCentre(int32 CardIndex)
{
	int32 IndexDistanceFromCentre = 0;

	float CentreCardIndex = (HeldUpgradeCards.Num() - 1) / 2;

	float DistanceFromCentre = CardIndex - CentreCardIndex;

	if (DistanceFromCentre > 0)
	{
		//~right of centre (positive)
		IndexDistanceFromCentre = FMath::RoundToInt32(DistanceFromCentre - 0.5f);
	}
	else
	{
		IndexDistanceFromCentre = FMath::RoundToInt32(DistanceFromCentre);
	}

	return IndexDistanceFromCentre;
}

