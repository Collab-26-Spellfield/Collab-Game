// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugDataGrabber.h"
#include <fstream>
#include <iostream>
#include <string>

#include "HttpModule.h"


void UDebugDataGrabber::LogDebugData(FDebugLogData DataToPull)
{
	//gets the details for PlayerCards
	for (auto Element : DataToPull.PlayerCards)
	{
		for (auto DBGData : DebugData)
		{
			for (auto DataPC : DBGData.PlayerCards)
			{
				if (DataToPull.PlayerID == DebugData[DataToPull.PlayerID].PlayerID)
					DBGData.PlayerID = DataToPull.PlayerID;

				if (DataPC.Key != DataToPull.Stats.UpgradeParameters.UpgradeName)
				{
					DataPC.Key = DataToPull.Stats.UpgradeParameters.UpgradeName;
				}
				else
					DataPC.Value;
				
			}
				
		}
	}
	
	UE_LOG(LogClass, Display, TEXT("Log class"));
	UE_LOG(LogBlueprint, Display, TEXT("Log Blueprint"));
}

void UDebugDataGrabber::WriteAllSavedDebugDataToFile()
{
	std::string Path = TCHAR_TO_UTF8(*FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()));
	FDateTime Time = FDateTime::Now();
	FString CompletePath = Path.c_str() + FString("/DebugData/") + Time.GetDate().ToString() + "/Playtest" + Time.ToString() + FString(".PLog");

	if (!FPaths::FileExists(CompletePath))
	{
		FString ContentToSave = "Game Count: ";		ContentToSave.AppendInt(GameCount);		ContentToSave	+= "\n";
		ContentToSave +=		"Round Count: ";	ContentToSave.AppendInt(RoundCounter);	ContentToSave	+= "\n";
		
		
		for (auto Data : OverallCardsChosen)
		{
			ContentToSave.Append("\n Card Upgrade Picked: " + Data.Key);
			ContentToSave.Append("\n\t Card Picked: "); ContentToSave.AppendInt(Data.Value.TimesCardPicked);
			ContentToSave.Append("\t Card Won: ");		ContentToSave.AppendInt(Data.Value.TimesWonWithCard);
		}
		FFileHelper::SaveStringToFile(ContentToSave, *CompletePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_None);
	}
	else
	{
		UE_LOG(LogBlueprint, Warning, TEXT("File exists"));
	}
	
}

void UDebugDataGrabber::ClearLogSavedData()
{
	for (int i = 0; i < _countof(DebugData); ++i)
	{
		DebugData[i] = FDebugLogData();
		
	}
}

void UDebugDataGrabber::UpdateCardDataForPlayerOnRoundBasis(FCardStats Card, int PlayerID, bool PlayerWon)
{
	if (PlayerID == 1)
		RoundCounter++;
	

	if (DebugData[PlayerID-1].PlayerCards.Find(Card.UpgradeParameters.UpgradeName))
		DebugData[PlayerID-1].PlayerCards.Find(Card.UpgradeParameters.UpgradeName)->TimesCardPicked++;
		
	if (PlayerWon)
	{
		for (auto& Element : DebugData[PlayerID - 1].PlayerCards)
		{
			Element.Value.TimesWonWithCard++;
			UE_LOG(LogTemp, Warning, TEXT("The card %s has won %i times and has been picked %i times by PlayerID: %i on round %i"), *Element.Key, Element.Value.TimesWonWithCard, Element.Value.TimesCardPicked, PlayerID, RoundCounter);
		}
	}
	
	if (!DebugData[PlayerID-1].PlayerCards.Find(Card.UpgradeParameters.UpgradeName))
	{
		DebugData[PlayerID-1].PlayerCards.Add(Card.UpgradeParameters.UpgradeName).TimesCardPicked++;
	}
	
}

void UDebugDataGrabber::OnGameEndPrintAllData()
{
	UE_LOG(LogClass, Error, TEXT("Game: %i | Rounds Played: %i"),GameCount, RoundCounter);
	
	FetchAllAvailableDebugData();
	
	for (auto CardsChosen : OverallCardsChosen)
	{
		UE_LOG(LogClass, Error, TEXT("Card: %s, has been picked %i times and has won %i times"), *CardsChosen.Key, CardsChosen.Value.TimesCardPicked, CardsChosen.Value.TimesWonWithCard);
	}
	WriteAllSavedDebugDataToFile();
	GameCount++;
}

void UDebugDataGrabber::FetchAllAvailableDebugData()
{
	for (int i = 0; i < _countof(DebugData); ++i)
	{
		for (auto CardsChosen: DebugData[i].PlayerCards)
		{
			if (!OverallCardsChosen.Find(CardsChosen.Key))
			{
				OverallCardsChosen.Add(CardsChosen.Key);
			}
			
			OverallCardsChosen.Find(CardsChosen.Key)->TimesCardPicked += CardsChosen.Value.TimesCardPicked; 
			OverallCardsChosen.Find(CardsChosen.Key)->TimesWonWithCard += CardsChosen.Value.TimesWonWithCard; 
		}
		
	}
}
