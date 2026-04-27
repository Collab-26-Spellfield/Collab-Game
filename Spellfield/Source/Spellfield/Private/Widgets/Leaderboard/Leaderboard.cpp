// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Leaderboard/Leaderboard.h"

void ULeaderboard::InitializeLeaderboard(TArray<FLeaderboardInfo> LeaderboardEntries)
{
	UE_LOG(LogTemp, Warning, TEXT("Number of Entries to Present: %d"), LeaderboardEntries.Num());

	OrderedLeaderboardEntries = OrderLeaderboard(LeaderboardEntries);

	ClearLeaderboard();

	//Start Reveal Loop
	GetWorld()->GetTimerManager().SetTimer(LeaderboardEntryCreationTimer, this, &ULeaderboard::EstablishNewEntryWidget, RevealSpeedPerEntry, true);
}

void ULeaderboard::NewLeaderBoardEntryConstructed_Implementation(ULeaderboardEntry* NewEntryWidget)
{
	UE_LOG(LogTemp, Warning, TEXT("NewLeaderBoardEntryConstructed not overriden in blueprint"));
}

void ULeaderboard::ClearLeaderboard_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ClearLeaderboard not overriden in blueprint"));
}

TArray<FLeaderboardInfo> ULeaderboard::OrderLeaderboard(TArray<FLeaderboardInfo> LeaderboardToSort)
{
	TArray<FLeaderboardInfo> SortedLeaderboard;

	//Index Leaderboard Of Type
	switch (LeaderboardType)
	{
		case ELeaderboardType::Index:
			SortedLeaderboard = LeaderboardToSort;
		break;

		case ELeaderboardType::Wins:
			for (int i = 0; i<LeaderboardToSort.Num();i++)
			{
				if (SortedLeaderboard.IsEmpty())
				{
					SortedLeaderboard.Add(LeaderboardToSort[i]);
				}
				else
				{
					for (int j= 0; j< SortedLeaderboard.Num();j++)
					{
						if (LeaderboardToSort[i].PlayerWins > SortedLeaderboard[j].PlayerWins)
						{
							continue;
						}
						else
						{
							SortedLeaderboard.Insert(LeaderboardToSort[i], j);
							break;
						}
					}

					if (!SortedLeaderboard.Contains(LeaderboardToSort[i]))
					{
						SortedLeaderboard.Add(LeaderboardToSort[i]);
					}	
				}
			}
		break;

		default:
			SortedLeaderboard = LeaderboardToSort;
		break;
	}

	// Set Leaderboard Order
	switch (LeaderboardOrder)
	{
		case ELeaderboardOrder::Ascending:
			//Remains As Is
		break;

		case ELeaderboardOrder::Descending:
			//Flip Array
			Algo::Reverse(SortedLeaderboard);
		break;

		default:
		break;
	}

	UE_LOG(LogTemp, Warning, TEXT("Number of Entries Sorted: %d"), SortedLeaderboard.Num());

	return SortedLeaderboard;
}

void ULeaderboard::EstablishNewEntryWidget()
{
	UE_LOG(LogTemp, Warning, TEXT("Adding New Leaderboard Entry"));

	//Get Current Index Using LeaderboardRevealOrder
	int32 EntryToCreateIndex = 0;

	switch (LeaderboardRevealOrder)
	{
		case ELeaderboardRevealOrder::Ascending:
			EntryToCreateIndex = HeldEntryWidgets.Num();
		break;

		case ELeaderboardRevealOrder::Descending:
			EntryToCreateIndex = OrderedLeaderboardEntries.Num() - HeldEntryWidgets.Num() - 1;
		break;

		default:
			EntryToCreateIndex = HeldEntryWidgets.Num();
		break;
	}

	//Create Widget
	ULeaderboardEntry* NewEntryWidget = CreateWidget<ULeaderboardEntry>(GetWorld(), LeaderboardEntryClass);
	HeldEntryWidgets.Add(NewEntryWidget);

	//Bind Child Delegates
	NewEntryWidget->OnLeaderboardEntrySetUp.RemoveDynamic(this, &ULeaderboard::HandleOnEntryHovered);
	NewEntryWidget->OnLeaderboardEntryCleanUp.RemoveDynamic(this, &ULeaderboard::HandleOnEntryHovered);
	NewEntryWidget->OnLeaderboardEntryHovered.RemoveDynamic(this, &ULeaderboard::HandleOnEntryHovered);
	NewEntryWidget->OnLeaderboardEntryUnhovered.RemoveDynamic(this, &ULeaderboard::HandleOnEntryHovered);
	NewEntryWidget->OnLeaderboardEntryPressed.RemoveDynamic(this, &ULeaderboard::HandleOnEntryHovered);
	NewEntryWidget->OnLeaderboardEntryReleased.RemoveDynamic(this, &ULeaderboard::HandleOnEntryHovered);

	NewEntryWidget->OnLeaderboardEntrySetUp.AddDynamic(this, &ULeaderboard::HandleOnEntryHovered);
	NewEntryWidget->OnLeaderboardEntryCleanUp.AddDynamic(this, &ULeaderboard::HandleOnEntryHovered);
	NewEntryWidget->OnLeaderboardEntryHovered.AddDynamic(this, &ULeaderboard::HandleOnEntryHovered);
	NewEntryWidget->OnLeaderboardEntryUnhovered.AddDynamic(this, &ULeaderboard::HandleOnEntryHovered);
	NewEntryWidget->OnLeaderboardEntryPressed.AddDynamic(this, &ULeaderboard::HandleOnEntryHovered);
	NewEntryWidget->OnLeaderboardEntryReleased.AddDynamic(this, &ULeaderboard::HandleOnEntryHovered);

	//Find Widget Transform

	NewEntryWidget->SetRenderTransform(GetEntryTransform(EntryToCreateIndex));

	//Initialize Widget ... Subsequently triggers the "SetUp" Process

	NewEntryWidget->InitializeEntry(OrderedLeaderboardEntries[EntryToCreateIndex]);

	//Establish In Blueprint Layout
	NewLeaderBoardEntryConstructed(NewEntryWidget);

	//End Looping If All Entries Present
	if (HeldEntryWidgets.Num() >= OrderedLeaderboardEntries.Num())
	{
		GetWorld()->GetTimerManager().ClearTimer(LeaderboardEntryCreationTimer);
	}
}

FWidgetTransform ULeaderboard::GetEntryTransform(int32 EntryIndex)
{
	FWidgetTransform DesiredEntryTransform;

	DesiredEntryTransform.Translation = { EntryIndex * EntryXSpacing, EntryIndex * EntryYSpacing };

	return DesiredEntryTransform;
}

void ULeaderboard::HandleOnEntrySetUp_Implementation(ULeaderboardEntry* HoveredEntry)
{
	UE_LOG(LogTemp, Warning, TEXT("HandleOnEntrySetUp not overriden in blueprint"));
}

void ULeaderboard::HandleOnEntryCleanUp_Implementation(ULeaderboardEntry* HoveredEntry)
{
	UE_LOG(LogTemp, Warning, TEXT("HandleOnEntryCleanUp not overriden in blueprint"));
}

void ULeaderboard::HandleOnEntryHovered_Implementation(ULeaderboardEntry* HoveredEntry)
{
	UE_LOG(LogTemp, Warning, TEXT("HandleOnEntryHovered not overriden in blueprint"));
}

void ULeaderboard::HandleOnEntryUnhovered_Implementation(ULeaderboardEntry* HoveredEntry)
{
	UE_LOG(LogTemp, Warning, TEXT("HandleOnEntryUnhovered not overriden in blueprint"));
}

void ULeaderboard::HandleOnEntryPressed_Implementation(ULeaderboardEntry* HoveredEntry)
{
	UE_LOG(LogTemp, Warning, TEXT("HandleOnEntryPressed not overriden in blueprint"));
}

void ULeaderboard::HandleOnEntryReleased_Implementation(ULeaderboardEntry* HoveredEntry)
{
	UE_LOG(LogTemp, Warning, TEXT("HandleOnEntryReleased not overriden in blueprint"));
}
