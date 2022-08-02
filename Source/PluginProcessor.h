/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "ActivityTimer.h"
#include "gui/SignalIndicator.h"

//==============================================================================
/**
*/
class ActivityTimerAudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    ActivityTimerAudioProcessor();
    ~ActivityTimerAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    void addSignalIndicator (SignalIndicator* signalIndicator) const;
    void removeSignalIndicator (SignalIndicator* signalIndicator) const;

    ActivityTimer* getTimer () const;

private:
    void checkIfAudioBufferHasSignal(const juce::AudioBuffer<float>& buffer) const;

    static bool floatIsNearlyZero(float floatNum);
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ActivityTimerAudioProcessor)
    std::unique_ptr<ActivityTimer> activityTimer;
    std::unique_ptr<juce::AudioParameterBool> silence;
};
