#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include "head.h"
class GeometricObject
{
	public:
		GeometricObject();
		GeometricObject(string color, bool filled);
		string getColor();
		void setColor(string color);
		bool isFilled();
		void setFilled(bool filled);
		string toString();
	protected:
		string color;
		bool filled;
};

#endif
