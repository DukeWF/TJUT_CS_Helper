#include <iostream>
using namespace std;

class Circle {
public:
  // The radius of this circle
  double radius;

  // Construct a circle object
  Circle() {
    radius = 1;
  }

  // Construct a circle object
  Circle(double newRadius) {
    radius = newRadius;
  }

  // Return the area of this circle
  double getArea() {
    return radius * radius * 3.14159;
  }
};

int main() {
    Circle circle1, circle2;
    circle1 = Circle();
    circle2 = Circle(5);

    cout << "Area is " << Circle().getArea() << endl;
    cout << "Area is " << Circle(5).getArea() << endl;

} 
