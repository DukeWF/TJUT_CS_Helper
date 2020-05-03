#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
public:
  Course(const string &name);
  string getName();
  void addStudent(const string &student);
  string * getStudents();
  int getNumberOfStudents();

private:
  string name;
  string students[100];
  int numberOfStudents;
};

#endif
