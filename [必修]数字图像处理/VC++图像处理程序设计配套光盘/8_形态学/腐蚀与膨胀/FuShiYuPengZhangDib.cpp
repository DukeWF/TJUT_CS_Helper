#include "stdafx.h"
#include "windowsx.h"
#include "math.h"
#include "FuShiYuPengZhangDib.h"
#include "MainFrm.h"


 
 
FuShiYuPengZhangDib::FuShiYuPengZhangDib()
{
}
FuShiYuPengZhangDib::~FuShiYuPengZhangDib()
{
}


 

///***************************************************************/           
/*�������ƣ�ChuiZhiFuShi()                                        
/*�������ͣ�void                                      
/*���ܣ���ͼ����д�ֱ��ʴ��            
/***************************************************************/ 
void FuShiYuPengZhangDib::ChuiZhiFuShi()
{
	LPBYTE p_data;	// ָ��DIB����ָ��
	LPBYTE	lpSrc;// ָ��Դͼ���ָ��
	LPBYTE	lpDst;// ָ�򻺴�ͼ���ָ��
	LPBYTE	temp;// ָ�򻺴�DIBͼ���ָ��
	int i;
	int j;
	int n;//ѭ������
	p_data = GetData();// �ҵ�DIBͼ��������ʼλ��
	LONG wide = GetWidth();// DIB�Ŀ��
	LONG height = GetHeight();// DIB�ĸ߶�
	if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{ 	
		temp = new BYTE[wide*height];// ��ʱ�����ڴ棬�Ա�����ͼ��
		lpDst = (LPBYTE)temp;
		memset(lpDst, (BYTE)255, wide * height);// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
		//ʹ�ô�ֱ����ĽṹԪ�ؽ��и�ʴ
		for(j = 1; j < height - 1; j++)
		{
			for(i = 0; i < wide; i ++)
			{
				//����ʹ��3��1�ĽṹԪ�أ�Ϊ��ֹԽ�磬���Բ��������ϱߺ����±ߵ���������
				// ָ��Դͼ������j�У���i�����ص�ָ��			
				lpSrc = (unsigned char *)(p_data + wide * j + i);
				lpDst = (unsigned char *)(temp + wide * j + i);	// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��
				*lpDst = 0;//Ŀ��ͼ���еĵ�ǰ���ȸ��ɺ�ɫ
				// ���Դͼ����(0,-1)��(0,0)��(0,1)������֮һ�а׵㣬
				// ��Ŀ��ͼ���е�(0,0)�㸳�ɰ�ɫ
				for (n = 0; n < 3; n++)
				{
					if (*(lpSrc + (n - 1) * wide) > 128)
					{
						*lpDst = 255;					 
						break;
					}
				}				
			}
		}
		// ���Ƹ�ʴ���ͼ��
		memcpy(p_data, temp, wide * height);
		// �ͷ��ڴ�
		delete temp; 
	}
	else //24λ���ɫ
	{
		LONG DibWidth;    //ԭͼ������	     
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		//ʹ�ô�ֱ����ĽṹԪ�ؽ��и�ʴ
		for(j = 1; j < height - 1; j++)
		{
			for(i = 0; i < DibWidth; i+=3)
			{
				//����ʹ��3��1�ĽṹԪ�أ�Ϊ��ֹԽ�磬���Բ��������ϱߺ����±ߵ���������
				// ָ��Դͼ������j�У���i�����ص�ָ��			
				lpSrc = (unsigned char *)(p_data + DibWidth * j + i);
				lpDst = (unsigned char *)(p_temp + DibWidth * j + i);	// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��
				
				*lpDst = 0;//Ŀ��ͼ���еĵ�ǰ���ȸ��ɺ�ɫ
				*(lpDst+1)=0;
				*(lpDst+2)=0;
				// ���Դͼ����(0,-1)��(0,0)��(0,1)������֮һ�а׵㣬
				// ��Ŀ��ͼ���е�(0,0)�㸳�ɰ�ɫ
				for(int m=0;m<3;m++)
				{
					for (n = 0; n < 3; n++)
					{
						if (*(lpSrc + (n - 1) * DibWidth) > 128)
						{
							*lpDst = 255;
							break;
						}
						else
							*lpDst =*lpSrc ;
					}
					lpSrc++;
					lpDst++;
				}			
			}
		}
		// ���Ƹ�ʴ���ͼ��
		memcpy(p_data, p_temp, DibWidth * height); 
		// �ͷ��ڴ�
		delete []p_temp;
	}	
}



///***************************************************************/           
/*�������ƣ�Shuipingfushi()                                        
/*�������ͣ�void                                      
/*���ܣ���ͼ�����ˮƽ��ʴ��            
/***************************************************************/ 
void FuShiYuPengZhangDib::Shuipingfushi()
{
	// ָ��DIB����ָ��
	LPBYTE p_data;
	// ָ��Դͼ���ָ��
	LPBYTE	lpSrc;
	// ָ�򻺴�ͼ���ָ��
	LPBYTE	lpDst;
	// ָ�򻺴�DIBͼ���ָ��	 
	LPBYTE	temp;
	//ѭ������
	int i;
	int j;
	int n;
	// �ҵ�DIBͼ��������ʼλ��
	p_data = GetData();
	// DIB�Ŀ��
	LONG wide = GetWidth();
	// DIB�ĸ߶�
	LONG height = GetHeight();
	if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{    
		// ��ʱ�����ڴ棬�Ա�����ͼ��
		temp = new BYTE[wide*height];
		// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
		lpDst = (LPBYTE)temp;
		memset(lpDst, (BYTE)255, wide * height);
		// ʹ��ˮƽ����ĽṹԪ�ؽ��и�ʴ
		for (j = 0; j < height; j++)
		{
			for (i = 1; i < wide - 1; i ++)
			{
				// ����ʹ��1��3�ĽṹԪ�أ�Ϊ��ֹԽ�磬���Բ���������ߺ����ұߵ���������
				lpSrc = (unsigned char *)(p_data + wide *j + i);
				// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
				lpDst = (unsigned char *)(temp + wide * j + i);
				// Ŀ��ͼ���еĵ�ǰ���ȸ��ɺ�ɫ
				*lpDst = 0;
				// ���Դͼ����(-1,0)��(0,0)��(1,0)������֮һ�а׵㣬
				// ��Ŀ��ͼ���е�(0,0)�㸳�ɰ�ɫ
				for (n = 0; n < 3; n++)
				{
					if (*(lpSrc + (n - 1) ) > 128)
					{
						*lpDst = 255;
						break;
					}
				}				
			}
		}
		// ���Ƹ�ʴ���ͼ��
		memcpy(p_data, temp, wide * height); 
		// �ͷ��ڴ�
		delete temp; 
	}
	else //24λ���ɫ
	{
		LONG DibWidth;    //ԭͼ������	     
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		// ʹ��ˮƽ����ĽṹԪ�ؽ��и�ʴ
		for (j = 0; j < height; j++)
		{
			for (i = 3; i < DibWidth - 3; i +=3)
			{
				// ����ʹ��1��3�ĽṹԪ�أ�Ϊ��ֹԽ�磬���Բ���������ߺ����ұߵ���������
				lpSrc = (unsigned char *)(p_data + DibWidth *j + i);
				// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
				lpDst = (unsigned char *)(p_temp + DibWidth * j + i);
				// Ŀ��ͼ���еĵ�ǰ���ȸ��ɺ�ɫ
				*lpDst = 0;
				*(lpDst+1)=0;
				*(lpDst+2)=0;
				// ���Դͼ����(-1,0)��(0,0)��(1,0)������֮һ�а׵㣬
				// ��Ŀ��ͼ���е�(0,0)�㸳�ɰ�ɫ
				for(int m=0;m<3;m++)
				{
					for (n = 0; n < 3; n++)
					{
						if (*(lpSrc + (n - 1)*3 ) > 128)
						{
							*lpDst = 255;
							break;
						}
						else 
							*lpDst =*lpSrc;
					}
					lpSrc++;
					lpDst++;
				}
			}
		}
		// ���Ƹ�ʴ���ͼ��
		memcpy(p_data, p_temp, DibWidth * height); 
		// �ͷ��ڴ�
		delete []p_temp; 
	}	
}



///***************************************************************/           
/*�������ƣ�Quanfangxiangfushi()                                        
/*�������ͣ�void                                      
/*���ܣ���ͼ�����ȫ����ʴ��            
/***************************************************************/
void FuShiYuPengZhangDib::Quanfangxiangfushi()
{
	// ָ��DIB����ָ��
	LPBYTE p_data;
	// ָ��Դͼ���ָ��
	LPBYTE	lpSrc;
	// ָ�򻺴�ͼ���ָ��
	LPBYTE	lpDst;
    // ָ�򻺴�DIBͼ���ָ��
	LPBYTE	temp;
	//ѭ������
	int i;
	int j;
	int  m;
	int n;
	// �ҵ�DIBͼ��������ʼλ��
	p_data = GetData();
	// DIB�Ŀ��
	LONG wide= GetWidth();
	// DIB�ĸ߶�
	LONG height =GetHeight();
    if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{  	
		// ��ʱ�����ڴ棬�Ա�����ͼ��
		temp =new BYTE[wide*height];
		// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
		lpDst = (LPBYTE)temp;
		memset(lpDst, (BYTE)255, wide * height);
		// 3��3�ĽṹԪ��
		int B[9] = {1, 0, 1,
			        0, 0, 0,
			        1, 0, 1};
		// ʹ��ȫ����ĽṹԪ�ؽ��и�ʴ
		for (j = 1; j < height - 1; j++)
		{
			for (i = 1; i < wide - 1; i++)
			{
				// ����ʹ��3��3�ĽṹԪ�أ�Ϊ��ֹԽ�磬���Բ����������ҡ��ϡ����ıߵ�����
				// ָ��Դͼ������j�У���i�����ص�ָ��			
				lpSrc = (unsigned char *)(p_data + wide * j + i);
				// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
				lpDst = (unsigned char *)(temp + wide * j + i);
				// Ŀ��ͼ���еĵ�ǰ���ȸ��ɺ�ɫ
				*lpDst = 0; 
				// ���Դͼ����3��3�ṹԪ�ض�Ӧλ���а׵�	
				// ��Ŀ��ͼ���е�(0,0)�㸳�ɰ�ɫ
				for (m = 0; m < 3; m++)
				{
					for (n = 0; n < 3; n++)
					{
						if (B[m + n] == 1)
							continue;
						
						if (*(lpSrc + (1 - m) * wide +(n - 1) ) > 128)
						{
							*lpDst = 255;
							break;
						}
					}
				}				
			}
		}
		// ���Ƹ�ʴ���ͼ��
		memcpy(p_data, temp, wide * height);
		// �ͷ��ڴ�
		delete temp;
	}
	else //24λ���ɫ
	{
		LONG DibWidth;    //ԭͼ������	     
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		// 3��3�ĽṹԪ��
		int B[9] = {1, 0, 1,
		        	0, 0, 0,
		        	1, 0, 1};
		// ʹ��ȫ����ĽṹԪ�ؽ��и�ʴ
		for (j = 1; j < height - 1; j++)
		{
			for (i = 3; i < DibWidth - 3; i+=3)
			{
				// ����ʹ��3��3�ĽṹԪ�أ�Ϊ��ֹԽ�磬���Բ����������ҡ��ϡ����ıߵ�����
				// ָ��Դͼ������j�У���i�����ص�ָ��			
				lpSrc = (unsigned char *)(p_data + DibWidth * j + i);
				// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
				lpDst = (unsigned char *)(p_temp + DibWidth * j + i);
				// Ŀ��ͼ���еĵ�ǰ���ȸ��ɺ�ɫ
				*lpDst = 0;
				*(lpDst+1)=0;
				*(lpDst+2)=0;
				// ���Դͼ����3��3�ṹԪ�ض�Ӧλ���а׵�	
				// ��Ŀ��ͼ���е�(0,0)�㸳�ɰ�ɫ
				for(int l=0;l<3;l++)
				{
					for (m = 0; m < 3; m++)
					{
						for (n = 0; n < 3; n++)
						{
							if (B[m + n] == 1)
								continue;
							if (*(lpSrc + (1 - m) * DibWidth +(n - 1)*3 ) > 128)
							{
								*lpDst = 255;
								break;
							}
							else 
								*lpDst = *lpSrc;
						}
					}
					*lpSrc++;
					*lpDst++;
				}
			}
		}
		// ���Ƹ�ʴ���ͼ��
		memcpy(p_data, p_temp, DibWidth * height);
		// �ͷ��ڴ�
		delete []p_temp;
	}   
}



///***************************************************************/           
/*�������ƣ�Shuipingpengzhang()                                        
/*�������ͣ�void                                      
/*���ܣ���ͼ�����ˮƽ���͡�            
/***************************************************************/
void FuShiYuPengZhangDib::Shuipingpengzhang()
{
	// ָ��DIB����ָ��
	LPBYTE p_data;
	// ָ��Դͼ���ָ��
	LPBYTE	lpSrc;
	// ָ�򻺴�ͼ���ָ��
	LPBYTE	lpDst;
	// ָ�򻺴�DIBͼ���ָ��
 	LPBYTE	temp;
	//ѭ������
	int i;
	int j;
	int n;
 	// �ҵ�DIBͼ��������ʼλ��
	p_data= GetData();
	// DIB�Ŀ��
	LONG wide = GetWidth();
	// DIB�ĸ߶�
	LONG height = GetHeight();
	if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{    
		// ��ʱ�����ڴ棬�Ա�����ͼ��
		temp = new BYTE[wide*height];
		// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
		lpDst = (LPBYTE)temp;
		memset(lpDst, (BYTE)255, wide * height);
		// ʹ��ˮƽ����ĽṹԪ�ؽ�������
		for (j = 0; j < height; j++)
		{
			for (i = 1; i < wide - 1; i++)
			{
				// ����ʹ��1��3�ĽṹԪ�أ�Ϊ��ֹԽ�磬���Բ���������ߺ����ұߵ���������
				// ָ��Դͼ������j�У���i�����ص�ָ��			
				lpSrc = (unsigned char *)(p_data + wide * j + i);
				// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
				lpDst = (unsigned char *)(temp + wide * j + i);
				// Ŀ��ͼ���еĵ�ǰ���ȸ��ɰ�ɫ
				*lpDst = 255;		 
				// ���Դͼ����(-1,0)��(0,0)��(1,0)������֮һ�кڵ㣬
				// ��Ŀ��ͼ���е�(0,0)�㸳�ɺ�ɫ
				for (n = 0; n < 3; n++)
				{
					if (*(lpSrc + (n - 1) ) < 128)
					{
						*lpDst = 0;					 
						break;
					}
				}				
			}
		}
		// �������ͺ��ͼ��
		memcpy(p_data, temp, wide * height); 
		// �ͷ��ڴ�
		delete temp;
	}
	else //24λ���ɫ
	{
		LONG DibWidth;    //ԭͼ������	     
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		// ʹ��ˮƽ����ĽṹԪ�ؽ�������
		for (j = 0; j < height-1; j++)
		{
			for (i = 3; i < DibWidth ; i+=3)
			{
				// ����ʹ��1��3�ĽṹԪ�أ�Ϊ��ֹԽ�磬���Բ���������ߺ����ұߵ���������
				// ָ��Դͼ������j�У���i�����ص�ָ��			
				lpSrc = (unsigned char *)(p_data + DibWidth * j + i);
				// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
				lpDst = (unsigned char *)(p_temp + DibWidth * j + i);
				// Ŀ��ͼ���еĵ�ǰ���ȸ��ɰ�ɫ
				*lpDst = *lpSrc;			 
				*(lpDst+1) = *(lpSrc+1);
				*(lpDst+2) = *(lpSrc+2);
				// ���Դͼ����(-1,0)��(0,0)��(1,0)������֮һ�кڵ㣬
				// ��Ŀ��ͼ���е�(0,0)�㸳�ɺ�ɫ
				for(int m=0;m<3;m++)
				{
					for (n = 0; n < 3; n++)
					{
						if (*(lpSrc + (n - 1)*3 ) < 127)
						{
							*lpDst = 0;
							break;
						}				
					}
					*lpSrc++;
					*lpDst++;
				}
			}
		}
		// �������ͺ��ͼ��
		memcpy(p_data, p_temp, DibWidth * height); 
		// �ͷ��ڴ�
		delete []p_temp;
	}  
}


///***************************************************************/           
/*�������ƣ�Chuizhipengzhang()                                        
/*�������ͣ�void                                      
/*���ܣ���ͼ����д�ֱ���͡�            
/***************************************************************/
void FuShiYuPengZhangDib::Chuizhipengzhang()
{
	// ָ��DIB����ָ��
	LPBYTE p_data;
	// ָ��Դͼ���ָ��
	LPBYTE	lpSrc;
	// ָ�򻺴�ͼ���ָ��
	LPBYTE	lpDst;
	// ָ�򻺴�DIBͼ���ָ��
 	LPBYTE	temp;
	//ѭ������
	int i;
	int j;
	int n;
	// �ҵ�DIBͼ��������ʼλ��
	p_data = GetData();
	// DIB�Ŀ��
	LONG wide = GetWidth();
	// DIB�ĸ߶�
	LONG height = GetHeight();
	if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{    
	    // ��ʱ�����ڴ棬�Ա�����ͼ��
		temp =new BYTE[wide*height];
		// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
		lpDst = (LPBYTE)temp;
		memset(lpDst, (BYTE)255, wide * height);
		//ʹ�ô�ֱ����ĽṹԪ�ؽ�������
		for(j = 1; j < height - 1; j++)
		{
			for(i = 0; i < wide; i ++)
			{
				//����ʹ��3��1�ĽṹԪ�أ�Ϊ��ֹԽ�磬���Բ��������ϱߺ����±ߵ���������
				// ָ��Դͼ������j�У���i�����ص�ָ��			
				lpSrc = (unsigned char *)(p_data+ wide * j + i);
				// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
				lpDst = (unsigned char *)(temp + wide * j + i);
				//Ŀ��ͼ���еĵ�ǰ���ȸ��ɰ�ɫ		
				*lpDst = 255;			 
				// ���Դͼ����(0,-1)��(0,0)��(0,1)������֮һ�кڵ㣬
				// ��Ŀ��ͼ���е�(0,0)�㸳�ɺ�ɫ
				for (n = 0; n < 3; n++)
				{
					if (*(lpSrc + (n - 1) * wide) < 128)
					{
						*lpDst = 0;
						break;
					}
				}				
			}
		}
		// �������ͺ��ͼ��
		memcpy(p_data, temp, wide *height);
		// �ͷ��ڴ�
		delete temp;
	}
	else //24λ���ɫ
	{
		LONG DibWidth;    //ԭͼ������	    
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		//ʹ�ô�ֱ����ĽṹԪ�ؽ�������
		for(j = 1; j < height - 1; j++)
		{
			for(i = 0; i < DibWidth; i +=3)
			{
				//����ʹ��3��1�ĽṹԪ�أ�Ϊ��ֹԽ�磬���Բ��������ϱߺ����±ߵ���������
				// ָ��Դͼ������j�У���i�����ص�ָ��			
				lpSrc = (unsigned char *)(p_data+ DibWidth * j + i);
				// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
				lpDst = (unsigned char *)(p_temp + DibWidth * j + i);
				//Ŀ��ͼ���еĵ�ǰ���ȸ��ɰ�ɫ
				*lpDst = *lpSrc;			 
				*(lpDst+1) = *(lpSrc+1);
				*(lpDst+2) = *(lpSrc+2);
				// ���Դͼ����(0,-1)��(0,0)��(0,1)������֮һ�кڵ㣬
				// ��Ŀ��ͼ���е�(0,0)�㸳�ɺ�ɫ
				for (int m=0;m<3;m++)
				{
					for (n = 0; n < 3; n++)
					{
						if (*(lpSrc + (n - 1) * DibWidth) < 127)
						{
							*lpDst = 0;                  
							break;
						}				
					}
					*lpSrc++;
					*lpDst++;
				}
			}
		}
		// �������ͺ��ͼ��
		memcpy(p_data, p_temp, DibWidth *height);
		// �ͷ��ڴ�
		delete []p_temp;
	}	
}


///***************************************************************/           
/*�������ƣ�Quanfangxiangpengzhang()                                        
/*�������ͣ�void                                      
/*���ܣ���ͼ�����ȫ�������͡�            
/***************************************************************/
void FuShiYuPengZhangDib::Quanfangxiangpengzhang()
{
	// ָ��DIB����ָ��
	LPBYTE p_data;
	// ָ��Դͼ���ָ��
	LPBYTE	lpSrc;
	// ָ�򻺴�ͼ���ָ��
	LPBYTE	lpDst;
	// ָ�򻺴�DIBͼ���ָ��
	LPBYTE	temp;
	//ѭ������
	int i;
	int j;
	int m;
	int n;
	// �ҵ�DIBͼ��������ʼλ��
	p_data = GetData();
 	// DIB�Ŀ��
	LONG wide =GetWidth();
	// DIB�ĸ߶�
	LONG height = GetHeight();
	if (m_pBitmapInfoHeader->biBitCount<9)//�Ҷ�ͼ��
	{    
		// ��ʱ�����ڴ棬�Ա�����ͼ��
		temp = new BYTE[wide*height];
		// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
		lpDst = (LPBYTE)temp;
		memset(lpDst, (BYTE)255, wide * height);
		// 3��3�ĽṹԪ��
		int B[9] = {1, 0, 1,
			        0, 0, 0,
			        1, 0, 1};
		// ʹ��ȫ����ĽṹԪ�ؽ��и�ʴ
		for (j = 1; j <  height - 1; j++)
		{
			for (i = 1; i < wide -1; i ++)
			{
				// ����ʹ��3��3�ĽṹԪ�أ�Ϊ��ֹԽ�磬���Բ����������ҡ��ϡ����ıߵ�����
				// ָ��Դͼ������j�У���i�����ص�ָ��			
				lpSrc = (unsigned char *)(p_data + wide * j + i);
				// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
				lpDst = (unsigned char *)(temp + wide * j + i);
				// Ŀ��ͼ���еĵ�ǰ���ȸ��ɰ�ɫ
				*lpDst = 255;
				// ���Դͼ����3��3�ṹԪ�ض�Ӧλ���кڵ�	
				// ��Ŀ��ͼ���е�(0,0)�㸳�ɺ�ɫ
				for (m = 0; m < 3; m++)
				{
					for (n = 0; n < 3; n++)
					{
						if (B[m + n] == 1)
							continue;
						if (*(lpSrc + (1 - m) * wide +(n - 1) ) < 128)
						{
							*lpDst = 0;						 
							break;
						}
					}
				}				
			}
		}
		// ���Ƹ�ʴ���ͼ��
		memcpy(p_data, temp, wide * height);
		// �ͷ��ڴ�
		delete temp;
	}
	else //24λ���ɫ
	{
		LONG DibWidth;    //ԭͼ������	     
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		// 3��3�ĽṹԪ��
		int B[9] = {1, 0, 1,
					0, 0, 0,
					1, 0, 1};
		// ʹ��ȫ����ĽṹԪ�ؽ��и�ʴ
		for (j = 1; j <  height - 1; j++)
		{
			for (i = 3; i < DibWidth -3; i +=3)
			{
				// ����ʹ��3��3�ĽṹԪ�أ�Ϊ��ֹԽ�磬���Բ����������ҡ��ϡ����ıߵ�����
				// ָ��Դͼ������j�У���i�����ص�ָ��			
				lpSrc = (unsigned char *)(p_data + DibWidth * j + i);
				// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
				lpDst = (unsigned char *)(p_temp + DibWidth * j + i);
				// Ŀ��ͼ���еĵ�ǰ���ȸ��ɰ�ɫ
				*lpDst = *lpSrc;			 
				*(lpDst+1) = *(lpSrc+1);
				*(lpDst+2) = *(lpSrc+2);
				// ���Դͼ����3��3�ṹԪ�ض�Ӧλ���кڵ�	
				// ��Ŀ��ͼ���е�(0,0)�㸳�ɺ�ɫ
				for(int l=0;l<3;l++)
				{
					for (m = 0; m < 3; m++)
					{
						for (n = 0; n < 3; n++)
						{
							if (B[m + n] == 1)
								continue;
							if (*(lpSrc + (1 - m) * DibWidth +(n - 1)*3 ) < 128)
							{
								*lpDst = 0;	
								break;
							}
						}
					}
					*lpSrc++;
					*lpDst++;
				}
			}
		}
		// ���Ƹ�ʴ���ͼ��
		memcpy(p_data, p_temp, DibWidth * height);
		// �ͷ��ڴ�
		delete []p_temp;
	}  
}
