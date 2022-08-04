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

#include "plugin_editor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ActivityTimerAudioProcessorEditor::ActivityTimerAudioProcessorEditor (ActivityTimerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    activityTimer = audioProcessor.getTimer();
    myLookAndFeel.reset (new theme::MyLookAndFeel);
    juce::LookAndFeel::setDefaultLookAndFeel(myLookAndFeel.get());
    //[/Constructor_pre]

    expireTimeProgressBar.reset (new juce::ProgressBar (activityTimer->expirePercentage));
    addAndMakeVisible (expireTimeProgressBar.get());
    expireTimeProgressBar->setName ("expireTimeProgressBar");

    expireTimeProgressBar->setBounds (0, 248, 624, 24);

    secondsViewer.reset (new TimeViewer (activityTimer->getSeconds(), MAX_SECONDS));
    addAndMakeVisible (secondsViewer.get());
    secondsViewer->setName ("secondsViewer");

    secondsViewer->setBounds (432, 72, 160, 100);

    minutesViewer.reset (new TimeViewer (activityTimer->getMinutes(), MAX_SECONDS));
    addAndMakeVisible (minutesViewer.get());
    minutesViewer->setName ("minutesViewer");

    minutesViewer->setBounds (232, 72, 160, 100);

    hoursViewer.reset (new TimeViewer (activityTimer->getHours(), MAX_SECONDS));
    addAndMakeVisible (hoursViewer.get());
    hoursViewer->setName ("hoursViewer");

    hoursViewer->setBounds (32, 72, 160, 100);

    sliderActiveSustain.reset (new juce::Slider ("sliderActiveSustain"));
    addAndMakeVisible (sliderActiveSustain.get());
    sliderActiveSustain->setTooltip (TRANS("ActivateSustain: The duration(seconds) that timer remains active when a signal is received"));
    sliderActiveSustain->setRange (0, 60, 1);
    sliderActiveSustain->setSliderStyle (juce::Slider::LinearHorizontal);
    sliderActiveSustain->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 30, 20);
    sliderActiveSustain->addListener (this);
    sliderActiveSustain->setSkewFactor (0.5);

    sliderActiveSustain->setBounds (32, 200, 160, 24);

    signalIndicator.reset (new SignalIndicator());
    addAndMakeVisible (signalIndicator.get());
    signalIndicator->setName ("signalIndicator");

    signalIndicator->setBounds (544, 24, 24, 24);

    shapeButtonReset.reset (new juce::ShapeButton ("shapeButtonReset", myLookAndFeel->colourTheme.primaryLight, myLookAndFeel->colourTheme.primaryAccent, myLookAndFeel->colourTheme.primary));
    addAndMakeVisible (shapeButtonReset.get());
    shapeButtonReset->setName ("shapeButtonReset");

    shapeButtonReset->setBounds (56, 24, 24, 24);


    //[UserPreSize]
    sliderActiveSustain->setValue (activityTimer->activeSustain->get());
    activityTimer->addViewers (hoursViewer.get(), minutesViewer.get(), secondsViewer.get());
    audioProcessor.addSignalIndicator (signalIndicator.get());
    expireTimeProgressBar->setPercentageDisplay (false);

    shapeButtonReset->setTooltip ("Reset timer");
    shapeButtonReset->addListener (this);
    shapeButtonReset->setShape (myLookAndFeel->getResetButtonPath(), false, true, false);
    //[/UserPreSize]

    setSize (625, 260);


    //[Constructor] You can add your own custom stuff here..

    //[/Constructor]
}

ActivityTimerAudioProcessorEditor::~ActivityTimerAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    activityTimer->removeViewers (hoursViewer.get(), minutesViewer.get(), secondsViewer.get());
    audioProcessor.removeSignalIndicator (signalIndicator.get());
    myLookAndFeel = nullptr;
    //[/Destructor_pre]

    expireTimeProgressBar = nullptr;
    secondsViewer = nullptr;
    minutesViewer = nullptr;
    hoursViewer = nullptr;
    sliderActiveSustain = nullptr;
    signalIndicator = nullptr;
    shapeButtonReset = nullptr;


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
        int x = 0, y = 0, width = 625, height = 260;
        juce::Colour fillColour1 = juce::Colour (0x4f395b64), fillColour2 = juce::Colour (0xff2c3333);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             312.0f - 0.0f + x,
                                             130.0f - 0.0f + y,
                                             fillColour2,
                                             40.0f - 0.0f + x,
                                             static_cast<float> (-40) - 0.0f + y,
                                             true));
        g.fillRect (x, y, width, height);
    }

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

void ActivityTimerAudioProcessorEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderActiveSustain.get())
    {
        //[UserSliderCode_sliderActiveSustain] -- add your slider handling code here..
        const double sliderValue = sliderThatWasMoved->getValue();
        *(activityTimer->activeSustain) = juce::roundToInt (sliderValue);
        activityTimer->refreshExpirePercentage();
        //[/UserSliderCode_sliderActiveSustain]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ActivityTimerAudioProcessorEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == shapeButtonReset.get())
    {
        juce::AlertWindow::showOkCancelBox (juce::MessageBoxIconType::NoIcon, "Reset timer",
                                            "This operation cannot be undone, continue?",
                                            {}, {}, {},
                                            juce::ModalCallbackFunction::create ([this] (bool result)
                                            {
                                                if (result)
                                                {
                                                    activityTimer->resetTimer();
                                                }
                                            }));
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ActivityTimerAudioProcessorEditor"
                 componentName="" parentClasses="public juce::AudioProcessorEditor, public juce::Button::Listener"
                 constructorParams="ActivityTimerAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), audioProcessor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="625" initialHeight="260">
  <BACKGROUND backgroundColour="ff2c3333">
    <RECT pos="0 0 625 260" fill=" radial: 312.5 130, 40 -40, 0=4f395b64, 1=ff2c3333"
          hasStroke="0"/>
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
  </BACKGROUND>
  <GENERICCOMPONENT name="expireTimeProgressBar" id="5b9b34c3e2d42153" memberName="expireTimeProgressBar"
                    virtualName="" explicitFocusOrder="0" pos="0 248 624 24" class="juce::ProgressBar"
                    params="activityTimer-&gt;expirePercentage"/>
  <GENERICCOMPONENT name="secondsViewer" id="90009543150fc52b" memberName="secondsViewer"
                    virtualName="" explicitFocusOrder="0" pos="432 72 160 100" class="TimeViewer"
                    params="activityTimer-&gt;getSeconds(), MAX_SECONDS"/>
  <GENERICCOMPONENT name="minutesViewer" id="ebd403bb1fedd8ca" memberName="minutesViewer"
                    virtualName="" explicitFocusOrder="0" pos="232 72 160 100" class="TimeViewer"
                    params="activityTimer-&gt;getMinutes(), MAX_SECONDS"/>
  <GENERICCOMPONENT name="hoursViewer" id="b4e4b2945914687a" memberName="hoursViewer"
                    virtualName="" explicitFocusOrder="0" pos="32 72 160 100" class="TimeViewer"
                    params="activityTimer-&gt;getHours(), MAX_SECONDS"/>
  <SLIDER name="sliderActiveSustain" id="bd4a151633c1aa7e" memberName="sliderActiveSustain"
          virtualName="" explicitFocusOrder="0" pos="32 200 160 24" tooltip="ActivateSustain: The duration(seconds) that timer remains active when a signal is received"
          min="0.0" max="60.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="20" skewFactor="0.5"
          needsCallback="1"/>
  <GENERICCOMPONENT name="signalIndicator" id="6b00bd3e186e3c3a" memberName="signalIndicator"
                    virtualName="" explicitFocusOrder="0" pos="544 24 24 24" class="SignalIndicator"
                    params=""/>
  <GENERICCOMPONENT name="shapeButtonReset" id="cbf3a07047fff8e8" memberName="shapeButtonReset"
                    virtualName="" explicitFocusOrder="0" pos="56 24 24 24" class="juce::ShapeButton"
                    params="&quot;shapeButtonReset&quot;, myLookAndFeel-&gt;colourTheme.primaryLight, myLookAndFeel-&gt;colourTheme.primaryAccent, myLookAndFeel-&gt;colourTheme.primary"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

