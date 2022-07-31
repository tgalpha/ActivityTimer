/*
  ==============================================================================

    ActivityTimer.h
    Created: 31 Jul 2022 3:43:40pm
    Author:  tgalpha

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


class ActivityTimer : public juce::Timer
{
public:
    ActivityTimer();
    ~ActivityTimer() override;

    void timerCallback() override;
    void startTimer();
    void setTimerState(int hourValue, int minuteValue, int secondValue, int activeSustainValue) const;
    void activate();
    void resetTimer();

    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    bool isActive() const;

    juce::AudioParameterInt* activeSustain;
private:
    static void increase(juce::AudioParameterInt* targetMember);

    const int intervalInMilliseconds = 1000;

    juce::AudioParameterInt* hour;
    juce::AudioParameterInt* minute;
    juce::AudioParameterInt* second;

    // in second
    unsigned int activeExpireTime = 0;
};
