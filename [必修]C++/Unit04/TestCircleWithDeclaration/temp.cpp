Circle circle1;
Circle *pCircle = &circle1; 
cout << "The radius is " << (*pCircle).radius << endl;
cout << "The area is " << (*pCircle).getArea() << endl;
(*pCircle).radius = 5.5;
cout << "The radius is " << pCircle->radius << endl;
cout << "The area is " << pCircle->getArea() << endl;

