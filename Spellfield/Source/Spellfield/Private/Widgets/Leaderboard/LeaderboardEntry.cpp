// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Leaderboard/LeaderboardEntry.h"

void ULeaderboardEntry::InitializeEntry_Implementation(FLeaderboardInfo EntryParameters)
{

}

void ULeaderboardEntry::SetUp_Implementation()
{
	//UE_LOG(LogTemp, Warning, TEXT("SetUp Event Not Overriden In Blueprint"));

	OnLeaderboardEntrySetUp.Broadcast(this);
}

void ULeaderboardEntry::CleanUp_Implementation()
{
	//UE_LOG(LogTemp, Warning, TEXT("CleanUp Event Not Overriden In Blueprint"));

	OnLeaderboardEntryCleanUp.Broadcast(this);
}

void ULeaderboardEntry::EntryHovered_Implementation()
{
	//UE_LOG(LogTemp, Warning, TEXT("EntryHovered Event Not Overriden In Blueprint"));

	OnLeaderboardEntryHovered.Broadcast(this);
}

void ULeaderboardEntry::EntryUnhovered_Implementation()
{
	//UE_LOG(LogTemp, Warning, TEXT("EntryUnhovered Event Not Overriden In Blueprint"));

	OnLeaderboardEntryUnhovered.Broadcast(this);
}

void ULeaderboardEntry::EntryPressed_Implementation()
{
	//UE_LOG(LogTemp, Warning, TEXT("EntryPressed Event Not Overriden In Blueprint"));

	OnLeaderboardEntryPressed.Broadcast(this);
}

void ULeaderboardEntry::EntryReleased_Implementation()
{
	//UE_LOG(LogTemp, Warning, TEXT("EntryReleased Event Not Overriden In Blueprint"));

	OnLeaderboardEntryReleased.Broadcast(this);
}

