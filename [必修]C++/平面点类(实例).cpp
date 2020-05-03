#include <iostream>
using namespace std;
class Shape
{
public:
 virtual float getArea() = 0;
};

class Rectangle : public Shape
{
public:
 Rectangle (int w, int l);
 virtual float getArea();
 ~Rectangle();
private:
 int width,length;
};

Rectangle::Rectangle (int w,int l) { width = w; length =l; }
float Rectangle::getArea() { return width*length;}

/* Class Circle */
class Circle : public Shape
{
public:
 Circle (int r);
 virtual float getArea();
 ~Circle();
private:
 int radius;
};
Circle::Circle (int r) { radius = r; }
float Circle::getArea() { return 3.1416*radius*radius;}

int main ()
{
Shape *s[2];
int i;
s[0] = new Rectangle (4,3);
s[1] = new Circle (5);
for (i=0;i<2;i++) cout << "area[" <<i<< "]=" << s[i]->getArea() << endl; 
return 0;
}

