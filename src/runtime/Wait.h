#ifndef WAIT_H
#define WAIT_H

#include <thread>
#include <chrono>

// Wait for a specified number of seconds
inline void Wait(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

// Wait for a specified number of milliseconds
inline void milliWait(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

#endif // WAIT_H
