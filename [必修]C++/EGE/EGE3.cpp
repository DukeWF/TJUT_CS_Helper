/*
	Name: 
	Copyright: 
	Author: 
	Date: 11/07/17 13:33
	Description: EGE����1
*/
#include "graphics.h"
void mainloop(){
	for(;is_run();delay_fps(1)){
		/* TODO (#1#): �߼����� */
		setfillcolor(EGERGB(random(255),random(255),random(255)));
		
		/* TODO (#1#): ͼ�θ��� */
		//���� 
		cleardevice();
		fillellipse(200,200,50,30);
	}
}
int main(void){
	setinitmode(INIT_DEFAULT|INIT_NOFORCEEXIT);
	initgraph(640,480);
	randomize();
	setrendermode(RENDER_MANUAL);
	mainloop();
	closegraph();
	return 0;
} 
