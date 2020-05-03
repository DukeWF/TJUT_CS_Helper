#include <iostream>
using namespace std;
class Hello {
public:
	Hello() {
		cout << "We are getting in Hello" <<endl;
	}
	~Hello() {
		cout << "We are getting out of Hello" << endl;
	}
	int Say(const char* sentence);	
};
int main(int argc, char** argv) {
	char aloha[] = "Aloha World!";
	std::cout << "Hello world!\n";
	cout << aloha << endl; 
	for(int i=0; i<sizeof(aloha);i++){
		cout<<*(aloha+i);
	}
	cout << "\n";
	Hello myHello;
	myHello.Say();
	myHello.Say("Aloha World!");
	return 0;
}



int Hello::Say(const char* sentence) {
	if (!sentence)
		cout << sentence << endl;
	else
	    cout << "I don't know what you are saying!" << endl;
	return 0;
		
}
