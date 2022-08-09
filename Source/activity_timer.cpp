/*
  ==============================================================================

    ActivityTimer.cpp
    Created: 31 Jul 2022 3:43:40pm
    Author:  tgalpha

  ==============================================================================
*/

#include "activity_timer.h"

#include "Constants.h"

ActivityTimer::ActivityTimer(SerializableParameters* s) : Timer()
{
    serializableParameters = s;
    hasSignal.reset(new juce::AudioParameterBool(0, "hasSignal", false));
    startTimer();
}

ActivityTimer::~ActivityTimer()
{
    stopTimer();
    hasSignal = nullptr;
}

void ActivityTimer::timerCallback()
{
    if (!isActive()) return;
    debugPrintTime();

    increase(serializableParameters->seconds.get());
    if (!hasSignal->get())
    {
        activeExpireTime--;
        refreshExpirePercentage();
    }

    if (serializableParameters->seconds->get() < MAX_SECONDS) return;

    increase(serializableParameters->minutes.get());
    *serializableParameters->seconds = 0;

    if (serializableParameters->minutes->get() < MAX_MINUTES) return;

    increase(serializableParameters->hours.get());
    *serializableParameters->minutes = 0;
}

void ActivityTimer::startTimer()
{
    Timer::startTimer(intervalInMilliseconds);
}

int ActivityTimer::getHours() const
{
    return serializableParameters->hours->get();
}

int ActivityTimer::getMinutes() const
{
    return serializableParameters->minutes->get();
}

int ActivityTimer::getSeconds() const
{
    return serializableParameters->seconds->get();
}

void ActivityTimer::activate()
{
    activeExpireTime = serializableParameters->activeSustain->get();
    refreshExpirePercentage();
}

void ActivityTimer::resetTimer()
{
    stopTimer();
    *serializableParameters->hours = 0;
    *serializableParameters->minutes = 0;
    *serializableParameters->seconds = 0;
    startTimer();
}

void ActivityTimer::refreshExpirePercentage ()
{
    activeExpireTime = std::min (serializableParameters->activeSustain->get(), activeExpireTime);
    if (activeExpireTime == 0)
    {
        expirePercentage = 0.0;
        return;
    }
    
    expirePercentage = static_cast<double> (activeExpireTime) / serializableParameters->activeSustain->get();
}

void ActivityTimer::setSignalState (bool newValue)
{
    *hasSignal = newValue;
    if (newValue)
    {
        activate();
    }
}

void ActivityTimer::addViewers(TimeViewer* hoursViewer, TimeViewer* minutesViewer,
                               TimeViewer* secondsViewer) const
{
    serializableParameters->hours->addListener(hoursViewer);
    serializableParameters->minutes->addListener(minutesViewer);
    serializableParameters->seconds->addListener(secondsViewer);
}

void ActivityTimer::removeViewers(TimeViewer* hoursViewer, TimeViewer* minutesViewer,
    TimeViewer* secondsViewer) const
{
    serializableParameters->hours->removeListener(hoursViewer);
    serializableParameters->minutes->removeListener(minutesViewer);
    serializableParameters->seconds->removeListener(secondsViewer);
}

void ActivityTimer::addSignalIndicator (SignalIndicator* signalIndicator) const
{
    hasSignal->addListener (signalIndicator);
}

void ActivityTimer::removeSignalIndicator (SignalIndicator* signalIndicator) const
{
    hasSignal->removeListener (signalIndicator);
}

bool ActivityTimer::isActive() const
{
    return activeExpireTime > 0;
}

bool ActivityTimer::getSignalState () const
{
    return hasSignal->get();
}

void ActivityTimer::increase(juce::AudioParameterInt* targetMember)
{
    *targetMember = targetMember->get() + 1;
}

void ActivityTimer::debugPrintTime()
{
#ifdef DEBUG
    std::cout << serializableParameters->hours->get() << ':' << serializableParameters->minutes->get() << ':' << serializableParameters->seconds->get() << std::endl;
#endif
}
