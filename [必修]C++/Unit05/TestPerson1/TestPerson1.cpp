#include <iostream>
#include "Person1.h"
#include "Date1.h"  // Wrong
using namespace std;

int main()
{
  Person person(111223333, 1970, 5, 3);
  Date *pDate = person.getBirthDate();
  pDate -> setYear(2010);
  cout << person.getBirthDate() -> getYear() << endl;
  return 0;
}
