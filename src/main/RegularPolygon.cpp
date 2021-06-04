#include "RegularPolygon.h"
#include <iostream>

void RegularPolygon::setSingleSideLength(double singleSideLength) { 
	RegularPolygon::singleSideLength = singleSideLength;
	RegularPolygon::perimeter = singleSideLength * RegularPolygon::getSides();
	RegularPolygon::apothem = std::tan(RegularPolygon::degreeToRadian(RegularPolygon::getSingleInteriorAngle() / 2)) * (singleSideLength / 2);
	RegularPolygon::radius = (singleSideLength / 2) / std::cos(RegularPolygon::degreeToRadian(RegularPolygon::getSingleInteriorAngle() / 2));
	RegularPolygon::area = (RegularPolygon::getPerimeter() * RegularPolygon::getApothem()) / 2;
}

void RegularPolygon::setPerimeter(double perimeter){
	RegularPolygon::singleSideLength = perimeter / RegularPolygon::getSides();
	RegularPolygon::perimeter = perimeter;
	RegularPolygon::apothem = std::tan(RegularPolygon::degreeToRadian(RegularPolygon::getSingleInteriorAngle() / 2)) * (RegularPolygon::getSingleSideLength() / 2);
	RegularPolygon::radius = (RegularPolygon::getSingleSideLength() / 2) / std::cos(RegularPolygon::degreeToRadian(RegularPolygon::getSingleInteriorAngle() / 2));
	RegularPolygon::area = (perimeter * RegularPolygon::getApothem()) / 2;
}

void RegularPolygon::setApothem(double apothem) {
	RegularPolygon::singleSideLength = (apothem / std::tan(RegularPolygon::degreeToRadian(RegularPolygon::getSingleInteriorAngle() / 2))) * 2;
	RegularPolygon::perimeter = RegularPolygon::singleSideLength * RegularPolygon::getSides();
	RegularPolygon::apothem = apothem;
	RegularPolygon::radius = apothem / std::sin(RegularPolygon::degreeToRadian(RegularPolygon::getSingleInteriorAngle() / 2));
	RegularPolygon::area = (RegularPolygon::getPerimeter() * apothem) / 2;
}

void RegularPolygon::setRadius(double radius) {
	RegularPolygon::singleSideLength = (radius * std::cos(RegularPolygon::degreeToRadian(RegularPolygon::getSingleInteriorAngle() / 2))) * 2;
	RegularPolygon::perimeter = RegularPolygon::singleSideLength * RegularPolygon::getSides();
	RegularPolygon::apothem = radius * std::sin(RegularPolygon::degreeToRadian(RegularPolygon::getSingleInteriorAngle() / 2));
	RegularPolygon::radius = radius;
	RegularPolygon::area = (RegularPolygon::getPerimeter() * RegularPolygon::getApothem()) / 2;
}

std::ostream& operator<<(std::ostream& output, const RegularPolygon& regularPolygon) {
	output << "Regular Polygon[Sides=" << regularPolygon.getSides() << 
		", Single Side Length=" << regularPolygon.getSingleSideLength() <<
		", Perimeter=" << regularPolygon.getPerimeter()  << 
		", Apothem=" << regularPolygon.getApothem() << 
		", Radius=" << regularPolygon.getRadius() <<
		", Area=" << regularPolygon.getArea() <<
		", Total Interior Angles=" << regularPolygon.getTotalInteriorAngles() <<
		", Single Interior Angle=" << regularPolygon.getSingleInteriorAngle() << 
		", Single Exterior Angle=" << regularPolygon.getSingleExteriorAngle() 
		<< "]";
	return output;
}
