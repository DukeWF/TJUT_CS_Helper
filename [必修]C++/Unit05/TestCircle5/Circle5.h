#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
  Circle();
  Circle(double);
  double getArea();
  double getRadius();
  void setRadius(double);
  
  static int getNumberOfObjects(); //static function

private:
  double radius;
  
  static int numberOfObjects;      //static variable 
};

#endif
