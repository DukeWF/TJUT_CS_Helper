#include <iostream>
#include "stack.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i[10];
	for(int t=0;t<10;t++) i[t]=t;
	Stack stack(i,10);
	while(!stack.empty()) std::cout<<stack.pop()<<" ";
	return 0;
}
