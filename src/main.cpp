# Example entry point src/main.cpp
#include "physics/physics.h"
#include "audio/audio.h"
#include "utils/utils.h"
#include <furnace/furnace.h>

int main() {

    // Initialize Furnace
    Furnace::init();

    // Example usage of subsystems
    Physics::init();
    Audio::playSound("example.mp3");

    // Main loop
    while (true) {
        // Update subsystems
        Physics::update();
        Audio::update();
    }

    return 0;
}
