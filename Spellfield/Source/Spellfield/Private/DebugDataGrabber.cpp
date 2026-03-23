// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugDataGrabber.h"
#include <fstream>
#include <iostream>

void UDebugDataGrabber::LogDebugData(FDebugLogData DataToPull)
{
	auto NameOfClass = DataToPull.Stats;
	DataToPull.Stats.UpgradeParameters.UpgradeName;
	DataToPull.Stats.UpgradeParameters.UpgradeName;
	DataToPull.Stats.UpgradeParameters.UpgradeName;
	
	
	UE_LOG(LogClass, Display, TEXT("Log class"));
	UE_LOG(LogBlueprint, Display, TEXT("Log Blueprint"));
}

void UDebugDataGrabber::WriteAllSavedDebugDataToFile(FString FileName)
{
	std::ofstream file;
	file.open("FileName.txt", std::ios::in);
	for (auto Data : DebugData)
	{
		file << "test";
	}
	file.close();
}

void UDebugDataGrabber::ClearLogSavedData()
{
	for (int i = 0; i < 4; ++i)
	{
		DebugData[i] = FDebugLogData();
		
	}
}
