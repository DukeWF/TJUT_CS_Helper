#include "graphics.h"
int main(){
	//init 与 close 成对出现 
	initgraph(640, 480);
	
	char s[101];
	//对话框显示（标题，提示，字符串，长度） 
	inputbox_getline("Input Box", "Input a string", s, 100);
	outtextxy(10, 10, s);
	//将参数以十进制整数的形式输出 
	int x = getInteger();
	xyprintf(10, 30, "This is an integer: %d", x);
	//将参数以浮点数的形式输出 
	double y = getDouble();
	xyprintf(10, 50, "This is an double: %f", y);
	//在指定的矩形框显示字符串（左上角坐标x，y，高度，宽度，字符串） 
	getString(s, 100);
	outtextrect(10, 80, 100, 60, s);
	//显示文本（指定大小格式） 
	char c = getChar("Input a character");
	outtext(c);
	//显示直线 
	int coords[4];
	int* pc = getCoords(coords, 2);
	line(pc[0], pc[1], pc[2], pc[3]);
	//结束处理 
	ege::getch();//等待用户输入字符 
	closegraph();
	return 0;
} 
