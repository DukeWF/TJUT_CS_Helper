#include "Person.h"

Person::Person(int id, int year, int month, int day)
{
  id_ = id;
  birthDate = new Date(year, month, day);
}

int Person::getId()
{
  return id_;
}

Date * Person::getBirthDate()
{
  return birthDate; // Return the pointer of the object
}
