#include "graphics.h"
int main(){
	//init �� close �ɶԳ��� 
	initgraph(640, 480);
	
	char s[101];
	//�Ի�����ʾ�����⣬��ʾ���ַ��������ȣ� 
	inputbox_getline("Input Box", "Input a string", s, 100);
	outtextxy(10, 10, s);
	//��������ʮ������������ʽ��� 
	int x = getInteger();
	xyprintf(10, 30, "This is an integer: %d", x);
	//�������Ը���������ʽ��� 
	double y = getDouble();
	xyprintf(10, 50, "This is an double: %f", y);
	//��ָ���ľ��ο���ʾ�ַ��������Ͻ�����x��y���߶ȣ���ȣ��ַ����� 
	getString(s, 100);
	outtextrect(10, 80, 100, 60, s);
	//��ʾ�ı���ָ����С��ʽ�� 
	char c = getChar("Input a character");
	outtext(c);
	//��ʾֱ�� 
	int coords[4];
	int* pc = getCoords(coords, 2);
	line(pc[0], pc[1], pc[2], pc[3]);
	//�������� 
	ege::getch();//�ȴ��û������ַ� 
	closegraph();
	return 0;
} 
