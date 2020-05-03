#include <iostream>
#include "Person1.h"
using namespace std;

void displayPerson(Person &person1, Person &person2)
{
  cout << "\tperson1 id: " << person1.getId() << endl;
  cout << "\tperson1 birth year: " <<
    person1.getBirthDate() -> getYear() << endl;
  cout << "\tperson2 id: " << person2.getId() << endl;
  cout << "\tperson2 birth year: " <<
    person2.getBirthDate() -> getYear() << endl;
}

int main()
{
  Person person1(111, 1970, 5, 3);
  Person person2(person1);

  cout << "After creating person1 and person2" << endl;
  displayPerson(person1, person2);

  person2.getBirthDate() -> setYear(1963);

  cout << "\nAfter modifying person2's birthDate" << endl;
  displayPerson(person1, person2);
  
  cout << "\n\nperson1.birthDate == person2.birthDate:  " << boolalpha <<
          (person1.getBirthDate() == person2.getBirthDate()) << "\n\n";

  Person person3(111, 1970, 5, 3);
  Person person4 = person3;
  
  cout << "person3.birthDate =" <<
          /*强制类型转换*/reinterpret_cast<int> (person3.getBirthDate()) << endl;
  cout << "person4.birthDate =" << 
          reinterpret_cast<int> (person4.getBirthDate()) << endl;

  return 0;
}
