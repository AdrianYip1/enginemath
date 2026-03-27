#include <enginemath/enginemath.hpp>

#include <iostream>

int main() {
    enginemath::Vec2 position{10.0f, 5.0f};
    enginemath::Vec2 velocity{2.0f, -1.0f};

    position += velocity;

    std::cout << "position: (" << position.x << ", " << position.y << ")\n";

    std::cout << "left position is:" << enginemath::Vec2::left().x << ", " << enginemath::Vec2::left().y <<"\n";

    enginemath::Vec2 one(4, 4);
    enginemath::Vec2 two(5, 5);
    float dotResult = one.dot(two);

    std::cout << "dot result of " << one.x << ", " << one.y << " and "<< two.x << ", " << two.y << " is: "<< dotResult << "\n"; 


    return 0;
}
