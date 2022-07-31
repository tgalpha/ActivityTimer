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
#include  "../Constants.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ActivityTimerAudioProcessorEditor::ActivityTimerAudioProcessorEditor (ActivityTimerAudioProcessor& p, ActivityTimer& t)
    : AudioProcessorEditor (&p), audioProcessor (p), activityTimer(t)
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

    secondsViewer.reset (new TimeViewer (activityTimer.getSeconds(), MAX_SECONDS));
    addAndMakeVisible (secondsViewer.get());
    secondsViewer->setName ("secondsViewer");

    secondsViewer->setBounds (432, 72, 160, 100);

    minutesViewer.reset (new TimeViewer (activityTimer.getMinutes(), MAX_SECONDS));
    addAndMakeVisible (minutesViewer.get());
    minutesViewer->setName ("minutesViewer");

    minutesViewer->setBounds (232, 72, 160, 100);

    hoursViewer.reset (new TimeViewer (activityTimer.getHours(), MAX_SECONDS));
    addAndMakeVisible (hoursViewer.get());
    hoursViewer->setName ("hoursViewer");

    hoursViewer->setBounds (32, 72, 160, 100);

    sliderActiveSustain.reset (new juce::Slider ("sliderActiveSustain"));
    addAndMakeVisible (sliderActiveSustain.get());
    sliderActiveSustain->setTooltip (TRANS("The duration(seconds) that timer remains active when a signal is received"));
    sliderActiveSustain->setRange (0, 600, 1);
    sliderActiveSustain->setSliderStyle (juce::Slider::LinearHorizontal);
    sliderActiveSustain->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    sliderActiveSustain->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff395b64));
    sliderActiveSustain->setColour (juce::Slider::thumbColourId, juce::Colour (0xffa5c9ca));
    sliderActiveSustain->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x66a5c9ca));
    sliderActiveSustain->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0xffe7f6f2));
    sliderActiveSustain->addListener (this);
    sliderActiveSustain->setSkewFactor (0.5);

    sliderActiveSustain->setBounds (152, 200, 150, 40);


    //[UserPreSize]
    sliderActiveSustain->setValue(activityTimer.activeSustain->get());
    //[/UserPreSize]

    setSize (625, 260);


    //[Constructor] You can add your own custom stuff here..
    activityTimer.addViewers(hoursViewer.get(), minutesViewer.get(), secondsViewer.get());
    //[/Constructor]
}

ActivityTimerAudioProcessorEditor::~ActivityTimerAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    activityTimer.removeViewers(hoursViewer.get(), minutesViewer.get(), secondsViewer.get());
    //[/Destructor_pre]

    textButtonReset = nullptr;
    secondsViewer = nullptr;
    minutesViewer = nullptr;
    hoursViewer = nullptr;
    sliderActiveSustain = nullptr;


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
        float x = 120.0f, y = 72.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 208.0f, y = 105.0f, width = 10.0f, height = 10.0f;
        juce::Colour fillColour = juce::Colour (0xffa5c9ca);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 2.000f);
    }

    {
        float x = 208.0f, y = 137.0f, width = 10.0f, height = 10.0f;
        juce::Colour fillColour = juce::Colour (0xffa5c9ca);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 2.000f);
    }

    {
        float x = 232.0f, y = 72.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 320.0f, y = 72.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 432.0f, y = 72.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 520.0f, y = 72.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 408.0f, y = 105.0f, width = 10.0f, height = 10.0f;
        juce::Colour fillColour = juce::Colour (0xffa5c9ca);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 2.000f);
    }

    {
        float x = 408.0f, y = 137.0f, width = 10.0f, height = 10.0f;
        juce::Colour fillColour = juce::Colour (0xffa5c9ca);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 2.000f);
    }

    {
        float x = 32.0f, y = 72.0f, width = 72.0f, height = 100.0f;
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        int x = 23, y = 205, width = 127, height = 30;
        juce::String text (TRANS("ActivateSustain:"));
        juce::Colour fillColour = juce::Colour (0xffe7f6f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (16.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
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
        activityTimer.resetTimer();
        //[/UserButtonCode_textButtonReset]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void ActivityTimerAudioProcessorEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderActiveSustain.get())
    {
        //[UserSliderCode_sliderActiveSustain] -- add your slider handling code here..
        const double sliderValue = sliderThatWasMoved->getValue();
        *activityTimer.activeSustain = juce::roundToInt(sliderValue);
        //[/UserSliderCode_sliderActiveSustain]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
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
                 constructorParams="ActivityTimerAudioProcessor&amp; p, ActivityTimer&amp; t"
                 variableInitialisers="AudioProcessorEditor (&amp;p), audioProcessor (p), activityTimer(t)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="625" initialHeight="260">
  <BACKGROUND backgroundColour="ff2c3333">
    <ROUNDRECT pos="120 72 72 100" cornerSize="10.0" fill="solid: ffe7f6f2"
               hasStroke="0"/>
    <ROUNDRECT pos="208 105 10 10" cornerSize="2.0" fill="solid: ffa5c9ca" hasStroke="0"/>
    <ROUNDRECT pos="208 137 10 10" cornerSize="2.0" fill="solid: ffa5c9ca" hasStroke="0"/>
    <ROUNDRECT pos="232 72 72 100" cornerSize="10.0" fill="solid: ffe7f6f2"
               hasStroke="0"/>
    <ROUNDRECT pos="320 72 72 100" cornerSize="10.0" fill="solid: ffe7f6f2"
               hasStroke="0"/>
    <ROUNDRECT pos="432 72 72 100" cornerSize="10.0" fill="solid: ffe7f6f2"
               hasStroke="0"/>
    <ROUNDRECT pos="520 72 72 100" cornerSize="10.0" fill="solid: ffe7f6f2"
               hasStroke="0"/>
    <ROUNDRECT pos="408 105 10 10" cornerSize="2.0" fill="solid: ffa5c9ca" hasStroke="0"/>
    <ROUNDRECT pos="408 137 10 10" cornerSize="2.0" fill="solid: ffa5c9ca" hasStroke="0"/>
    <ROUNDRECT pos="32 72 72 100" cornerSize="10.0" fill="solid: ffe7f6f2" hasStroke="0"/>
    <TEXT pos="23 205 127 30" fill="solid: ffe7f6f2" hasStroke="0" text="ActivateSustain:"
          fontname="Default font" fontsize="16.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <TEXTBUTTON name="textButtonReset" id="d22744b80c4e49fb" memberName="textButtonReset"
              virtualName="" explicitFocusOrder="0" pos="32 16 72 24" bgColOff="ff395b64"
              textCol="ffe7f6f2" textColOn="ffe7f6f2" buttonText="Reset" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <GENERICCOMPONENT name="secondsViewer" id="90009543150fc52b" memberName="secondsViewer"
                    virtualName="" explicitFocusOrder="0" pos="432 72 160 100" class="TimeViewer"
                    params="activityTimer.getSeconds(), MAX_SECONDS"/>
  <GENERICCOMPONENT name="minutesViewer" id="ebd403bb1fedd8ca" memberName="minutesViewer"
                    virtualName="" explicitFocusOrder="0" pos="232 72 160 100" class="TimeViewer"
                    params="activityTimer.getMinutes(), MAX_SECONDS"/>
  <GENERICCOMPONENT name="hoursViewer" id="b4e4b2945914687a" memberName="hoursViewer"
                    virtualName="" explicitFocusOrder="0" pos="32 72 160 100" class="TimeViewer"
                    params="activityTimer.getHours(), MAX_SECONDS"/>
  <SLIDER name="sliderActiveSustain" id="bd4a151633c1aa7e" memberName="sliderActiveSustain"
          virtualName="" explicitFocusOrder="0" pos="152 200 150 40" tooltip="The duration(seconds) that timer remains active when a signal is received"
          bkgcol="ff395b64" thumbcol="ffa5c9ca" textboxhighlight="66a5c9ca"
          textboxoutline="ffe7f6f2" min="0.0" max="600.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="0.5" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

