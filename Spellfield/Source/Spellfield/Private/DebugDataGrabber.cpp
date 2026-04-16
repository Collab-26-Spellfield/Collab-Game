// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugDataGrabber.h"
#include <string>


void UDebugDataGrabber::SetGameModeName(FString GameModeName)
{
	GameModesPlayed.Add(GameModeName);
	RoundCounter++;
	CardsDisplayed.CardsAvailable.Empty();
}

void UDebugDataGrabber::AddCardThatCanBeSelected_DEBUG(FString AvailableCard)
{
	CardsDisplayed.CardsAvailable.Add(AvailableCard);
	CardsAvailableAtEachRound.Add(RoundCounter,CardsDisplayed);
}

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
		FString ContentToSave;
		//FString ContentToSave = "Game Count: ";		ContentToSave.AppendInt(GameCount);		ContentToSave	+= "\n";
		//FString ContentToSave=		"Round Count: ";	ContentToSave.AppendInt(RoundCounter);	ContentToSave	+= "\n";
		//ContentToSave +=		"Player Count: ";	ContentToSave.AppendInt(GetWorld()->PlayerNum);
		
		ContentToSave.Append("Cards Picked And Won Across All Rounds: \n\n");
		for (auto Data : OverallCardsChosen) //All card stats and times picked
		{
			ContentToSave.Append("\n Card Upgrade Picked: " + Data.Key);
			ContentToSave.Append("\n\t Card Picked: " + FString::FromInt(Data.Value.TimesCardPicked));
			ContentToSave.Append("\t Card Won: " + FString::FromInt(Data.Value.TimesWonWithCard));
		}
		
		ContentToSave.Append("\n\n\nData Across All Rounds: \n\n");
		for (int i = 0; i < RoundCounter; i++)
		{
			ContentToSave.Append("Round: " + FString::FromInt(i+1));
			ContentToSave.Append("\nGamemode Played: " + GameModesPlayed[i] + "\n");

			FCurrentCardsDisplayed* CurrentCardsDisplayed = CardsAvailableAtEachRound.Find(i+1);

			if (CurrentCardsDisplayed != nullptr)
			{
				ContentToSave.Append("\n\n Card Availability At Round End:\n");
				for (int j = 0; j < CurrentCardsDisplayed->CardsAvailable.Num(); j++)
					ContentToSave.Append("\t- " + CurrentCardsDisplayed->CardsAvailable[j] + "\n");
			}

			for (FDebugLogData D_Data : DebugData)
			{
				if (D_Data.PlayerID != -1)
				{
					ContentToSave.Append("\n\n[Data for PlayerID : " + FString::FromInt(D_Data.PlayerID) + "]");
					ContentToSave.Append("\n\tPlaced in Position " + FString::FromInt(D_Data.PositionInGame[i]) + "\n");
					ContentToSave.Append("\tScore: " + FString::FromInt(D_Data.PlayerScore[i]) + "\n");
					ContentToSave.Append("\n\tUpgrade Cards Player Has Obtained: \n\n");
					int j = 0;
					for (auto DataPC : D_Data.PlayerCards)
					{
						if (j <= i)
							ContentToSave.Append("\n\t-" + DataPC.Key);
						else
							break;
						j++;
					}
					if (CurrentCardsDisplayed != nullptr)
						ContentToSave.Append("\t(End of Round Pick)\n\n\n");
				}
			}
				
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
	DebugData[PlayerID].PlayerID = PlayerID;

	if (DebugData[PlayerID].PlayerCards.Find(Card.UpgradeParameters.UpgradeName))
		DebugData[PlayerID].PlayerCards.Find(Card.UpgradeParameters.UpgradeName)->TimesCardPicked = 1;
		
	if (PlayerWon)
	{
		//Debug me to check if a player owns the same card but stacked as we probably don't want to increase x amount of 1 card if multiple are owned
		for (auto& Element : DebugData[PlayerID].PlayerCards)
		{
			Element.Value.TimesWonWithCard++;
			UE_LOG(LogTemp, Warning, TEXT("The card %s has won %i times and has been picked %i times by PlayerID: %i on round %i"), *Element.Key, Element.Value.TimesWonWithCard, Element.Value.TimesCardPicked, PlayerID, RoundCounter);
		}
	}
	
	if (!DebugData[PlayerID].PlayerCards.Find(Card.UpgradeParameters.UpgradeName))
	{
		DebugData[PlayerID].PlayerCards.Add(Card.UpgradeParameters.UpgradeName).TimesCardPicked++;
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
	OverallCardsChosen.Empty();
	GameCount++;
}

void UDebugDataGrabber::FetchAllAvailableDebugData()
{
	OverallCardsChosen.Empty();
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

void UDebugDataGrabber::SetPlayerScore_DEBUG(int ID, int Score)
{
	DebugData[ID].PlayerScore.Add(Score);
}

void UDebugDataGrabber::SetPlayerPosInGame_DEBUG(int ID, int Pos)
{
	DebugData[ID].PositionInGame.Add(Pos);
}
