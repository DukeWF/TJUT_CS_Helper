#include "stdafx.h"
#include "windowsx.h"
#include "math.h"
#include "BingXingBianJieDib.h"
#include "MainFrm.h"
#include "DynSplitView2.h"
 
BingXingBianJieDib::BingXingBianJieDib()
{
}
BingXingBianJieDib::~BingXingBianJieDib()
{
}

///***************************************************************/           
/*�������ƣ�Lunkuotiqu()                                      
/*�������ͣ�void                                     
/*���ܣ���ͼ�����������ȡ��            
/***************************************************************/ 
void BingXingBianJieDib::Lunkuotiqu()
{
    LPBYTE  p_data ;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	// ָ��Դͼ���ָ��
	LPBYTE	lpSrc;
	// ָ�򻺴�ͼ���ָ��
	LPBYTE	lpDst;	
	// ָ�򻺴�DIBͼ���ָ��
	LPBYTE	temp;
	//ѭ������
	long i;
	long j;
	unsigned char n1,n2,n3,n4,n5,n6,n7,n8;
	//����ֵ
	unsigned char pixel;
	// ��ʱ�����ڴ棬�Ա�����ͼ��
	p_data=GetData();
	wide=GetWidth();
    height=GetHeight();
	temp = new BYTE[wide * height];
	for (j=0;j<height;j++)
	{
		for(i=0;i<wide;i++)
		{
			lpSrc = (LPBYTE)p_data + wide * j + i;
			if(*lpSrc>127)
				*lpSrc=255;
			else
				*lpSrc=0;
		}
	}
	// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
	memset(temp,  255, wide * height);
	for(j = 1; j <height-1; j++)
	{
		for(i = 1;i <wide-1; i++)
		{
			// ָ��Դͼ������j�У���i�����ص�ָ��			
			lpSrc = (LPBYTE)p_data + wide * j + i;
			// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
			lpDst = (LPBYTE)temp + wide * j + i;
			//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
			pixel = (unsigned char)*lpSrc;
			if(pixel == 0)
			{
				*lpDst = (unsigned char)0;
				n1 = (unsigned char)*(lpSrc + wide -1);
				n2  = (unsigned char)*(lpSrc + wide );
				n3 = (unsigned char)*(lpSrc + wide +1);
				n4 = (unsigned char)*(lpSrc -1);
				n5= (unsigned char)*(lpSrc +1);
				n6 = (unsigned char)*(lpSrc - wide -1);
				n7 = (unsigned char)*(lpSrc - wide );
				n8 = (unsigned char)*(lpSrc - wide +1);
				//������ڵİ˸��㶼�Ǻڵ�
				if(n1+n2+n3+n4+n5+n6+n7+n8==0)
				{
					*lpDst = (unsigned char)255;
				}
			}
		}
	}
	// ���Ƹ�ʴ���ͼ��
	memcpy(p_data,temp, wide * height);
	// �ͷ��ڴ�
	delete temp;	 
}

///***************************************************************/           
/*�������ƣ�Diedaifazhi(int *tongji)                                       
/*�������ͣ�void
/*����˵����tonji     ---ֱ��ͼ�Ҷ�ֵͳ��                                      
/*���ܣ���ͼ����е�����ֵѡȡ��            
/***************************************************************/ 
void BingXingBianJieDib::Diedaifazhi(int *tongji)
{
    // ѭ������
	LONG i;
	LONG j;
	// ָ��DIB����ָ��
	LPBYTE p_data;
	// �ҵ�DIBͼ��������ʼλ��
	p_data = GetData();
	// DIB�Ŀ��
	LONG wide = this->GetDibWidthBytes();
	// DIB�ĸ߶�
	LONG height = this->GetHeight();
	// ������ֵ
	int T1, T2;
	T1 = 127;
	T2 = 0;
	// ��ʱ����
	int Temp0, Temp1, Temp2, Temp3;
	Temp0 = Temp1 = Temp2 = Temp3 = 0;
	while (true)
	{
		// ������һ��������ֵ
		for (i = 0; i < T1 + 1; i++)
		{
			Temp0 += tongji[i] * i;
			Temp1 += tongji[i];
		}
		for (i = T1 + 1; i < 256; i++)
		{
			Temp2 += tongji[i] * i;
			Temp3 += tongji[i];
		}
		T2 = (Temp0 / Temp1 + Temp2 / Temp3) / 2;
		// ����������Ƿ�������
		if (T1 == T2)
			break;
		else
			T1 = T2;
	}
	// �Ը����ؽ��лҶ�ת��
	for (j = 0; j < height; j ++)
	{
		for (i = 0; i < wide; i ++)
		{
			// ��ȡ����
			unsigned char temp = *((unsigned char *)p_data + wide * j + i);
			// �ж����ػҶ�ֵ�Ƿ񳬳���Χ
			if (temp < T1)
				temp = 0;
			else
				temp = 255;
			// ��д�����������
			*((unsigned char *)p_data + wide * j + i) = temp;
		}
	}
}

///***************************************************************/           
/*�������ƣ�Fenbutongji(int *tongji)                                      
/*�������ͣ�void
/*����˵����tonji     ---ֱ��ͼ�Ҷ�ֵͳ��                                      
/*���ܣ���ͼ����лҶ�ֵͳ�ơ�            
/***************************************************************/ 
void BingXingBianJieDib::Fenbutongji(int *tongji)
{
	// ѭ������
	LONG i;
	LONG j;
	//������ʼ��
	memset(tongji,0,sizeof(int) * 256);
	// ָ��DIB����ָ��
	LPBYTE p_data;
	// �ҵ�DIBͼ��������ʼλ��
	p_data = this->GetData();
	// DIB�Ŀ��
	LONG wide = GetDibWidthBytes();
	// DIB�ĸ߶�
	LONG height = GetHeight();
	// �Ը����ؽ��лҶ�ת��
	for (j = 0; j < height; j ++)
	{
		for (i = 0; i <wide; i++)
		{
			// �Ը����ؽ��лҶ�ͳ��
			unsigned char temp = *((unsigned char *)p_data + wide * j + i);
			tongji[temp]++; 
		}
	}
}

///***************************************************************/           
/*�������ƣ�Lunkuogenzong()                                      
/*�������ͣ�void                                     
/*���ܣ���ͼ����б߽���١�            
/***************************************************************/ 
void BingXingBianJieDib::Lunkuogenzong()
{
   	// ָ��Դͼ���ָ��
	LPBYTE	lpSrc;
	LPBYTE   p_data ;
	// ָ�򻺴�ͼ���ָ��
	LPBYTE	lpDst;
	// ָ�򻺴�DIBͼ���ָ��
	LPBYTE	temp;
	long wide;
	long height;
	//ѭ������
	long i;
	long j;
	//����ֵ
    long pixel;
	//�Ƿ��ҵ���ʼ�㼰�ص���ʼ��
	bool bFindStartPoint;
	//�Ƿ�ɨ�赽һ���߽��
	bool bFindPoint;
	//��ʼ�߽���뵱ǰ�߽��
	Point StartPoint,CurrentPoint;
	//�˸��������ʼɨ�跽��
	int Direction[8][2]={{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0}};
	int BeginDirect;
	p_data=GetData();
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		wide=GetWidth();
		height=GetHeight();
		for (j=0;j<height;j++)
		{
			for(i=0;i<wide;i++)
			{
				lpSrc = (LPBYTE)p_data + wide * j + i;
				if(*lpSrc>127)
					*lpSrc=255;
				else
					*lpSrc=0;
			}
		}	
		// ��ʱ�����ڴ棬�Ա�����ͼ��
		temp = new BYTE[wide*height];
		// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
		lpDst = temp;
		memset(lpDst, (BYTE)255, wide * height);
		//���ҵ������Ϸ��ı߽��
		bFindStartPoint = false;
		for (j = 0;j < height && !bFindStartPoint;j++)
		{
			for(i = 0;i < wide && !bFindStartPoint;i++)
			{
				// ָ��Դͼ������j�У���i�����ص�ָ��			
				lpSrc =  (LPBYTE)(p_data + wide * j + i);
				//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
				pixel =  *lpSrc;
				if(pixel ==0)
				{
					bFindStartPoint = true;
					StartPoint.Height = j;
					StartPoint.Width = i;
					// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
					lpDst = (LPBYTE)(temp + wide * j + i);	
					*lpDst = 0;
				}		
			}
		}
		//������ʼ���������·�������ʼɨ�������Ϸ���
		BeginDirect = 0;
		//���ٱ߽�
		bFindStartPoint = false;
		//�ӳ�ʼ�㿪ʼɨ��
		CurrentPoint.Height = StartPoint.Height;
		CurrentPoint.Width = StartPoint.Width;
		while(!bFindStartPoint)
		{
			bFindPoint = false;
			while(!bFindPoint)
			{
				//��ɨ�跽��鿴һ������
				lpSrc = (LPBYTE)(p_data + wide * ( CurrentPoint.Height + Direction[BeginDirect][1])
					+ (CurrentPoint.Width + Direction[BeginDirect][0]));
				pixel =  *lpSrc;
				if(pixel== 0)
				{
					bFindPoint = true;
					CurrentPoint.Height = CurrentPoint.Height + Direction[BeginDirect][1];
					CurrentPoint.Width = CurrentPoint.Width + Direction[BeginDirect][0];
					if(CurrentPoint.Height == StartPoint.Height && CurrentPoint.Width == StartPoint.Width)
					{
						bFindStartPoint = true;
					}
					lpDst =  (LPBYTE)(temp + wide * CurrentPoint.Height + CurrentPoint.Width);
					*lpDst = 0;
					//ɨ��ķ�����ʱ����ת����
					BeginDirect--;
					if(BeginDirect == -1)
						BeginDirect = 7;
					BeginDirect--;
					if(BeginDirect == -1)
						BeginDirect = 7;
				}
				else
				{
					//ɨ�跽��˳ʱ����תһ��
					BeginDirect++;
					if(BeginDirect == 8)
						BeginDirect = 0;
				}
			}
		}
		// ����ͼ��
		memcpy(p_data, temp, wide * height);
		// �ͷ��ڴ�
		delete temp; 
	}	
}

///***************************************************************/           
/*�������ƣ�Zhongzitianchong(CPoint SeedPoint)                                      
/*�������ͣ�void
/*����˵����SeedPoint  ---ѡ�����ӵ�                                     
/*���ܣ���ͼ�����������䡣            
/***************************************************************/ 
void BingXingBianJieDib::Zhongzitianchong(CPoint SeedPoint)
{
	// ָ��Դͼ���ָ��
	LPBYTE	lpSrc;
    //ͼ��ĸߺͿ�
	int height,wide ;
	//����ֵ
	long pixel;
	//���Ӷ�ջ��ָ��
	Seed *Seeds;
	int StackPoint;
    LPBYTE  temp;
	//��ǰ����λ��
	int iCurrentPixelx,iCurrentPixely;
	temp =this->GetData();
	lpSrc=temp;
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		height=this->GetHeight();
		wide=this->GetWidth();		 
		for(int  j=0;j<height;j++)
		{
			for(int  i=0;i<wide;i++)
			{
				if(*lpSrc>110)
					*lpSrc=255;
				else
					*lpSrc=0; 
				lpSrc++;
			}
		}         
		//��ʼ������
		Seeds = new Seed[wide*height];
		Seeds[1].Height = SeedPoint.y;
		Seeds[1].Width = SeedPoint.x;
		StackPoint = 1;
		while( StackPoint != 0)
		{
			//ȡ������
			iCurrentPixelx = Seeds[StackPoint].Width;
			iCurrentPixely = Seeds[StackPoint].Height;
			StackPoint--;
			lpSrc = (LPBYTE)temp + wide * iCurrentPixely + iCurrentPixelx;
			//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
			pixel =  *lpSrc;	 
			//����ǰ��Ϳ��
			*lpSrc =0;
			//�ж�����ĵ㣬���Ϊ�ף���ѹ���ջ
			//ע���ֹԽ��
			if(iCurrentPixelx > 0)
			{
				lpSrc = (LPBYTE)temp + wide * iCurrentPixely + iCurrentPixelx - 1;
				//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
				pixel =  *lpSrc;
				if (pixel == 255)
				{
					StackPoint++;
					Seeds[StackPoint].Height = iCurrentPixely;
					Seeds[StackPoint].Width = iCurrentPixelx - 1;
				}
			}
			//�ж�����ĵ㣬���Ϊ�ף���ѹ���ջ
			//ע���ֹԽ��
			if(iCurrentPixely < height - 1)
			{
				lpSrc = (LPBYTE)temp + wide * (iCurrentPixely + 1) + iCurrentPixelx;
				//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
				pixel =  *lpSrc;
				if (pixel == 255)
				{
					StackPoint++;
					Seeds[StackPoint].Height = iCurrentPixely + 1;
					Seeds[StackPoint].Width = iCurrentPixelx;
				}
			}
			//�ж�����ĵ㣬���Ϊ�ף���ѹ���ջ
			//ע���ֹԽ��
			if(iCurrentPixelx < wide - 1)
			{
				lpSrc = (LPBYTE)temp + wide * iCurrentPixely + iCurrentPixelx + 1;
				//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
				pixel =  *lpSrc;
				if (pixel == 255)
				{
					StackPoint++;
					Seeds[StackPoint].Height = iCurrentPixely;
					Seeds[StackPoint].Width = iCurrentPixelx + 1;
				}
			}
			//�ж�����ĵ㣬���Ϊ�ף���ѹ���ջ
			//ע���ֹԽ��
			if(iCurrentPixely > 0)
			{
				lpSrc = (LPBYTE)temp + wide * (iCurrentPixely - 1) + iCurrentPixelx;
				//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
				pixel =  *lpSrc;
				if (pixel == 255)
				{
					StackPoint++;
					Seeds[StackPoint].Height = iCurrentPixely - 1;
					Seeds[StackPoint].Width = iCurrentPixelx;
				}		 
			}
		}
		//�ͷŶ�ջ
		delete Seeds;
	}
	else	//24λ��ɫ
	{
		height=this->GetHeight();
		wide=this->GetDibWidthBytes();         
		//��ʼ������
		Seeds = new Seed[wide*height];
		Seeds[1].Height = SeedPoint.y;
		Seeds[1].Width = SeedPoint.x*3;
		StackPoint = 1;
		while( StackPoint != 0)
		{
			//ȡ������
			iCurrentPixelx = Seeds[StackPoint].Width;
			iCurrentPixely = Seeds[StackPoint].Height;
			StackPoint--;
			lpSrc = (LPBYTE)temp + wide * iCurrentPixely + iCurrentPixelx;
			//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
			pixel =  *lpSrc;	 
			//����ǰ��Ϳ��
			*lpSrc =0;
			//�ж�����ĵ㣬���Ϊ�ף���ѹ���ջ
			//ע���ֹԽ��
			if(iCurrentPixelx > 0)
			{
				lpSrc = (LPBYTE)temp + wide * iCurrentPixely + iCurrentPixelx - 1;
				//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
				pixel =  *lpSrc;
				if (pixel == 255)
				{
					StackPoint++;
					Seeds[StackPoint].Height = iCurrentPixely;
					Seeds[StackPoint].Width = iCurrentPixelx - 1;
				}
			}
			//�ж�����ĵ㣬���Ϊ�ף���ѹ���ջ
			//ע���ֹԽ��
			if(iCurrentPixely < height - 1)
			{
				lpSrc = (LPBYTE)temp + wide * (iCurrentPixely + 1) + iCurrentPixelx;
				//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
				pixel =  *lpSrc;
				if (pixel == 255)
				{
					StackPoint++;
					Seeds[StackPoint].Height = iCurrentPixely + 1;
					Seeds[StackPoint].Width = iCurrentPixelx;
				}		 
			}
			//�ж�����ĵ㣬���Ϊ�ף���ѹ���ջ
			//ע���ֹԽ��
			if(iCurrentPixelx < wide - 1)
			{
				lpSrc = (LPBYTE)temp + wide * iCurrentPixely + iCurrentPixelx + 1;
				//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
				pixel =  *lpSrc;
				if (pixel == 255)
				{
					StackPoint++;
					Seeds[StackPoint].Height = iCurrentPixely;
					Seeds[StackPoint].Width = iCurrentPixelx + 1;
				}
			}
			//�ж�����ĵ㣬���Ϊ�ף���ѹ���ջ
			//ע���ֹԽ��
			if(iCurrentPixely > 0)
			{
				lpSrc = (LPBYTE)temp + wide * (iCurrentPixely - 1) + iCurrentPixelx;
				//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
				pixel =  *lpSrc;
				if (pixel == 255)
				{
					StackPoint++;
					Seeds[StackPoint].Height = iCurrentPixely - 1;
					Seeds[StackPoint].Width = iCurrentPixelx;
				}		 
			}
		}
		//�ͷŶ�ջ
		delete Seeds;
	}
}

///***************************************************************/           
/*�������ƣ�Yuzhifenge(int Yuzhi)                                      
/*�������ͣ�void
/*����˵����Yuzhi  ---��ֵѡȡ                                     
/*���ܣ���ͼ�������ֵ�ָ            
/***************************************************************/
void BingXingBianJieDib::Yuzhifenge(int Yuzhi)
{
	// ָ��Դͼ���ָ��
	LPBYTE  p_data;
	LPBYTE	lpSrc;
	// ָ�򻺴�ͼ���ָ��
	LPBYTE	lpDst;
	// ָ�򻺴�DIBͼ���ָ��
	LPBYTE	temp;
	//ѭ������
	long i;
	long j;
	//ͼ��ĸߺͿ�
	long wide;
	long height;
	p_data=GetData();
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
		wide=GetWidth();
	else	//24λ��ɫ
		wide=GetDibWidthBytes();
	height=GetHeight();
	temp=new BYTE[wide*height];
	memset(temp,255,wide*height);
	for (j=0;j<height;j++)
	{
		for(i=0;i<wide;i++)
		{
			lpSrc=p_data+wide*j+i;
			lpDst=temp+wide*j+i;
			if(abs(*lpSrc-Yuzhi)<30)
				*lpDst=Yuzhi;			
		}
	}
    memcpy(p_data,temp,wide*height);
	delete temp;	
}

///***************************************************************/           
/*�������ƣ�Qiyuzengzhang(CPoint point)                                      
/*�������ͣ�void
/*����˵����point  ---���������                                     
/*���ܣ���ͼ���������������            
/***************************************************************/
void BingXingBianJieDib::Qiyuzengzhang(CPoint point)
{
    // ѭ������
	int i;
	int j;
	// ָ��DIB����ָ��
	LPBYTE p_data;
	// �ҵ�DIBͼ��������ʼλ��	
    p_data=GetData();
	// DIB�Ŀ��
	LONG wide = GetWidth();	
	// DIB�ĸ߶�
	LONG height =GetHeight();
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		// �������ӵ�һ�ĻҶ�ֵ
		unsigned char  zhongzi=*(p_data+point.y*wide+point.x);	
		// �Ը����ؽ��лҶ�ת��
		for (j = 0; j < height; j ++)
		{
			for (i = 0; i < wide; i ++)
			{
				//��ȡ����ɫ����
				unsigned char temp = *((unsigned char *)p_data + wide * j +i);
				if (abs(temp - zhongzi) < 10)    //��ǰ��ͬ����һ�Ҷ�ֵ�ȽϽӽ�
				{								
					//������һ����ɫ������ǰ����			 
					*((unsigned char *)p_data + wide * j + i ) = temp;
				}
				else 
					*((unsigned char *)p_data + wide * j + i ) =255;
			}
		}
	}
	else	//24λ��ɫ
	{
		// �������ӵ�һ�ĻҶ�ֵ
		int  zhongzi=*(p_data+(height-point.y)*wide*3+point.x*3);
		int   zhongzi2=*(p_data+(height-point.y)*wide*3+point.x*3+1);
		int   zhongzi3=*(p_data+(height-point.y)*wide*3+point.x*3+2);  	
		// �Ը����ؽ��лҶ�ת��
		for (j = 0; j < height; j ++)
		{
			for (i = 0; i < wide; i ++)
			{
				//��ȡ����ɫ����
				int  temp = *((unsigned char *)p_data + 3*wide * j +i*3);
				int  temp2 = *((unsigned char *)p_data + 3*wide * j +i*3+1);
				int  temp3 = *((unsigned char *)p_data + 3*wide * j +i*3+2);
				if (abs(temp - zhongzi) < 10&&abs(temp2 - zhongzi2) < 10&&abs(temp3 - zhongzi3) < 10)    //��ǰ��ͬ����һ�Ҷ�ֵ�ȽϽӽ�
				{								
					//������һ����ɫ������ǰ����			 
					*(p_data + 3*wide * j + i*3 ) = temp;
					*(p_data +3*wide* j + i*3+1 ) = temp2;
					*(p_data +3*wide * j + i*3+2 ) = temp3;
				}
				else 
				{
					*(p_data + 3*wide * j + i*3 ) =255;
					*(p_data + 3*wide * j + i*3+1 ) =255;
					*(p_data + 3*wide * j + i*3+2 ) = 255;
				}
			}
		}
	} 
}
 
///***************************************************************/           
/*�������ƣ�Zhifangtu(float *fPs_Y)                              */
/*�������ͣ�void                                                 */
/*����˵����tongji  �Ҷȷֲ��ܶ�ͳ��                             */                           
/*���ܣ���ͼ����лҶ�ֱ��ͼͳ�ơ�								 */
/*****************************************************************/
void BingXingBianJieDib::Zhifangtu(float *tongji)
{
	// ѭ������
	int i;
	int j;
	// �Ҷȼ���
	int huidu[256];
	int wide,height;    //ԭͼ������
	// ������ʼ��
	memset(huidu,0,sizeof(huidu));
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
        wide=this->GetWidth ();
        height=this->GetHeight ();
		int width= (((wide*24) + 31) / 32 * 4) ;
		LPBYTE temp1=new BYTE[wide*height+1024];    //��ͼ�񻺳���
		//����ԭͼ�񵽻���ͼ��
		memcpy( temp1,m_pData,wide*height );
		// �Ը����ؽ��лҶ�ͳ��
		for (i = 0; i < height; i ++)
		{
			for (j = 0; j <wide; j ++)
			{
				unsigned char  temp =  temp1[wide* i + j] ;			  			 
				// �Ҷ�ͳ�Ƽ���
				huidu[temp]++;		
			}
		}
		// ����Ҷȷֲ��ܶ�
		for(i=0;i<256;i++)
			tongji[i] = huidu[i] / (height * wide *1.0f);
	}
	else	//24λ��ɫ
	{
       	wide=this->GetDibWidthBytes();
        height=this->GetHeight ();
		LPBYTE  temp1=new BYTE[wide*height];    //��ͼ�񻺳���
		//����ԭͼ�񵽻���ͼ��
		memcpy(temp1,m_pData,wide*height );
		// �Ը����ؽ��лҶ�ͳ��
		for (i = 0; i < height; i ++)
		{
			for (j = 0; j <wide; j ++)
			{
				unsigned char  temp = temp1[wide* i + j] ;
				// �Ҷ�ͳ�Ƽ���
				huidu[temp]++;		
			}
		} 
		// ����Ҷȷֲ��ܶ�
		for(i=0;i<256;i++)
			tongji[i] = huidu[i] / (height * wide *1.0f);
	} 
}

///***************************************************************/           
/*�������ƣ�BanYuZhi(int Yuzhi)                                      
/*�������ͣ�void
/*����˵����Yuzhi  ---��ֵѡȡ                                     
/*���ܣ���ͼ����а���ֵ�ָ            
/***************************************************************/
void BingXingBianJieDib::BanYuZhi(int Yuzhi)
{
    // ָ��Դͼ���ָ��
	LPBYTE  p_data;
	LPBYTE	lpSrc;
	// ָ�򻺴�ͼ���ָ��
	LPBYTE	lpDst;
	// ָ�򻺴�DIBͼ���ָ��
	LPBYTE	temp;
	//ѭ������
	long i;
	long j;
	//ͼ��ĸߺͿ�
	long wide;
	long height;
	p_data=GetData();
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		wide=GetWidth();
	}
	else	//24λ��ɫ
		wide=GetDibWidthBytes();
	height=GetHeight();
	temp=new BYTE[wide*height];
	memset(temp,255,wide*height);
	for (j=0;j<height;j++)
	{
		for(i=0;i<wide;i++)
		{
			lpSrc=p_data+wide*j+i;
			
			lpDst=temp+wide*j+i;
			
			if((*lpSrc-Yuzhi)<30)
				*lpDst=*lpSrc;			
		}
	}
    memcpy(p_data,temp,wide*height);
	delete temp;
	
}

///***************************************************************/           
/*�������ƣ�Lunkuotiqu(CPoint SeedPoint)                                      
/*�������ͣ�void
/*����˵����SeedPoint  ---���ӵ�ѡȡ                                     
/*���ܣ���24λ��ɫͼ�����������ȡ��            
/***************************************************************/
void BingXingBianJieDib::Lunkuotiqu(CPoint SeedPoint)
{
    LPBYTE  p_data ;     //ԭͼ������ָ��
    int R,G,B,R1,G1,B1;
	int wide,height;    //ԭͼ������
	// ָ��Դͼ���ָ��
	LPBYTE	lpSrc;	
	// ָ�򻺴�ͼ���ָ��
	LPBYTE	lpDst;	
	// ָ�򻺴�DIBͼ���ָ��
	LPBYTE	temp;	
	//ѭ������
	int i;
	int j;
	p_data=GetData();
	wide=GetWidth();
    height=GetHeight();
	temp = new BYTE[wide * height*3];
	// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
	memset(temp,  255, wide * height*3);
	lpSrc=p_data+wide*3*(height-SeedPoint.y)+3*SeedPoint.x;
	R1=*lpSrc;
    lpSrc++;
	G1=*lpSrc;
	lpSrc++;
	B1=*lpSrc;
	for(j=0;j<height;j++)
	{
		for(i=0;i<wide;i++)
		{
			lpSrc = (LPBYTE)p_data + wide * j*3 + i*3;
			// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
			lpDst = (LPBYTE)temp + wide * j*3 + i*3;
			int I;
			I=0;
			for(int k=i-1;k<i+2;k++)
			{
				for(int l=j-1;l<j+2;l++)
				{
					if(k>=0&&l>=0&&k<wide&&l<height)
					{
						R=*(p_data+l*wide*3+k*3);
						G=*(p_data+l*wide*3+k*3+1);
						B=*(p_data+l*wide*3+k*3+2);
						if(abs(R-R1)<10&&abs(G-G1)<10&&abs(B-B1)<10)
							I++;
					}
				}
			}
			if(I!=9)
			{	
				*lpDst=*lpSrc;
				*(lpDst+1)=*(lpSrc+1);
				*(lpDst+2)=*(lpSrc+2);
			} 
			else
			{
				*lpDst=255;
				*(lpDst+1)=255;
				*(lpDst+2)=255;
			}
		}
	}
	memcpy(p_data,temp, wide * height*3);
	delete temp;
}

/*************************************************************/
//���㷨ֻ����������б߽��ͼ��//
/*************************************************************/
void BingXingBianJieDib::Lunkuogenzong(CPoint SeedPoint)
{
	// ָ��Դͼ���ָ��
	LPBYTE	lpSrc;
	LPBYTE   p_data ;
	int R1,G1,B1;
    int R,G,B;
	// ָ�򻺴�ͼ���ָ��
	LPBYTE	lpDst;
	// ָ�򻺴�DIBͼ���ָ��
	LPBYTE	temp;
	int wide;
	int height; 
	//ѭ������
	int i;
	int j;
	//����ֵ
    int pixel;
	//�Ƿ��ҵ���ʼ�㼰�ص���ʼ��
	bool bFindStartPoint;
	//�Ƿ�ɨ�赽һ���߽��
	bool bFindPoint;
	//��ʼ�߽���뵱ǰ�߽��
	Point StartPoint,CurrentPoint;
	//�˸��������ʼɨ�跽��
	int Direction[8][2]={{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0}};
	int BeginDirect;
	p_data=GetData();
	wide=this->GetWidth();
	height=this->GetHeight();
	// ��ʱ�����ڴ棬�Ա�����ͼ��
	temp = new BYTE[wide*height*3];
	// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
	lpDst = temp;
	memset(temp, (BYTE)255, wide * height*3);
	//���ҵ����󷽵ı߽��
    lpSrc=p_data+wide*3*(height-SeedPoint.y)+3*SeedPoint.x;//ȷ�������ɫ��ֵ
	R1=*lpSrc;
    lpSrc++;
	G1=*lpSrc;
	lpSrc++;
	B1=*lpSrc;
	bFindStartPoint = false;
    int s= height-SeedPoint.y;
	for(i=SeedPoint.x;i>1;i--)  //�����㿪ʼ����Ѱ�ұ߽���ʼ��
	{
		lpSrc = (LPBYTE)p_data + wide * (height-SeedPoint.y)*3 + i*3;
		// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
		lpDst = (LPBYTE)temp + wide * (height-SeedPoint.y)*3 + i*3;
		int count;
		count=0;
		for(int k=i-1;k<i+2;k++)
		{
			for(int l=s-1;l<s+2;l++)
			{
				if(k>=0&&l>=0&&k<wide&&l<height)
				{
					R=*(p_data+l*wide*3+k*3);
					G=*(p_data+l*wide*3+k*3+1);
					B=*(p_data+l*wide*3+k*3+2);
					if(abs(R-R1)<10&&abs(G-G1)<10&&abs(B-B1)<10)
						count++;
				}
			}
		}
		if(count!=9)
		{
			bFindStartPoint = true;
			StartPoint.Height = s;
			StartPoint.Width = i;
			// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
			lpDst = (LPBYTE)(temp + wide * s*3 + i*3);	
			*lpDst = 0;
			*(lpDst+1)=0;
			*(lpDst+2)=0;
			break;
		} 
	}	        
	//������ʼ���������·�������ʼɨ�������Ϸ���
	BeginDirect = 0;
	//���ٱ߽�
	bFindStartPoint = false;
	//�ӳ�ʼ�㿪ʼɨ��
	CurrentPoint.Height = StartPoint.Height;
	CurrentPoint.Width = StartPoint.Width;
	while(!bFindStartPoint)
	{
		bFindPoint = false;
		while(!bFindPoint)
		{
			//��ɨ�跽��鿴һ������
			lpSrc = (LPBYTE)(p_data + 3*wide * ( CurrentPoint.Height + Direction[BeginDirect][1])
				+ 3*(CurrentPoint.Width + Direction[BeginDirect][0]));
			R =*lpSrc;
			G=*(lpSrc+1);
			B=*(lpSrc+2);
			if(abs(R-R1)<10&&abs(G-G1)<10&&abs(B-B1)<10)
			{
				bFindPoint = true;
				CurrentPoint.Height = CurrentPoint.Height + Direction[BeginDirect][1];
				CurrentPoint.Width = CurrentPoint.Width + Direction[BeginDirect][0];
				if(CurrentPoint.Height == StartPoint.Height && CurrentPoint.Width == StartPoint.Width)
				{
					bFindStartPoint = true;
				}
				lpDst =  (LPBYTE)(temp + 3*wide * CurrentPoint.Height + 3*CurrentPoint.Width);
				*lpDst = *lpSrc;
                *(lpDst+1) = *(lpSrc+1);
				*(lpDst+2) = *(lpSrc+2);
				//ɨ��ķ�����ʱ����ת����
				BeginDirect--;
				if(BeginDirect == -1)
					BeginDirect = 7;
				BeginDirect--;
				if(BeginDirect == -1)
					BeginDirect = 7;
			}
			else
			{
				//ɨ�跽��˳ʱ����תһ��
				BeginDirect++;
				if(BeginDirect == 8)
					BeginDirect = 0;
			}
		}
	}
	// ����ͼ��
	memcpy(p_data, temp, 3*wide * height);
	// �ͷ��ڴ�
    delete temp; 
}
