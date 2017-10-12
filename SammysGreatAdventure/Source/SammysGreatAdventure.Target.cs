// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class SammysGreatAdventureTarget : TargetRules
{
	public SammysGreatAdventureTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("SammysGreatAdventure");
	}
}
