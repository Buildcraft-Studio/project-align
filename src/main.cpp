#include <csignal> // For C++, use <signal.h> for C
#include <iostream>

#include <vector>
#include <string>
#include "runtime/exitCode.hpp"
#include "runtime/PhysicRuntime.hpp"
#include "physic/Collision.hpp" // <-- Add this include
#include "runtime/Heartbeat.hpp"
#include "runtime/Wait.h"

int shutdownSignal = 0;
// Signal handler function
void my_signal_handler(int sig) {
    std::cout << "Caught signal " << sig << std::endl;
    // Perform cleanup or exit gracefully
    shutdownSignal = sig;
    exit(sig); 
}
int main()
{
    try {
       Heartbeat heartbeat;
        // Register the signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, my_signal_handler);
    std::cout << "Program running. Press Ctrl+C to trigger signal." << std::endl;

       while (shutdownSignal == 0) {
           heartbeat.runPulse(true);
           std::cout << heartbeat.getDebugOut() << std::endl;
           Wait(5); // Wait for 5 second before next pulse
       }
    } catch (const std::exception& e) {
        Runtime::handleException(e);
    } catch (...) {
        Runtime::handleUnknownException();
    }
    return 0;
}
