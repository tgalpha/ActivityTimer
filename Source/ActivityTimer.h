/*
  ==============================================================================

    ActivityTimer.h
    Created: 31 Jul 2022 3:43:40pm
    Author:  tgalpha

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

#include "gui/TimeViewer.h"


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

    void addViewers(TimeViewer* hoursViewer, TimeViewer* minutesViewer, TimeViewer* secondsViewer) const;
    void removeViewers(TimeViewer* hoursViewer, TimeViewer* minutesViewer, TimeViewer* secondsViewer) const;

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    bool isActive() const;

    juce::AudioParameterInt* activeSustain;
private:
    static void increase(juce::AudioParameterInt* targetMember);
    void debugPrintTime() const;

    const int intervalInMilliseconds = 1000;

    juce::AudioParameterInt* hours;
    juce::AudioParameterInt* minutes;
    juce::AudioParameterInt* seconds;

    // in second
    unsigned int activeExpireTime = 0;
};
