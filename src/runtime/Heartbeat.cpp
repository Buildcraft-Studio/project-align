#include <iostream>
#include <thread>
#include <atomic>
#include "Heartbeat.hpp"
#include "Wait.h"  // Include Wait utility
#include "TickSpeed.h"

// Shared Game State
std::atomic<bool> running(true);
float objectPosition = 0.0f;  // Example shared variable

// Instantiate the Heartbeat and TickSpeed modules
Heartbeat hb;
TickSpeed tickSpeed(60);  // Fixed at 60 ticks per second

// Worker Thread: Handles Game Logic (e.g., Physics, AI, etc.)
void gameLogicThread() {
    while (running) {
        tickSpeed.waitForNextTick();  // Ensure game logic runs at fixed TPS

        // Update game logic (for example, physics)
        objectPosition += 0.1f;

        // Trigger heartbeat pulse after game update
        hb.runPulse(true);  // Debug output can be checked here if needed
    }
}

// Main Thread: Handles Rendering (or any other tasks)
void renderLoop() {
    while (running) {
        // Wait for the next pulse to render
        while (!hb.getIsPulse()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Polling delay
        }

        // Render frame (or update visual state)
        std::cout << "Rendering Frame: Object Position = " << objectPosition << std::endl;
    }
}

int main() {
    // Start game logic thread
    std::thread logicThread(gameLogicThread);

    std::cout << "Press Enter to exit...\n";

    // Start render loop (on main thread)
    renderLoop();

    // Stop game logic thread
    running = false;
    logicThread.join();

    std::cout << "Program exited cleanly.\n";
    return 0;
}
