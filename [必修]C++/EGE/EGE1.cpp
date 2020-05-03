#include "graphics.h"
int main(){
	//创建绘图窗口 （320*240） 
	initgraph(1920,1080);
	
	//输出图像 
	outtextxy(20,120,"Hello World!");//文本输出
	line(10,10,300,200);//线性输出
	
	//结束处理 
	ege::getch();//ege库内的getch()方法 
	closegraph();
	return 0;
}
