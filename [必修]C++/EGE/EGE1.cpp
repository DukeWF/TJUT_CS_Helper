#include "graphics.h"
int main(){
	//������ͼ���� ��320*240�� 
	initgraph(1920,1080);
	
	//���ͼ�� 
	outtextxy(20,120,"Hello World!");//�ı����
	line(10,10,300,200);//�������
	
	//�������� 
	ege::getch();//ege���ڵ�getch()���� 
	closegraph();
	return 0;
}
