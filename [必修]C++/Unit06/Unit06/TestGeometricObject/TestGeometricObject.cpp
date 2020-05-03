#include "GeometricObject.h"
#include "DerivedCircle.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

int main()
{
  GeometricObject shape;
  shape.setColor("red");
  shape.setFilled(true);
  cout << shape.toString() << endl << endl;

  Circle circle(5);
  circle.setColor("black");
  circle.setFilled(false);
  cout << circle.toString() << endl;
  cout << "  Circle radius: " << circle.getRadius() <<
          " area: "         << circle.getArea() <<
          " perimeter: "    << circle.getPerimeter() <<
          " \n" << endl;


  Rectangle rectangle(2, 3);
  rectangle.setColor("orange");
  rectangle.setFilled(true);
  cout << rectangle.toString() << endl;
  cout << "  Rectangle width: " << rectangle.getWidth() <<
          " height: "         << rectangle.getHeight() <<
          " area: "           << rectangle.getArea() <<
          " perimeter: "      << rectangle.getPerimeter() <<
          " \n" << endl;

  return 0;
}
