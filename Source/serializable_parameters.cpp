/*
  ==============================================================================

    serializable_parameters.cpp
    Created: 9 Aug 2022 10:28:32pm
    Author:  tgalpha

  ==============================================================================
*/

#include "serializable_parameters.h"
#include "constants.h"

SerializableParameters::SerializableParameters ()
{
  hours.reset(new juce::AudioParameterInt(1, "Hour", 0, MAX_HOURS, 0));
  minutes.reset(new juce::AudioParameterInt(2, "Minute", 0, MAX_MINUTES, 0));
  seconds.reset(new juce::AudioParameterInt(3, "Second", 0, MAX_SECONDS, 0));
  activeSustain.reset(new juce::AudioParameterInt(4, "ActiveSustain", 0, MAX_ACTIVE_SUSTAIN, DEFAULT_ACTIVE_SUSTAIN));
  sensitivity.reset(new juce::AudioParameterInt(5, "Sensitivity", 0, MAX_SENSITIVITY, DEFAULT_SENSITIVITY));

}

SerializableParameters::~SerializableParameters ()
{
  hours = nullptr;
  minutes = nullptr;
  seconds = nullptr;
  activeSustain = nullptr;
  sensitivity = nullptr;
}

void SerializableParameters::loadState (const void* data, int sizeInBytes) const
{
  juce::MemoryInputStream memoryInputStream (data, sizeInBytes, false);
  *hours = memoryInputStream.readInt();
  *minutes = memoryInputStream.readInt();
  *seconds = memoryInputStream.readInt();
  *activeSustain = memoryInputStream.readInt();
  *sensitivity = memoryInputStream.readInt();
}

void SerializableParameters::saveState (juce::MemoryBlock& destData) const
{
  juce::MemoryOutputStream memoryOutputStream (destData, true);
  memoryOutputStream.writeInt (hours->get());
  memoryOutputStream.writeInt (minutes->get());
  memoryOutputStream.writeInt (seconds->get());
  memoryOutputStream.writeInt (activeSustain->get());
  memoryOutputStream.writeInt (sensitivity->get());
}
