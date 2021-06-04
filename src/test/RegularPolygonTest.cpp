#include <iostream>
#include <string>
#include "../main/RegularPolygon.h"
int main()
{
    RegularPolygon hexagon(6);
    hexagon.setRadius(525);
    
    //Expected Output:
    //Regular Polygon[Sides=6, Single Side Length=525, Perimeter=3150, Apothem=454.663, Radius=525, Area=716095, Total Interior Angles=720, Single Interior Angle=120, Single Exterior Angle=60]
    std::cout << hexagon << std::endl;
}

