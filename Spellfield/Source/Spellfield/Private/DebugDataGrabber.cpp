// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugDataGrabber.h"
#include <fstream>
#include <iostream>
#include <string>


void UDebugDataGrabber::LogDebugData(FDebugLogData DataToPull)
{
	//gets the details for PlayerCards
	for (auto Element : DataToPull.PlayerCards)
	{
		for (auto DBGData : DebugData)
		{
			for (auto DataPC : DBGData.PlayerCards)
			{
				if (DataToPull.playerIDThatWon == DebugData[DataToPull.playerIDAsIndex].playerIDThatWon)
					DBGData.playerIDThatWon = DataToPull.playerIDThatWon;

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

void UDebugDataGrabber::WriteAllSavedDebugDataToFile(FString FileName)
{
	//FFileHelper fileh;
	std::string fullPath = TCHAR_TO_UTF8(*FPaths::ConvertRelativePathToFull(FPaths::ProjectDir())) + std::string(TCHAR_TO_UTF8(*FileName)) + ".txt";

	FString path = FPaths::MakeValidFileName(FileName) + ".txt";
		
	std::ofstream file = std::ofstream();
	file.open(fullPath, std::ios::in);
	for (auto Data : DebugData)
	{
		FString DataContents =
			"Upgrade Name:" + Data.Stats.UpgradeParameters.UpgradeName + "\n"
			"Number of Times Card Picked" + FString::FromInt(Data.NumberOfTimesCardPicked) + "\n"
			"Winning Player" + FString::FromInt(Data.playerIDThatWon) + "\n"

		;
		file << "test";
	}
	
	//FFileHelper::LoadFileToString(" ", FPaths::ProjectContentDir() + TEXT("TEST.txt"));
	file.close();
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
	if (PlayerWon)
	{
		for (auto& Element : DebugData[PlayerID - 1].PlayerCards)
		{
			Element.Value++;
			UE_LOG(LogTemp, Warning, TEXT("The card %s has won %i times"), *Element.Key, Element.Value);
		}
	}
	
	if (!DebugData[PlayerID-1].PlayerCards.Find(Card.UpgradeParameters.UpgradeName))
	{
		DebugData[PlayerID-1].PlayerCards.Add(Card.UpgradeParameters.UpgradeName);
	}
	
}
