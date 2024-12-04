//# Example entry point src/main.cpp
#include "physics/physics.h"
#include "audio/audio.h"
#include "utils/utils.h"
//#include <furnace/furnace.h>

#include <iostream>
#include <iomanip> // For formatting

int main() {
    std::string user_input;

    // Create a menu
    std::cout << "=====================================\n";
    std::cout << "           Welcome to My App         \n";
    std::cout << "=====================================\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. Settings\n";
    std::cout << "3. Exit\n";
    std::cout << "=====================================\n";
    std::cout << "Enter your choice: ";

    std::cin >> user_input;

    if (user_input == "1") {
        std::cout << "Starting the game...\n";
    } else if (user_input == "2") {
        std::cout << "Opening settings...\n";
    } else if (user_input == "3") {
        std::cout << "Exiting the program. Goodbye!\n";
    } else {
        std::cout << "Invalid choice! Please try again.\n";
    }

    return 0;
}
