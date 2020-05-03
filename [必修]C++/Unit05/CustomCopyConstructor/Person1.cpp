#include "Person1.h"

Person::Person(int id, int year, int month, int day)
{
  this -> id = id;
  birthDate = new Date(year, month, day);
}

Person::Person(Person &person)
{
  id = person.id;
  Date *p = person.getBirthDate();//
  birthDate = new Date(*p);//利用解引用创建新对象（在堆区） 
}

int Person::getId()
{
  return id;
}

Date * Person::getBirthDate()
{
  return birthDate; // Return the pointer of the object
}
