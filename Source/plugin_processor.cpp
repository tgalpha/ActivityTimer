/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "plugin_processor.h"
#include "gui/plugin_editor.h"

//==============================================================================
ActivityTimerAudioProcessor::ActivityTimerAudioProcessor ()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor (BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
        .withInput ("Input", juce::AudioChannelSet::stereo(), true)
#endif
        .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
#endif
    )
#endif
{
    serializableParameters.reset (new SerializableParameters());
    activityTimer.reset(new ActivityTimer(serializableParameters.get()));
}

ActivityTimerAudioProcessor::~ActivityTimerAudioProcessor ()
{
    serializableParameters = nullptr;
    activityTimer = nullptr;
}

//==============================================================================
const juce::String ActivityTimerAudioProcessor::getName () const
{
    return JucePlugin_Name;
}

bool ActivityTimerAudioProcessor::acceptsMidi () const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool ActivityTimerAudioProcessor::producesMidi () const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool ActivityTimerAudioProcessor::isMidiEffect () const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double ActivityTimerAudioProcessor::getTailLengthSeconds () const
{
    return 0.0;
}

int ActivityTimerAudioProcessor::getNumPrograms ()
{
    return 1; // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int ActivityTimerAudioProcessor::getCurrentProgram ()
{
    return 0;
}

void ActivityTimerAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String ActivityTimerAudioProcessor::getProgramName (int index)
{
    return {};
}

void ActivityTimerAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void ActivityTimerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void ActivityTimerAudioProcessor::releaseResources ()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ActivityTimerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
#else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
#endif

    return true;
#endif
}
#endif

void ActivityTimerAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    const auto totalNumInputChannels = getTotalNumInputChannels();
    const auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    checkIfAudioBufferHasSignal (buffer);
}

//==============================================================================
bool ActivityTimerAudioProcessor::hasEditor () const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* ActivityTimerAudioProcessor::createEditor ()
{
    return new ActivityTimerAudioProcessorEditor (*this);
}

//==============================================================================
void ActivityTimerAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    serializableParameters->saveState (destData);
}

void ActivityTimerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    serializableParameters->loadState (data, sizeInBytes);
    activityTimer->startTimer();
}

SerializableParameters* ActivityTimerAudioProcessor::getSerializableParameters () const
{
    return serializableParameters.get();
}


ActivityTimer* ActivityTimerAudioProcessor::getTimer() const
{
    return activityTimer.get();
}

void ActivityTimerAudioProcessor::checkIfAudioBufferHasSignal (const juce::AudioBuffer<float>& buffer) const
{
    const int numSamples = buffer.getNumSamples();
    float magnitude = buffer.getMagnitude (0, numSamples);
    magnitude = magnitude * serializableParameters->sensitivity->get();
    
    if (floatIsNearlyZero (magnitude))
    {
        activityTimer->setSignalState(false);
        return;
    }
    activityTimer->setSignalState(true);
}

bool ActivityTimerAudioProcessor::floatIsNearlyZero (const float floatNum)
{
    constexpr float epsilon = 0.01;
    return std::abs(floatNum) <= epsilon;
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter ()
{
    return new ActivityTimerAudioProcessor();
}
