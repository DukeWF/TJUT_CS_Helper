/*100�û����0-99����Ӧ����Ϊ�����Ʊ��*/ 
/*ʵ�֣������� ���룬���ļ��ж�ȡ��Ӧ��Ϣ���������Ƿ���ȷ*/ 
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
//���������ļ�
		fwrite(numbers, sizeof(int), ARSIZE, iofile);		 
	} 
