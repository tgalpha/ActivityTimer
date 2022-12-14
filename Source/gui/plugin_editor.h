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

#include "my_look_and_feel.h"
#include "time_viewer.h"
#include "signal_indicator.h"
#include "../plugin_processor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ActivityTimerAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                           public juce::Button::Listener
{
public:
    //==============================================================================
    ActivityTimerAudioProcessorEditor (ActivityTimerAudioProcessor& p);
    ~ActivityTimerAudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ActivityTimerAudioProcessor& audioProcessor;
    ActivityTimer* activityTimer;

    juce::TooltipWindow tooltipWindow { this, 500 };

    std::unique_ptr<theme::MyLookAndFeel> myLookAndFeel;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ProgressBar> expireTimeProgressBar;
    std::unique_ptr<TimeViewer> secondsViewer;
    std::unique_ptr<TimeViewer> minutesViewer;
    std::unique_ptr<TimeViewer> hoursViewer;
    std::unique_ptr<SignalIndicator> signalIndicator;
    std::unique_ptr<juce::ShapeButton> shapeButtonReset;
    std::unique_ptr<juce::ShapeButton> shapeButtonSettings;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ActivityTimerAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

