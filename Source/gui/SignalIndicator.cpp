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

#include "SignalIndicator.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SignalIndicator::SignalIndicator ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (24, 24);


    //[Constructor] You can add your own custom stuff here..
    SettableTooltipClient::setTooltip (TRANS("SignalIndicator: Lights up when a signal is received."));
    //[/Constructor]
}

SignalIndicator::~SignalIndicator()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SignalIndicator::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = 0.0f, y = 0.0f, width = 24.0f, height = 24.0f;
        juce::Colour fillColour1 = juce::Colour (0xff395b64), fillColour2 = juce::Colour (0xff2c3333);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        if (isLight)
        {
            fillColour1 = juce::Colour (0xffa5c9ca);
            fillColour2 = juce::Colour (0xffe7f6f2);
        }
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             12.0f - 0.0f + x,
                                             12.0f - 0.0f + y,
                                             fillColour2,
                                             0.0f - 0.0f + x,
                                             0.0f - 0.0f + y,
                                             true));
        g.fillEllipse (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SignalIndicator::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void SignalIndicator::parameterValueChanged (int parameterIndex, float newValue)
{
    juce::MessageManagerLock lock (juce::Thread::getCurrentThread());
    
    if (! lock.lockWasGained())
        return;
    
    isLight = !newValue;
    
    repaint();
}

void SignalIndicator::parameterGestureChanged (int parameterIndex, bool gestureIsStarting)
{
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SignalIndicator" componentName=""
                 parentClasses="public juce::Component, public juce::AudioProcessorParameter::Listener, public juce::SettableTooltipClient"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="24"
                 initialHeight="24">
  <BACKGROUND backgroundColour="323e44">
    <ELLIPSE pos="0 0 24 24" fill=" radial: 12 12, 0 0, 0=ff395b64, 1=ff2c3333"
             hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

