#include <iostream>
#pragma once
class RegularPolygon
{
	private:
		unsigned int sides = 3;
		double singleSideLength = 0;
		double perimeter = 0;
		const double totalInteriorAngles = ((double)sides - 2) * 180;
		const double singleInteriorAngle = totalInteriorAngles / sides;
		const double singleExteriorAngle = 180 - singleInteriorAngle;
		double apothem = 0;
		double radius = 0;
		double area = 0;
	public:
		RegularPolygon(unsigned int sides=3) {
			if (sides < 3) {
				throw std::invalid_argument("polygon sides cannont be lower than 3 sides");
			}
		}
		unsigned int getSides() const { return sides; }
		double getSingleSideLength() const { return singleSideLength; }
		double getPerimeter() const { return perimeter; }
		const double getTotalInteriorAngles() const { return totalInteriorAngles; }
		const double getSingleInteriorAngle() const { return singleInteriorAngle; }
		const double getSingleExteriorAngle() const { return singleExteriorAngle; }
		double getApothem() const { return apothem; }
		double getRadius() const { return radius; }
		double getArea() const { return area; }
};

