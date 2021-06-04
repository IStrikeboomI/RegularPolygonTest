#include <iostream>
#pragma once
/*Regular Polygons are polygons where all the sides are equal and all the interior angles are equal
 Apothem is the length from the center of the polygon to the center of any side length
 Radius is the length from the center of the polygon to any vertex
 Perimeter is found through sides * Single Side Length
 Area is found with (perimeter * apothem) / 2
 Total Interior Angles is the sum of all the interior angles and found with (sides - 2) * 180
 Single Interior Angle is found with (Total Interior Angles) / sides
        ---------------
       /			120\
      /                 \
     /                   \
    /          O          \
    \          | \        /
     \        a|  \r     /s
      \        |_  \    /
	   \       |_|  \  /
		---------------
				  s/2	

		Here we have a regular polygon with 6 sides (hexagon)
		a = Apothem
		r = Radius
		s = Single Side length
		the total interior angles is (6 - 2) * 180 = 720
		the single interior angle is 720 / 6 = 120

		There is a right triangle formed by the apothem, radius, and half of a side length
		you can get the angle for the triangle by doing half of the interior angle because the triangle bisects it

        |\
        | \
      a |  \ r
        |   \
        |    \
        |   0 \
         -----
		 s/2
		
		Since you already know the interior angle based on the amount of sides, you can find 0 by the number of sides
		you also only need one of the three numbers for the triangle to solve the rest because it's a right triangle and you have the angle
		Using trigonometry you can find the other sides
		c++ trigonometry using std uses radians instead of degrees
		we can convert degrees to radians by doing degree * (pi/180)
		
		finding apothem with only r can be done with r * sin(radian)
		finding apothem with only s/2 can be done with (s/2) * tan(radian)
		finding radius with only a can be done with a / sin(radian)
		finding radius with only s/2 can be done with (s/2) / cos(radian)
		finding s/2 with only a can be done with a / tan(radian)
		finding s/2 with only r can be done with r * cos(radian)

		Lets say we have a regular octogon (8 sides) with side length of 4	
		an octogon has a single interior angle of 135
		for the the right triangle the x is 67.5 deg (1.1781 radians)
		s/2 = 2
		a = tan(1.1781) * 2 = 4.828
		r = 2 / cos(1.1781) = 5.226
		perimeter = 4 * 8 = 32
		area = (4.828 * 32) / 2 = 77.248
*/
class RegularPolygon
{
	private:
		unsigned int sides = 3;
		double singleSideLength = 0,
			perimeter = 0,
			apothem = 0,
			radius = 0,
			area = 0,
			totalInteriorAngles = 0,
			singleInteriorAngle = 0,
			singleExteriorAngle = 0;
	public:
		//Sides defaults to 3 because 3 is the min number of sides possible for polygons
		RegularPolygon(int sides=3) {
			if (sides < 3) {
				throw std::invalid_argument("polygon sides cannont be lower than 3 sides");
			}
			else {
				this->sides = sides;
				totalInteriorAngles = ((double)sides - 2) * 180;
				singleInteriorAngle = totalInteriorAngles / sides;
				singleExteriorAngle = 180 - singleInteriorAngle;
			}
		}
		unsigned int getSides() const { return sides; }
		double getSingleSideLength() const { return singleSideLength; }
		double getPerimeter() const { return perimeter; }
		 double getTotalInteriorAngles() const { return totalInteriorAngles; }
		 double getSingleInteriorAngle() const { return singleInteriorAngle; }
		 double getSingleExteriorAngle() const { return singleExteriorAngle; }
		double getApothem() const { return apothem; }
		double getRadius() const { return radius; }
		double getArea() const { return area; }
		//Converting degree to radians is done by degree * (pi/180)
		//std::acos(-1) is pi
		static double degreeToRadian(double degree) { return degree * (std::acos(-1) / 180); }
		void setSingleSideLength(double singleSideLength);
		void setPerimeter(double perimeter);
		void setApothem(double apothem);
		void setRadius(double radius);
		friend std::ostream& operator<<(std::ostream& output, const RegularPolygon& regularPolygon);
};

