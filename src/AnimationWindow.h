/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.6

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <juce_core/juce_core.h>
#include <juce_graphics/juce_graphics.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_gui_extra/juce_gui_extra.h>

// AnimationAppDemo.h does not qualify uses of the juce namespace.
// To avoid changing that file, we just import the namespace as a whole.
// This is super hacky, please do not try this at home ;-)
using namespace juce;
//[/Headers]

#include "AnimationAppDemo.h"

//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AnimationWindow : public juce::Component
{
  public:
    //==============================================================================
    AnimationWindow();
    ~AnimationWindow() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void static initialize(); // Call this to initialize the component
    void static finalize();   // Call this when library is about to be unloaded to
                              // free resources
    void static showWindow();
    void static hideWindow();
    //[/UserMethods]

    void paint(juce::Graphics &g) override;
    void resized() override;

  private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    static AnimationWindow *sfInstance;

    std::unique_ptr<juce::DocumentWindow> fWindow;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<AnimationAppDemo> animation;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AnimationWindow)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
