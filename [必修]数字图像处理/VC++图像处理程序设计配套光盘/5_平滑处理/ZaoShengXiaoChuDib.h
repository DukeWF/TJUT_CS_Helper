#ifndef __ZaoShengXiaoChuDib_H
#define __ZaoShengXiaoChuDib_H
#include "Cdib.h"

class ZaoShengXiaoChuDib :public CDib
{
public:
	ZaoShengXiaoChuDib();
	~ZaoShengXiaoChuDib();

public:
	void Chaoxian(int T);
	void HeiBaiFanZhuan();
	void GuDing(int YuZhi);    //�̶���ֵ����ֵ������
    void black(int connec);    //�������������ص㺯��
	void threethree();//3*3��ֵ�˲�
	void nn(int n);//n*n��ֵ�˲�
	void nnzhong(int n);//n*n��ֵ�˲�
	void shizi(int n); //ʮ������ֵ�˲���
	void nnzuida(int n); //n*n���ֵ�˲�
	void suijizaosheng();//�����������
    void jiaoyanzaosheng();//������������
    void jubupingjun();//��ѡ��ľֲ�ƽ���� 
protected: 
};
#endif