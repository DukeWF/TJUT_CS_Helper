#ifndef ABSTRACTGEOMETRICOBJECT_H
#define ABSTRACTGEOMETRICOBJECT_H
#include <string>
using namespace std;

class GeometricObject
{
public:
  GeometricObject();
  GeometricObject(string color, bool filled);

public:
  string getColor();
  void setColor(string color);
  bool isFilled();
  void setFilled(bool filled);
  string toString();
  virtual double getArea() {  };
  virtual double getPerimeter() {  };

private:
  string color_;
  bool filled_;
}; // Must place semicolon here

#endif
