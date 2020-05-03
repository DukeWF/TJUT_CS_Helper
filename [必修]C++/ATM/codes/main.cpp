#include <iostream>
#include "ATM.h"
#include "customer.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Î±²Ù×÷°æ ver 1.0 
int main(int argc, char** argv) {	
	customer c;
	ATM atm(c);
	atm.welcome();
	return 0;
}

