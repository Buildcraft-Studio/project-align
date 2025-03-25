#include <iostream>
#include <thread>
#include <atomic>
#include <csignal>  // For signal handling
#include "runtime/Heartbeat.hpp"
#include "runtime/TickSpeed.h"
#include "runtime/Wait.h"

// Shared Game State
std::atomic<bool> running(true);
float objectPosition = 0.0f;  // Example shared variable

// Instantiate the Heartbeat and TickSpeed modules
Heartbeat hb;
TickSpeed tickSpeed(60);  // Fixed at 60 ticks per second

// Signal handler for SIGINT (Ctrl+C)
void signalHandler(int signal) {
    std::cout << "\nCaught signal " << signal << ", exiting...\n";
    running.store(false, std::memory_order_relaxed);  // Set running to false to stop threads
}

// Worker Thread: Handles Game Logic (e.g., Physics, AI, etc.)
void gameLogicThread() {
    while (running.load(std::memory_order_relaxed)) {
        tickSpeed.waitForNextTick();  // Ensure game logic runs at fixed TPS

        // Update game logic (for example, physics)
        objectPosition += 0.1f;

        // Trigger heartbeat pulse after game update
        hb.runPulse(true);  // Debug output can be checked here if needed
    }
}

// Main Thread: Handles Rendering (or any other tasks)
void renderLoop() {
    while (running.load(std::memory_order_relaxed)) {
        // Wait for the next pulse to render
        while (!hb.getIsPulse() && running.load(std::memory_order_relaxed)) {
            milliWait(1);  // Polling delay using Wait utility
        }

        // Render frame (or update visual state)
        if (running.load(std::memory_order_relaxed)) {
            std::cout << "Rendering Frame: Object Position = " << objectPosition << std::endl;
        }
    }
}

int main() {
    // Register signal handler for SIGINT (Ctrl+C)
    std::signal(SIGINT, signalHandler);

    // Start game logic thread
    std::thread logicThread(gameLogicThread);

    std::cout << "Press Ctrl+C to exit...\n";

    // Start render loop (on main thread)
    renderLoop();

    // Stop game logic thread after the render loop ends
    running.store(false, std::memory_order_relaxed);  // Ensure logic thread stops
    logicThread.join();  // Ensure the game logic thread exits cleanly

    std::cout << "Program exited cleanly.\n";
    return 0;
}
