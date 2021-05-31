#include <iostream>
#include "../main/RegularPolygon.h"
int main()
{
    RegularPolygon hexagon(6);
    
    std::cout << hexagon.getApothem() << std::endl;
}

