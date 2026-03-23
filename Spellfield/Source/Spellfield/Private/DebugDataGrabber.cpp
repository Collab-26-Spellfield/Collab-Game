// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugDataGrabber.h"
#include <fstream>
#include <iostream>

#include "Structs/CardStats.h"

void UDebugDataGrabber::LogDebugData(FDebugLogData DataToPull, int PlayerID)
{
	auto NameOfClass = DataToPull.Stats;
	DataToPull.Stats->UpgradeParameters.UpgradeName;
	DataToPull.Stats->UpgradeParameters.UpgradeName;
	DataToPull.Stats->UpgradeParameters.UpgradeName;
	
	
	UE_LOG(LogClass, Display, TEXT("Log class"));
	UE_LOG(LogBlueprint, Display, TEXT("Log Blueprint"));
}

void UDebugDataGrabber::WriteAllSavedDebugDataToFile(FString FileName)
{
	std::fstream file;
	file.open("FileName", std::ios::in);
	for (auto Data : DebugData)
	{
		file << "test" << std::endl;
		file.close();
	}
}

void UDebugDataGrabber::ClearLogSavedData()
{
	for (int i = 0; i < 4; ++i)
	{
		DebugData[i] = new FDebugLogData;
	}
}
