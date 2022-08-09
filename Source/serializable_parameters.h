/*
  ==============================================================================

    serializable_parameters.h
    Created: 9 Aug 2022 10:28:32pm
    Author:  tgalpha

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SerializableParameters
{
public:
    SerializableParameters();
    ~SerializableParameters();

    void loadState(const void* data, int sizeInBytes) const;
    void saveState(juce::MemoryBlock& destData) const;
    
    std::unique_ptr<juce::AudioParameterInt> hours;
    std::unique_ptr<juce::AudioParameterInt> minutes;
    std::unique_ptr<juce::AudioParameterInt> seconds;
    
    std::unique_ptr<juce::AudioParameterInt> activeSustain;
    std::unique_ptr<juce::AudioParameterInt> sensitivity;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SerializableParameters)
};
