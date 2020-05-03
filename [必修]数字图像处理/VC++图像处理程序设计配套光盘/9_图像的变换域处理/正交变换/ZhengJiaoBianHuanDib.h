#ifndef __ZhengJiaoBianHuanDib_H
#define __ZhengJiaoBianHuanDib_H

#include "Cdib.h"

struct CNumber
{
	double re;
	double im;
};
class ZhengJiaoBianHuanDib :public CDib
{
public:
	ZhengJiaoBianHuanDib();
	~ZhengJiaoBianHuanDib();

public:
	 CNumber Add(CNumber c1,CNumber c2);//ʵ�ָ����ļӷ�����
	 CNumber Sub(CNumber c1,CNumber c2);//ʵ�ָ����ļ�������
	 CNumber Mul(CNumber c1,CNumber c2);//ʵ�ָ����ĳ˷�����
	 void QFC(CNumber* t,CNumber* f,int power);//�˺���ʵ�ֿ��ٸ���Ҷ�任
	 void QuickFourier();//�˺�������ʵ��ͼ��ĸ���Ҷ�任
     void LiSan(double *t, double *f, int r);//�˺���ʵ����ɢ���ұ任
     void WALSH(double *t, double *f, int r);//�ú�������ʵ�ֿ����ֶ�ʲ-������任��
     bool DIBLiSanYuXuan(LPBYTE lpDIBBits, LONG lWidth, LONG lHeight);//�˺���ʵ��ͼ�����ɢ���ұ任
     bool DIBWalsh(LPBYTE lpDIBBits, LONG lWidth, LONG lHeight);//�ú�������ʵ��ͼ����ֶ�ʲ-������任��

protected:

};
#endif