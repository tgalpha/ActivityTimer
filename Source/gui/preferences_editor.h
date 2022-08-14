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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "../activity_timer.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PreferencesEditor  : public juce::Component,
                           public juce::Slider::Listener
{
public:
    //==============================================================================
    PreferencesEditor (ActivityTimer* t, SerializableParameters* s);
    ~PreferencesEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ActivityTimer* activityTimer;
    SerializableParameters* serializableParameters;

    juce::TooltipWindow tooltipWindow { this, 500 };
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> sliderActiveSustain;
    std::unique_ptr<juce::Label> labelActivitySustain;
    std::unique_ptr<juce::Label> labelSensitivity;
    std::unique_ptr<juce::Slider> sliderSensitivity;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PreferencesEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

