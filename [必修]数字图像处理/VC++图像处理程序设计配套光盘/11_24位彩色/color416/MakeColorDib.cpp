// MakeColorDib.cpp: implementation of the MakeColorDib class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DSplit.h"
#include "MakeColorDib.h"
#include "MainFrm.h"
#include "math.h"
#define BOUND(x,a,b) (((x) < (a)) ? (a) : (((x) > (b)) ? (b) : (x)))
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MakeColorDib::MakeColorDib()
{

}

MakeColorDib::~MakeColorDib()
{

}

/***************************************************************/
/*�������ƣ�MakegGray()                                        */
/*�������ͣ�void                                               */
/*���ܣ����ɫת����256ɫ�Ҷ�ͼ��                            */
/***************************************************************/
void MakeColorDib::MakegGray()    //�Ҷȱ仯
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();   //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	for(int j=0;j<height;j++)	// ÿ��
		for(int i=0;i<DibWidth;i+=3)	// ÿ��
		{
			BYTE* pbyBlue = p_data++;   //�õ���ɫֵ
			BYTE* pbyGreen = p_data++;  //�õ���ɫֵ
			BYTE* pbyRed = p_data++;    //�õ���ɫֵ
			BYTE r = *pbyRed;
			BYTE g = *pbyGreen;
			BYTE b = *pbyBlue;
			//ȡ��ԭr,g,b�е����ֵ��Ϊ����������ֵ����ֵ
			int gray=0;
			if(r>g)
				gray=r;
			else 
				gray=g;
			if(gray<b)
				gray=b;			
       		*pbyBlue = gray;     //��ȡ�������ֵ�������ص�������
			*pbyGreen = gray;    //��ȡ�������ֵ�������ص��̷���
			*pbyRed = gray;	     //��ȡ�������ֵ�������صĺ����
		}
}

/***************************************************************/
/*�������ƣ�LightAlter(int m_Light)                            */
/*�������ͣ�void                                               */
/*������int m_Light���û���������ֵ                            */
/*���ܣ���ͼ��ʹ����ֵ���������ȵ�����                         */
/***************************************************************/
void MakeColorDib::LightAlter(int m_Light)    //���ȵ���
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();    //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	for(int j=0;j<height;j++)	// ÿ��
	for(int i=0;i<DibWidth;i++)	// ÿ��
	{   
		int a=0;
		a=int(*p_data*m_Light/100);   //������ǰ�������
		*p_data=a;
		//�жϷ�Χ��ȡ�ú����ֵ
		if(a<0) 
			*p_data=0;  
	    if(a>255)
			*p_data=255;
        p_data++;   //ָ����һָ��
	}
}

/***************************************************************/
/*�������ƣ�LightReverse()                                     */
/*�������ͣ�void                                               */
/*���ܣ�ͼ�������ȡ����                                       */
/***************************************************************/
void MakeColorDib::LightReverse()    //����ȡ��
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	for(int j=0;j<height;j++)	// ÿ��
		for(int i=0;i<DibWidth;i++)	// ÿ��
		{
			int a=*p_data;   //ȡ�õ�ǰ���ֵ
			*p_data=255-a;    //ȡ��
			p_data++;  //ָ����һָ��  
		}
}

/***************************************************************/
/*�������ƣ�ContrastAlter(int m_Increment)                     */
/*�������ͣ�void                                               */
/*������int m_Increment���û���������ֵ                        */
/*���ܣ���ͼ��ʹ����ֵ�������Աȶȴ���                       */
/***************************************************************/
void MakeColorDib::ContrastAlter(int m_Increment)   ///�Աȶȴ���
{
	int nHigh = 255 - m_Increment;
	//���ڼ���������Դ���
	if(nHigh < m_Increment)
	{
		nHigh = 127;
		m_Increment = 120;
	}
	if(m_Increment < -127)
		m_Increment = -120;
	//��չ��ѹ������ĳ���
	int nStretch = 255;
	if(m_Increment >= 0)
		nStretch = 255 - 2 * m_Increment;
	else
		nStretch = 255 + 2 * m_Increment;
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	if(m_Increment >= 0)   // m_Increment>=0ʱ
	{
		for(int j=0;j<height;j++)	// ÿ��
			for(int i=0;i<DibWidth-3;i+=3)	// ÿ��
			{   
				//ȡ�õ�ǰ�㣨��ɫ����ֵ������
				BYTE* pbyBlue = p_data++;    
				if(*pbyBlue<=m_Increment)
					*pbyBlue=0;
				else if(*pbyBlue>nHigh)
					*pbyBlue=255;
				else
					*pbyBlue=(BYTE)((((int)*pbyBlue - m_Increment) * 255) / nStretch );
				//ȡ�õ�ǰ�㣨��ɫ����ֵ������
				BYTE* pbyGreen = p_data++;
				if(*pbyGreen<=m_Increment)
					*pbyGreen=0;
				else if(*pbyGreen>nHigh)
					*pbyGreen=255;
				else
					*pbyGreen=(BYTE)((((int)*pbyGreen - m_Increment) * 255) / nStretch );
				//ȡ�õ�ǰ�㣨��ɫ����ֵ������
				BYTE* pbyRed = p_data++;
				if(*pbyRed<=m_Increment)
					*pbyRed=0;
				else if(*pbyRed>nHigh)
					*pbyRed=255;
				else
					*pbyRed=(BYTE)((((int)*pbyRed - m_Increment) * 255) / nStretch );
			}
			
	}
	else  // m_Increment < 0 ʱ
	{
		for(int j=0;j<height;j++)
			for(int i=0;i<DibWidth-3;i+=3)
			{	//ȡ�õ�ǰ�㣨��ɫ����ֵ������
				BYTE* pbyBlue = p_data++;
				*pbyBlue = (BYTE)((((int)(*pbyBlue) * nStretch) / 255) - m_Increment);
				//ȡ�õ�ǰ�㣨��ɫ����ֵ������
				BYTE* pbyGreen = p_data++;
				*pbyGreen = (BYTE)((((int)(*pbyGreen) * nStretch) / 255) - m_Increment);
				//ȡ�õ�ǰ�㣨��ɫ����ֵ������
				BYTE* pbyRed = p_data++;
				*pbyRed = (BYTE)((((int)(*pbyRed) * nStretch) / 255) - m_Increment);				
			}
	}
}

/***************************************************************/
/*�������ƣ�Exposal()                                          */
/*�������ͣ�void                                               */
/*���ܣ�ͼ���ع⴦��                                         */
/***************************************************************/
void MakeColorDib::Exposal() //�ع⴦��
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	for(int j=0;j<height;j++)	// ÿ��
		for(int i=0;i<DibWidth;i++)	// ÿ��
		{
			BYTE* pbydata = p_data++;  //ȡ�õ�ǰ���ֵ
			BYTE a=*pbydata;   //������ʱ����
			*pbydata=(a>128)?a:(255-a);   //����
		}
		
}

/***************************************************************/
/*�������ƣ�PaintColor(int m_Red,int m_Green,int m_Blue)       */
/*�������ͣ�void                                               */
/*������int m_Red��m_Green��m_Blue���û������ĺ�����ֵ         */
/*���ܣ���ͼ��ʹ����ֵ��������ɫ����                         */
/***************************************************************/
void MakeColorDib::PaintColor(int m_Red,int m_Green,int m_Blue) //��ɫ����
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	for(int j=0;j<height;j++)	// ÿ��
		for(int i=0;i<DibWidth;i+=3)	// ÿ��
		{			
			BYTE* pbyBlue = p_data++;	//ȡ�õ�ǰ�㣨��ɫ����ֵ					
			BYTE* pbyGreen = p_data++;  //ȡ�õ�ǰ�㣨��ɫ����ֵ
			BYTE* pbyRed = p_data++;    //ȡ�õ�ǰ�㣨��ɫ����ֵ
			BYTE r = *pbyRed;
			BYTE g = *pbyGreen;
			BYTE b = *pbyBlue;
    		BYTE gray=(BYTE)(((WORD)r * 59 + (WORD)g * 30 + (WORD)b * 11) / 100);
			*pbyBlue = (BYTE)((m_Blue * gray) / 255);  
			*pbyGreen = (BYTE)((m_Green * gray) / 255);
			*pbyRed = (BYTE)((m_Red * gray) / 255);
		}
}

/***************************************************************/
/*�������ƣ�NeonLight()                                        */
/*�������ͣ�void                                               */
/*���ܣ�ʹͼ������޺紦��Ч����                               */
/***************************************************************/
void MakeColorDib::NeonLight()   //�޺紦��
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
    BYTE *p_temp=new BYTE[height*DibWidth];	// ��ʱ�����ڴ棬�Ա�����ͼ��
	for(int j=0;j<height-4;j++)	// ÿ��
	{
		for(int i=0;i<DibWidth-1;i++)	// ÿ��
		{
			 int pby_pt=0;
			 //������ִ���㷨
			 pby_pt=(*(p_data+(height-j-1)*DibWidth+i)-*(p_data+(height-j-1)*DibWidth+i+3))
				   *(*(p_data+(height-j-1)*DibWidth+i)-*(p_data+(height-j-1)*DibWidth+i+3))
				   +(*(p_data+(height-j-1)*DibWidth+i)-*(p_data+(height-j-2)*DibWidth+i))
				   *(*(p_data+(height-j-1)*DibWidth+i)-*(p_data+(height-j-2)*DibWidth+i));
			*(p_temp+(height-j-1)*DibWidth+i)=2*int(sqrt(pby_pt));
			//�жϺϷ���
			if(*(p_temp+(height-j-1)*DibWidth+i)<0)
				 *(p_temp+(height-j-1)*DibWidth+i)=0;
			if(*(p_temp+(height-j-1)*DibWidth+i)>255)
				 *(p_temp+(height-j-1)*DibWidth+i)=255;
		}
	}
    memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
    delete []p_temp;   //ɾ����ʱ�����ڴ�
}

/***************************************************************/
/*�������ƣ�Smoothness()                                       */
/*�������ͣ�void                                               */
/*���ܣ�ʹͼ��ƽ������                                       */
/***************************************************************/
void MakeColorDib::Smoothness()   //ƽ������
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
    int h[3][3];////����(3x3)����
	h[0][0] = 1;  h[0][1] = 1; h[0][2] = 1;
	h[1][0] = 1;  h[1][1] = 1; h[1][2] = 1;
	h[2][0] = 1;  h[2][1] = 1; h[2][2] = 1;
    BYTE *p_temp=new BYTE[height*DibWidth];	// ��ʱ�����ڴ棬�Ա�����ͼ��
	for(int j=0;j<height-2;j++)	// ÿ��
	{
		for(int i=0;i<DibWidth-8;i++)	// ÿ��
		{
	        double pby_pt=0;
                    //��Ӧ�ĵ�0�е�ֵ���Ծ����Ӧֵ�������
		     pby_pt= h[0][0]*(*(p_data+(height-j-1)*DibWidth+i))
				    +h[0][1]*(*(p_data+(height-j-1)*DibWidth+i+3))
				    +h[0][2]*(*(p_data+(height-j-1)*DibWidth+i+6))
                    //��Ӧ�ĵ�1�е�ֵ���Ծ����Ӧֵ�������
			    	+h[1][0]*(*(p_data+(height-j-2)*DibWidth+i))
			    	+h[1][1]*(*(p_data+(height-j-2)*DibWidth+i+3))
			    	+h[1][2]*(*(p_data+(height-j-2)*DibWidth+i+6))
                    //��Ӧ�ĵ�2�е�ֵ���Ծ����Ӧֵ�������
    		        +h[2][0]*(*(p_data+(height-j-3)*DibWidth+i))
					+h[2][1]*(*(p_data+(height-j-3)*DibWidth+i+3))
					+h[2][2]*(*(p_data+(height-j-3)*DibWidth+i+6));
			*(p_temp+(height-j-2)*DibWidth+i+3)=abs(int(pby_pt/9));//ȡ�ܺ͵ĵ�ƽ��ֵ
		}
	}
   	memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
   	delete []p_temp;//ɾ����ʱ�����ڴ�
}

/***************************************************************/
/*�������ƣ�Embossment()                                       */
/*�������ͣ�void                                               */
/*���ܣ�����ͼ�񸡵���Ч����                                 */
/***************************************************************/
void MakeColorDib::Embossment()   //������
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
    BYTE *p_temp=new BYTE[height*DibWidth];	// ��ʱ�����ڴ棬�Ա�����ͼ��
	for(int j=0;j<height;j++)	// ÿ��
	{
		for(int i=0;i<DibWidth-4;i++)	// ÿ��
		{
			 int pby_pt=0;
			 //�����ص�ÿ������ִ���㷨
			 pby_pt=*(p_data+(height-j-1)*DibWidth+i)
				   -*(p_data+(height-j-1)*DibWidth+i+3)+128;
			 *(p_temp+(height-j-1)*DibWidth+i+3)=pby_pt;
			//����Ϸ���
			if(*(p_temp+(height-j-1)*DibWidth+i+3)<0)
				*(p_temp+(height-j-1)*DibWidth+i+3)=0;
			else if(*(p_temp+(height-j-1)*DibWidth+i+3)>255)
				*(p_temp+(height-j-1)*DibWidth+i+3)=255;
		}
	}
    memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
    delete []p_temp;   //ɾ����ʱ�����ڴ�
}

/***************************************************************/
/*�������ƣ�Spread()                                           */
/*�������ͣ�void                                               */
/*���ܣ�ͼ����ɢ����                                         */
/***************************************************************/
void MakeColorDib::Spread()   //��ɢ����
{ 
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
    BYTE *p_temp=new BYTE[height*DibWidth];	// ��ʱ�����ڴ棬�Ա�����ͼ��
	for(int j=0;j<height-4;j++)	// ÿ��
	{
		for(int i=0;i<DibWidth-14;i++)	// ÿ��
		{
			 int m=0,n=0;
			 m=rand()%5; //ȡ���������
			 n=rand()%5; //ȡ���������
			 int pby_pt=0;	
			 pby_pt=*(p_data+(height-j-1-m)*DibWidth+i+3*n);//�õ���Ӧ�������ֵ
			 *(p_temp+(height-j-3)*DibWidth+i+6)=pby_pt;
		}
	}
    memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
    delete []p_temp;   //ɾ����ʱ�����ڴ�
}

/***************************************************************/
/*�������ƣ�Sharp()                                            */
/*�������ͣ�void                                               */
/*���ܣ�ͼ���񻯴���                                         */
/***************************************************************/
void MakeColorDib::Sharp()   //ͼ����
{
 	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
    BYTE *p_temp=new BYTE[height*DibWidth];
	for(int j=0;j<height-1;j++)	// ÿ��
	{
		for(int i=0;i<DibWidth-5;i++)	// ÿ��
		{
	        int pby_pt=0;	
			pby_pt= *(p_data+(height-j-2)*DibWidth+i+3)
			       -*(p_data+(height-j-1)*DibWidth+i);
			*(p_temp+(height-j-2)*DibWidth+i+3)=*(p_data+(height-j-2)*DibWidth+i+3)
				                                 +abs(int(pby_pt/4));
			if(*(p_temp+(height-j-2)*DibWidth+i+3)>255)
			   *(p_temp+(height-j-2)*DibWidth+i+3)=255;
		}
	}
    memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
    delete []p_temp;  //ɾ����ʱ�����ڴ�
}

/***************************************************************/
/*�������ƣ�HighLVBO(int m_GaoTong)                            */
/*�������ͣ�void                                               */
/*������int m_GaoTong���û���������ֵ��ѡ�����                */
/*���ܣ���ͼ��ʹ����ֵ�����и�ͨ�˲���                         */
/***************************************************************/
void MakeColorDib::HighLVBO(int m_GaoTong)   //��ͨ�˲�
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	int h[3][3];  ////����(3x3)����
	if(m_GaoTong==1)
	{   //����1��������ͨ��
		h[0][0] =1;   h[0][1] =-2;  h[0][2] =1;
		h[1][0] =-2;  h[1][1] =5;   h[1][2] =-2;
		h[2][0] =1;   h[2][1] =-2;  h[2][2] =1;
	}
	else if(m_GaoTong==2)
	{   //����2���еȸ�ͨ��
		h[0][0] = 0;   h[0][1] = -1; h[0][2] = 0;
		h[1][0] = -1;  h[1][1] =  5; h[1][2] = -1;
		h[2][0] = 0;   h[2][1] = -1; h[2][2] = 0;
	}
	else
	{   //����3��������ͨ��
		h[0][0] = -1;  h[0][1] = -1; h[0][2] = -1;
		h[1][0] = -1;  h[1][1] =  9; h[1][2] = -1;
		h[2][0] = -1;  h[2][1] = -1; h[2][2] = -1;
	}
    BYTE *p_temp=new BYTE[height*DibWidth];	// ��ʱ�����ڴ棬�Ա�����ͼ��
	for(int j=0;j<height-2;j++)	// ÿ��
	{
		for(int i=0;i<DibWidth-8;i++)	// ÿ��
		{
			int pby_pt=0;
			//��Ӧ�ĵ�0�е�ֵ���Ծ����Ӧֵ�������
			pby_pt=  h[0][0]*(*(p_data+(height-j-1)*DibWidth+i))
				+h[0][1]*(*(p_data+(height-j-1)*DibWidth+i+3))
				+h[0][2]*(*(p_data+(height-j-1)*DibWidth+i+6))
				//��Ӧ�ĵ�1�е�ֵ���Ծ����Ӧֵ�������
				+h[1][0]*(*(p_data+(height-j-2)*DibWidth+i))
				+h[1][1]*(*(p_data+(height-j-2)*DibWidth+i+3))
				+h[1][2]*(*(p_data+(height-j-2)*DibWidth+i+6))
				//��Ӧ�ĵ�2�е�ֵ���Ծ����Ӧֵ�������
				+h[2][0]*(*(p_data+(height-j-3)*DibWidth+i))
				+h[2][1]*(*(p_data+(height-j-3)*DibWidth+i+3))
				+h[2][2]*(*(p_data+(height-j-3)*DibWidth+i+6));
			*(p_temp+(height-j-2)*DibWidth+i+3)=abs(pby_pt);
			if(pby_pt>255) //�ж��Ƿ�Խ��
				*(p_temp+(height-j-2)*DibWidth+i+3)=255;
		}
	}
   	memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
    delete []p_temp;  //ɾ����ʱ�����ڴ�
}

/***************************************************************/
/*�������ƣ�LowLVBO()                                          */
/*�������ͣ�void                                               */
/*���ܣ�ʵ��ͼ���ͨ�˲�(3x3)��                                */
/***************************************************************/
void MakeColorDib::LowLVBO()   //��ͨ�˲�(3x3)
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
    double h[3][3];////����(3x3)����
	h[0][0] = 0.1;  h[0][1] = 0.1; h[0][2] = 0.1;
	h[1][0] = 0.1;  h[1][1] = 0.2; h[1][2] = 0.1;
	h[2][0] = 0.1;  h[2][1] = 0.1; h[2][2] = 0.1;
	BYTE *p_temp=new BYTE[height*DibWidth];	// ��ʱ�����ڴ棬�Ա�����ͼ��
	for(int j=0;j<height-2;j++)	// ÿ��
	{
		for(int i=0;i<DibWidth-8;i++)	// ÿ��
		{
			double pby_pt=0;
            //��Ӧ�ĵ�0�е�ֵ���Ծ����Ӧֵ�������	
			pby_pt=  h[0][0]*(*(p_data+(height-j-1)*DibWidth+i))
				+h[0][1]*(*(p_data+(height-j-1)*DibWidth+i+3))
				+h[0][2]*(*(p_data+(height-j-1)*DibWidth+i+6))
				//��Ӧ�ĵ�0�е�ֵ���Ծ����Ӧֵ�������
				+h[1][0]*(*(p_data+(height-j-2)*DibWidth+i))
				+h[1][1]*(*(p_data+(height-j-2)*DibWidth+i+3))
				+h[1][2]*(*(p_data+(height-j-2)*DibWidth+i+6))
				//��Ӧ�ĵ�0�е�ֵ���Ծ����Ӧֵ�������
				+h[2][0]*(*(p_data+(height-j-3)*DibWidth+i))
				+h[2][1]*(*(p_data+(height-j-3)*DibWidth+i+3))
				+h[2][2]*(*(p_data+(height-j-3)*DibWidth+i+6));
			*(p_temp+(height-j-2)*DibWidth+i+3)=abs(int(pby_pt));
		}
	}
	memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
	delete []p_temp;  //ɾ����ʱ�����ڴ�
}

/***************************************************************/
/*�������ƣ�LowLVBObig()                                       */
/*�������ͣ�void                                               */
/*���ܣ�ʵ��ͼ���ͨ�˲�(5x5)��                                */
/***************************************************************/
void MakeColorDib::LowLVBObig()   //��ͨ�˲�(5x5)
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	int h[5][5];//����(5x5)����
	h[0][0] = 1;  h[0][1] = 1; h[0][2] = 1; h[0][3] = 1; h[0][4] = 1;
	h[1][0] = 1;  h[1][1] = 2; h[1][2] = 2; h[1][3] = 2; h[1][4] = 1;
	h[2][0] = 1;  h[2][1] = 2; h[2][2] = 3; h[2][3] = 2; h[2][4] = 1;
	h[3][0] = 1;  h[3][1] = 2; h[3][2] = 2; h[3][3] = 2; h[3][4] = 1;
	h[4][0] = 1;  h[4][1] = 1; h[4][2] = 1; h[4][3] = 1; h[4][4] = 1;
	BYTE *p_temp=new BYTE[height*DibWidth];	// ��ʱ�����ڴ棬�Ա�����ͼ��
	for(int j=0;j<height-4;j++)	// ÿ��
	{
		for(int i=0;i<DibWidth-14;i++)	// ÿ��
		{
	        int pby_pt=0;
	        //��Ӧ�ĵ�0�е�ֵ���Ծ����Ӧֵ�������
			pby_pt=h[0][0]*(*(p_data+(height-j-1)*DibWidth+i))
				  +h[0][1]*(*(p_data+(height-j-1)*DibWidth+i+3))
				  +h[0][2]*(*(p_data+(height-j-1)*DibWidth+i+6))
			      +h[0][3]*(*(p_data+(height-j-1)*DibWidth+i+9))
				  +h[0][4]*(*(p_data+(height-j-1)*DibWidth+i+12))
                  //��Ӧ�ĵ�1�е�ֵ���Ծ����Ӧֵ�������
			      +h[1][0]*(*(p_data+(height-j-2)*DibWidth+i))
			      +h[1][1]*(*(p_data+(height-j-2)*DibWidth+i+3))
				  +h[1][2]*(*(p_data+(height-j-2)*DibWidth+i+6))
				  +h[1][3]*(*(p_data+(height-j-2)*DibWidth+i+9))
				  +h[1][4]*(*(p_data+(height-j-2)*DibWidth+i+12))
                  //��Ӧ�ĵ�2�е�ֵ���Ծ����Ӧֵ�������
			      +h[2][0]*(*(p_data+(height-j-3)*DibWidth+i))
				  +h[2][1]*(*(p_data+(height-j-3)*DibWidth+i+3))
				  +h[2][2]*(*(p_data+(height-j-3)*DibWidth+i+6))
				  +h[2][3]*(*(p_data+(height-j-3)*DibWidth+i+9))
				  +h[2][4]*(*(p_data+(height-j-3)*DibWidth+i+12))
                  //��Ӧ�ĵ�3�е�ֵ���Ծ����Ӧֵ�������
			      +h[3][0]*(*(p_data+(height-j-4)*DibWidth+i))
			      +h[3][1]*(*(p_data+(height-j-4)*DibWidth+i+3))
				  +h[3][2]*(*(p_data+(height-j-4)*DibWidth+i+6))
				  +h[3][3]*(*(p_data+(height-j-4)*DibWidth+i+9))
				  +h[3][4]*(*(p_data+(height-j-4)*DibWidth+i+12))
                  //��Ӧ�ĵ�4�е�ֵ���Ծ����Ӧֵ�������
			      +h[4][0]*(*(p_data+(height-j-5)*DibWidth+i))
				  +h[4][1]*(*(p_data+(height-j-5)*DibWidth+i+3))
				  +h[4][2]*(*(p_data+(height-j-5)*DibWidth+i+6))
				  +h[4][3]*(*(p_data+(height-j-5)*DibWidth+i+9))
				  +h[4][4]*(*(p_data+(height-j-5)*DibWidth+i+12));
                  //Ϊ�˼��㷽�����ǰѳ���35������Ȩ�ͣ��������ܺ�֮��
			*(p_temp+(height-j-3)*DibWidth+i+6)=abs(int(pby_pt/35));
		}
	}
	memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
	delete []p_temp;  //ɾ����ʱ�����ڴ�
}

/***************************************************************/
/*�������ƣ�ShuiPingGROW()                                     */
/*�������ͣ�void                                               */
/*���ܣ�ʹͼ��ˮƽ��ǿ��                                       */
/***************************************************************/
void MakeColorDib::ShuiPingGROW()   //ˮƽ��ǿ
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	int h[3][1];//����(3x1)����
	h[0][0] = -1;  
	h[1][0] = 2; 
	h[2][0] = -1;
	BYTE *p_temp=new BYTE[height*DibWidth];	// ��ʱ�����ڴ棬�Ա�����ͼ��
	for(int j=0;j<height-2;j++)	// ÿ��
	{
		for(int i=0;i<DibWidth-8;i++)	// ÿ��
		{
			int pby_pt=0;
			//��Ӧ��3�е�ֵ�˷ֱ��Ծ����Ӧֵ�������
			pby_pt= h[0][0]*(*(p_data+(height-j-1)*DibWidth+i))
				+h[1][0]*(*(p_data+(height-j-2)*DibWidth+i))
				+h[2][0]*(*(p_data+(height-j-3)*DibWidth+i));
			if(pby_pt>20)
				*(p_temp+(height-j-2)*DibWidth+i)=abs(pby_pt)+100;
			else
				*(p_temp+(height-j-2)*DibWidth+i)=abs(pby_pt);
		}
	}
	memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
    delete []p_temp;  //ɾ����ʱ�����ڴ�
}

/***************************************************************/
/*�������ƣ�ChuiZhiGROW()                                      */
/*�������ͣ�void                                               */
/*���ܣ�ʹͼ��ֱ��ǿ��                                       */
/***************************************************************/
void MakeColorDib::ChuiZhiGROW()   //��ֱ��ǿ
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	int h[1][3];//����(1x3)����
	h[0][0] = -1; 
	h[0][1] = 2;
	h[0][2] = -1;
	BYTE *p_temp=new BYTE[height*DibWidth];	// ��ʱ�����ڴ棬�Ա�����ͼ��
	for(int j=0;j<height-2;j++)	// ÿ��
	{
		for(int i=0;i<DibWidth-8;i++)	// ÿ��
		{
			int pby_pt=0;
			//��Ӧ�ĵ�0�е�ֵ���Ծ����Ӧֵ�������
			pby_pt= h[0][0]*(*(p_data+(height-j-1)*DibWidth+i))
				+h[0][1]*(*(p_data+(height-j-1)*DibWidth+i+3))
				+h[0][2]*(*(p_data+(height-j-1)*DibWidth+i+6));
			if(pby_pt>20)
				*(p_temp+(height-j-2)*DibWidth+i)=abs(pby_pt)+100;
			else
				*(p_temp+(height-j-2)*DibWidth+i)=abs(pby_pt);
		}
	}
	memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
	delete []p_temp;  //ɾ����ʱ�����ڴ�
}

/***************************************************************/
/*�������ƣ�ShuangXiangGROW()                                  */
/*�������ͣ�void                                               */
/*���ܣ�ʹͼ��˫����ǿ��                                       */
/***************************************************************/
void MakeColorDib::ShuangXiangGROW()    //˫����ǿ
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	int h[3][3];//����(3x3)����
	h[0][0] = -1;  h[0][1] = -1; h[0][2] = -1;
	h[1][0] = -1;  h[1][1] =  8; h[1][2] = -1;
	h[2][0] = -1;  h[2][1] = -1; h[2][2] = -1; 
	BYTE *p_temp=new BYTE[height*DibWidth];	// ��ʱ�����ڴ棬�Ա�����ͼ��
	for(int j=0;j<height-2;j++)	// ÿ��
	{	
		for(int i=0;i<DibWidth-8;i++)	// ÿ��
		{
			int pby_pt=0;
			//��Ӧ�ĵ�0�е�ֵ���Ծ����Ӧֵ�������
			pby_pt= h[0][0]*(*(p_data+(height-j-1)*DibWidth+i))
				+h[0][1]*(*(p_data+(height-j-1)*DibWidth+i+3))
				+h[0][2]*(*(p_data+(height-j-1)*DibWidth+i+6))
				//��Ӧ�ĵ�1�е�ֵ���Ծ����Ӧֵ�������
				+h[1][0]*(*(p_data+(height-j-2)*DibWidth+i))
				+h[1][1]*(*(p_data+(height-j-2)*DibWidth+i+3))
				+h[1][2]*(*(p_data+(height-j-2)*DibWidth+i+6))
				//��Ӧ�ĵ�2�е�ֵ���Ծ����Ӧֵ�������
				+h[2][0]*(*(p_data+(height-j-3)*DibWidth+i))
				+h[2][1]*(*(p_data+(height-j-3)*DibWidth+i+3))
				+h[2][2]*(*(p_data+(height-j-3)*DibWidth+i+6));
			if(pby_pt>20)
				*(p_temp+(height-j-2)*DibWidth+i)=abs(pby_pt)+100;
			else
				*(p_temp+(height-j-2)*DibWidth+i)=abs(pby_pt);
		}
	}	
	memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
	delete []p_temp;  //ɾ����ʱ�����ڴ�
}

/***************************************************************/
/*�������ƣ�Mosaic()                                           */
/*�������ͣ�void                                               */
/*���ܣ�ʹͼ�����������Ч����                                 */
/***************************************************************/
void MakeColorDib::Mosaic()    //������
{
	BYTE *p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ�������ֽڿ�
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	BYTE *p_temp=new BYTE[height*DibWidth];	// ��ʱ�����ڴ棬�Ա�����ͼ��
	for(int j=0;j<height-4;j+=5)	// ÿ��
	{	
	    for(int i=0;i<DibWidth-14;i+=15)	// ÿ��
		{   //��Ӧ��Χ(5x5)������ɫֵ���ƽ��
			int pby_pt=0;
			for(int m=0;m<5;m++)
				for(int n=0;n<15;n+=3)
				{   
					pby_pt+=*(p_data+(height-j-1-m)*DibWidth+i+n);
				}
				
			for(m=0;m<5;m++)
				for(int n=0;n<14;n+=3)
				{
					*(p_temp+(height-j-1-m)*DibWidth+i+n)=int(pby_pt/25);
				}	
            //��Ӧ��Χ(5x5)������ɫֵ���ƽ��
			pby_pt=0;
			for(m=0;m<5;m++)
				for(int n=0;n<15;n+=3)
				{
					pby_pt+=*(p_data+(height-j-1-m)*DibWidth+i+n+1);
				}
			for(m=0;m<5;m++)
				for(int n=0;n<14;n+=3)
				{
					*(p_temp+(height-j-1-m)*DibWidth+i+n+1)=int(pby_pt/25);
				}
            //��Ӧ��Χ(5x5)�����ɫֵ���ƽ��
			pby_pt=0;
			for(m=0;m<5;m++)
				for(int n=0;n<15;n+=3)
				{
					pby_pt+=*(p_data+(height-j-1-m)*DibWidth+i+n+2);
				}
			for(m=0;m<5;m++)
				for(int n=0;n<14;n+=3)
				{
					*(p_temp+(height-j-1-m)*DibWidth+i+n+2)=int(pby_pt/25);
				}
		}			
	}
	memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
	delete []p_temp;  //ɾ����ʱ�����ڴ�
}
