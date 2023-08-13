#include "LibMain.h"

#include <array>
#include <juce_events/juce_events.h>
namespace gigperformer
{
namespace sdk
{

GigPerformerAPI *CreateGPExtension(LibraryHandle handle)
{
    return new LibMain(handle);
}

} // namespace sdk
} // namespace gigperformer

// List of menu items
std::vector<std::string> menuNames = {
    "Show",
    "Hide",
};

int LibMain::GetMenuCount()
{
    return static_cast<int>(menuNames.size());
}

std::string LibMain::GetMenuName(int index)
{
    std::string text;
    if (index >= 0 && static_cast<std::size_t>(index) < menuNames.size())
    {
        text = menuNames[index];
    }

    return text;
}

void LibMain::InvokeMenu(int index)
{
    if (index >= 0 && static_cast<std::size_t>(index) < menuNames.size())
    {
        switch (index)
        {
        case 0:
            AnimationWindow::showWindow();
            break;
        case 1:
            AnimationWindow::hideWindow();
            break;
        default:
            break;
        }
    }
}

extern "C" void GPScript_ShowAnimation(GPRuntimeEngine *)
{
    // We need to go through MessageManager::callAsync() to ensure that this gets called on the GUI thread.
    // Else, all bets are off and a crash is likely.
    juce::MessageManager::getInstance()->callAsync([]() { AnimationWindow::showWindow(); });
}

extern "C" void GPScript_HideAnimation(GPRuntimeEngine *)
{
    // We need to go through MessageManager::callAsync() to ensure that this gets called on the GUI thread.
    // Else, all bets are off and a crash is likely.
    juce::MessageManager::getInstance()->callAsync([]() { AnimationWindow::hideWindow(); });
}

ExternalAPI_GPScriptFunctionDefinition functionList[] = {
    {"Show", "", "", "Show the animation", GPScript_ShowAnimation},
    {"Hide", "", "", "Hide the animation", GPScript_HideAnimation},
};

int LibMain::RequestGPScriptFunctionSignatureList(GPScript_AllowedLocations, // these are allowed in any script
                                                  ExternalAPI_GPScriptFunctionDefinition **list)
{
    *list = functionList;
    int count = sizeof(functionList) / sizeof(ExternalAPI_GPScriptFunctionDefinition);
    return count;
}
