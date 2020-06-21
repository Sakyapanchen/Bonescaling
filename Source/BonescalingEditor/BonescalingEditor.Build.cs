// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class BonescalingEditor : ModuleRules
{
	public BonescalingEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine", "InputCore", "AnimGraphRuntime", "Bonescaling", "UnrealEd" });

		PrivateDependencyModuleNames.AddRange(new string[] { "AnimGraph", "BlueprintGraph" });
	}
}
