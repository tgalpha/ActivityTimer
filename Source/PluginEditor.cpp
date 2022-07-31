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
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ActivityTimerAudioProcessorEditor::ActivityTimerAudioProcessorEditor (ActivityTimerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    textButtonReset.reset (new juce::TextButton ("textButtonReset"));
    addAndMakeVisible (textButtonReset.get());
    textButtonReset->setButtonText (TRANS("Reset"));
    textButtonReset->addListener (this);
    textButtonReset->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff395b64));
    textButtonReset->setColour (juce::TextButton::textColourOffId, juce::Colour (0xffe7f6f2));
    textButtonReset->setColour (juce::TextButton::textColourOnId, juce::Colour (0xffe7f6f2));

    textButtonReset->setBounds (32, 16, 72, 24);

    timeViewer.reset (new TimeViewer());
    addAndMakeVisible (timeViewer.get());
    timeViewer->setName ("timeViewer");

    timeViewer->setBounds (0, 96, 710, 100);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (710, 300);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ActivityTimerAudioProcessorEditor::~ActivityTimerAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textButtonReset = nullptr;
    timeViewer = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ActivityTimerAudioProcessorEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff2c3333));

    {
        float x = 208.0f, y = 96.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 296.0f, y = 129.0f, width = 10.0f, height = 10.0f;
        juce::Colour fillColour = juce::Colour (0xffa5c9ca);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 2.000f);
    }

    {
        float x = 296.0f, y = 161.0f, width = 10.0f, height = 10.0f;
        juce::Colour fillColour = juce::Colour (0xffa5c9ca);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 2.000f);
    }

    {
        float x = 320.0f, y = 96.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 408.0f, y = 96.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 520.0f, y = 96.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 608.0f, y = 96.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 496.0f, y = 129.0f, width = 10.0f, height = 10.0f;
        juce::Colour fillColour = juce::Colour (0xffa5c9ca);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 2.000f);
    }

    {
        float x = 496.0f, y = 161.0f, width = 10.0f, height = 10.0f;
        juce::Colour fillColour = juce::Colour (0xffa5c9ca);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 2.000f);
    }

    {
        float x = 120.0f, y = 96.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 32.0f, y = 96.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ActivityTimerAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ActivityTimerAudioProcessorEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButtonReset.get())
    {
        //[UserButtonCode_textButtonReset] -- add your button handler code here..
        //[/UserButtonCode_textButtonReset]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ActivityTimerAudioProcessorEditor"
                 componentName="" parentClasses="public juce::AudioProcessorEditor"
                 constructorParams="ActivityTimerAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), audioProcessor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="710" initialHeight="300">
  <BACKGROUND backgroundColour="ff2c3333">
    <ROUNDRECT pos="208 96 72 100" cornerSize="10.0" fill="solid: ffe7f6f2"
               hasStroke="0"/>
    <ROUNDRECT pos="296 129 10 10" cornerSize="2.0" fill="solid: ffa5c9ca" hasStroke="0"/>
    <ROUNDRECT pos="296 161 10 10" cornerSize="2.0" fill="solid: ffa5c9ca" hasStroke="0"/>
    <ROUNDRECT pos="320 96 72 100" cornerSize="10.0" fill="solid: ffe7f6f2"
               hasStroke="0"/>
    <ROUNDRECT pos="408 96 72 100" cornerSize="10.0" fill="solid: ffe7f6f2"
               hasStroke="0"/>
    <ROUNDRECT pos="520 96 72 100" cornerSize="10.0" fill="solid: ffe7f6f2"
               hasStroke="0"/>
    <ROUNDRECT pos="608 96 72 100" cornerSize="10.0" fill="solid: ffe7f6f2"
               hasStroke="0"/>
    <ROUNDRECT pos="496 129 10 10" cornerSize="2.0" fill="solid: ffa5c9ca" hasStroke="0"/>
    <ROUNDRECT pos="496 161 10 10" cornerSize="2.0" fill="solid: ffa5c9ca" hasStroke="0"/>
    <ROUNDRECT pos="120 96 72 100" cornerSize="10.0" fill="solid: ffe7f6f2"
               hasStroke="0"/>
    <ROUNDRECT pos="32 96 72 100" cornerSize="10.0" fill="solid: ffe7f6f2" hasStroke="0"/>
  </BACKGROUND>
  <TEXTBUTTON name="textButtonReset" id="d22744b80c4e49fb" memberName="textButtonReset"
              virtualName="" explicitFocusOrder="0" pos="32 16 72 24" bgColOff="ff395b64"
              textCol="ffe7f6f2" textColOn="ffe7f6f2" buttonText="Reset" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <GENERICCOMPONENT name="timeViewer" id="90009543150fc52b" memberName="timeViewer"
                    virtualName="" explicitFocusOrder="0" pos="0 96 710 100" class="TimeViewer"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

