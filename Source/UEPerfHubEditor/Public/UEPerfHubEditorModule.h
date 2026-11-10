#pragma once

#include "Modules/ModuleInterface.h"

class UEPERFHUBEDITOR_API FUEPerfHubEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
