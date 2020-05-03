#include "stdafx.h"
#include "windowsx.h"
#include "math.h"
#include "TuXiangHeChengDib.h"
#include "MainFrm.h"
#include "DynSplitView2.h"

 
 
TuXiangHeChengDib::TuXiangHeChengDib()
{
	bool m_valid=true;
}
TuXiangHeChengDib::~TuXiangHeChengDib()
{
}



///***************************************************************/           
/*�������ƣ�Add(LPBYTE p_data, LPBYTE p_dataBK,int wide,int height)                                        
/*�������ͣ�void 
/*����˵����p_data       ԭͼ���׵�ַ
/*          p_dataBK     ����ͼ���׵�ַ
/*          wide��height ԭͼ��ĸߺͿ�                                   
/*���ܣ���ͼ����м����㡣            
/***************************************************************/ 
void TuXiangHeChengDib::Add(LPBYTE p_data, LPBYTE p_dataBK,int wide,int height)
{
	LPBYTE lpSrc;  //ԭͼ������ָ��
    LPBYTE lpDst;   //Ŀ������ָ��
    LPBYTE lpSrcBK;  //��������ָ��	
	if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{
		int i,j;  //ѭ������
		LPBYTE  temp=new BYTE[wide*height];    //��ͼ�񻺳���
		//��ʼ���·�����ڴ�Ϊ255
		memset(temp,255,wide*height);			
		//����ÿ�����صļ�����
		for(j=1;j<height-1;j++)
		{
			for(i=1;i<wide-1;i++)
			{
				//���ԭ����ָ��
				lpSrc=p_data+wide*j+i;
				//���Ŀ������ָ��
				lpDst=temp+wide*j+i;
				//��ñ�������ָ��
				lpSrcBK=p_dataBK+wide*j+i;
				//���м�����
				if((*lpSrc+*lpSrcBK)>255)
					*lpDst=255;
				else
					*lpDst=(*lpSrc+*lpSrcBK);
			}
		}
		memcpy(p_data, temp,wide*height);   //���ƴ�����ͼ��
		delete  temp;
	}
	else //24λ���ɫ
	{
		LONG wide,height,DibWidth;    //ԭͼ������
		p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
		wide=this->GetWidth ();  //ȡ��ԭͼ�����������
		height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		//����ÿ�����صļ�����
		for(int j=1;j<height-1;j++)
		{
			for(int i=3;i<DibWidth-3;i++)
			{
				//���ԭ����ָ��
				lpSrc=p_data+DibWidth*j+i;
				//���Ŀ������ָ��
				lpDst=p_temp+DibWidth*j+i;
				//��ñ�������ָ��
				lpSrcBK=p_dataBK+DibWidth*j+i;
				//���м�����
				if((*lpSrc+*lpSrcBK)>255)
					*lpDst=255;
				else
					*lpDst=(*lpSrc+*lpSrcBK);
			}
		}
		memcpy(p_data, p_temp,DibWidth*height);   //���ƴ�����ͼ��
		delete  []p_temp;
	}	
}



///***************************************************************/           
/*�������ƣ�Sub(LPBYTE p_data, LPBYTE p_dataBK,int wide,int height)                                        
/*�������ͣ�void 
/*����˵����p_data       ԭͼ���׵�ַ
/*          p_dataBK     ����ͼ���׵�ַ
/*          wide��height ԭͼ��ĸߺͿ�                                   
/*���ܣ���ͼ����м����㡣            
/***************************************************************/ 
void TuXiangHeChengDib::Sub(LPBYTE p_data, LPBYTE p_dataBK, int wide, int height)
{
	LPBYTE lpSrc;  //ԭͼ������ָ��
    LPBYTE lpDst;   //Ŀ������ָ��
    LPBYTE lpSrcBK;  //��������ָ��
    if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{
		int i,j;  //ѭ������
		LPBYTE  temp=new BYTE[wide*height];    //��ͼ�񻺳���
		//��ʼ���·�����ڴ�Ϊ255
		memset(temp,255,wide*height);	
		//����ÿ�����صļ�����
		for(j=1;j<height-1;j++)
		{
			for(i=1;i<wide-1;i++)
			{
				//���ԭ����ָ��
				lpSrc=p_data+wide*j+i;
				//���Ŀ������ָ��
				lpDst=temp+wide*j+i;
				//��ñ�������ָ��
				lpSrcBK=p_dataBK+wide*j+i;
				//���м�����
				if((*lpSrc-*lpSrcBK)<0)
					*lpDst=0;
				else
					*lpDst=(*lpSrc-*lpSrcBK);
			}
		}
		memcpy(p_data, temp,wide*height);   //���ƴ�����ͼ��
		delete  temp;
	}
	else//24λ���ɫ
	{
		int wide,height,DibWidth;    //ԭͼ������
		p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
		wide=this->GetWidth ();  //ȡ��ԭͼ�����������
		height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		//����ÿ�����صļ�����
		for(int j=1;j<height-1;j++)
		{
			for(int i=1;i<DibWidth-1;i++)
			{
				//���ԭ����ָ��
				lpSrc=p_data+DibWidth*j+i;
				//���Ŀ������ָ��
				lpDst=p_temp+DibWidth*j+i;
				//��ñ�������ָ��
				lpSrcBK=p_dataBK+DibWidth*j+i;
				//���м�����
				if((*lpSrc-*lpSrcBK)<0)
					*lpDst=0;
				else
					*lpDst=(*lpSrc-*lpSrcBK);
			}
		}
		memcpy(p_data, p_temp,DibWidth*height);   //���ƴ�����ͼ��
		delete  []p_temp;
	}
}



///***************************************************************/           
/*�������ƣ�Yuyunsuan(LPBYTE p_data, LPBYTE p_dataBK,int wide,int height)                                        
/*�������ͣ�void 
/*����˵����p_data       ԭͼ���׵�ַ
/*          p_dataBK     ����ͼ���׵�ַ
/*          wide��height ԭͼ��ĸߺͿ�                                   
/*���ܣ���ͼ����������㡣            
/***************************************************************/
void TuXiangHeChengDib::Yuyunsuan(LPBYTE p_data, LPBYTE p_dataBK, int wide, int height)
{
    if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{
		int i,j;  //ѭ������ 	 
		LPBYTE  temp1=new BYTE[wide*height]; //��ͼ�񻺳���
		LPBYTE  temp2=new BYTE[wide*height]; 
		memset( temp1,0,wide*height);
		memset( temp2,0,wide*height);
		//��ԭͼ��ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<wide;i++)
			{
				if(p_data[wide*j+i]>128)
					temp1[wide*j+i]=1; 
			}
		}
		//�Ա�����ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<wide;i++)
			{
				if(p_dataBK[wide*j+i]>128)
					temp2[wide*j+i]=1; 
			}
		}
		//����ÿ�����ص�������
		for(j=1;j<height-1;j++)
		{
			for(i=1;i<wide-1;i++)
			{   
				if( temp2[wide*j+i]==1&& temp1[wide*j+i]==1)
					temp1[wide*j+i]=255;
				else 
					temp1[wide*j+i]=0;
			}
		}
		memcpy(p_data, temp1,wide*height);   //���ƴ�����ͼ��
		delete  temp1;
		delete  temp2;
	}
	else//24λ���ɫ
	{
		int i,j;  //ѭ������
		LPBYTE  p_data;     //ԭͼ������ָ��
		int wide,height,DibWidth;    //ԭͼ������
		p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
		wide=this->GetWidth ();  //ȡ��ԭͼ�����������
		height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp1=new BYTE[height*DibWidth];
		BYTE *p_temp2=new BYTE[height*DibWidth];
		//��ԭͼ��ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<DibWidth;i++)
			{
				if(p_data[DibWidth*j+i]>128)
					p_temp1[DibWidth*j+i]=1; 
			}
		}
		//�Ա�����ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<DibWidth;i++)
			{
				if(p_dataBK[DibWidth*j+i]>128)
					p_temp2[DibWidth*j+i]=1; 
			}
		}
		//����ÿ�����ص�������
		for(j=1;j<height-1;j++)
		{
			for(i=1;i<DibWidth-1;i++)
			{   
				if( p_temp2[DibWidth*j+i]==1&& p_temp1[DibWidth*j+i]==1)
					p_temp1[DibWidth*j+i]=255;
				else 
					p_temp1[DibWidth*j+i]=0;
			}
		}
		memcpy(p_data, p_temp1,DibWidth*height);   //���ƴ�����ͼ��
		delete  []p_temp1;
		delete  []p_temp2;
	}
}
///***************************************************************/           
/*�������ƣ�Huoyunsuan(LPBYTE p_data, LPBYTE p_dataBK,int wide,int height)                                        
/*�������ͣ�void 
/*����˵����p_data       ԭͼ���׵�ַ
/*          p_dataBK     ����ͼ���׵�ַ
/*          wide��height ԭͼ��ĸߺͿ�                                   
/*���ܣ���ͼ����л����㡣            
/***************************************************************/ 
void TuXiangHeChengDib::Huoyunsuan(LPBYTE p_data, LPBYTE p_dataBK, int wide, int height)
{
    if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{
		int i,j;  //ѭ������		 
		LPBYTE  temp1=new BYTE[wide*height]; //��ͼ�񻺳���
		LPBYTE  temp2=new BYTE[wide*height]; 
		memset(temp1,0,wide*height);
		memset(temp2,0,wide*height);
		//��ԭͼ��ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<wide;i++)
			{
				if(p_data[wide*j+i]>128)
					temp1[wide*j+i]=1; 
			}
		}
		//�Ա�����ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<wide;i++)
			{
				if(p_dataBK[wide*j+i]>128)
					temp2[wide*j+i]=1; 
			}
		}
		//����ÿ�����ص�������
		for(j=1;j<height-1;j++)
		{
			for(i=1;i<wide-1;i++)
			{   
				if( temp2[wide*j+i]==0&& temp1[wide*j+i]==0)
					temp1[wide*j+i]=0;
				else 
					temp1[wide*j+i]=255;
			}
		}
		memcpy(p_data, temp1,wide*height);   //���ƴ�����ͼ��
		delete  temp1;
		delete  temp2;
	}
	else//24λ���ɫ
	{
		int i,j;  //ѭ������
		LPBYTE  p_data;     //ԭͼ������ָ��
		int wide,height,DibWidth;    //ԭͼ������
		p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
		wide=this->GetWidth ();  //ȡ��ԭͼ�����������
		height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp1=new BYTE[height*DibWidth];
		BYTE *p_temp2=new BYTE[height*DibWidth];
		//��ԭͼ��ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<DibWidth;i++)
			{
				if(p_data[DibWidth*j+i]>128)
					p_temp1[DibWidth*j+i]=1; 
			}
		}
		//�Ա�����ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<DibWidth;i++)
			{
				if(p_dataBK[DibWidth*j+i]>128)
					p_temp2[DibWidth*j+i]=1; 
			}
		}
		//����ÿ�����ص�������
		for(j=1;j<height-1;j++)
		{
			for(i=1;i<DibWidth-1;i++)
			{   
				if( p_temp2[DibWidth*j+i]==0&& p_temp1[DibWidth*j+i]==0)
					p_temp1[DibWidth*j+i]=0;
				else 
					p_temp1[DibWidth*j+i]=255;
			}
		}
        memcpy(p_data, p_temp1,DibWidth*height);   //���ƴ�����ͼ��
		delete  []p_temp1;
		delete  []p_temp2;
	}
}



///***************************************************************/           
/*�������ƣ�Feiyunsuan()                                        
/*�������ͣ�void                                   
/*���ܣ���ͼ����з����㡣            
/***************************************************************/ 
void TuXiangHeChengDib::Feiyunsuan()
{
	int i,j;  //ѭ������
	BYTE* p_data;//ͼ��ָ��
	int wide,height;  //ԭͼ�ĸߺͿ�
	p_data=GetData();
    if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��	    
	   wide=GetWidth();
	else//24λ���ɫ
	   wide=GetDibWidthBytes();
	height=GetHeight();
	LPBYTE p_temp1=new BYTE[wide*height]; //��ͼ�񻺳���         
	memset(p_temp1,0,wide*height); //��ʼ��Ϊ0
	//��ԭͼ��ֵ��
	for(j=0;j<height;j++)
	{
		for(i=0;i<wide;i++)
		{
				if(p_data[wide*j+i]>128)
				p_temp1[wide*j+i]=1; 
		}
	}
 
	//����ÿ�����ص�������
    for(j=1;j<height-1;j++)
	{
		for(i=1;i<wide-1;i++)
		{   
				if(p_temp1[wide*j+i]==0 )
				 p_temp1[wide*j+i]=255;
				else 
				 p_temp1[wide*j+i]=0;
		}
	}
    memcpy(p_data,p_temp1,wide*height);   //���ƴ�����ͼ��
	delete p_temp1;
}



///***************************************************************/           
/*�������ƣ�Huofei(LPBYTE p_data, LPBYTE p_dataBK,int wide,int height)                                        
/*�������ͣ�void 
/*����˵����p_data       ԭͼ���׵�ַ
/*          p_dataBK     ����ͼ���׵�ַ
/*          wide��height ԭͼ��ĸߺͿ�                                   
/*���ܣ���ͼ����л�����㡣            
/***************************************************************/ 
void TuXiangHeChengDib::Huofei(LPBYTE p_data, LPBYTE p_dataBK, int wide, int height)
{
	if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{
		int i,j;  //ѭ������		 
		LPBYTE  temp1=new BYTE[wide*height]; //��ͼ�񻺳���
		LPBYTE  temp2=new BYTE[wide*height]; 
		memset( temp1,0,wide*height);
		memset( temp2,0,wide*height);
		//��ԭͼ��ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<wide;i++)
			{
				if(p_data[wide*j+i]>128)
					temp1[wide*j+i]=1; 
			}
		}
		//�Ա�����ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<wide;i++)
			{
				if(p_dataBK[wide*j+i]>128)
					temp2[wide*j+i]=1; 
			}
		}
		//����ÿ�����ص�������
		for(j=1;j<height-1;j++)
		{
			for(i=1;i<wide-1;i++)
			{   
				if( temp2[wide*j+i]==0&& temp1[wide*j+i]==0)
					temp1[wide*j+i]=255;
				else 
					temp1[wide*j+i]=0;
			}
		}
		memcpy(p_data, temp1,wide*height);   //���ƴ�����ͼ��
		delete  temp1;
		delete  temp2;
	}
	else//24λ���ɫ
	{
		int i,j;  //ѭ������
		LPBYTE  p_data;     //ԭͼ������ָ��
		int wide,height,DibWidth;    //ԭͼ������
		p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
		wide=this->GetWidth ();  //ȡ��ԭͼ�����������
		height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp1=new BYTE[height*DibWidth];
		BYTE *p_temp2=new BYTE[height*DibWidth];
		//��ԭͼ��ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<DibWidth;i++)
			{
				if(p_data[DibWidth*j+i]>128)
					p_temp1[DibWidth*j+i]=1; 
			}
		}
		//�Ա�����ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<DibWidth;i++)
			{
				if(p_dataBK[DibWidth*j+i]>128)
					p_temp2[DibWidth*j+i]=1; 
			}
		}
		//����ÿ�����ص�������
		for(j=1;j<height-1;j++)
		{
			for(i=3;i<DibWidth-3;i++)
			{   
				if( p_temp2[DibWidth*j+i]==0&& p_temp1[DibWidth*j+i]==0)
					p_temp1[DibWidth*j+i]=255;
				else 
					p_temp1[DibWidth*j+i]=0;
			}
		}
		memcpy(p_data, p_temp1,DibWidth*height);   //���ƴ�����ͼ��
		delete  []p_temp1;
		delete  []p_temp2;
	}
}



///***************************************************************/           
/*�������ƣ�Yufei(LPBYTE p_data, LPBYTE p_dataBK,int wide,int height)                                        
/*�������ͣ�void 
/*����˵����p_data       ԭͼ���׵�ַ
/*          p_dataBK     ����ͼ���׵�ַ
/*          wide��height ԭͼ��ĸߺͿ�                                   
/*���ܣ���ͼ�����������㡣            
/***************************************************************/
void TuXiangHeChengDib::Yufei(LPBYTE p_data, LPBYTE p_dataBK, int wide, int height)
{
	if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{
		int i,j;  //ѭ������		 
		PBYTE  temp1=new BYTE[wide*height]; //��ͼ�񻺳���
		LPBYTE  temp2=new BYTE[wide*height]; 
		memset( temp1,0,wide*height);
		memset( temp2,0,wide*height);
		//��ԭͼ��ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<wide;i++)
			{
				if(p_data[wide*j+i]>128)
					temp1[wide*j+i]=1; 
			}
		}
		//�Ա�����ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<wide;i++)
			{
				if(p_dataBK[wide*j+i]>128)
					temp2[wide*j+i]=1; 
			}
		}
		//����ÿ�����ص��������
		for(j=1;j<height-1;j++)
		{
			for(i=1;i<wide-1;i++)
			{   
				if( temp2[wide*j+i]==1&& temp1[wide*j+i]==1)
					temp1[wide*j+i]=0;
				else 
					temp1[wide*j+i]=255;
			}
		}
		memcpy(p_data, temp1,wide*height);   //���ƴ�����ͼ��
		delete  temp1;
		delete  temp2;
	}
	else//24λ���ɫ
	{
		int i,j;  //ѭ������
		LPBYTE  p_data;     //ԭͼ������ָ��
		int wide,height,DibWidth;    //ԭͼ������
		p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
		wide=this->GetWidth ();  //ȡ��ԭͼ�����������
		height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp1=new BYTE[height*DibWidth];
		BYTE *p_temp2=new BYTE[height*DibWidth];
		//��ԭͼ��ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<DibWidth;i++)
			{
				if(p_data[DibWidth*j+i]>128)
					p_temp1[DibWidth*j+i]=1; 
			}
		}
		//�Ա�����ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<DibWidth;i++)
			{
				if(p_dataBK[DibWidth*j+i]>128)
					p_temp2[DibWidth*j+i]=1; 
			}
		}
		//����ÿ�����ص��������
		for(j=1;j<height-1;j++)
		{
			for(i=3;i<DibWidth-3;i++)
			{   
				if( p_temp2[wide*j+i]==1&& p_temp1[DibWidth*j+i]==1)
					p_temp1[DibWidth*j+i]=0;
				else 
					p_temp1[DibWidth*j+i]=255;
			}
		}
		memcpy(p_data, p_temp1,DibWidth*height);   //���ƴ�����ͼ��
		delete  []p_temp1;
		delete  []p_temp2;
	}
}


///***************************************************************/           
/*�������ƣ�Yihuo(LPBYTE p_data, LPBYTE p_dataBK,int wide,int height)                                        
/*�������ͣ�void 
/*����˵����p_data       ԭͼ���׵�ַ
/*          p_dataBK     ����ͼ���׵�ַ
/*          wide��height ԭͼ��ĸߺͿ�                                   
/*���ܣ���ͼ�����������㡣            
/***************************************************************/
void TuXiangHeChengDib::Yihuo(LPBYTE p_data, LPBYTE p_dataBK, int wide, int height)
{
	if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{
       int i,j;  //ѭ������ 
	   LPBYTE  temp1=new BYTE[wide*height]; //��ͼ�񻺳���
       LPBYTE  temp2=new BYTE[wide*height]; 
	   memset( temp1,0,wide*height);
       memset( temp2,0,wide*height);
	   //��ԭͼ��ֵ��
	   for(j=0;j<height;j++)
	   {
			for(i=0;i<wide;i++)
			{
				if(p_data[wide*j+i]>128)
				 temp1[wide*j+i]=1; 
			}
		}
		//�Ա�����ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<wide;i++)
			{
				if(p_dataBK[wide*j+i]>128)
				   temp2[wide*j+i]=1; 
			}
		}
		//����ÿ�����ص��������
        for(j=1;j<height-1;j++)
		{
			for(i=1;i<wide-1;i++)
			{   
				if( temp2[wide*j+i]+ temp1[wide*j+i]==1)
				  temp1[wide*j+i]=255;
				else 
					  temp1[wide*j+i]=0;
			}
		}
        memcpy(p_data, temp1,wide*height);   //���ƴ�����ͼ��
		delete  temp1;
		delete  temp2;
	}
	else//24λ���ɫ
	{
        int i,j;  //ѭ������
	    LPBYTE  p_data;     //ԭͼ������ָ��
	    int wide,height,DibWidth;    //ԭͼ������
	    p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
        wide=this->GetWidth ();  //ȡ��ԭͼ�����������
        height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	    DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	    BYTE *p_temp1=new BYTE[height*DibWidth];
	    BYTE *p_temp2=new BYTE[height*DibWidth];
		//��ԭͼ��ֵ��
		for(j=0;j<height;j++)
		{
			for(i=0;i<DibWidth;i++)
			{
				if(p_data[DibWidth*j+i]>128)
				 p_temp1[DibWidth*j+i]=1; 
			}
		}
		//�Ա�����ֵ��
			for(j=0;j<height;j++)
		{
			for(i=0;i<DibWidth;i++)
			{
				if(p_dataBK[DibWidth*j+i]>128)
				   p_temp2[DibWidth*j+i]=1; 
			}
		}
		//����ÿ�����ص��������
        for(j=1;j<height-1;j++)
		{
			for(i=3;i<DibWidth-3;i++)
			{   
				if( p_temp2[DibWidth*j+i]+ p_temp1[DibWidth*j+i]==1)
					p_temp1[DibWidth*j+i]=255;
				else 
					p_temp1[DibWidth*j+i]=0;
			}
		}
        memcpy(p_data, p_temp1,DibWidth*height);   //���ƴ�����ͼ��
		delete  []p_temp1;
		delete  []p_temp2;
	}
}
