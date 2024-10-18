#include <iostream>
#include "physics.hpp"
#include "vector2.hpp"

// Simple render function (you can replace it with your actual rendering logic)
void renderPlayer(const vector2 &position)
{
	std::cout << "Player position: (" << position.x << ", " << position.y << ")" << std::endl;
}

int main() {
    // Initialize player physics with a starting position
    physics playerphysics(vector2(0, 0));

    // Simulate for 10 frames
    for (int frame = 0; frame < 10; ++frame) {
        float deltaTime = 0.016f;  // Simulate 16 ms per frame (~60 FPS)

        // Apply a force (e.g., jumping or moving)
        if (frame == 2) {
            vector2 jumpForce(0, -10);
            playerphysics.applyForce(jumpForce);
        }

        // Update physics
        playerphysics.update(deltaTime);

        // Render player at updated position
        renderPlayer(playerphysics.position);
    }

    return 0;
}
