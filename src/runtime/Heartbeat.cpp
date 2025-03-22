#include "Heartbeat.hpp"
#include <iostream>
#include <thread>

void Heartbeat::runPulse(bool debug) {
    if (!isPulse) {
        isPulse = true;  // Lock the pulse update

        // Debugging output
        if (debug) {
            debugOut = "Pulse value: " + std::to_string(pulse);  // Set debug output
            Heartbeat::setDebugOut(debugOut);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(20)); // Short delay
        pulse += 1;  // Increment pulse
        isPulse = false;  // Unlock pulse update
    }
}

int Heartbeat::getPulse() const {
    return pulse;
}

void Heartbeat::setPulse(int pulse) {
    this->pulse = pulse;
}

bool Heartbeat::getIsPulse() const {
    return isPulse;
}

void Heartbeat::setIsPulse(bool isPulse) {
    this->isPulse = isPulse;
}

std::string Heartbeat::getDebugOut() const {
    return debugOut;
}

void Heartbeat::setDebugOut(const std::string& debugOut) {
    this->debugOut = debugOut;
}
