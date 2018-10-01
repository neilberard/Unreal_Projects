// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LevelEditor.h"
#include "IMyFirstPlugin.h"



DEFINE_LOG_CATEGORY(ModuleLog);

class FMyFirstPlugin : public IMyFirstPlugin
{

public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FMyFirstPlugin, IMyFirstPlugin);


void CreateToolbarButton()
{
    TSharedPtr<FUICommandList> CommandList;



    struct Local
    {
        static void AddToolbarButton(FToolBarBuilder& ToolbarBuilder)
        {
            //NOTE:: Leave spacing in names for auto padding - Might be benificial to alter this later to lock in a solid size
            //and to remove string size
            ToolbarBuilder.AddToolBarButton(
                NULL,
                NAME_None,
                FText::FromString("   MyPlugin   "),
                FText::FromString("New")
            );
        }
    };

    CommandList = MakeShareable(new FUICommandList);

    TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
    ToolbarExtender->AddToolBarExtension(
        "Content",
        EExtensionHook::After,
        CommandList,
        FToolBarExtensionDelegate::CreateStatic(&Local::AddToolbarButton));

    FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor") ;

    //LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);



}


static void Empty(){};

void FMyFirstPlugin::StartupModule()
{
    UE_LOG(ModuleLog, Warning, TEXT("MY FIRST PLUGIN WORKS"));
    
    CreateToolbarButton();
    // This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FMyFirstPlugin::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}


