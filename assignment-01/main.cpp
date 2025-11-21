#include <iostream>
#include "Point3D.h"

int main() {
    // Demonstrate Point3D
    Point3D p1(1, 2, 3);
    Point3D p2(4, 5, 6);
    std::cout << "Point 1: " << p1 << std::endl;
    std::cout << "Point 2: " << p2 << std::endl;
    std::cout << "Distance between p1 and p2: " << p1.distanceTo(p2) << std::endl;


    return 0;
}
