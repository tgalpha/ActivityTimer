/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "TimeViewer.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TimeViewer::TimeViewer (int currentValue, int maxValue)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (160, 100);


    //[Constructor] You can add your own custom stuff here..
    maxValue_ = maxValue;
    tens = currentValue / 10;
    ones = currentValue % 10;
    //[/Constructor]
}

TimeViewer::~TimeViewer()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TimeViewer::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    {
        int x = 0, y = 0, width = 72, height = 100;
        juce::String text = std::to_string(tens);
        juce::Colour fillColour = juce::Colour (0xff395b64);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("zcoolqingkehuangyouti", 90.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 88, y = 0, width = 72, height = 100;
        juce::String text = std::to_string(ones);
        juce::Colour fillColour = juce::Colour (0xff395b64);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("zcoolqingkehuangyouti", 90.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }
    //[/UserPaint]
}

void TimeViewer::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void TimeViewer::parameterValueChanged(int parameterIndex, float newValue)
{
    juce::MessageManagerLock lock (juce::Thread::getCurrentThread());

    if (! lock.lockWasGained())
        return;

    int intValue = juce::roundToInt(newValue * maxValue_);
    tens = intValue / 10;
    ones = intValue % 10;
    repaint();
}

void TimeViewer::parameterGestureChanged(int parameterIndex, bool gestureIsStarting)
{
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TimeViewer" componentName=""
                 parentClasses="public juce::Component, public juce::AudioProcessorParameter::Listener"
                 constructorParams="int currentValue, int maxValue" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="160" initialHeight="100">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

