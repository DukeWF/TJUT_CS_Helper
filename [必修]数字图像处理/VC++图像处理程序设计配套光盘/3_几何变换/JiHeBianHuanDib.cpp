#include "stdafx.h"
#include "windowsx.h"
#include "math.h"
#include "JiHeBianHuanDib.h"
#include "MainFrm.h"
#include "DynSplitView2.h"
 
#define PI 3.1415926535
#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4) 

#define RADIAN(angle) ((angle)*PI/180.0) //�Ƕȵ�����ת���ĺ�

JiHeBianHuanDib::JiHeBianHuanDib()
{

}

JiHeBianHuanDib::~JiHeBianHuanDib()
{

}

///***************************************************************/           
/*�������ƣ�JingXiang(bool fangshi)                                        
/*�������ͣ�void
/*����˵����fangshi --�жϱ�־Ϊ true ˮƽ����Ϊ false ��ֱ����                                      
/*���ܣ���ͼ����о�����ʾ��            
/***************************************************************/ 
void JiHeBianHuanDib::JingXiang(bool fangshi)
{
    // ָ��Դͼ���ָ��
	LPBYTE	lpSrc;
	LPBYTE  p_data;
	// ָ��Ҫ���������ָ��
	LPBYTE	lpDst;
	// ָ����ͼ���ָ��
	LPBYTE	temp;
	// ѭ������
	LONG	i;
	LONG	j;
	//ͼ��ĸ����
	long height=this->GetHeight();
	long wide=this->GetWidth();
	p_data=this->GetData();
	// ��ʱ�����ڴ棬�Ա���һ��ͼ��
	temp = new BYTE[wide*height];
	// �жϾ���ʽ
	if (fangshi)		// ˮƽ����
	{
		if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
		{
			// ���ͼ��ÿ�н��в���
			for(j = 0; j < height; j++)
			{
				for(i = 0; i <  wide;i++)
				{
					lpSrc = (LPBYTE)p_data +wide *j + i;
					lpDst = (LPBYTE)temp + wide* j+ wide - i;
					*lpDst = *lpSrc;
				}
			}
			memcpy(p_data,temp, wide*height);
		}
		else	//24λ��ɫ
		{
			wide=this->GetDibWidthBytes();
			temp=new BYTE[height*wide];
			// ���ͼ��ÿ�н��в���
			for(j = 0; j < height; j++)
			{
				for(i = 0; i <  wide;i=i+3)
				{
					lpSrc = (LPBYTE)(p_data +wide *j + i);
					lpDst = (LPBYTE)temp + wide* j+ wide - i;
					*(lpDst) = *lpSrc;
					*(lpDst+1) = *(lpSrc+1);
					*(lpDst+2) = *(lpSrc+2);
				}			
			}
			memcpy(p_data,temp, wide*height);
		}		
	}
	else		// ��ֱ����
	{
       	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
		{
			// ����ϰ�ͼ����в���
			for(i = 0; i <  wide;i++)
			{
				for(j = 0; j < height; j++)
				{
					lpSrc = (LPBYTE)p_data + wide * j+i;
					lpDst = (LPBYTE)temp + wide * (height - j - 1)+i;
					*lpDst = *lpSrc;
				}
			}
			memcpy(p_data,temp, wide*height);	       
		}
		else	//24λ��ɫ		
		{
			wide=this->GetDibWidthBytes();
			temp=new BYTE[height*wide];
			// ����ϰ�ͼ����в���
			for(i = 0; i <  wide;i++)
			{
				for(j = 0; j < height; j++)
				{
					lpSrc = (LPBYTE)p_data + wide * j+i;
					lpDst = (LPBYTE)temp + wide * (height - j - 1)+i;
					*lpDst = *lpSrc;
				}
			}
			memcpy(p_data,temp, wide*height);
			// �ͷ��ڴ�
			delete temp;		
		}	   
	}
}

///***************************************************************/           
/*�������ƣ�Zhuanzhi()                                        
/*�������ͣ�void                                     
/*���ܣ���ͼ�����ת�ô���            
/***************************************************************/
void JiHeBianHuanDib::Zhuanzhi()
{
	// ͼ��Ŀ�Ⱥ͸߶�
	LONG	wide=this->GetWidth();
	LONG	height=this->GetHeight();
	//ͼ��ÿ���ֽ���
	LONG lLineBytes=(((wide*8)+31)/32*4);
	//��ͼ��ÿ���ֽ���
    LONG lNewLineBytes=(((height*8)+31)/32*4);
	// ָ��Դͼ���ָ��
	LPBYTE	p_data=this->GetData();
	// ָ��Դ���ص�ָ��
	LPBYTE	lpSrc;
	// ָ��ת��ͼ���Ӧ���ص�ָ��
	LPBYTE	lpDst;
	// ָ��ת��ͼ���ָ��
	LPBYTE	temp;	
	// ѭ������
	LONG	i;
	LONG	j;
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{ 
		//�����ڴ�
		temp=new BYTE[wide*lNewLineBytes];
		
		// ���ͼ��ÿ�н��в���
		for(j = 0; j < height; j++)
		{
			// ���ÿ��ͼ��ÿ�н��в���
			for(i = 0; i < wide;i++)
			{
				// ָ��ԴDIB��j�У���i�����ص�ָ��
				lpSrc = (LPBYTE)p_data+ lLineBytes * j + i;
				// ָ��ת��DIB��i�У���j�����ص�ָ��
				// ע��˴�wide��height��ԴDIB�Ŀ�Ⱥ͸߶ȣ�Ӧ�û���
				lpDst = (LPBYTE)temp + lNewLineBytes* i+ j;
				// ��������
				*lpDst = *lpSrc;
			}
		}
		m_pBitmapInfoHeader->biHeight=wide;
		m_pBitmapInfoHeader->biWidth=height;
		// ����ת�ú��ͼ��
		memcpy(p_data, temp, wide* height);
		// �ͷ��ڴ�
		delete  temp;
	}
	else	//24λ��ɫ
	{
		lLineBytes=wide*3;
		lNewLineBytes=height*3;
		temp=new BYTE[wide*lNewLineBytes];
		// ���ͼ��ÿ�н��в���
		for(j = 0; j < height; j++)
		{
			// ���ÿ��ͼ��ÿ�н��в���
			for(i = 0; i < wide;i++)
			{
				// ָ��ԴDIB��j�У���i�����ص�ָ��
				lpSrc = (LPBYTE)p_data+ lLineBytes * j + i*3;
				// ָ��ת��DIB��i�У���j�����ص�ָ��
				// ע��˴�wide��height��ԴDIB�Ŀ�Ⱥ͸߶ȣ�Ӧ�û���
				lpDst = (LPBYTE)temp +lNewLineBytes* i+ j*3;
				// ��������
				*lpDst++ = *lpSrc++;
				*lpDst++ = *lpSrc++;
				*lpDst = *lpSrc;			
			}		
		}
		m_pBitmapInfoHeader->biHeight=wide;
		m_pBitmapInfoHeader->biWidth=height;
		// ����ת�ú��ͼ��
		memcpy(p_data, temp, wide* height*3);	
		// �ͷ��ڴ�
		delete  temp;
	}
}

///***************************************************************/           
/*�������ƣ�Xuanzhuan(int RotateAngle)                                        
/*�������ͣ�void
/*����˵����RotateAngle --��ת�Ƕ�                                     
/*���ܣ���ͼ�������ת����            
/*****************************************************************/
void JiHeBianHuanDib::Xuanzhuan(double RotateAngle)
{
    DWORD        OffBits,SrcBufSize,DstBufSize,DstLineBytes;
    LPBYTE       lpTempPtr,lpPtr,lpSrc,lpTemp;
    double       SrcX1,SrcY1,SrcX2,SrcY2;
    double       SrcX3,SrcY3,SrcX4,SrcY4;
    double       DstX1,DstY1,DstX2,DstY2;
    double       DstX3,DstY3,DstX4,DstY4;
    DWORD        x0,y0,x1,y1;
    double       cosa,sina; 
    double       num1,num2;
    int          LineBytes;
	//�Ƕȵ����ȵ�ת��
    RotateAngle=(double)RADIAN(RotateAngle);
    cosa=(double)cos((double)RotateAngle);
    sina=(double)sin((double)RotateAngle);
    //ԭͼ�Ŀ�Ⱥ͸߶�
    lpSrc=this->GetData();
    int Wold=this->GetWidth();
    int Hold=this->GetHeight();
    //ԭͼ���ĸ��ǵ�����
	SrcX1=(double)(-0.5*Wold);
	SrcY1=(double)(0.5*Hold);
	SrcX2=(double)(0.5*Wold);
	SrcY2=(double)(0.5*Hold);
	SrcX3=(double)(-0.5*Wold);
	SrcY3=(double)(-0.5*Hold);
	SrcX4=(double)(0.5*Wold);
	SrcY4=(double)(-0.5*Hold);
	//��ͼ�ĸ��ǵ�����
	DstX1=cosa*SrcX1+sina*SrcY1;
	DstY1=-sina*SrcX1+cosa*SrcY1;
	DstX2=cosa*SrcX2+sina*SrcY2;
	DstY2=-sina*SrcX2+cosa*SrcY2;
	DstX3=cosa*SrcX3+sina*SrcY3;
	DstY3=-sina*SrcX3+cosa*SrcY3;
	DstX4=cosa*SrcX4+sina*SrcY4;
	DstY4=-sina*SrcX4+cosa*SrcY4;
	//������ͼ�Ŀ�ȣ��߶�
	int Wnew = (DWORD)(max(fabs(DstX4-DstX1), fabs(DstX3-DstX2))+0.5);
	int Hnew = (DWORD)(max(fabs(DstY4-DstY1), fabs(DstY3-DstY2))+0.5);
	//�������(2.9)�е��������������������Ժ�ÿ�ζ�������
	num1=(double)( -0.5*Wnew*cosa-0.5*Hnew*sina+0.5*Wold);
	num2=(double)(0.5*Wnew*sina-0.5*Hnew*cosa+0.5*Hold);
	if(m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{
		//���µĻ������е�ÿ���ֽڶ����255�������Ժ�δ��������ؾ��ǰ�ɫ
		DstBufSize=Wnew*Hnew;
		lpTempPtr=new BYTE[Wnew*Hnew];
		memset(lpTempPtr,(BYTE)255,Wnew*Hnew);
		lpTemp=lpTempPtr;
		for(y1=0;y1<Hnew;y1++)
		{
			for(x1=0;x1<Wnew;x1++)
			{
				//x0,y0Ϊ��Ӧ��ԭͼ�ϵ�����
				x0= (DWORD)(x1*cosa+y1*sina+num1);
				y0= (DWORD)(-1.0f*x1*sina+y1*cosa+num2);
				if( (x0>=0) && (x0<Wold) && (y0>=0) && (y0<Hold))   //��ԭͼ��Χ��
				{
					lpPtr=lpSrc+y0*Wold+x0;
					lpTempPtr=lpTemp+y1*Wnew+x1;
					*lpTempPtr=*lpPtr; //�������صĸ���
					lpTempPtr=lpTemp;
				}
			}
		}
		this->SetWidth(Wnew);
		this->SetHeight(Hnew);
		this->m_pData=lpTemp;
	}
	else	//24λ��ɫ
	{
		//���µĻ������е�ÿ���ֽڶ����255�������Ժ�δ��������ؾ��ǰ�ɫ
		DstBufSize=Wnew*Hnew*3;
		lpTempPtr=new BYTE[Wnew*Hnew*3];
		memset(lpTempPtr,(BYTE)255,Wnew*Hnew*3);
		lpTemp=lpTempPtr;
		for(y1=0;y1<Hnew;y1++)
		{
			for(x1=0;x1<Wnew;x1++)
			{
				//x0,y0Ϊ��Ӧ��ԭͼ�ϵ�����
				x0= (DWORD)(x1*cosa+y1*sina+num1);
				y0= (DWORD)(-1.0f*x1*sina+y1*cosa+num2);
				if((x0>=0) && (x0<Wold) && (y0>=0) && (y0<Hold))   //��ԭͼ��Χ��
				{
					lpPtr=lpSrc+y0*Wold*3+x0*3;
					lpTempPtr=lpTemp+y1*Wnew*3+x1*3;					
					*lpTempPtr++=*lpPtr++; //�������صĸ���
					*lpTempPtr++=*lpPtr++; //�������صĸ���
					*lpTempPtr=*lpPtr; //�������صĸ���
					lpTempPtr=lpTemp;
				}
			}
		}
		this->SetWidth(Wnew);
		this->SetHeight(Hnew);
		this->m_pData=lpTemp;
	}
}

void JiHeBianHuanDib::clearmem2()
{
	LONG temp;
	temp=m_pBitmapInfoHeader->biHeight;
    m_pBitmapInfoHeader->biHeight=m_pBitmapInfoHeader->biWidth;
	m_pBitmapInfoHeader->biWidth=temp;
}

///***************************************************************/           
/*�������ƣ�Suofang(float xzoom, float yzoom)                                        
/*�������ͣ�void
/*����˵����xzoom --ˮƽ��С�ı���
/*          yzoom --��ֱ��С�ı���                                     
/*���ܣ���ͼ��������Ŵ���            
/*****************************************************************/
void JiHeBianHuanDib::SuoXiao(float xzoom, float yzoom)
{
    // Դͼ��Ŀ�Ⱥ͸߶�
	LONG	wide;
	LONG	height;
	LONG    LineBytes;
	// ���ź�ͼ��Ŀ�Ⱥ͸߶�
	LONG	newwide;
	LONG	newheight;
	// ָ��Դͼ���ָ��
	LPBYTE	p_data ;
	LPBYTE  temp;
    temp=this->GetData();
    p_data= temp;
	// ָ��Դ���ص�ָ��
	LPBYTE	lpSrc;
	// ָ������ͼ���Ӧ���ص�ָ��
	LPBYTE	lpDst;
	// ָ������ͼ���ָ��
	LPBYTE	hDIB;
	// ѭ����������������DIB�е����꣩
	LONG	i;
	LONG	j;
	// ������ԴDIB�е�����
	LONG	i0;
	LONG	j0;
	if(m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{
		// ��ȡͼ��Ŀ��
		wide = this->GetWidth();
		LineBytes=(wide*8+31)/32*4;
		// ��ȡͼ��ĸ߶�
		height = this->GetHeight();
		// �������ź��ͼ��ʵ�ʿ�Ⱥ͸߶�
		// �˴�ֱ�Ӽ�0.5������ǿ������ת��ʱ���������룬����ֱ�ӽ�ȥС������
		newwide = (LONG) (wide * xzoom  + 0.5);
		newheight = (LONG) (height * yzoom  + 0.5);
		// �����ڴ棬�Ա�����DIB
		hDIB = new BYTE[ newwide * newheight*3 ];
		int k1 =yzoom+ 0.5;
		int k2 =xzoom+ 0.5;
		// ���ͼ��ÿ�н��в���
		for(j = 0; j < height-1; j=j+k1)
		{
			// ���ͼ��ÿ�н��в���
			for(i = 0; i < wide-1; i=i+k2)
			{
				// ָ����DIB��i�У���j�����ص�ָ��
				// ע��˴���Ⱥ͸߶�����DIB�Ŀ�Ⱥ͸߶�
				lpDst = (LPBYTE)hDIB  + newwide * j + i;
				// �����������ԴDIB�е�����
				j0 = (LONG) (j / yzoom  + 0.5);
				i0 = (LONG) (i / xzoom  + 0.5);
				// �ж��Ƿ���Դͼ��Χ��
				if( (i0 >= 0) && (i0 < wide) && (j0 >= 0) && (j0 < height))
				{
					// ָ��ԴDIB��i0�У���j0�����ص�ָ��
					lpSrc = (LPBYTE)p_data + wide * j0 + i0;
					// ��������
					*lpDst = *lpSrc;
				}
				else
				{
					// ����Դͼ��û�е����أ�ֱ�Ӹ�ֵΪ255
					*lpDst = 255;
				}
			}
		}
		// ������С���ͼ��
		for(j=0;j<height;j++)
		{	
			for(i=0;i<wide;i++)
			{
				if(j<=newheight&&i<=newwide)
				{ 
					lpDst = (LPBYTE)hDIB  + newwide * j + i;
					*p_data=*lpDst;		     
				}
				else *p_data=255;
				p_data++;
			}
		}	    
		delete hDIB; 
	}
	else	//24λ��ɫ
	{
		// ��ȡͼ��Ŀ��
		wide = this->GetDibWidthBytes();
		LineBytes = (((wide * 8)+31)/32*4);
		// ��ȡͼ��ĸ߶�
		height = this->GetHeight();
		// �������ź��ͼ��ʵ�ʿ��
		// �˴�ֱ�Ӽ�0.5������ǿ������ת��ʱ���������룬����ֱ�ӽ�ȥС������
		newwide = (LONG) (LineBytes * xzoom  + 0.5);
		// �������ź��ͼ��߶�
		newheight = (LONG) (height * yzoom  + 0.5);
		// �����ڴ棬�Ա�����DIB
		hDIB = new BYTE[ newwide * newheight*3 ];
		int k1 =(int)(yzoom+ 0.5);
		int k2 =(int)(xzoom+ 0.5);
		// ���ͼ��ÿ�н��в���
		for(j = 0; j < height-1; j=j+k1)
		{
			// ���ͼ��ÿ�н��в���
			for(i = 0; i < LineBytes-1; i=i+k2*3)
			{
				// ָ����DIB��i�У���j�����ص�ָ��
				// ע��˴���Ⱥ͸߶�����DIB�Ŀ�Ⱥ͸߶�
				lpDst = (LPBYTE)hDIB  + newwide * j + i;			
				// �����������ԴDIB�е�����
				j0 = (LONG) (j / yzoom  + 0.5);
				i0 = (LONG) (i / xzoom  + 0.5);
				// �ж��Ƿ���Դͼ��Χ��
				if( (i0 >= 0) && (i0 < LineBytes) && (j0 >= 0) && (j0 < height))
				{				
					// ָ��ԴDIB��i0�У���j0�����ص�ָ��
					lpSrc = (LPBYTE)p_data + LineBytes * j0 + i0;
					// ��������
					*lpDst = *lpSrc;
					*(lpDst+1)=*(lpSrc+1);
					*(lpDst+2)=*(lpSrc+2);               
				}
				else
				{
					// ����Դͼ��û�е����أ�ֱ�Ӹ�ֵΪ255
					*lpDst = 255;
				}
			}
		}
		// ������С���ͼ��
		for(j=0;j<height;j++)
		{	
			for(i=0;i<LineBytes;i++)
			{
				if(j<=newheight&&i<=newwide)
				{   
					lpDst = (LPBYTE)hDIB  + newwide * j + i;
					*p_data=*lpDst;
				
				}
				else *p_data=255;
				
				p_data++;
			}
		}
	}
}

/***************************************************************/           
/*�������ƣ�PingYi(int m_Xmove, int m_Ymove)                                       
/*�������ͣ�void
/*����˵����m_Xmove ͼ���ˮƽƽ������m_Ymove ͼ��Ĵ�ֱƽ����                                    
/*���ܣ���ͼ�����ƽ����ʾ��            
/***************************************************************/ 
void JiHeBianHuanDib::PingYi(int m_Xmove, int m_Ymove)
{
	// ָ��Դͼ���ָ��
	LPBYTE	lpSrc;
    LPBYTE   p_data;
	// ָ��Ҫ���������ָ��
	LPBYTE	lpDst;
	// ָ����ͼ���ָ��
	LPBYTE	temp;
	// ѭ������
	int	i,j;
	//ͼ��ĸߺͿ�
	LONG wide,height;
	// ͼ��ÿ�е��ֽ���
	LONG lLineBytes;
	p_data=GetData();
	wide=GetWidth();
	height=GetHeight();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{	
		// ����ͼ��ÿ�е��ֽ���
		lLineBytes = (((wide * 8)+31)/32*4);	
		// ��ʱ�����ڴ棬�Ա�����ͼ��
		temp=new BYTE [lLineBytes*height];
		// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
		lpDst = (LPBYTE)temp;
		memset(lpDst, (BYTE)255, lLineBytes * height);
		// ÿ��
		for( i = 0; i < wide; i++)
		{
			// ÿ��
			for( j = 0; j < height; j++)
			{
				// �����������ԴDIB�е�����
				lpSrc = (LPBYTE)p_data + lLineBytes * (height - 1 - j) + i;
				int i0,j0;
				// �������������DIB�е�����
				i0 = i+m_Xmove;
				j0 = j + m_Ymove;
				// �ж��Ƿ�����ͼ��Χ��
				if( (i0 >= 0) && (i0 < wide) && (j0 >= 0) && (j0 < height))
				{
					lpDst = (LPBYTE)temp + lLineBytes *(height - 1 - j0) + i0;
					// ��������
					*lpDst = *lpSrc;
				}
				else
				{
					// ����Դͼ��û�е����أ�ֱ�Ӹ�ֵΪ255
					* ((unsigned char*)lpDst) = 255;
				}
			}
		}
		// ����ƽ�ƺ��ͼ��
		memcpy(p_data, temp, lLineBytes * height);
		// �ͷ��ڴ�
		delete temp;
	}
    else 	//24λ��ɫ
    { 	     
		wide=this->GetDibWidthBytes() ;   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *temp=new BYTE[height*wide];
		// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
		lpDst = (LPBYTE)temp;
		memset(lpDst, (BYTE)255, wide * height);
		// ÿ��
		for(int j = 0; j < height; j++)
		{
			// ÿ��
			for( i = 0; i < wide; i++)
			{			
				// �����������ԴDIB�е�����
				lpSrc = (LPBYTE)p_data + wide * (height - 1 - j) + i;
				int i0,j0;
				// �������������DIB�е�����
				i0 = i+m_Xmove*3;
				j0 = j + m_Ymove;
				
				// �ж��Ƿ�����ͼ��Χ��
				if( (i0 >= 0) && (i0 < wide) && (j0 >= 0) && (j0 < height))
				{
					lpDst = (LPBYTE)temp + wide*(height - 1 - j0) + i0;
					// ��������
					*lpDst = *lpSrc;
				}
				else
				{
					// ����Դͼ��û�е����أ�ֱ�Ӹ�ֵΪ255
					* ((unsigned char*)lpDst) = 255;
				}			
			}
		}
		// ����ƽ�ƺ��ͼ��
		memcpy(p_data, temp, wide * height);
	}
}

///*********************************************************************************/           
/*�������ƣ�FangDa(LPBYTE temp,float xzoom ,float yzoom,LONG wide,LONG	height,LONG	newwide,LONG newheight)
/*�������ͣ�LPBYTE 
/*����˵����temp  --��ͼ����׵�ַ
/*          xzoom --ˮƽ�Ŵ�ı���
/*          yzoom --��ֱ�Ŵ�ı���  
/*          wide  --ԭͼ��Ŀ��
/*			height--ԭͼ��ĸ߶�
/*			newwide--��ͼ��Ŀ��
/*			newheight--��ͼ��ĸ߶�
/*�������ͣ�LPBYTE                         
/*���ܣ���ͼ����зŴ���            
/************************************************************************************/
LPBYTE JiHeBianHuanDib::FangDa(LPBYTE temp, float xzoom, float yzoom,LONG wide,LONG	height,LONG	newwide,LONG newheight)
{
	// ָ��Դͼ���ָ��
	LPBYTE	p_data ;
	LPBYTE  temp1;
	// ָ��Դ���ص�ָ��
	LPBYTE	lpSrc;
	// ָ������ͼ���Ӧ���ص�ָ��
	LPBYTE	lpDst;
	int	i;
	int	j;
	// ������ԴDIB�е�����
	int	i0;
	int	j0;
	p_data=this->GetData();
	// ��ȡͼ��Ŀ��
	int	k1=(int)yzoom ;
    int	k2= (int)xzoom ; 
	if(m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{
		temp1 = new BYTE[newwide * newheight];
		memset(temp1,(BYTE)255,newwide * newheight);		
		// ���ͼ��ÿ�н��в���
		for(j = 0; j < newheight; j++)
		{
			// ���ͼ��ÿ�н��в���
			for(i = 0; i < newwide; i++)
			{
				lpDst = (LPBYTE)temp1+newwide*j+i;
				i0=(int)(i/xzoom+0.5);
				j0=(int)(j/yzoom+0.5);	
				if( (i0 >= 0) && (i0 < wide) && (j0 >= 0) && (j0 < height))
				{
					lpSrc=(LPBYTE)p_data + wide * j0 + i0;	
					*lpDst=*lpSrc;
				}
			}
		}   
		temp=temp1;
		return temp; 
	}
	else	//24λ��ɫ		
	{
		// �����ڴ棬�Ա�����DIB
		temp1 = new BYTE[newwide * newheight*4];
		memset(temp1,255,newwide * newheight*4);
		int r,g,b;
		// ���ͼ��ÿ�н��в���
		for(j = 0; j < height; j++)
		{
			// ���ͼ��ÿ�н��в���
			for(i = 0; i < wide; i++)
			{
				lpSrc = (LPBYTE)p_data + wide * j*3 + i*3;
				r=*lpSrc++;
				g=*lpSrc++;
				b=*lpSrc;
				// ��������
				for(int n=0;n<k1;n++)
				for(int m=0;m<k2;m++)
				{
					// ָ��ԴDIB��i0�У���j0�����ص�ָ��	
					lpDst = (LPBYTE)temp1  + newwide *(j*k1+n) + (i+m)*k2*3;
					*lpDst++ = r;   
					*lpDst++ = g;      
					*lpDst = b;		
				}
			}
		}
		// ����ת�ú��ͼ��	
		temp=temp1;
		// �ͷ��ڴ�
		return temp;
	}
}
