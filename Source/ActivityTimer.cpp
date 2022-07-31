/*
  ==============================================================================

    ActivityTimer.cpp
    Created: 31 Jul 2022 3:43:40pm
    Author:  tgalpha

  ==============================================================================
*/

#include "ActivityTimer.h"

ActivityTimer::ActivityTimer() : Timer()
{
    hour = new juce::AudioParameterInt(0, "Hour", 0, 999, 0);
    minute = new juce::AudioParameterInt(0, "Minute", 0, 60, 0);
    second = new juce::AudioParameterInt(0, "Second", 0, 60, 0);
    activeSustain = new juce::AudioParameterInt(0, "ActiveSustain", 0, 600, 0);
}

ActivityTimer::~ActivityTimer()
{
    stopTimer();
    delete hour;
    delete minute;
    delete second;
    delete activeSustain;
}

void ActivityTimer::timerCallback()
{
    if (!isActive()) return;

    increase(second);
    activeExpireTime--;

    if (second->get() < 60) return;

    increase(minute);
    *second = 0;

    if (minute->get() < 60) return;

    increase(hour);
    *minute = 0;
}

void ActivityTimer::startTimer()
{
    Timer::startTimer(intervalInMilliseconds);
}

int ActivityTimer::getHour() const
{
    return hour->get();
}

int ActivityTimer::getMinute() const
{
    return minute->get();
}

int ActivityTimer::getSecond() const
{
    return second->get();
}

void ActivityTimer::setTimerState(int hourValue, int minuteValue, int secondValue, int activeSustainValue) const
{
    *hour = hourValue;
    *minute = minuteValue;
    *second = secondValue;
    *activeSustain = activeSustainValue;
}

void ActivityTimer::activate()
{
    activeExpireTime = activeSustain->get();
}

void ActivityTimer::resetTimer()
{
    stopTimer();
    *hour = 0;
    *minute = 0;
    *second = 0;
    startTimer();
}

bool ActivityTimer::isActive() const
{
    return activeExpireTime > 0;
}

void ActivityTimer::increase(juce::AudioParameterInt* targetMember)
{
    *targetMember = targetMember->get() + 1;
}
