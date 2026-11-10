#include "UEPerfHubModule.h"

#include "Logging/LogMacros.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogUEPerfHub, Log, All);

void FUEPerfHubModule::StartupModule()
{
    UE_LOG(LogUEPerfHub, Log, TEXT("UEPerfHub runtime module started."));
}

void FUEPerfHubModule::ShutdownModule()
{
    UE_LOG(LogUEPerfHub, Log, TEXT("UEPerfHub runtime module stopped."));
}

IMPLEMENT_MODULE(FUEPerfHubModule, UEPerfHub)
