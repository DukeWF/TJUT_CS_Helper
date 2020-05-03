/*
	Name: 
	Copyright: 
	Author: 
	Date: 11/07/17 13:33
	Description: EGE动画1
*/
#include "graphics.h"
void mainloop(){
	int x=0;
	setcolor(EGERGB(0, 0xFF, 0));
	setfillcolor(EGERGB(0,0,0xFF));
	for(;is_run();delay_fps(60)){
		/* TODO (#1#): 逻辑更新 */ 
		x=(x+1)%440;
		/* TODO (#1#): 图形更新 */
		cleardevice();
		//圆心坐标是（x+半径） 
		fillellipse(x+100,200,100,100);
	}
}
int main(){
	setinitmode(INIT_ANIMATION);
	initgraph(640,480);
	randomize();
	mainloop();
	closegraph();
	return 0;
}
