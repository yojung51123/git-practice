// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class project06 : ModuleRules
{
	public project06(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
