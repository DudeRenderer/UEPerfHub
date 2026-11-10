#include "UEPerfHubEditorModule.h"

#include "Logging/LogMacros.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogUEPerfHubEditor, Log, All);

void FUEPerfHubEditorModule::StartupModule()
{
    UE_LOG(LogUEPerfHubEditor, Log, TEXT("UEPerfHub editor module started."));
}

void FUEPerfHubEditorModule::ShutdownModule()
{
    UE_LOG(LogUEPerfHubEditor, Log, TEXT("UEPerfHub editor module stopped."));
}

IMPLEMENT_MODULE(FUEPerfHubEditorModule, UEPerfHubEditor)
