using UnrealBuildTool;

public class UEPerfHub : ModuleRules
{
    public UEPerfHub(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core"
        });
    }
}
