#include "geometricobject.h"
GeometricObject::GeometricObject()
{
	this->color = "white";
	this->filled = false;
}
GeometricObject::GeometricObject(string color, bool filled)
{
	this->color = color;
	this->filled = filled;	
}
string GeometricObject::getColor()
{
	return color;
}
void GeometricObject::setColor(string color)
{
	this->color = color;
	return;
}
bool GeometricObject::isFilled(){
	return filled;
}
void GeometricObject::setFilled(bool filled){
	this->filled = filled;
}
string GeometricObject::toString(){
	return "This is a GeometeicObject, The color is " + color + " and the filled is " + boolalpha + filled;
	
}

