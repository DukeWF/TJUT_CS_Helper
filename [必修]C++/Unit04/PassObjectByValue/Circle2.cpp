#include "Circle2.h"

// Construct a circle object
Circle::Circle()
{
  radius_ = 1;
}

// Construct a circle object
Circle::Circle(double newRadius)
{
  radius_ = newRadius;
}

// Return the area of this circle
double Circle::getArea()
{
  return radius_ * radius_ * 3.14159;
}

// Return the radius of this circle
double Circle::getRadius()
{
  return radius_;
}

// Set a new radius
void Circle::setRadius(double newRadius)
{
  radius_ = (newRadius >= 0) ? newRadius : 0;
}
