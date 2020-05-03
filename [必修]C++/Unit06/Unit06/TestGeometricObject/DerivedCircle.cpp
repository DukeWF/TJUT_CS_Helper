#include "DerivedCircle.h"

// Construct a default circle object
Circle::Circle()
{
  radius_ = 1;
}

// Construct a circle object with specified radius
Circle::Circle(double radius)
{
  radius_ = radius;
}

// Return the radius of this circle
double Circle::getRadius()
{
  return radius_;
}

// Set a new radius
void Circle::setRadius(double radius)
{
  radius_ = (radius >= 0) ? radius : 0;
}

// Return the area of this circle
double Circle::getArea()
{
  return radius_ * radius_ * 3.14159;
}

// Return the perimeter of this circle
double Circle::getPerimeter()
{
  return 2 * radius_ * 3.14159;
}

// Return the diameter of this circle
double Circle::getDiameter()
{
  return 2 * radius_;
}
