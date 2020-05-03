#include "stdafx.h"
#include "windowsx.h"
#include "math.h"
#include "ZaoShengXiaoChuDib.h"
#include "MainFrm.h"
#include "DSplitView.h"
 
ZaoShengXiaoChuDib::ZaoShengXiaoChuDib()
{

}

ZaoShengXiaoChuDib::~ZaoShengXiaoChuDib()
{
}

/***************************************************************/           
/*�������ƣ�GuDing()                                           */
/*�������ͣ�void                                               */
/*������int Yuzhi���趨����ֵ                                  */
/*���ܣ���ͼ��ʹ�ù̶���ֵ�����ж�ֵ����                       */
/***************************************************************/
void ZaoShengXiaoChuDib::GuDing(int YuZhi)
{
	LPBYTE  p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	p_data=this->GetData ();     //ȡ��ԭͼ��������ָ��
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��		
	{
		wide=this->GetWidth ();
		height=this->GetHeight ();
		for(int j=0;j<height;j++)
		{
			for(int i=0;i<wide;i++)
			{
				if(*p_data>YuZhi)          //�Ҷ�ֵ���ڸ�����ֵ����Ϊ255
					*p_data=255;
				else
					*p_data=0;             //��������Ϊ0
				p_data++;
			}
		}
	}
	else	//24λ��ɫ
	{
		wide=this->GetWidth();
		height=this->GetHeight ();
		for(int j=0;j<height;j++)
		{
			for(int i=0;i<wide;i++)    //������������ѭ��
			{
				if(*p_data>YuZhi)          //������ֵ��Ϊ0
					*p_data=255;   //������Ϊ255
				else
					*p_data=0;             //��������Ϊ0
				p_data++; 				 
			}
		}
	}
}

/***************************************************************/ 
/*�������ƣ�HeiBaiFanZhuan()                                   */
/*�������ͣ�void                                               */
/*���ܣ��Զ�ֵͼ��ĺڰ׵�����������                           */
/***************************************************************/
void ZaoShengXiaoChuDib::HeiBaiFanZhuan()
{
	int averg,averg2,averg3;
	BYTE *p_data;		//ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	p_data=this->GetData ();//ȡ��ԭͼ��������ָ��
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		wide=this->GetWidth ();		//ȡ��ԭͼ����������
		height=this->GetHeight ();  //ȡ��ԭͼ����������
		GuDing(100);				//���ж�ֵ��
		BYTE* p_temp=new BYTE[wide*height];// ���벢�����м仺��
		memcpy(p_temp,m_pData,wide*height);// ����ͼ�����ݵ��м仺��
		//��3*3���δ��ڵ�8���ھ�ֵ�����˲�
		for(int j=1;j<height-1;j++)
		{	
			for(int i=1;i<wide-1;i++)
			{
				averg=0;			
				//����Χ8���ھ�ֵ
				averg=(int)((p_data[(j-1)*wide+(i-1)]+p_data[(j-1)*wide+i]
					+p_data[(j-1)*wide+(i+1)]+p_data[j*wide+(i-1)]
					+p_data[j*wide+i+1]+p_data[(j+1)*wide+(i-1)]
					+p_data[(j+1)*wide+i]+p_data[(j+1)*wide+i+1])/8);
				if(abs(averg-p_temp[j*wide+i])>127.5)
					p_temp[j*wide+i]=averg;
			}
		}
		memcpy(p_data,p_temp,wide*height);
		delete p_temp;
	}
	else	//24λ��ɫ
	{
		wide=this->GetWidth();  //ȡ��ԭͼ����������
		height=this->GetHeight ();  //ȡ��ԭͼ����������
		GuDing(100);  //���ж�ֵ��
		BYTE* p_temp=new BYTE[wide*height*3];// ���벢�����м仺��
		memcpy(p_temp,m_pData,wide*height*3);// ����ͼ�����ݵ��м仺��
		//��3*3���δ��ڵ�8���ھ�ֵ�����˲�
		for(int j=1;j<height-1;j++)
		{	
			for(int i=1;i<wide-1;i++)
			{
				averg=0;
				averg2=0;
				averg3=0;
				//����Χ8���ھ�ֵ
				averg=(int)((p_data[(j-1)*wide*3+(i-1)*3]+p_data[(j-1)*wide*3+i*3]
					+p_data[(j-1)*wide*3+(i+1)*3]+p_data[j*wide*3+(i-1)*3]
					+p_data[j*wide*3+(i+1)*3]+p_data[(j+1)*wide*3+(i-1)*3]
					+p_data[(j+1)*wide*3+i*3]+p_data[(j+1)*wide*3+(i+1)*3])/8);
				averg2=(int)((p_data[(j-1)*wide*3+(i-1)*3+1]+p_data[(j-1)*wide*3+i*3+1]
					+p_data[(j-1)*wide*3+(i+1)*3+1]+p_data[j*wide*3+(i-1)*3+1]
					+p_data[j*wide*3+(i+1)*3+1]+p_data[(j+1)*wide*3+(i-1)*3+1]
					+p_data[(j+1)*wide*3+i*3+1]+p_data[(j+1)*wide*3+(i+1)*3+1])/8);
				averg3=(int)((p_data[(j-1)*wide*3+(i-1)*3+2]+p_data[(j-1)*wide*3+i*3+2]
					+p_data[(j-1)*wide*3+(i+1)*3+2]+p_data[j*wide*3+(i-1)*3+2]
					+p_data[j*wide*3+(i+1)*3+2]+p_data[(j+1)*wide*3+(i-1)*3+2]
					+p_data[(j+1)*wide*3+i*3+2]+p_data[(j+1)*wide*3+(i+1)*3+2])/8);
				if(abs(averg-p_temp[j*wide*3+i*3])>127.5)
					p_temp[j*wide*3+i*3]=averg;
				if(abs(averg2-p_temp[j*wide*3+i*3+1])>127.5)
					p_temp[j*wide*3+i*3+1]=averg2;
				if(abs(averg3-p_temp[j*wide*3+i*3+2])>127.5)
					p_temp[j*wide*3+i*3+2]=averg3;
			}
		}
		memcpy(p_data,p_temp,wide*height*3);
		delete p_temp;
	}
}

/***************************************************************/ 
/*�������ƣ�black(int connec)                                  */
/*�������ͣ�void                                               */
/*������int connec���趨����ͨѡ��                             */
/*���ܣ��Զ�ֵͼ������������������ص㡣                       */
/***************************************************************/
void ZaoShengXiaoChuDib::black(int connec)
{
	// ָ��DIB����ָ��
	BYTE *p_data;
    p_data=this->GetData();  	//ȡ��ԭͼ��������ָ�� 
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		int wide=this->GetWidth();  //ȡ��ԭͼ����������
		int height=this->GetHeight();  //ȡ��ԭͼ����������
		//��ֵ��
		GuDing(100);	
		// ���벢�����м仺��
		BYTE* p_temp=new BYTE[wide*height]; 	
		// ����ͼ�����ݵ��м仺��
		memcpy(p_temp,p_data,wide*height);
		// 4���ӵ�����£���ȥ�������Ҷ�Ϊ255(�׵�)�Ĺ����ڵ�	
		if (connec==4)
		{
			for (int j=1;j<height-1;j++)
			{
				for (int i=1;i<wide-1;i++)
				{
					if (*(p_temp + wide * j + i)==255) 
						continue;
					if((*(p_temp + wide * (j-1) + i)+
						*(p_temp + wide * (j+1) + i)+
						*(p_temp + wide * j + i-1)+
						*(p_temp + wide * j + i+1))==255*4)
					{
						*(p_data + wide * j + i)=255;
					}
				}
			}
	delete p_temp;
		}
		// 8���ӵ�����£���ȥ��Χ��Ϊ255(�׵�)�Ĺ����ڵ�	
		if (connec==8)
		{
			for (int j = 1; j < height-1; j ++)
			{
				for (int i = 1; i < wide-1; i ++)
				{
					if (*(p_temp + wide * j + i)==255)
						continue;
					if((*(p_temp + wide * (j-1) + i)+
						*(p_temp + wide * (j+1) + i)+
						*(p_temp + wide * j + i-1)+
						*(p_temp + wide * j + i-1)+
						*(p_temp + wide * (j-1) + i-1)+
						*(p_temp + wide * (j+1) + i+1)+
						*(p_temp + wide * (j-1) + i+1)+
						*(p_temp + wide * (j+1) + i-1))==255*8)
					{	
						*(p_data + wide * j + i)=255;
					}
				}
			}
delete p_temp;
		}
			
	}
/*	else	//24λ��ɫ
	{
		int wide= this->GetWidth();  //ȡ��ԭͼ����������
		int height=this->GetHeight();  //ȡ��ԭͼ����������
		//��ֵ��
		GuDing(100);	
		// ���벢�����м仺��
		BYTE* p_temp=new BYTE[wide*height*3]; 	
		// ����ͼ�����ݵ��м仺��
		memcpy(p_temp,p_data,wide*height*3);
		// 4���ӵ�����£���ȥ�������Ҷ�Ϊ255(�׵�)�Ĺ����ڵ�	
		if (connec==4)
		{
			for (int j=1;j<height-1;j++)
			{
				for (int i=1;i<wide-1;i++)
				{
					if ((*(p_temp + wide * j*3 + i*3)==255)&&
						(*(p_temp + wide * j*3 + i*3+1)==255) &&
						(*(p_temp + wide * j*3 + i*3+2)==255))
						continue;
					if(((*(p_temp + wide * (j-1)*3 + i*3)+
						*(p_temp + wide * (j+1)*3 + i*3)+
						*(p_temp + wide * j*3 + (i-1)*3)+
						*(p_temp + wide * j*3 + (i+1)*3))==255*4)&&
						((*(p_temp + wide * (j-1)*3 + i*3+1)+
						*(p_temp + wide * (j+1)*3 + i*3+1)+
						*(p_temp + wide * j*3 + (i-1)*3+1)+
						*(p_temp + wide * j*3 + (i+1)*3+1))==255*4)&&
						((*(p_temp + wide * (j-1)*3 + i*3+2)+
						*(p_temp + wide * (j+1)*3 + i*3+2)+
						*(p_temp + wide * j*3 + (i-1)*3+2)+
						*(p_temp + wide * j*3 + (i+1)*3+2))==255*4))
					{	
						*(p_data + wide * j*3 + i*3)=255;
						*(p_data + wide * j*3 + i*3+1)=255;
						*(p_data + wide * j*3 + i*3+2)=255;
					}
				}
			}
			delete p_temp;
		}
		// 8���ӵ�����£���ȥ��Χ��Ϊ255(�׵�)�Ĺ����ڵ�	
		if (connec==8)
		{
			for (int j = 1; j < height-1; j ++)
			{
				for (int i = 1; i < wide-1; i ++)
				{
					if ((*(p_temp + wide * j*3 + i*3)==255)&&
						(*(p_temp + wide * j*3 + i*3+1)==255)&&
						(*(p_temp + wide * j*3 + i*3+2)==255))
						continue;
					if(((*(p_temp + wide * (j-1)*3 + i*3)+
						*(p_temp + wide * (j+1)*3 + i*3)+
						*(p_temp + wide * j*3 + (i-1)*3)+
						*(p_temp + wide * j*3 + (i-1)*3)+
						*(p_temp + wide * (j-1)*3 + (i-1)*3)+
						*(p_temp + wide * (j+1)*3 + (i+1)*3)+
						*(p_temp + wide * (j-1)*3 + (i+1)*3)+
						*(p_temp + wide * (j+1)*3 + (i-1)*3))==255*8)&&
						((*(p_temp + wide * (j-1)*3 + i*3+1)+
						*(p_temp + wide * (j+1)*3 + i*3+1)+
						*(p_temp + wide * j*3 + (i-1)*3+1)+
						*(p_temp + wide * j*3 + (i-1)*3+1)+
						*(p_temp + wide * (j-1)*3 + (i-1)*3+1)+
						*(p_temp + wide * (j+1)*3 + (i+1)*3+1)+
						*(p_temp + wide * (j-1)*3 + (i+1)*31+1)+
						*(p_temp + wide * (j+1)*3 + (i-1)*3+1))==255*8)&&
						((*(p_temp + wide * (j-1)*3 + i*3+2)+
						*(p_temp + wide * (j+1)*3 + i*3+2)+
						*(p_temp + wide * j*3 + (i-1)*3+2)+
						*(p_temp + wide * j*3 + (i-1)*3+2)+
						*(p_temp + wide * (j-1)*3 + (i-1)*3+2)+
						*(p_temp + wide * (j+1)*3 + (i+1)*3+2)+
						*(p_temp + wide * (j-1)*3 + (i+1)*3+2)+
						*(p_temp + wide * (j+1)*3 + (i-1)*3+2))==255*8))
					{	
						*(p_data + wide * j*3 + i*3)=255;
						*(p_data + wide * j*3 + i*3+1)=255;
						*(p_data + wide * j*3 + i*3+2)=255;
					}
				}
			}
		delete p_temp;
		}
		
	}*/
}

/***************************************************************/ 
/*�������ƣ�threethree()                                       */
/*�������ͣ�void                                               */
/*���ܣ���ͼ�����3*3��ֵ�˲�����                            */
/***************************************************************/
void ZaoShengXiaoChuDib::threethree() 
{
	float averg,averg2,averg3;
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	p_data=this->GetData ();//ȡ��ԭͼ��������ָ��
	wide=this->GetWidth (); //ȡ��ԭͼ����������
    height=this->GetHeight ();  //ȡ��ԭͼ����������
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{    
		BYTE* p_temp=new BYTE[wide*height];
		int size=wide*height;
		memset(p_temp,255,size);
		//��3*3���δ��ڵ�8���ھ�ֵ�����˲�
		for(int j=1;j<height-1;j++)
		{
			for(int i=1;i<wide-1;i++)
			{
				averg=0;
				//����Χ8���ھ�ֵ
				averg=(int)(p_data[(j-1)*wide+(i-1)]+p_data[(j-1)*wide+i]
					+p_data[(j-1)*wide+(i+1)]+p_data[j*wide+(i-1)]
					+p_data[j*wide+i+1]+p_data[(j+1)*wide+(i-1)]
					+p_data[(j+1)*wide+i]+p_data[(j+1)*wide+i+1])/8;
				
				p_temp[j*wide+i]=averg;
			}
		}
		memcpy(p_data,p_temp,wide*height);
		delete p_temp;
	}
	else	//24λ��ɫ
	{		
		BYTE* p_temp=new BYTE[wide*height*3];
		int size=wide*height*3;
		memset(p_temp,255,size);
		
		//��3*3���δ��ڵ�8���ھ�ֵ�����˲�
		for(int j=1;j<height-1;j++)
		{
			for(int i=1;i<wide-1;i++)
			{
				averg=0;
				averg2=0;
				averg3=0;
				//����Χ8���ھ�ֵ
				averg=(int)(p_data[(j-1)*wide*3+(i-1)*3]+p_data[(j-1)*wide*3+i*3]
					+p_data[(j-1)*wide*3+(i+1)*3]+p_data[j*wide*3+(i-1)*3]
					+p_data[j*wide*3+(i+1)*3]+p_data[(j+1)*wide*3+(i-1)*3]
					+p_data[(j+1)*wide+i*3]+p_data[(j+1)*wide+(i+1)*3])/8;
				averg2=(int)(p_data[(j-1)*wide*3+(i-1)*3+1]+p_data[(j-1)*wide*3+i*3+1]
					+p_data[(j-1)*wide*3+(i+1)*3+1]+p_data[j*wide*3+(i-1)*3+1]
					+p_data[j*wide*3+(i+1)*3+1]+p_data[(j+1)*wide*3+(i-1)*3+1]
					+p_data[(j+1)*wide+i*3+1]+p_data[(j+1)*wide+(i+1)*3+1])/8;
				averg3=(int)(p_data[(j-1)*wide*3+(i-1)*3+2]+p_data[(j-1)*wide*3+i*3+2]
					+p_data[(j-1)*wide*3+(i+1)*3+2]+p_data[j*wide*3+(i-1)*3+2]
					+p_data[j*wide*3+(i+1)*3+2]+p_data[(j+1)*wide*3+(i-1)*3+2]
					+p_data[(j+1)*wide+i*3+2]+p_data[(j+1)*wide+(i+1)*3+2])/8;
				p_temp[j*wide*3+i*3]=(int)averg;
				p_temp[j*wide*3+i*3+1]=(int)averg2;
				p_temp[j*wide*3+i*3+2]=(int)averg3;
			}
		}
		memcpy(p_data,p_temp,wide*height*3);
		delete p_temp;
	}
}

/***************************************************************/
/*�������ƣ�Chaoxian(int T)                                    */
/*�������ͣ�void                                               */
/*������int T���趨����ֵ                                      */
/*���ܣ���������ƽ������                                       */
/***************************************************************/
void ZaoShengXiaoChuDib::Chaoxian(int T)
{
	int averg,averg2,averg3;
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	p_data=this->GetData ();//ȡ��ԭͼ��������ָ��
	wide=this->GetWidth (); //ȡ��ԭͼ����������
    height=this->GetHeight ();  //ȡ��ԭͼ����������
	if(m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{    
		BYTE* p_temp=new BYTE[wide*height];
		int size=wide*height;
		memset(p_temp,255,size);
		//��3*3���δ��ڵ�8���ھ�ֵ�����˲�
		for(int j=1;j<height-1;j++)
		{
			for(int i=1;i<wide-1;i++)
			{
				averg=0;
				//����Χ8���ھ�ֵ
				averg=(int)(p_data[(j-1)*wide+(i-1)]+p_data[(j-1)*wide+i]
					+p_data[(j-1)*wide+(i+1)]+p_data[j*wide+(i-1)]
					+p_data[j*wide+i+1]+p_data[(j+1)*wide+(i-1)]
					+p_data[(j+1)*wide+i]+p_data[(j+1)*wide+i+1])/8;
				if(abs(p_temp[j*wide+i]-averg)>T)
					p_temp[j*wide+i]=averg;
			}
		}
		memcpy(p_data,p_temp,wide*height);
		delete p_temp;
	}
	else	//24λ��ɫ
	{	
		BYTE* p_temp=new BYTE[wide*height*3];
		int size=wide*height*3;
		memset(p_temp,255,size);
		//��3*3���δ��ڵ�8���ھ�ֵ�����˲�
		for(int j=1;j<height-1;j++)
		{
			for(int i=1;i<wide-1;i++)
			{
				averg=0;
				averg2=0;
				averg3=0;
				//����Χ8���ھ�ֵ
				averg=(int)(p_data[(j-1)*wide*3+(i-1)*3]+p_data[(j-1)*wide+i*3]
					+p_data[(j-1)*wide*3+(i+1)*3]+p_data[j*wide+(i-1)*3]
					+p_data[j*wide*3+(i+1)*3]+p_data[(j+1)*wide+(i-1)*3]
					+p_data[(j+1)*wide*3+i*3]+p_data[(j+1)*wide+(i+1)*3])/8;
				averg2=(int)(p_data[(j-1)*wide*3+(i-1)*3+1]+p_data[(j-1)*wide+i*3+1]
					+p_data[(j-1)*wide*3+(i+1)*3+1]+p_data[j*wide+(i-1)*3+1]
					+p_data[j*wide*3+(i+1)*3+1]+p_data[(j+1)*wide+(i-1)*3+1]
					+p_data[(j+1)*wide*3+i*3+1]+p_data[(j+1)*wide+(i+1)*3+1])/8;
				averg3=(int)(p_data[(j-1)*wide*3+(i-1)*3+2]+p_data[(j-1)*wide+i*3+2]
					+p_data[(j-1)*wide*3+(i+1)*3+2]+p_data[j*wide+(i-1)*3+2]
					+p_data[j*wide*3+(i+1)*3+2]+p_data[(j+1)*wide+(i-1)*3+2]
					+p_data[(j+1)*wide*3+i*3+2]+p_data[(j+1)*wide+(i+1)*3+2])/8;
				if(abs(p_temp[j*wide*3+i*3]-averg)>T)
					p_temp[j*wide*3+i*3]=averg;
				if(abs(p_temp[j*wide*3+i*3+1]-averg2)>T)
					p_temp[j*wide*3+i*3+1]=averg2;
				if(abs(p_temp[j*wide*3+i*3+2]-averg3)>T)
					p_temp[j*wide*3+i*3*2]=averg3;
			}
		}
		memcpy(p_data,p_temp,wide*height*3);
		delete p_temp;
	}
}

/***************************************************************/ 
/*�������ƣ�nn(int n)                                          */
/*�������ͣ�void                                               */
/*������int n���趨�����δ��ڲ�����������                      */
/*���ܣ���ͼ�����n*n��ֵ�˲�����                            */
/***************************************************************/
void ZaoShengXiaoChuDib::nn(int n)
{
    DWORD size;
	size=GetSize();
	BYTE *p_data;
	int xx,yy,n2,sum,sum2,sum3;
	int wide,height;    //ԭͼ������
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		BYTE* p_temp=new BYTE [size];
		memset(p_temp,255,size);
		if(n<3||n%2!=1)//ȷ��nΪ����
			AfxMessageBox("������һ�����ڵ���3������");
		if(n>=3&&n%2==1)
			n2=(n-1)/2;
		p_data=this->GetData();//ȡ��ԭͼ��������ָ��
		wide=this->GetWidth(); //ȡ��ԭͼ����������
		height=this->GetHeight();  //ȡ��ԭͼ����������
		//��N*N���δ���ƽ����
		for(int j=n2;j<height-n2;j++)
		{
			for(int i=n2;i<wide-n2;i++)
			{	//��N*N���δ����ڵ��ܺ�sum
				sum=0;
				for(yy=j-n2;yy<=j+n2;yy++)
					for(xx=i-n2;xx<=i+n2;xx++)
						sum+=p_data[yy*wide+xx];
				//��n*n���δ����ڵ�ƽ��ֵ�����������Ϊ��ʾͼ������ֵ
				p_temp[j*wide+i]=(int)((float)sum/(n*n)+0.5);
					
			}
		}
		memcpy(p_data,p_temp,size);
		delete p_temp;
	}
	else	//24λ��ɫ
	{			
		if(n<3||n%2!=1)//ȷ��nΪ����
			AfxMessageBox("������һ�����ڵ���3������");
		if(n>=3&&n%2==1)
			n2=(n-1)/2;
		p_data=this->GetData();//ȡ��ԭͼ��������ָ��
		wide=this->GetWidth(); //ȡ��ԭͼ����������
		height=this->GetHeight();  //ȡ��ԭͼ����������
		BYTE* p_temp=new BYTE [wide*height*3];
		memset(p_temp,255,wide*height*3);
		//��N*N���δ���ƽ����
		for(int j=n2;j<height-n2;j++)
		{
			for(int i=n2;i<wide-n2;i++)
			{	
				//��N*N���δ����ڵ��ܺ�sum
				sum=0;
				sum2=0;
				sum3=0;
				for(yy=j-n2;yy<=j+n2;yy++)
					for(xx=i-n2;xx<=i+n2;xx++)
					{
						sum+=p_data[yy*wide*3+xx*3];
						sum2+=p_data[yy*wide*3+xx*3+1];
						sum3+=p_data[yy*wide*3+xx*3+2];
					}
				//��n*n���δ����ڵ�ƽ��ֵ�����������Ϊ��ʾͼ������ֵ
				p_temp[j*wide*3+i*3]=(int)((float)sum/(n*n)+0.5);
				p_temp[j*wide*3+i*3+1]=(int)((float)sum2/(n*n)+0.5);
				p_temp[j*wide*3+i*3+2]=(int)((float)sum3/(n*n)+0.5);
			}
		}
		memcpy(p_data,p_temp,wide*height*3);
		delete p_temp;
	}
} 

/***************************************************************/ 
/*�������ƣ�nnzhong(int n)                                     */
/*�������ͣ�void                                               */
/*������int n���趨�����δ��ڲ�����������                      */
/*���ܣ���ͼ�����n*n��ֵ�˲�����                            */
/***************************************************************/
void ZaoShengXiaoChuDib::nnzhong(int n)
{
	DWORD size;
	size=GetSize();
	BYTE* p_temp=new BYTE [size];
	memset(p_temp,255,size);
	int yy,xx,n2,nn,chuo,chg,m,medi,medi2,medi3,madom,mado[1000],mado2[1000],mado3[1000];
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	if(n<3||n%2!=1)//���ȡֵ�Ƿ�Ϊ3.5.7�ȵ�����
		AfxMessageBox("������һ�����ڵ���3������");
	if(n>=3&&n%2==1)
		n2=(n-1)/2;
    nn=n*n;
	chuo=(nn-1)/2;
	p_data=this->GetData();//ȡ��ԭͼ��������ָ��
	wide=this->GetWidth(); //ȡ��ԭͼ����������
    height=this->GetHeight();  //ȡ��ԭͼ����������
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		//n*n��ֵ�˲�
		for(int j=n2;j<height-n2;j++)
			for(int i=n2;i<wide-n2;i++)
			{
				//��n*n���δ��ڲ��ֵ���������ֵ����mado[m]
				m=0;
				for(yy=j-n2;yy<=j+n2;yy++)
					for(xx=i-n2;xx<=i+n2;xx++)
					{
						mado[m]=p_data[yy*wide+xx];
						m++;
					}
				//��mado[m]�е�ֵ���½�˳����ð�ݷ�����
				do{
					chg=0;
					for(m=0;m<nn-1;m++)
					{
						if(mado[m]<mado[m+1])
						{
							madom=mado[m];
							mado[m]=mado[m+1];
							mado[m+1]=madom;
							chg=1;
						}
					}
				}while(chg==1);	
				//����ֵmedi
				medi=mado[chuo];
				//����ֵ������ʾͼ����
				p_temp[j*wide+i]=medi;
			}
		memcpy(p_data,p_temp,size);
		delete p_temp;
	}
	else	//24λ��ɫ
	{
		//n*n��ֵ�˲�
		for(int j=n2;j<height-n2;j++)
			for(int i=n2;i<wide-n2;i++)
			{
				//��n*n���δ��ڲ��ֵ���������ֵ����mado[m]
				m=0;
				for(yy=j-n2;yy<=j+n2;yy++)
					for(xx=i-n2;xx<=i+n2;xx++)
					{
						mado[m]=p_data[yy*wide*3+xx*3];
						mado2[m]=p_data[yy*wide*3+xx*3+1];
						mado3[m]=p_data[yy*wide*3+xx*3+2];
						m++;
					}
				//��mado[m]�е�ֵ���½�˳����ð�ݷ�����
				do{
					chg=0;
					for(m=0;m<nn-1;m++)
					{
						if(mado[m]<mado[m+1])
						{
							madom=mado[m];
							mado[m]=mado[m+1];
							mado[m+1]=madom;
							chg=1;
						}
						if(mado2[m]<mado2[m+1])
						{
							madom=mado2[m];
							mado2[m]=mado2[m+1];
							mado2[m+1]=madom;
							chg=1;
						}
						if(mado3[m]<mado3[m+1])
						{
							madom=mado3[m];
							mado3[m]=mado3[m+1];
							mado3[m+1]=madom;
							chg=1;
						}
					}
				}while(chg==1);	
				//����ֵmedi
				medi=mado[chuo];
				medi2=mado2[chuo];
				medi3=mado3[chuo];
				//����ֵ������ʾͼ����
				p_temp[j*wide*3+i*3]=medi;
				p_temp[j*wide*3+i*3+1]=medi2;
				p_temp[j*wide*3+i*3+2]=medi3;
			}
		memcpy(p_data,p_temp,wide*height*3);
		delete p_temp;
	}
}

/***************************************************************/
/*�������ƣ�shizi(int n)                                       */
/*�������ͣ�void                                               */
/*������int n���趨�����δ��ڲ�����������                      */
/*���ܣ���ͼ�����ʮ������ֵ�˲���                             */
/***************************************************************/
void ZaoShengXiaoChuDib::shizi(int n)
{ 
    DWORD size;
	size=GetSize();
	BYTE* p_temp=new BYTE [size];
	memset(p_temp,255,size);
    int yy,xx,n2,nn,chuo,chg,m,medi,medi2,medi3,madom,mado[1000],mado2[1000],mado3[1000];
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	if(n<3||n%2!=1)//���ȡֵ�Ƿ�Ϊ3.5.7�ȵ�����
	AfxMessageBox("������һ�����ڵ���3������");
	if(n>=3&&n%2==1)
    n2=(n-1)/2;
    nn=n+n-1;
    chuo=(nn-1)/2;
	p_data=this->GetData();//ȡ��ԭͼ��������ָ��
	wide=this->GetWidth(); //ȡ��ԭͼ����������
    height=this->GetHeight();  //ȡ��ԭͼ����������
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		//ʮ������ֵ�˲�
		for(int j=n2;j<height-n2;j++)
		for(int i=n2;i<wide-n2;i++)
		{
			//��ʮ�������δ��ڲ��ֵ���������ֵ����mado[m]
			//(���뺬���ĵĴ�ֱ����)
			m=0;
			for(yy=j-n2;yy<=j+n2;yy++)
			{
				mado[m]=p_data[yy*wide+i];
				m++;
			}
			//��������������ĵ�ˮƽ���֣�
			for(xx=i-n2;xx<=i+n2;xx++)
			{
				if(xx==i)continue;
				mado[m]=p_data[j*wide+xx];
				m++;
			}
			//��mado[m]�����ݰ��½�˳��ð�ݷ�����
			do{
				chg=0;
				for(m=0;m<nn-1;m++)
				{
					if(mado[m]<mado[m+1])
					{
						madom=mado[m];
						mado[m]=mado[m+1];
						mado[m+1]=madom;
						chg=1;
					}
				}
			}while(chg==1);
			//����ֵmedi
			medi=mado[chuo];
			p_temp[j*wide+i]=medi;
		}		
		memcpy(m_pData,p_temp,size);
		delete p_temp;
	}
	else	//24λ��ɫ
	{	
		//ʮ������ֵ�˲�
		for(int j=n2;j<height-n2;j++)
		for(int i=n2;i<wide-n2;i++)
		{
			//��ʮ�������δ��ڲ��ֵ���������ֵ����mado[m]
			//(���뺬���ĵĴ�ֱ����)
			m=0;
			for(yy=j-n2;yy<=j+n2;yy++)
			{
				mado[m]=p_data[yy*wide*3+i*3];
				mado2[m]=p_data[yy*wide*3+i*3+1];
				mado3[m]=p_data[yy*wide*3+i*3+2];
				m++;
			}
			//��������������ĵ�ˮƽ���֣�
			for(xx=i-n2;xx<=i+n2;xx++)
			{
				if(xx==i)continue;
				mado[m]=p_data[j*wide*3+xx*3];
				mado2[m]=p_data[j*wide*3+xx*3+1];
				mado3[m]=p_data[j*wide*3+xx*3+2];
				m++;
			}
			//��mado[m]�����ݰ��½�˳��ð�ݷ�����
			do{
				chg=0;
				for(m=0;m<nn-1;m++)
				{
					if(mado[m]<mado[m+1])
					{
						madom=mado[m];
						mado[m]=mado[m+1];
						mado[m+1]=madom;
						chg=1;
					}
					if(mado2[m]<mado2[m+1])
					{
						madom=mado2[m];
						mado2[m]=mado2[m+1];
						mado2[m+1]=madom;
						chg=1;
					}
					if(mado3[m]<mado3[m+1])
					{
						madom=mado3[m];
						mado3[m]=mado3[m+1];
						mado3[m+1]=madom;
						chg=1;
					}
				}
			}while(chg==1);
			//����ֵmedi
			medi=mado[chuo];
			medi2=mado2[chuo];
			medi3=mado3[chuo];
			p_temp[j*wide*3+i*3]=medi;
			p_temp[j*wide*3+i*3+1]=medi2;
			p_temp[j*wide*3+i*3+2]=medi3;					
		}		
		memcpy(m_pData,p_temp,wide*height*3);
		delete p_temp;
	}
}

/***************************************************************/ 
/*�������ƣ�nnzuida(int n)                                     */
/*�������ͣ�void                                               */
/*������int n���趨�����δ��ڲ�����������                      */
/*���ܣ���ͼ�����N*N���ֵ�˲���                              */
/***************************************************************/
void ZaoShengXiaoChuDib::nnzuida(int n)
{
    DWORD size;
	size=GetSize();
	int yy,xx,n2,nn,m,madomax,madomax2,madomax3,mado[1000],mado2[1000],mado3[1000];
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height;
    BYTE* p_temp=new BYTE [size];
	memset(p_temp,255,size);
	if(n<3||n%2!=1)//ȷ��n��3���ϵ�����
	AfxMessageBox("������һ�����ڵ���3������");
	if(n>=3&&n%2==1)
	n2=(n-1)/2;
	nn=n*n;
	p_data=this->GetData();//ȡ��ԭͼ��������ָ��
   	wide=this->GetWidth(); //ȡ��ԭͼ����������
    height=this->GetHeight();  //ȡ��ԭͼ����������
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		//n*n���ֵƵ���˲�
		for(int j=n2;j<height-n2;j++)
		for(int i=n2;i<wide-n2;i++)
		{
			//��n*n���δ��ڲ��ָ��Ƶ�mado[m]
			m=0;
			for(yy=j-n2;yy<=j+n2;yy++)
			for(xx=i-n2;xx<=i+n2;xx++)
			{
				mado[m]=p_data[yy*wide+xx];
				m++;
			}
			//�ҳ�mado[m]�е����ֵmadomax,�������Ƶ��ֵ
			madomax=mado[0];
			for(m=1;m<nn;m++)
				if(madomax<mado[m])
				madomax=mado[m];
			p_temp[j*wide+i]=madomax;
		}                 
		memcpy(m_pData,p_temp,size);
		delete p_temp;
	}
	else	//24λ��ɫ
	{		    
		//n*n���ֵƵ���˲�
		for(int j=n2;j<height-n2;j++)
		for(int i=n2;i<wide-n2;i++)
		{
			//��n*n���δ��ڲ��ָ��Ƶ�mado[m]
			m=0;
			for(yy=j-n2;yy<=j+n2;yy++)
			for(xx=i-n2;xx<=i+n2;xx++)
			{
				mado[m]=p_data[yy*wide*3+xx*3];
				mado2[m]=p_data[yy*wide*3+xx*3+1];
				mado3[m]=p_data[yy*wide*3+xx*3+2];
				m++;
			}
			//�ҳ�mado[m]�е����ֵmadomax,�������Ƶ��ֵ
			madomax=mado[0];
			madomax2=mado2[0];
			madomax3=mado3[0];
			for(m=1;m<nn;m++)
			{
				if(madomax<mado[m])
					madomax=mado[m];
				if(madomax2<mado2[m])
					madomax2=mado2[m];
				if(madomax3<mado3[m])
					madomax3=mado3[m];
			}
			p_temp[j*wide*3+i*3]=madomax;
			p_temp[j*wide*3+i*3+1]=madomax2;
			p_temp[j*wide*3+i*3+2]=madomax3;
		}                 
		memcpy(m_pData,p_temp,wide*height*3);
		delete p_temp;
	}
}

/***************************************************************/  
/*�������ƣ�suijizaosheng()                                    */
/*�������ͣ�void                                               */
/*���ܣ���ͼ����������������                               */
/***************************************************************/
void ZaoShengXiaoChuDib::suijizaosheng()
{
	int noisepoint;
    DWORD size;
	size=GetSize();
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height;
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		BYTE* p_temp=new BYTE [size];
		memset(p_temp,255,size);
		p_data=this->GetData();//ȡ��ԭͼ��������ָ��
		memcpy(p_temp,p_data,size);
		wide=this->GetWidth(); //ȡ��ԭͼ����������
		height=this->GetHeight();  //ȡ��ԭͼ����������
		//�����������
		for(int j=0;j<height;j++)
		for(int i=0;i<wide;i++)
		{
			noisepoint=rand()/1024;
			p_temp[j*wide+i]=(p_temp[j*wide+i]*224/256+(int)noisepoint);
		}
		memcpy(m_pData,p_temp,size);
		delete p_temp;
	}
	else	//24λ��ɫ
	{
		size=GetSize();
		BYTE* p_temp=new BYTE [size];
		memset(p_temp,255,size);
		p_data=this->GetData();//ȡ��ԭͼ��������ָ��
		memcpy(p_temp,p_data,size);
		wide=this->GetWidth()*3; //ȡ��ԭͼ����������
		height=this->GetHeight();  //ȡ��ԭͼ����������
		//�����������
		for(int j=0;j<height;j++)
		for(int i=0;i<wide;i++)
		{
			noisepoint=rand()/1024;
			p_temp[j*wide+i]=(p_temp[j*wide+i]*224/256+(int)noisepoint);
		}
		memcpy(m_pData,p_temp,size);
		delete p_temp;
	}
}

/***************************************************************/
/*�������ƣ�jiaoyanzaosheng()                                  */
/*�������ͣ�void                                               */
/*���ܣ���ͼ����н�����������                               */
/***************************************************************/
void ZaoShengXiaoChuDib::jiaoyanzaosheng()
{
    DWORD size;
	size=GetSize();
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height;
    BYTE* p_temp=new BYTE [size];
	p_data=this->GetData();//ȡ��ԭͼ��������ָ��
	memcpy(p_temp,p_data,size);
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		wide=this->GetWidth(); //ȡ��ԭͼ����������
		height=this->GetHeight();  //ȡ��ԭͼ����������
		for(int j=0;j<height;j++)
		for(int i=0;i<wide;i++)
		{
			if(rand()>31500)
				p_temp[j*wide+i]=0;
		}
		memcpy(m_pData,p_temp,size);
		delete p_temp;
	}
	else	//24λ��ɫ
	{
		size=GetSize();
		BYTE* p_temp=new BYTE [size];
		p_data=this->GetData();//ȡ��ԭͼ��������ָ��
		memcpy(p_temp,p_data,size);
		wide=this->GetWidth()*3; //ȡ��ԭͼ����������
		height=this->GetHeight();  //ȡ��ԭͼ����������
		for(int j=0;j<height;j++)
		for(int i=0;i<wide;i++)
		{
			if(rand()>31500)
				p_temp[j*wide+i]=0;
		}
		memcpy(m_pData,p_temp,size);
		delete p_temp;
	}
}

/***************************************************************/ 
/*�������ƣ�jubupingjun()                                      */
/*�������ͣ�void                                               */
/*���ܣ���ͼ����оֲ�ƽ��������                             */
/***************************************************************/
void ZaoShengXiaoChuDib::jubupingjun() 
{
    DWORD size;
	size=GetSize();
	BYTE *p_data;//ԭͼ������ָ��
	BYTE* p_temp=new BYTE[size];
	int wide,height;
    int n,ji[9],nmin;
	float mean[9],bunsan[9],bmin;
	p_data=this->GetData();//ȡ��ԭͼ��������ָ��
	wide=this->GetWidth(); //ȡ��ԭͼ����������
    height=this->GetHeight();  //ȡ��ԭͼ����������
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{    
		memset(p_temp,255,size);
		for(int j=2;j<=height-3;j++)
		for(int i=2;i<=wide-3;i++)
		{
		//��9�ֽ�������ľ�ֵ���䷽��
			//��1��������
			ji[0]=p_data[(j-1)*wide+(i-1)];
			ji[1]=p_data[(j-1)*wide+i];
			ji[2]=p_data[(j-1)*wide+(i+1)];
			ji[3]=p_data[j*wide+(i-1)];
			ji[4]=p_data[j*wide+i];
			ji[5]=p_data[j*wide+(i+1)];
			ji[6]=p_data[(j+1)*wide+(i-1)];
			ji[7]=p_data[(j+1)*wide+i];
			ji[8]=p_data[(j+1)*wide+(i+1)];
			mean[0]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6]+ji[7]+ji[8])/9;
			bunsan[0]=0;
			for(n=0;n<=8;n++)
				bunsan[0]+=ji[n]*ji[n]-mean[0]*mean[0];
			//��2��������
			ji[0]=p_data[(j-2)*wide+(i-1)];
			ji[1]=p_data[(j-2)*wide+i];
			ji[2]=p_data[(j-2)*wide+(i+1)];
			ji[3]=p_data[(j-1)*wide+(i-1)];
			ji[4]=p_data[(j-1)*wide+i];
			ji[5]=p_data[(j-1)*wide+(i+1)];
			ji[6]=p_data[j*wide+i];
			mean[1]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
			bunsan[1]=0;
			for(n=0;n<=6;n++)
				bunsan[1]+=ji[n]*ji[n]-mean[1]*mean[1];
			//��3��������
			ji[0]=p_data[(j-1)*wide+(i-2)];
			ji[1]=p_data[(j-1)*wide+(i-1)];
			ji[2]=p_data[j*wide+(i-2)];
			ji[3]=p_data[j*wide+(i-1)];
			ji[4]=p_data[j*wide+i];
			ji[5]=p_data[(j+1)*wide+(i-2)];
			ji[6]=p_data[(j+1)*wide+(i-1)];
			mean[2]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
			bunsan[2]=0;
			for(n=0;n<=6;n++)
				bunsan[2]+=ji[n]*ji[n]-mean[2]*mean[2];
			//��4��������
			ji[0]=p_data[j*wide+i];
			ji[1]=p_data[(j+1)*wide+(i-1)];
			ji[2]=p_data[(j+1)*wide+i];
			ji[3]=p_data[(j+1)*wide+(i+1)];
			ji[4]=p_data[(j+2)*wide+(i-1)];
			ji[5]=p_data[(j+2)*wide+i];
			ji[6]=p_data[(j+2)*wide+(i+1)];
			mean[3]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
	  		bunsan[3]=0;
			for(n=0;n<=6;n++)
				bunsan[3]+=ji[n]*ji[n]-mean[3]*mean[3];
			//��5��������
			ji[0]=p_data[(j-1)*wide+(i+1)];
			ji[1]=p_data[(j-1)*wide+(i+2)];
			ji[2]=p_data[j*wide+i];
			ji[3]=p_data[j*wide+(i+1)];
			ji[4]=p_data[j*wide+(i+2)];
			ji[5]=p_data[(j+1)*wide+(i+1)];
			ji[6]=p_data[(j+1)*wide+(i+2)]; 
			mean[4]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
			bunsan[4]=0;
			for(n=0;n<=6;n++)
				bunsan[4]+=ji[n]*ji[n]-mean[4]*mean[4];	
			//��6��������
			ji[0]=p_data[(j-2)*wide+(i+1)];
			ji[1]=p_data[(j-2)*wide+(i+2)];
			ji[2]=p_data[(j-1)*wide+i];
			ji[3]=p_data[(j-1)*wide+(i+1)];
			ji[4]=p_data[(j-1)*wide+(i+2)];
			ji[5]=p_data[j*wide+i];
			ji[6]=p_data[j*wide+(i+1)]; 
			mean[5]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
	  		bunsan[5]=0;
			for(n=0;n<=6;n++)
				bunsan[5]+=ji[n]*ji[n]-mean[5]*mean[5];
			//��7��������
			ji[0]=m_pData[(j-2)*wide+(i-2)];
			ji[1]=p_data[(j-2)*wide+(i-1)];
			ji[2]=p_data[(j-1)*wide+(i-2)];
			ji[3]=p_data[(j-1)*wide+(i-1)];
			ji[4]=p_data[(j-1)*wide+i];
			ji[5]=p_data[j*wide+(i-1)];
			ji[6]=p_data[j*wide+i];
			mean[6]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
	 		bunsan[6]=0;
			for(n=0;n<=6;n++)
				bunsan[6]+=ji[n]*ji[n]-mean[6]*mean[6];
			//��8��������
			ji[0]=m_pData[j*wide+(i-1)];
			ji[1]=p_data[j*wide+i];
			ji[2]=p_data[(j+1)*wide+(i-2)];
			ji[3]=p_data[(j+1)*wide+(i-1)];
			ji[4]=p_data[(j+1)*wide+i];
			ji[5]=p_data[(j+2)*wide+(i-2)];
			ji[6]=p_data[(j+2)*wide+(i-1)];
			mean[7]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
	  		bunsan[7]=0;
			for(n=0;n<=6;n++)
				bunsan[7]+=ji[n]*ji[n]-mean[7]*mean[7];
			//��9��������
			ji[0]=p_data[j*wide+i];
			ji[1]=p_data[j*wide+(i+1)];
			ji[2]=p_data[(j+1)*wide+i];
			ji[3]=p_data[(j+1)*wide+(i+1)];
			ji[4]=p_data[(j+1)*wide+(i+2)];
			ji[5]=p_data[(j+2)*wide+(i+1)];
			ji[6]=p_data[(j+2)*wide+(i+2)];
			mean[8]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
	  		bunsan[8]=0;
			for(n=0;n<=6;n++)
				bunsan[8]+=ji[n]*ji[n]-mean[8]*mean[8];
			//�󷽲���С�Ľ�������nmin
			bmin=bunsan[0];
			nmin=0;
			for(n=0;n<=8;n++)
			{
				if(bmin>bunsan[n])
				{
					bmin=bunsan[n];
					nmin=n;
				}
				//��nmin��ֵ�����������Ϊ��ʾͼ���ֵ
				p_temp[j*wide+i]=(int)(mean[nmin]+0.5);
			}				 
		}
		memcpy(p_data,p_temp,size);
		delete p_temp;	
	}
	else	//24λ��ɫ
	{		    
		p_temp=new BYTE[wide*height*3];
		memset(p_temp,255,wide*height*3);
		for(int k=0;k<3;k++)
		for(int j=2;j<=height-3;j++)
		{
			for(int i=2;i<=wide-3;i++)
			{
			//��9�ֽ�������ľ�ֵ���䷽��
				//��1��������
				ji[0]=p_data[(j-1)*wide*3+(i-1)*3+k+k];
				ji[1]=p_data[(j-1)*wide*3+i*3+k];
				ji[2]=p_data[(j-1)*wide*3+(i+1)*3+k];
				ji[3]=p_data[j*wide*3+(i-1)*3+k];
				ji[4]=p_data[j*wide*3+i*3+k];
				ji[5]=p_data[j*wide*3+(i+1)*3+k];
				ji[6]=p_data[(j+1)*wide*3+(i-1)*3+k];
				ji[7]=p_data[(j+1)*wide*3+i*3+k];
				ji[8]=p_data[(j+1)*wide*3+(i+1)*3+k];
				mean[0]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6]+ji[7]+ji[8])/9;
				bunsan[0]=0;
				for(n=0;n<=8;n++)
					bunsan[0]+=ji[n]*ji[n]-mean[0]*mean[0];
				//��2��������
				ji[0]=p_data[(j-2)*wide*3+(i-1)*3+k];
				ji[1]=p_data[(j-2)*wide*3+i*3+k];
				ji[2]=p_data[(j-2)*wide*3+(i+1)*3+k];
				ji[3]=p_data[(j-1)*wide*3+(i-1)*3+k];
				ji[4]=p_data[(j-1)*wide*3+i*3+k];
				ji[5]=p_data[(j-1)*wide*3+(i+1)*3+k];
				ji[6]=p_data[j*wide*3+i*3+k];
				mean[1]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
				bunsan[1]=0;
				for(n=0;n<=6;n++)
					bunsan[1]+=ji[n]*ji[n]-mean[1]*mean[1];
				//��3��������
				ji[0]=p_data[(j-1)*wide*3+(i-2)*3+k];
				ji[1]=p_data[(j-1)*wide*3+(i-1)*3+k];
				ji[2]=p_data[j*wide*3+(i-2)*3+k];
				ji[3]=p_data[j*wide*3+(i-1)*3+k];
				ji[4]=p_data[j*wide*3+i*3+k];
				ji[5]=p_data[(j+1)*wide*3+(i-2)*3+k];
				ji[6]=p_data[(j+1)*wide*3+(i-1)*3+k];
				mean[2]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
				bunsan[2]=0;
				for(n=0;n<=6;n++)
					bunsan[2]+=ji[n]*ji[n]-mean[2]*mean[2];
				//��4��������
				ji[0]=p_data[j*wide*3+i*3+k];
				ji[1]=p_data[(j+1)*wide*3+(i-1)*3+k];
				ji[2]=p_data[(j+1)*wide*3+i*3+k];
				ji[3]=p_data[(j+1)*wide*3+(i+1)*3+k];
				ji[4]=p_data[(j+2)*wide*3+(i-1)*3+k];
				ji[5]=p_data[(j+2)*wide*3+i*3+k];
				ji[6]=p_data[(j+2)*wide*3+(i+1)*3+k];
				mean[3]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
	  			bunsan[3]=0;
				for(n=0;n<=6;n++)
					bunsan[3]+=ji[n]*ji[n]-mean[3]*mean[3];
				//��5��������
				ji[0]=p_data[(j-1)*wide*3+(i+1)*3+k];
				ji[1]=p_data[(j-1)*wide*3+(i+2)*3+k];
				ji[2]=p_data[j*wide*3+i*3+k];
				ji[3]=p_data[j*wide*3+(i+1)*3+k];
				ji[4]=p_data[j*wide*3+(i+2)*3+k];
				ji[5]=p_data[(j+1)*wide*3+(i+1)*3+k];
				ji[6]=p_data[(j+1)*wide*3+(i+2)*3+k]; 
				mean[4]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
				bunsan[4]=0;
				for(n=0;n<=6;n++)
					bunsan[4]+=ji[n]*ji[n]-mean[4]*mean[4];	
				//��6��������
				ji[0]=p_data[(j-2)*wide*3+(i+1)*3+k];
				ji[1]=p_data[(j-2)*wide*3+(i+2)*3+k];
				ji[2]=p_data[(j-1)*wide*3+i*3+k];
				ji[3]=p_data[(j-1)*wide*3+(i+1)*3+k];
				ji[4]=p_data[(j-1)*wide*3+(i+2)*3+k];
				ji[5]=p_data[j*wide*3+i*3+k];
				ji[6]=p_data[j*wide*3+(i+1)*3+k]; 
				mean[5]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
	  			bunsan[5]=0;
				for(n=0;n<=6;n++)
					bunsan[5]+=ji[n]*ji[n]-mean[5]*mean[5];
				//��7��������
				ji[0]=m_pData[(j-2)*wide*3+(i-2)*3+k];
				ji[1]=p_data[(j-2)*wide*3+(i-1)*3+k];
				ji[2]=p_data[(j-1)*wide*3+(i-2)*3+k];
				ji[3]=p_data[(j-1)*wide*3+(i-1)*3+k];
				ji[4]=p_data[(j-1)*wide*3+i*3+k];
				ji[5]=p_data[j*wide*3+(i-1)*3+k];
				ji[6]=p_data[j*wide*3+i*3+k];
				mean[6]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
	 			bunsan[6]=0;
				for(n=0;n<=6;n++)
					bunsan[6]+=ji[n]*ji[n]-mean[6]*mean[6];
				//��8��������
				ji[0]=m_pData[j*wide*3+(i-1)*3+k];
				ji[1]=p_data[j*wide*3+i*3+k];
				ji[2]=p_data[(j+1)*wide*3+(i-2)*3+k];
				ji[3]=p_data[(j+1)*wide*3+(i-1)*3+k];
				ji[4]=p_data[(j+1)*wide*3+i*3+k];
				ji[5]=p_data[(j+2)*wide*3+(i-2)*3+k];
				ji[6]=p_data[(j+2)*wide*3+(i-1)*3+k];
				mean[7]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
	  			bunsan[7]=0;
				for(n=0;n<=6;n++)
					bunsan[7]+=ji[n]*ji[n]-mean[7]*mean[7];
				//��9��������
				ji[0]=p_data[j*wide*3+i*3+k];
				ji[1]=p_data[j*wide*3+(i+1)*3+k];
				ji[2]=p_data[(j+1)*wide*3+i*3+k];
				ji[3]=p_data[(j+1)*wide*3+(i+1)*3+k];
				ji[4]=p_data[(j+1)*wide*3+(i+2)*3+k];
				ji[5]=p_data[(j+2)*wide*3+(i+1)*3+k];
				ji[6]=p_data[(j+2)*wide*3+(i+2)*3+k];
				mean[8]=(float)(ji[0]+ji[1]+ji[2]+ji[3]+ji[4]+ji[5]+ji[6])/7;
	  			bunsan[8]=0;
				for(n=0;n<=6;n++)
					bunsan[8]+=ji[n]*ji[n]-mean[8]*mean[8];
				//�󷽲���С�Ľ�������nmin
				bmin=bunsan[0];
				nmin=0;
				for(n=0;n<=8;n++)
				{
					if(bmin>bunsan[n])
					{
						bmin=bunsan[n];
						nmin=n;
					}
					//��nmin��ֵ�����������Ϊ��ʾͼ���ֵ
					p_temp[j*wide*3+i*3+k]=(int)(mean[nmin]+0.5);		
				}				 
			}
		}
		memcpy(p_data,p_temp,size);
		delete p_temp;
	}
}

