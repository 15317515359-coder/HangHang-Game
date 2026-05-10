// Copyright Epic Games, Inc. All Rights Reserved.

#include "HangHangGame.h"
#include "Modules/ModuleManager.h"

FIMPLEMENT_PRIMARY_GAME_MODULE(FHangHangGameModule, HangHangGame, "HangHangGame");

void FHangHangGameModule::StartupModule()
{
    // This code will execute after your module is loaded into memory
    UE_LOG(LogTemp, Warning, TEXT("HangHangGame Module Started!"));
}

void FHangHangGameModule::ShutdownModule()
{
    // This code will execute after your module is unloaded from memory
    UE_LOG(LogTemp, Warning, TEXT("HangHangGame Module Shutdown!"));
}
