#include <iostream>
#include <vector>
 
int main()
{
    try {
        std::cout << "Throwing an integer exception...\n";
        throw int(42);
    } catch( int i ) {
        std::cout << " the integer exception was caught, with value: " << i << '\n';
    }
 
    try {
        std::cout << "Creating a vector of size 5... \n";
        std::vector<int> v(5);
        std::cout << "Accessing the 11th element of the vector...\n";
        v.at(10);  // the at() function will check the range.
    } catch( std::exception& e) {
        std::cout << " a standard exception was caught, with message '" << e.what() << "'\n";
    }
    
}
