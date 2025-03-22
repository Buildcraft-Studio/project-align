#ifndef TICK_SPEED_H
#define TICK_SPEED_H

#include <chrono>
#include <thread>
#include "Wait.h"  // Include the Wait utility

class TickSpeed {
private:
    int tps;  // Ticks per second
    std::chrono::milliseconds tickDuration;

public:
    TickSpeed(int tps) : tps(tps), tickDuration(1000 / tps) {}

    // Waits to ensure fixed tick rate
    void waitForNextTick() {
        auto startTime = std::chrono::high_resolution_clock::now();
        
        // Wait until next tick
        auto elapsedTime = std::chrono::high_resolution_clock::now() - startTime;
        int remainingTime = tickDuration.count() - std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime).count();
        if (remainingTime > 0) {
            milliWait(remainingTime);  // Using Wait utility to handle sleep
        }
    }
};

#endif // TICK_SPEED_H
