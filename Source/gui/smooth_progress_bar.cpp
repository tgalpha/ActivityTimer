/*
Replace the implementation of visibilityChanged and timerCallback in juce_ProgressBar.cpp to get a smooth ProgressBar
*/

#include <JuceHeader.h>


namespace juce
{
    void ProgressBar::setRefreshRate (int newRefreshRate)
    {
        refreshRate = newRefreshRate;
        if (isTimerRunning())
        {
            stopTimer();
            startTimerHz (refreshRate);
        } 
    }

    void ProgressBar::setResponseSpeed (float newResponseSpeed)
    {
        responseSpeed = newResponseSpeed;
    }
    
    void ProgressBar::visibilityChanged ()
    {
        if (isVisible())
            startTimerHz (refreshRate);
        else
            stopTimer();
    }

    void ProgressBar::timerCallback ()
    {
        double newProgress = progress;

        const uint32 now = Time::getMillisecondCounter();
        lastCallbackTime = now;

        if (currentValue != newProgress
            || newProgress < 0 || newProgress >= 1.0
            || currentMessage != displayedMessage)
        {
            if (std::abs (newProgress - progress) < responseSpeed
                && newProgress >= 0 && newProgress <= 1.0
                && currentValue >= 0 && currentValue <= 1.0)
            {
                newProgress = currentValue + (newProgress - currentValue) * 0.1;
            }

            currentValue = newProgress;
            currentMessage = displayedMessage;
            repaint();

            if (auto* handler = getAccessibilityHandler())
                handler->notifyAccessibilityEvent (AccessibilityEvent::valueChanged);
        }
    }
} // namespace juce
