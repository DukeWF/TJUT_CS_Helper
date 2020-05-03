/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "test.h"

int main(int argc, char** argv) {
	Matrix a(2,3),b(3,2);
	a.Output();
	b.Output();

	Matrix c;
	c = a * b;
	c.Output();
}
