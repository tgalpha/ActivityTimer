/*
  ==============================================================================

    ActivityTimer.cpp
    Created: 31 Jul 2022 3:43:40pm
    Author:  tgalpha

  ==============================================================================
*/

#include "ActivityTimer.h"

#include "Constants.h"

ActivityTimer::ActivityTimer() : Timer()
{
    hours.reset(new juce::AudioParameterInt(1, "Hour", 0, MAX_HOURS, 0));
    minutes.reset(new juce::AudioParameterInt(2, "Minute", 0, MAX_MINUTES, 0));
    seconds.reset(new juce::AudioParameterInt(3, "Second", 0, MAX_SECONDS, 0));
    activeSustain.reset(new juce::AudioParameterInt(4, "ActiveSustain", 0, MAX_ACTIVE_SUSTAIN, DEFAULT_ACTIVE_SUSTAIN));
    startTimer();
}

ActivityTimer::~ActivityTimer()
{
    stopTimer();
    hours = nullptr;
    minutes = nullptr;
    seconds = nullptr;
    activeSustain = nullptr;
}

void ActivityTimer::timerCallback()
{
    if (!isActive()) return;
    debugPrintTime();

    increase(seconds.get());
    activeExpireTime--;

    if (seconds->get() < MAX_SECONDS) return;

    increase(minutes.get());
    *seconds = 0;

    if (minutes->get() < MAX_MINUTES) return;

    increase(hours.get());
    *minutes = 0;
}

void ActivityTimer::startTimer()
{
    Timer::startTimer(intervalInMilliseconds);
}

int ActivityTimer::getHours() const
{
    return hours->get();
}

int ActivityTimer::getMinutes() const
{
    return minutes->get();
}

int ActivityTimer::getSeconds() const
{
    return seconds->get();
}

void ActivityTimer::setTimerState(int hourValue, int minuteValue, int secondValue, int activeSustainValue) const
{
    *hours = hourValue;
    *minutes = minuteValue;
    *seconds = secondValue;
    *activeSustain = activeSustainValue;
}

void ActivityTimer::activate()
{
    activeExpireTime = activeSustain->get();
}

void ActivityTimer::resetTimer()
{
    stopTimer();
    *hours = 0;
    *minutes = 0;
    *seconds = 0;
    startTimer();
}

void ActivityTimer::addViewers(TimeViewer* hoursViewer, TimeViewer* minutesViewer,
    TimeViewer* secondsViewer) const
{
    hours->addListener(hoursViewer);
    minutes->addListener(minutesViewer);
    seconds->addListener(secondsViewer);
}

void ActivityTimer::removeViewers(TimeViewer* hoursViewer, TimeViewer* minutesViewer,
    TimeViewer* secondsViewer) const
{
    hours->removeListener(hoursViewer);
    minutes->removeListener(minutesViewer);
    seconds->removeListener(secondsViewer);
}

bool ActivityTimer::isActive() const
{
    return activeExpireTime > 0;
}

void ActivityTimer::increase(juce::AudioParameterInt* targetMember)
{
    *targetMember = targetMember->get() + 1;
}

void ActivityTimer::debugPrintTime() const
{
#ifdef DEBUG
    std::cout << hours->get() << ':' << minutes->get() << ':' << seconds->get() << std::endl;
#endif
}
