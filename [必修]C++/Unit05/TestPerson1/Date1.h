#ifndef DATE1_H
#define DATE1_H 
class Date
{
public:
  Date(int newYear, int newMonth, int newDay);
  int getYear();
  void setYear(int newYear);

private:
  int year;
  int month;
  int day;
};
#endif
