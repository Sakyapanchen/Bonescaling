// Fill out your copyright notice in the Description page of Project Settings.

#include "Bonescaling.h"
#include "Modules/ModuleManager.h"

class FBonescalingModule : public FDefaultGameModuleImpl
{
#if    WITH_EDITOR
	virtual void StartupModule() override
	{
		FModuleManager::Get().LoadModule(TEXT("BlueprintGraph"));
		FModuleManager::Get().LoadModule(TEXT("AnimGraphRuntime"));
		FModuleManager::Get().LoadModule(TEXT("BonescalingEditor"));
	}
#endif
};

IMPLEMENT_PRIMARY_GAME_MODULE(FBonescalingModule, Bonescaling, "Bonescaling");