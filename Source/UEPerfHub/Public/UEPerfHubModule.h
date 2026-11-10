#pragma once

#include "Modules/ModuleInterface.h"

class UEPERFHUB_API FUEPerfHubModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
