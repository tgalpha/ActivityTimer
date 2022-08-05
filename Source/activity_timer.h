/*
  ==============================================================================

    ActivityTimer.h
    Created: 31 Jul 2022 3:43:40pm
    Author:  tgalpha

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

#include "gui/signal_indicator.h"
#include "gui/time_viewer.h"


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
    void refreshExpirePercentage();
    void setSilenceState(bool isSilence);

    void addViewers(TimeViewer* hoursViewer, TimeViewer* minutesViewer, TimeViewer* secondsViewer) const;
    void removeViewers(TimeViewer* hoursViewer, TimeViewer* minutesViewer, TimeViewer* secondsViewer) const;
    void addSignalIndicator (SignalIndicator* signalIndicator) const;
    void removeSignalIndicator (SignalIndicator* signalIndicator) const;

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    bool isActive() const;

    std::unique_ptr<juce::AudioParameterInt> activeSustain;
    double expirePercentage = 0.0;
private:
    static void increase(juce::AudioParameterInt* targetMember);
    void debugPrintTime();

    const int intervalInMilliseconds = 1000;

    std::unique_ptr<juce::AudioParameterBool> silence;
    std::unique_ptr<juce::AudioParameterInt> hours;
    std::unique_ptr<juce::AudioParameterInt> minutes;
    std::unique_ptr<juce::AudioParameterInt> seconds;

    // in second
    int activeExpireTime = 0;
};
