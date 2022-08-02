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

#include "TimeViewer.h"
#include "SignalIndicator.h"
#include "../PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ActivityTimerAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                           public juce::Button::Listener,
                                           public juce::Slider::Listener
{
public:
    //==============================================================================
    ActivityTimerAudioProcessorEditor (ActivityTimerAudioProcessor& p);
    ~ActivityTimerAudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ActivityTimerAudioProcessor& audioProcessor;
    ActivityTimer* activityTimer;

    juce::TooltipWindow tooltipWindow { this, 500 };
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> textButtonReset;
    std::unique_ptr<TimeViewer> secondsViewer;
    std::unique_ptr<TimeViewer> minutesViewer;
    std::unique_ptr<TimeViewer> hoursViewer;
    std::unique_ptr<juce::Slider> sliderActiveSustain;
    std::unique_ptr<SignalIndicator> signalIndicator;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ActivityTimerAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

