// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Internationalization.h"
#include "ModuleManager.h"
#include "Slate.h"
#include "Logging/LogMacros.h"


DECLARE_LOG_CATEGORY_EXTERN(ModuleLog, Log, All);

/**
 * The public interface to this module.  In most cases, this interface is only public to sibling modules
 * within this plugin.
 */
class IMyFirstPlugin : public IModuleInterface
{

public:

    /**
     * Singleton-like access to this module's interface.  This is just for convenience!
     * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
     *
     * @return Returns singleton instance, loading the module on demand if needed
     */
    static inline IMyFirstPlugin& Get()
    {
        return FModuleManager::LoadModuleChecked< IMyFirstPlugin >("MyFirstPlugin");
    }

    /**
     * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
     *
     * @return True if the module is loaded and ready to use
     */
    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("MyFirstPlugin");
    }
};



