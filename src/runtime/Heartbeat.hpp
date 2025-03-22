#ifndef HEARTBEAT_HPP
#define HEARTBEAT_HPP

#include <string>
#include <atomic>

class Heartbeat {
private:
    std::atomic<bool> isPulse;
    std::string debugOut;

public:
    Heartbeat() : isPulse(false) {}

    void runPulse(bool debug) {
        if (!isPulse.load()) {
            isPulse.store(true);  // Lock the pulse

            // Debugging output
            if (debug) {
                debugOut = "Pulse triggered.";
            }

            // Set pulse for the next update
            isPulse.store(false);  // Unlock pulse
        }
    }

    bool getIsPulse() const {
        return isPulse.load();
    }

    std::string getDebugOut() const {
        return debugOut;
    }
};

#endif // HEARTBEAT_HPP
