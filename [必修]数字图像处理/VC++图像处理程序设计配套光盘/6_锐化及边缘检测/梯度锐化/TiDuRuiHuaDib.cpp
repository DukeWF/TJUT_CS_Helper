#include "stdafx.h"
#include "windowsx.h"
#include "math.h"
#include "TiDuRuiHuaDib.h"
#include "MainFrm.h"
#include "DynSplitView2.h"
#include "CDIB.h"
 
TiDuRuiHuaDib::TiDuRuiHuaDib()
{

}
TiDuRuiHuaDib::~TiDuRuiHuaDib()
{

}

///***************************************************************/           
/*�������ƣ�Menxianruihua()                                        
/*�������ͣ�void                                   
/*���ܣ���ͼ����������ݶ��񻯡�            
/*****************************************************************/ 
void TiDuRuiHuaDib::Menxianruihua()
{
    LPBYTE p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{		
        LPBYTE p_temp=new BYTE [wide*height];    //����ͼ��һ������
		memset(p_temp,255,wide*height);  //��ʼ��Ϊ255
		int temp;
		for(int j=1;j<height-1;j++)
		for(int i=1;i<wide-1;i++)
		{
			//����˫��һ��΢�ֹ�ʽ���㵱ǰ���صĻҶ�ֵ
			temp=(int)sqrt((p_data[wide*j+i]-p_data[wide*j+(i-1)])*
				(p_data[wide*j+i]-p_data[wide*j+(i-1)])+(p_data[wide*j+i]-p_data[wide*(j-1)+i])*
				(p_data[wide*j+i]-p_data[wide*(j-1)+i]));
			if (temp>=30)
			{   
				if((temp+100)>255)
					p_temp[wide*j+i]=255;
				else 
					p_temp[wide*j+i]=temp+100;
			}
			if (temp<30)
				p_temp[wide*j+i]=p_data[wide*j+i];
		}
		//���������е�ͼ���ƻ�ԭͼ������
		memcpy(p_data,p_temp,wide*height);
		//ɾ��������
		delete p_temp;
	}
	else	//24λ��ɫ
	{	
		int DibWidth;    //ԭͼ�������ֽڿ�	
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
        BYTE *p_temp=new BYTE[height*DibWidth];
		for(int j=1;j<height-1;j++)	// ÿ��
		{
			for(int i=3;i<DibWidth-3;i++)	// ÿ��
			{
				int pby_pt1=0,pby_pt2=0,pby_pt=0;	
				pby_pt1=p_data[DibWidth*j+i]-p_data[DibWidth*j+(i-3)];
				pby_pt2=p_data[DibWidth*j+i]-p_data[DibWidth*(j-1)+i];
				pby_pt=(int)sqrt(pby_pt1*pby_pt1+pby_pt2*pby_pt2);
				if (pby_pt>=30)
				{	 
					if((pby_pt+100)>255)
						p_temp[DibWidth*j+i]=255;
					else 
						p_temp[DibWidth*j+i]=pby_pt+100;
				}
				if (pby_pt<30)
					p_temp[DibWidth*j+i]=p_data[DibWidth*j+i];
			}
		}
		memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
		delete []p_temp;  //ɾ����ʱ�����ڴ�
	}
}

///***************************************************************/           
/*�������ƣ�Erzhirihua()                                      
/*�������ͣ�void                                   
/*���ܣ� �����ݶȶ�ֵ��ͼ��            
/***************************************************************/ 
void TiDuRuiHuaDib::Erzhirihua()
{
	LPBYTE  p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{        
        LPBYTE p_temp=new BYTE [wide*height];    //����ͼ��һ������
		memset(p_temp,255,wide*height);  //��ʼ��Ϊ255
		int temp;
		for(int j=1;j<height-1;j++)
			for(int i=1;i<wide-1;i++)
			{			
				//����˫��һ��΢�ֹ�ʽ���㵱ǰ���صĻҶ�ֵ
				temp=(int)sqrt((p_data[wide*j+i]-p_data[wide*j+(i-1)])*(p_data[wide*j+i]-p_data[wide*j+(i-1)])+(p_data[wide*j+i]-p_data[wide*(j-1)+i])*(p_data[wide*j+i]-p_data[wide*(j-1)+i]));
                if (temp>30)
				{   
					p_temp[wide*j+i]=255;					 
				}
				else 
					p_temp[wide*j+i]=0;
			}
		//���������е�ͼ���ƻ�ԭͼ������
		memcpy(p_data,p_temp,wide*height);
		//ɾ��������
		delete p_temp;
	}	
	else	//24λ��ɫ
	{	
	    int DibWidth;    //ԭͼ�������ֽڿ�	
	    DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
        BYTE *p_temp=new BYTE[height*DibWidth];
		for(int j=1;j<height-1;j++)	// ÿ��
		{
			for(int i=3;i<DibWidth-3;i++)	// ÿ��
			{
				int pby_pt1=0,pby_pt2=0,pby_pt=0;	
				pby_pt1=*(p_data+(height-j-1)*DibWidth+i)-*(p_data+(height-j-1)*DibWidth+i-3);
				pby_pt2=*(p_data+(height-j-1)*DibWidth+i)-*(p_data+(height-j)*DibWidth+i);
				pby_pt=(int)sqrt(pby_pt1*pby_pt1+pby_pt2*pby_pt2);
                if (pby_pt>30)
				{   
					*(p_temp+(height-j-1)*DibWidth+i)=255;					 
				}
				else 
					*(p_temp+(height-j-1)*DibWidth+i)=0;
			}
		}
        memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
        delete []p_temp;  //ɾ����ʱ�����ڴ�
	}
}

///***************************************************************/           
/*�������ƣ�GuDingRuiHua()                                       
/*�������ͣ�void                                   
/*���ܣ�����Ե�涨һ���ض��ĻҶȼ���            
/***************************************************************/ 
void TiDuRuiHuaDib::GuDingRuiHua()
{
	LPBYTE p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������ 	
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{     
        LPBYTE p_temp=new BYTE [wide*height];    //����ͼ��һ������
		memset(p_temp,255,wide*height);  //��ʼ��Ϊ255
		int temp;
		for(int j=1;j<height-1;j++)
		    for(int i=1;i<wide-1;i++)
			{
				//����˫��һ��΢�ֹ�ʽ���㵱ǰ���صĻҶ�ֵ
				temp=(int)sqrt((p_data[wide*j+i]-p_data[wide*j+(i-1)])*(p_data[wide*j+i]-p_data[wide*j+(i-1)])+(p_data[wide*j+i]-p_data[wide*(j-1)+i])*(p_data[wide*j+i]-p_data[wide*(j-1)+i]));
                if (temp>30)
				{   
                   p_temp[wide*j+i]=255;
				}
				else 
					p_temp[wide*j+i]=p_data[wide*j+i];
			}
		//���������е�ͼ���ƻ�ԭͼ������
		memcpy(p_data,p_temp,wide*height);
		//ɾ��������
		delete p_temp;
	}
	else	//24λ��ɫ
	{	    
	    int DibWidth;    //ԭͼ�������ֽڿ�	
	    DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
        BYTE *p_temp=new BYTE[height*DibWidth];
	    for(int j=1;j<height-1;j++)	// ÿ��
		{
			for(int i=3;i<DibWidth-3;i++)	// ÿ��
			{
				int pby_pt1=0,pby_pt2=0,pby_pt=0;	
				pby_pt1=*(p_data+(height-j-1)*DibWidth+i)-*(p_data+(height-j-1)*DibWidth+i-3);
				pby_pt2=*(p_data+(height-j-1)*DibWidth+i)-*(p_data+(height-j)*DibWidth+i);
				pby_pt=(int)sqrt(pby_pt1*pby_pt1+pby_pt2*pby_pt2);
				if (pby_pt>30)
				{   
					*(p_temp+(height-j-1)*DibWidth+i)=255;
				}
				else 
					*(p_temp+(height-j-1)*DibWidth+i)=*(p_data+(height-j-1)*DibWidth+i);
			}
		}
        memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
        delete []p_temp;  //ɾ����ʱ�����ڴ�
	}
}
