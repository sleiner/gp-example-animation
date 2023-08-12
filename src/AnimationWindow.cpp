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

//[Headers] You can add your own extra header files here...
#include <juce_events/juce_events.h>
//[/Headers]

#include "AnimationWindow.h"

//[MiscUserDefs] You can add your own user definitions and misc code here...
AnimationWindow *AnimationWindow::sfInstance = nullptr;

class MyDocumentWindow : public juce::DocumentWindow
{
  public:
    MyDocumentWindow() : DocumentWindow("Example Animation", juce::Colours::black, DocumentWindow::allButtons, true)
    {
    }

    virtual ~MyDocumentWindow()
    {
    }
    virtual void closeButtonPressed() override
    {
        setVisible(false);
    };
};
//[/MiscUserDefs]

//==============================================================================
AnimationWindow::AnimationWindow()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    animation.reset(new AnimationAppDemo());
    addAndMakeVisible(animation.get());

    //[UserPreSize]
    //[/UserPreSize]

    setSize(600, 400);

    //[Constructor] You can add your own custom stuff here..
    fWindow.reset(new MyDocumentWindow());
    fWindow->setContentNonOwned(this, true);
    fWindow->setResizable(true, true);
    fWindow->setUsingNativeTitleBar(true);
    //[/Constructor]
}

AnimationWindow::~AnimationWindow()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    animation = nullptr;

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AnimationWindow::paint(juce::Graphics &g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll(juce::Colour(0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AnimationWindow::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    animation->setBounds(0, 0, proportionOfWidth(1.0000f), proportionOfHeight(1.0000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
// other code here...
void AnimationWindow::initialize()
{
    juce::MessageManager::getInstance()->callAsync([]() {
        if (sfInstance == nullptr)
        {
            sfInstance = new AnimationWindow();
            sfInstance->fWindow->setTopLeftPosition(100, 100);
        }

        jassert(sfInstance != nullptr);
        sfInstance->fWindow->setVisible(true);
    });
}

void AnimationWindow::finalize()
{
    if (sfInstance != nullptr)
    {
        delete sfInstance;
        sfInstance = nullptr;
    }
}

void AnimationWindow::showWindow()
{
    sfInstance->fWindow->setVisible(true);
    sfInstance->fWindow->toFront(true);
}

void AnimationWindow::hideWindow()
{
    sfInstance->fWindow->setVisible(false);
}

//[/MiscUserCode]

//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AnimationWindow" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="animation" id="fc1b9d0447765b3e" memberName="animation"
             virtualName="AnimationAppDemo" explicitFocusOrder="0" pos="0 0 100% 100%"
             sourceFile="AnimationAppDemo.h" constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//[EndFile] You can add extra defines here...
//[/EndFile]
