using UnrealBuildTool;

public class UEPerfHubEditor : ModuleRules
{
    public UEPerfHubEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core"
        });

        PrivateDependencyModuleNames.AddRange(new[]
        {
            "UEPerfHub"
        });
    }
}
