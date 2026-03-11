// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/New folder/UpgradeTarotCard.h"

void UUpgradeTarotCard::CardHovered_Implementation()
{
	//Upgrade Tarot Specific Logic

	Super::CardHovered_Implementation();
}

void UUpgradeTarotCard::CardUnhovered_Implementation()
{
	//Upgrade Tarot Specific Logic

	Super::CardUnhovered_Implementation();
}

void UUpgradeTarotCard::CardPressed_Implementation()
{
	//Upgrade Tarot Specific Logic

	Super::CardPressed_Implementation();
}

void UUpgradeTarotCard::CardReleased_Implementation()
{
	//Upgrade Tarot Specific Logic

	Super::CardReleased_Implementation();
}

void UUpgradeTarotCard::InitializeCard(FUpgrade CardUpgrade)
{
	OwnedUpgrade = CardUpgrade;

	UpdateUpradeTarotLayout(OwnedUpgrade);
}

void UUpgradeTarotCard::UpdateUpradeTarotLayout_Implementation(FUpgrade UpgradeParameters)
{
	UE_LOG(LogTemp, Warning, TEXT("UpdateUpgradeTarotLayout not overriden in blueprint"));
}
