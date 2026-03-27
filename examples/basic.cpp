#include <enginemath/enginemath.hpp>

#include <iostream>

int main() {
    enginemath::Vec2 position{10.0f, 5.0f};
    enginemath::Vec2 velocity{2.0f, -1.0f};

    position += velocity;

    std::cout << "position: (" << position.x << ", " << position.y << ")\n";
    return 0;
}
