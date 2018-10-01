// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyFirstPlugin : ModuleRules {
    public MyFirstPlugin(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateIncludePaths.AddRange(new string[] {"MyFirstPlugin/Private" });
        
        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "Slate",
                "SlateCore",
                "InputCore",
                "DesktopWidgets",
                "EditorStyle",
                "SourceControl",
                "UnrealEd",
                "LevelEditor"
            }
        );
    }
}
