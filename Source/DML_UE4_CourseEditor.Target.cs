// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class DML_UE4_CourseEditorTarget : TargetRules
{
    public DML_UE4_CourseEditorTarget(TargetInfo Target)
    {
        Type = TargetType.Editor;
        //bUsesSteam = true;
    }

    //
    // TargetRules interface.
    //

    public override void SetupBinaries(
        TargetInfo Target,
        ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
        ref List<string> OutExtraModuleNames
        )
    {
        OutExtraModuleNames.AddRange(new string[] { "DML_UE4_Course" });
    }
}
