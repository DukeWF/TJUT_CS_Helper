#ifndef __HuiDuBianHuanDib_H
#define __HuiDuBianHuanDib_H
#include "Cdib.h"

class HuiDuBianHuanDib :public CDib
{
public:
	HuiDuBianHuanDib();
	~HuiDuBianHuanDib();
	
public:
	void Midufenbu(int *nNs_R,int *nNs_G,int *nNs_B);
	void ZhiFangTu(float *tongji,float *tongji2,float *tongji3);
	void GreenZhiFangTu(float *tongji);
	void BlueZhiFangTu(float *tongji);
	void RedZhiFangTu(float *tongji);
	void Fei0();//��ͼ����з���ȡһ����
	void GuDing(int YuZhi);//��ͼ����й̶���ֵ����
	void ShuangYu(int YuZhi1,int YuZhi2,int mode);//˫�̶���ֵ��
	void Chuizhitouying();//��ͼ����д�ֱͶӰ
	void Shuipingtouying();//��ͼ�����ˮƽͶӰ
	void Midufenbu(int* nNs_R);//����ͼ����ܶȷֲ�
	void Pipeibianhuan(BYTE bNum, int *npNu, float *fpPu);//���лҶ�ƥ��任
	int GetWidth();
	void Fenbujunhenghua(  );//���зֲ�����任
	void Chuangkoubianhuan(BYTE bLow, BYTE bUp);//�Ҷȴ��ڱ任
	void Zhexianbianhuan(BYTE bX1, BYTE bY1, BYTE bX2, BYTE bY2);//�Ҷ����߱任
	void ZhiFangTu(float* tongji);//�Ҷ�ֱ��ͼ��ʵ
	void FanSeBianHuan();//ͼ��ɫЧ��


protected:
};
#endif