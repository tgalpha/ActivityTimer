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

#include "preferences_editor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PreferencesEditor::PreferencesEditor (ActivityTimer* t, SerializableParameters* s)
{
    //[Constructor_pre] You can add your own custom stuff here..
    activityTimer = t;
    serializableParameters = s;
    //[/Constructor_pre]

    sliderActiveSustain.reset (new juce::Slider ("sliderActiveSustain"));
    addAndMakeVisible (sliderActiveSustain.get());
    sliderActiveSustain->setTooltip (TRANS("ActivateSustain: The duration(seconds) that timer remains active when a signal is received"));
    sliderActiveSustain->setRange (0, 60, 1);
    sliderActiveSustain->setSliderStyle (juce::Slider::LinearHorizontal);
    sliderActiveSustain->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 30, 20);
    sliderActiveSustain->addListener (this);
    sliderActiveSustain->setSkewFactor (0.5);

    sliderActiveSustain->setBounds (128, 16, 160, 24);

    labelActivitySustain.reset (new juce::Label ("labelActivitySustain",
                                                 TRANS("ActivitySustain:")));
    addAndMakeVisible (labelActivitySustain.get());
    labelActivitySustain->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    labelActivitySustain->setJustificationType (juce::Justification::centredLeft);
    labelActivitySustain->setEditable (false, false, false);
    labelActivitySustain->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelActivitySustain->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelActivitySustain->setBounds (8, 16, 111, 24);

    labelSensitivity.reset (new juce::Label ("labelSensitivity",
                                             TRANS("Sensitivity:")));
    addAndMakeVisible (labelSensitivity.get());
    labelSensitivity->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    labelSensitivity->setJustificationType (juce::Justification::centredLeft);
    labelSensitivity->setEditable (false, false, false);
    labelSensitivity->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelSensitivity->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelSensitivity->setBounds (8, 56, 111, 24);

    sliderSensitivity.reset (new juce::Slider ("sliderSensitivity"));
    addAndMakeVisible (sliderSensitivity.get());
    sliderSensitivity->setRange (1, 5, 1);
    sliderSensitivity->setSliderStyle (juce::Slider::LinearHorizontal);
    sliderSensitivity->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 30, 20);
    sliderSensitivity->addListener (this);

    sliderSensitivity->setBounds (128, 56, 160, 24);


    //[UserPreSize]
    sliderActiveSustain->setValue (serializableParameters->activeSustain->get());
    sliderSensitivity->setValue (serializableParameters->sensitivity->get());
    //[/UserPreSize]

    setSize (300, 96);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PreferencesEditor::~PreferencesEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderActiveSustain = nullptr;
    labelActivitySustain = nullptr;
    labelSensitivity = nullptr;
    sliderSensitivity = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PreferencesEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PreferencesEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PreferencesEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderActiveSustain.get())
    {
        //[UserSliderCode_sliderActiveSustain] -- add your slider handling code here..
        const double sliderValue = sliderThatWasMoved->getValue();
        *(serializableParameters->activeSustain) = juce::roundToInt (sliderValue);
        activityTimer->refreshExpirePercentage();
        //[/UserSliderCode_sliderActiveSustain]
    }
    else if (sliderThatWasMoved == sliderSensitivity.get())
    {
        //[UserSliderCode_sliderSensitivity] -- add your slider handling code here..
        const double sliderValue = sliderThatWasMoved->getValue();
        *(serializableParameters->sensitivity) = juce::roundToInt (sliderValue);
        //[/UserSliderCode_sliderSensitivity]
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

<JUCER_COMPONENT documentType="Component" className="PreferencesEditor" componentName=""
                 parentClasses="public juce::Component" constructorParams="ActivityTimer* t, SerializableParameters* s"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="300" initialHeight="96">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="sliderActiveSustain" id="bd4a151633c1aa7e" memberName="sliderActiveSustain"
          virtualName="" explicitFocusOrder="0" pos="128 16 160 24" tooltip="ActivateSustain: The duration(seconds) that timer remains active when a signal is received"
          min="0.0" max="60.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="20" skewFactor="0.5"
          needsCallback="1"/>
  <LABEL name="labelActivitySustain" id="1fe09e03243ac8d2" memberName="labelActivitySustain"
         virtualName="" explicitFocusOrder="0" pos="8 16 111 24" edTextCol="ff000000"
         edBkgCol="0" labelText="ActivitySustain:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="labelSensitivity" id="8399fc95c59bf63f" memberName="labelSensitivity"
         virtualName="" explicitFocusOrder="0" pos="8 56 111 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sensitivity:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="sliderSensitivity" id="65c02fb32e5bd71a" memberName="sliderSensitivity"
          virtualName="" explicitFocusOrder="0" pos="128 56 160 24" min="1.0"
          max="5.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="30" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

