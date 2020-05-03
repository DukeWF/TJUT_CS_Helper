#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  vector<int> intVector;

  // Store numbers 1, 2, 3, 4, 5, ..., 10 to the vector
  for (int i = 0; i < 10; i++)
    intVector.push_back(i + 1);

  // Display the numbers in the vector
  cout << "Numbers in the vector: ";
  for (int i = 0; i < intVector.size(); i++)
    cout << intVector[i] << " ";

  vector<string> stringVector;

  // Store strings into the vector
  stringVector.push_back("Guo-Jing");
  stringVector.push_back("Yang-Guo");
  stringVector.push_back("Zhang-Wuji");
  stringVector.push_back("Duan-Yu");

  // Display the string in the vector
  cout << "\nStrings in the string vector: ";
  for (int i = 0; i < stringVector.size(); i++)
    cout << stringVector[i] << " ";

  stringVector.pop_back(); // Remove the last element

  vector<string> v2;
  v2.swap(stringVector);
  v2[0] = "Wei-Xiaobao";

  // Redisplay the string in the vector
  cout << "\nStrings in the vector v2: ";
  for (int i = 0; i < v2.size(); i++)
    cout << v2.at(i) << " ";

  return 0;
}
