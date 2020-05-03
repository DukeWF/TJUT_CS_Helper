/*100用户编号0-99，对应密码为二进制编号*/ 
/*实现：输入编号 密码，从文件中读取对应信息，并检验是否正确*/ 
#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 100 
int main()
	{
		double numbers[ARSIZE];
		double value;
		const char *file ="numbers.dat";
		int i;
		long pos;
		FILE *iofile;
//生成密码文件
		fwrite(numbers, sizeof(int), ARSIZE, iofile);		 
	} 
