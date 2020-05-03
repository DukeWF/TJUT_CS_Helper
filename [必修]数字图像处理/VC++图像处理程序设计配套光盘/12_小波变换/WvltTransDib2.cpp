// WvltTrans.cpp: implementation of the CWvltTrans class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "windowsx.h"
#include "math.h"

#include "MainFrm.h"
#include "DynSplitView2.h"
//#include "wavelets.h"
//#include "DIP_System.h"
#include "WvltTransDib.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWvltTransDib::CWvltTransDib()
{
	layer1=FALSE;
	layer2=FALSE;
	layer3=FALSE;
}

CWvltTransDib::~CWvltTransDib()
{

}

void CWvltTransDib::Hangbianhuan()
{
	int i,j;
	LONG width,height;
	BYTE r, g, b;
	LPBYTE temp1, temp2;
	float tpBuffer;
	short maxVal,minVal,difVal;

	width=this->GetWidth();
	height=this->GetHeight();
	int nWidth=width/2;
	LONG lLineBytes = (width*3+3)/4 *4;
	//������ʱ���ݿռ�
	temp1 = new BYTE[height*width];
	temp2 = new BYTE[height*width];

	//���豸�����л��ԭʼͼ������
	for(j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			b=m_pData[j*lLineBytes+3*i];
			g=m_pData[j*lLineBytes+3*i+1];
			r=m_pData[j*lLineBytes+3*i+2];
			temp1[(height-1-j)*width+i]=(BYTE)(0.3*r+0.59*g+0.11*b);  
		}
	}

    for(j = 0; j < height; j ++)            
	{
		for(i = 0; i < nWidth; i ++)           
		{
			int w = i *2;
			temp2[j*width+i] = temp1[j*width+w];		//ż
			temp2[j*width+nWidth+i] = temp1[j*width+w+1];	//��
		}
	}
	//ͨ��ͼ��Ĳ�֣����С���任
	for(j=0; j<height; j++)
	{
		for(i=0; i<nWidth-1; i++)
		{
			temp2[j*width+nWidth+i] = temp2[j*width+nWidth+i] -temp2[j*width+i]+128;	
		}
	}

	maxVal=temp2[0*width+0];
	minVal=temp2[0*width+0];
	//�õ�ͼ��С��ϵ���ļ���ֵ�뼫Сֵ
	for( j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			if(maxVal<temp2[j*width+i])
				maxVal=temp2[j*width+i];
			if(minVal>temp2[j*width+i])
				minVal=temp2[j*width+i];
		}
	}
	//�����ȡͼ��С��ϵ���ļ�ֵ��
	difVal=maxVal-minVal;
	//С����������󣬷�����ʾ������
    for(j=0; j<(int)height; j++)
	{
		for(i=0; i<(int)width; i++)
		{
		//��ΪС���任���С��ϵ���п��ܳ���255�������࣬��ô�ͽ�
		//С��ϵ���ķ�Χӳ�䵽0~255�����ڣ��Ժ�������ƵĴ���Ŀ�Ķ���һ����
			tpBuffer=temp2[(height-1-j)*width+i];
			tpBuffer-=minVal;
			tpBuffer*=255;
			tpBuffer/=difVal;
			m_pData[j*lLineBytes+3*i]  = (BYTE)tpBuffer;
			m_pData[j*lLineBytes+3*i+1]= (BYTE)tpBuffer;
			m_pData[j*lLineBytes+3*i+2]= (BYTE)tpBuffer;
		}
	}
	//ɾ����ʱ�����ݿռ�
	delete temp1;
	delete temp2;	

}

void CWvltTransDib::Liebianhuan()
{
	int i,j;
	LONG width,height;
	BYTE r, g, b;
	LPBYTE temp1, temp2;
	float tpBuffer;
	short maxVal,minVal,difVal;

	width=this->GetWidth();
	height=this->GetHeight();
	int nHeight=height/2;
	LONG lLineBytes = (width*3+3)/4 *4;
	//������ʱ���ݿռ�
	temp1 = new BYTE[height*width];
	temp2 = new BYTE[height*width];

	//���豸�����л��ԭʼͼ������
	for(j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			b=m_pData[j*lLineBytes+3*i];
			g=m_pData[j*lLineBytes+3*i+1];
			r=m_pData[j*lLineBytes+3*i+2];
			temp1[(height-1-j)*width+i]=(BYTE)(0.3*r+0.59*g+0.11*b);  
		}
	}
	
	for(i = 0; i < width; i ++)            
	{
		for(j = 0; j < nHeight; j ++)           
		{
			int h = j *2 ;
			temp2[j*width+i] = temp1[h*width+i];		//even
			temp2[(nHeight + j)*width+i] = temp1[(h+1)*width+i];	//odd
		}
	}
	
	//ͨ��ͼ��Ĳ�֣����С���任
	for(i=0; i<width; i++)
	{
		for(j=0; j<nHeight-1; j++)
		{
			temp2[(nHeight + j)*width+i] -= temp2[j*width+i]+128;
		}
	}

	maxVal=temp2[0*width+0];
	minVal=temp2[0*width+0];
	//�õ�ͼ��С��ϵ���ļ���ֵ�뼫Сֵ
	for( j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			if(maxVal<temp2[j*width+i])
				maxVal=temp2[j*width+i];
			if(minVal>temp2[j*width+i])
				minVal=temp2[j*width+i];
		}
	}
	//�����ȡͼ��С��ϵ���ļ�ֵ��
	difVal=maxVal-minVal;
	//С����������󣬷�����ʾ������
    for(j=0; j<(int)height; j++)
	{
		for(i=0; i<(int)width; i++)
		{
		//��ΪС���任���С��ϵ���п��ܳ���255�������࣬��ô�ͽ�
		//С��ϵ���ķ�Χӳ�䵽0~255�����ڣ��Ժ�������ƵĴ���Ŀ�Ķ���һ����
			tpBuffer=temp2[(height-1-j)*width+i];
			tpBuffer-=minVal;
			tpBuffer*=255;
			tpBuffer/=difVal;
			m_pData[j*lLineBytes+3*i]  = (BYTE)tpBuffer;
			m_pData[j*lLineBytes+3*i+1]= (BYTE)tpBuffer;
			m_pData[j*lLineBytes+3*i+2]= (BYTE)tpBuffer;
		}
	}
	//ɾ����ʱ�����ݿռ�
	delete temp1;
	delete temp2;	
}

void CWvltTransDib::Once()
{
//	Hangbianhuan();
//	Liebianhuan();
	int i,j;
	LONG width,height,nWidth,nHeight;
	BYTE r, g, b;
	LPBYTE temp1, temp2,temp3;
	float tpBuffer;
	short maxVal,minVal,difVal;

	width=this->GetWidth();
	height=this->GetHeight();
	nWidth=width/2;
	nHeight=height/2;
	LONG lLineBytes = (width*3+3)/4 *4;
	//������ʱ���ݿռ�
	temp1 = new BYTE[height*width];
	temp2 = new BYTE[height*width];
	temp3 = new BYTE[height*width];

	//���豸�����л��ԭʼͼ������
	for(j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			b=m_pData[j*lLineBytes+3*i];
			g=m_pData[j*lLineBytes+3*i+1];
			r=m_pData[j*lLineBytes+3*i+2];
			temp1[(height-1-j)*width+i]=(BYTE)(0.3*r+0.59*g+0.11*b);  
		}
	}
	
    for(j = 0; j < height; j ++)            
	{
		for(i = 0; i < nWidth; i ++)           
		{
			int w = i *2;
			temp2[j*width+i] = temp1[j*width+w];		//ż
			temp2[j*width+nWidth+i] = temp1[j*width+w+1];	//��
		}
	}
	//ͨ��ͼ��Ĳ�֣����С���任
	for(j=0; j<height; j++)
	{
		for(i=0; i<nWidth-1; i++)
		{
			temp2[j*width+nWidth+i] -= temp2[j*width+i]+128;	
		}
	}

	for(i=0;i<nWidth;i++)
	{
		for(j=0;j<nHeight;j++)
		{
			int h=j*2;
			temp3[j*width+i]=temp2[h*width+i];//����
			temp3[(j+nHeight)*width+i]=temp2[(h+1)*width+i];//����
			temp3[j*width+nWidth+i]=temp2[h*width+nWidth+i];//����
			temp3[(j+nWidth)*width+nWidth+i]=temp2[(h+1)*width+nWidth+i];//����
		}
		for(j=0;j<nHeight;j++)
		{
			temp3[(j+nHeight)*width+i]-= temp3[j*width+i]+128;
			temp3[(j+nHeight)*width+nWidth+i]-= temp3[j*width+nWidth+i]+128;
		}
	}

	maxVal=temp3[0*width+0];
	minVal=temp3[0*width+0];
	//�õ�ͼ��С��ϵ���ļ���ֵ�뼫Сֵ
	for( j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			if(maxVal<temp3[j*width+i])
				maxVal=temp3[j*width+i];
			if(minVal>temp3[j*width+i])
				minVal=temp3[j*width+i];
		}
	}
	//�����ȡͼ��С��ϵ���ļ�ֵ��
	difVal=maxVal-minVal;
	//С����������󣬷�����ʾ������
    for(j=0; j<(int)height; j++)
	{
		for(i=0; i<(int)width; i++)
		{
		//��ΪС���任���С��ϵ���п��ܳ���255�������࣬��ô�ͽ�
		//С��ϵ���ķ�Χӳ�䵽0~255�����ڣ��Ժ�������ƵĴ���Ŀ�Ķ���һ����
			tpBuffer=temp3[(height-1-j)*width+i];
			tpBuffer-=minVal;
			tpBuffer*=255;
			tpBuffer/=difVal;
			m_pData[j*lLineBytes+3*i]  = (BYTE)tpBuffer;
			m_pData[j*lLineBytes+3*i+1]= (BYTE)tpBuffer;
			m_pData[j*lLineBytes+3*i+2]= (BYTE)tpBuffer;
		}
	}
	//ɾ����ʱ�����ݿռ�
	delete temp1;
	delete temp2;
	delete temp3;
	layer1=TRUE;
}

void CWvltTransDib::Twice()
{
	Once();
	int i,j;
	LONG width,height,nWidth,nHeight;
	BYTE r, g, b;
	LPBYTE temp1, temp2,temp3;
	float tpBuffer;
	short maxVal,minVal,difVal;

	width=this->GetWidth()/2;
	height=this->GetHeight()/2;
	nWidth=width/2;
	nHeight=height/2;
	LONG lLineBytes = (this->GetWidth()*3+3)/4 *4;
	//������ʱ���ݿռ�
	temp1 = new BYTE[height*width];
	temp2 = new BYTE[height*width];
	temp3 = new BYTE[height*width];

	//���豸�����л��ԭʼͼ������
	for(j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			b=m_pData[(j+height)*lLineBytes+3*i];
			g=m_pData[(j+height)*lLineBytes+3*i+1];
			r=m_pData[(j+height)*lLineBytes+3*i+2];
			temp1[(height-1-j)*width+i]=(BYTE)(0.3*r+0.59*g+0.11*b);  
		}
	}
	
    for(j = 0; j < height; j ++)            
	{
		for(i = 0; i < nWidth; i ++)           
		{
			int w = i *2;
			temp2[j*width+i] = (temp1[j*width+w]);		//ż
			temp2[j*width+nWidth+i] = (temp1[j*width+w+1]);	//��
		}
	}
	//ͨ��ͼ��Ĳ�֣����С���任
	for(j=0; j<height; j++)
	{
		for(i=0; i<nWidth-1; i++)
		{
			temp2[j*width+nWidth+i] -= temp2[j*width+i]+128;	
		}
	}

	for(i=0;i<nWidth;i++)
	{
		for(j=0;j<nHeight;j++)
		{
			int h=j*2;
			temp3[j*width+i]=temp2[h*width+i];//����
			temp3[(j+nHeight)*width+i]=temp2[(h+1)*width+i];//����
			temp3[j*width+nWidth+i]=temp2[h*width+nWidth+i];//����
			temp3[(j+nWidth)*width+nWidth+i]=temp2[(h+1)*width+nWidth+i];//����
		}
		for(j=0;j<nHeight;j++)
		{
			temp3[(j+nHeight)*width+i]-= temp3[j*width+i]+128;
			temp3[(j+nHeight)*width+nWidth+i]-= temp3[j*width+nWidth+i]+128;
		}
	}

	maxVal=temp3[0*width+0];
	minVal=temp3[0*width+0];
	//�õ�ͼ��С��ϵ���ļ���ֵ�뼫Сֵ
	for( j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			if(maxVal<temp3[j*width+i])
				maxVal=temp3[j*width+i];
			if(minVal>temp3[j*width+i])
				minVal=temp3[j*width+i];
		}
	}
	//�����ȡͼ��С��ϵ���ļ�ֵ��
	difVal=maxVal-minVal;
	//С����������󣬷�����ʾ������
    for(j=0; j<(int)height; j++)
	{
		for(i=0; i<(int)width; i++)
		{
		//��ΪС���任���С��ϵ���п��ܳ���255�������࣬��ô�ͽ�
		//С��ϵ���ķ�Χӳ�䵽0~255�����ڣ��Ժ�������ƵĴ���Ŀ�Ķ���һ����
			tpBuffer=temp3[(height-1-j)*width+i];
			tpBuffer-=minVal;
			tpBuffer*=255;
			tpBuffer/=difVal;
			m_pData[(j+height)*lLineBytes+3*i]  = (BYTE)tpBuffer;
			m_pData[(j+height)*lLineBytes+3*i+1]= (BYTE)tpBuffer;
			m_pData[(j+height)*lLineBytes+3*i+2]= (BYTE)tpBuffer;
		}
	}
	//ɾ����ʱ�����ݿռ�
	delete temp1;
	delete temp2;
	delete temp3;	
	layer2=TRUE;
}

void CWvltTransDib::Thrice()
{
	Twice();
	int i,j;
	LONG width,height,nWidth,nHeight;
	BYTE r, g, b;
	LPBYTE temp1, temp2,temp3;
	float tpBuffer;
	short maxVal,minVal,difVal;

	width=this->GetWidth()/4;
	height=this->GetHeight()/4;
	nWidth=width/2;
	nHeight=height/2;
	LONG lLineBytes = (this->GetWidth()*3+3)/4 *4;
	//������ʱ���ݿռ�
	temp1 = new BYTE[height*width];
	temp2 = new BYTE[height*width];
	temp3 = new BYTE[height*width];

	//���豸�����л��ԭʼͼ������
	for(j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			b=m_pData[(j+height*3)*lLineBytes+3*i];
			g=m_pData[(j+height*3)*lLineBytes+3*i+1];
			r=m_pData[(j+height*3)*lLineBytes+3*i+2];
			temp1[(height-1-j)*width+i]=(BYTE)(0.3*r+0.59*g+0.11*b);  
		}
	}
	
    for(j = 0; j < height; j ++)            
	{
		for(i = 0; i < nWidth; i ++)           
		{
			int w = i *2;
			temp2[j*width+i] = (temp1[j*width+w]);		//ż
			temp2[j*width+nWidth+i] = (temp1[j*width+w+1]);	//��
		}
	}
	//ͨ��ͼ��Ĳ�֣����С���任
	for(j=0; j<height; j++)
	{
		for(i=0; i<nWidth-1; i++)
		{
			temp2[j*width+nWidth+i] -= temp2[j*width+i]+128;	
		}
	}

	for(i=0;i<nWidth;i++)
	{
		for(j=0;j<nHeight;j++)
		{
			int h=j*2;
			temp3[j*width+i]=temp2[h*width+i];//����
			temp3[(j+nHeight)*width+i]=temp2[(h+1)*width+i];//����
			temp3[j*width+nWidth+i]=temp2[h*width+nWidth+i];//����
			temp3[(j+nWidth)*width+nWidth+i]=temp2[(h+1)*width+nWidth+i];//����
		}
		for(j=0;j<nHeight;j++)
		{
			temp3[(j+nHeight)*width+i]-= temp3[j*width+i]+128;
			temp3[(j+nHeight)*width+nWidth+i]-= temp3[j*width+nWidth+i]+128;
		}
	}

	maxVal=temp3[0*width+0];
	minVal=temp3[0*width+0];
	//�õ�ͼ��С��ϵ���ļ���ֵ�뼫Сֵ
	for( j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			if(maxVal<temp3[j*width+i])
				maxVal=temp3[j*width+i];
			if(minVal>temp3[j*width+i])
				minVal=temp3[j*width+i];
		}
	}
	//�����ȡͼ��С��ϵ���ļ�ֵ��
	difVal=maxVal-minVal;
	//С����������󣬷�����ʾ������
    for(j=0; j<(int)height; j++)
	{
		for(i=0; i<(int)width; i++)
		{
		//��ΪС���任���С��ϵ���п��ܳ���255�������࣬��ô�ͽ�
		//С��ϵ���ķ�Χӳ�䵽0~255�����ڣ��Ժ�������ƵĴ���Ŀ�Ķ���һ����
			tpBuffer=temp3[(height-1-j)*width+i];
			tpBuffer-=minVal;
			tpBuffer*=255;
			tpBuffer/=difVal;
			m_pData[(j+height*3)*lLineBytes+3*i]  = (BYTE)tpBuffer;
			m_pData[(j+height*3)*lLineBytes+3*i+1]= (BYTE)tpBuffer;
			m_pData[(j+height*3)*lLineBytes+3*i+2]= (BYTE)tpBuffer;
		}
	}
	//ɾ����ʱ�����ݿռ�
	delete temp1;
	delete temp2;
	delete temp3;	
	layer3=TRUE;
}

void CWvltTransDib::IDWT()
{
	if ((layer1==TRUE)||(layer2==TRUE)||(layer3==TRUE))
	{
		if(layer3)
			IDWT_Thrice();
		if(layer2)
			IDWT_Twice();
		if(layer1)
			IDWT_Once();
	}
	else
		AfxMessageBox("������С���任��",MB_OK,NULL);
}

void CWvltTransDib::IDWT_Once()
{
	int i,j;
	LONG width,height,nWidth,nHeight;
	BYTE r, g, b;
	LPBYTE temp1, temp2,temp3;
	float tpBuffer;
	short maxVal,minVal,difVal;

	width=this->GetWidth();
	height=this->GetHeight();
	nWidth=width/2;
	nHeight=height/2;
	LONG lLineBytes = (width*3+3)/4 *4;
	//������ʱ���ݿռ�
	temp1 = new BYTE[height*width];
	temp2 = new BYTE[height*width];
	temp3 = new BYTE[height*width];

	memset(temp1,0,height*width);
	memset(temp2,0,height*width);
	memset(temp3,0,height*width);

	//���豸�����л��ԭʼͼ������
	for(j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			b=m_pData[j*lLineBytes+3*i];
			g=m_pData[j*lLineBytes+3*i+1];
			r=m_pData[j*lLineBytes+3*i+2];
			temp1[(height-1-j)*width+i]=(BYTE)(0.3*r+0.59*g+0.11*b);  
		}
	}
	
	for(j=0; j<nHeight; j++)
	{
		for( i=0; i<width; i++)
		{
			int h=j*2;
			temp2[h*width+i]=temp1[j*width+i];
			temp2[(h+1)*width+i]=temp1[j*width+i]+temp1[(j+nHeight)*width+i]-128;
		}
	}

	for( i=0; i<nWidth-1; i++)
	{
		for(j=0; j<height; j++)
		{
			int w=i*2;
			temp3[j*width+w]=temp2[j*width+i];
			temp3[j*width+w+1]=temp2[j*width+i]+temp2[j*width+nWidth+i]-128;
		}
	}

	maxVal=temp3[0*width+0];
	minVal=temp3[0*width+0];
	//�õ�ͼ��С��ϵ���ļ���ֵ�뼫Сֵ
	for( j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			if(maxVal<temp3[j*width+i])
				maxVal=temp3[j*width+i];
			if(minVal>temp3[j*width+i])
				minVal=temp3[j*width+i];
		}
	}
	//�����ȡͼ��С��ϵ���ļ�ֵ��
	difVal=maxVal-minVal;
	//С����������󣬷�����ʾ������
    for(j=0; j<(int)height; j++)
	{
		for(i=0; i<(int)width; i++)
		{
		//��ΪС���任���С��ϵ���п��ܳ���255�������࣬��ô�ͽ�
		//С��ϵ���ķ�Χӳ�䵽0~255�����ڣ��Ժ�������ƵĴ���Ŀ�Ķ���һ����
			tpBuffer=temp3[(height-1-j)*width+i];
			tpBuffer-=minVal;
			tpBuffer*=255;
			tpBuffer/=difVal;
			m_pData[j*lLineBytes+3*i]  = (BYTE)tpBuffer;
			m_pData[j*lLineBytes+3*i+1]= (BYTE)tpBuffer;
			m_pData[j*lLineBytes+3*i+2]= (BYTE)tpBuffer;
		}
	}
	//ɾ����ʱ�����ݿռ�
	delete temp1;
	delete temp2;
	delete temp3;
	layer1=FALSE;
}

void CWvltTransDib::IDWT_Twice()
{
	int i,j;
	LONG width,height,nWidth,nHeight;
	BYTE r, g, b;
	LPBYTE temp1, temp2,temp3;
	float tpBuffer;
	short maxVal,minVal,difVal;

	width=this->GetWidth()/2;
	height=this->GetHeight()/2;
	nWidth=width/2;
	nHeight=height/2;
	LONG lLineBytes = (this->GetWidth()*3+3)/4 *4;
	//������ʱ���ݿռ�
	temp1 = new BYTE[height*width];
	temp2 = new BYTE[height*width];
	temp3 = new BYTE[height*width];

	memset(temp1,0,height*width);
	memset(temp2,0,height*width);
	memset(temp3,0,height*width);

	//���豸�����л��ԭʼͼ������
	for(j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			b=m_pData[(j+height)*lLineBytes+3*i];
			g=m_pData[(j+height)*lLineBytes+3*i+1];
			r=m_pData[(j+height)*lLineBytes+3*i+2];
			temp1[(height-1-j)*width+i]=(BYTE)(0.3*r+0.59*g+0.11*b);  
		}
	}
	
	for(j=0; j<nHeight; j++)
	{
		for( i=0; i<width; i++)
		{
			int h=j*2;
			temp2[h*width+i]=temp1[j*width+i];
			temp2[(h+1)*width+i]=temp1[j*width+i]+temp1[(j+nHeight)*width+i]-128;
		}
	}

	for( i=0; i<nWidth-1; i++)
	{
		for(j=0; j<height; j++)
		{
			int w=i*2;
			temp3[j*width+w]=temp2[j*width+i];
			temp3[j*width+w+1]=temp2[j*width+i]+temp2[j*width+nWidth+i]-128;
		}
	}

	maxVal=temp3[0*width+0];
	minVal=temp3[0*width+0];
	//�õ�ͼ��С��ϵ���ļ���ֵ�뼫Сֵ
	for( j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			if(maxVal<temp3[j*width+i])
				maxVal=temp3[j*width+i];
			if(minVal>temp3[j*width+i])
				minVal=temp3[j*width+i];
		}
	}
	//�����ȡͼ��С��ϵ���ļ�ֵ��
	difVal=maxVal-minVal;
	//С����������󣬷�����ʾ������
    for(j=0; j<(int)height; j++)
	{
		for(i=0; i<(int)width; i++)
		{
		//��ΪС���任���С��ϵ���п��ܳ���255�������࣬��ô�ͽ�
		//С��ϵ���ķ�Χӳ�䵽0~255�����ڣ��Ժ�������ƵĴ���Ŀ�Ķ���һ����
			tpBuffer=temp3[(height-1-j)*width+i];
			tpBuffer-=minVal;
			tpBuffer*=255;
			tpBuffer/=difVal;
			m_pData[(j+height)*lLineBytes+3*i]  = (BYTE)tpBuffer;
			m_pData[(j+height)*lLineBytes+3*i+1]= (BYTE)tpBuffer;
			m_pData[(j+height)*lLineBytes+3*i+2]= (BYTE)tpBuffer;
		}
	}
	//ɾ����ʱ�����ݿռ�
	delete temp1;
	delete temp2;
	delete temp3;
	layer2=FALSE;
}

void CWvltTransDib::IDWT_Thrice()
{
	int i,j;
	LONG width,height,nWidth,nHeight;
	BYTE r, g, b;
	LPBYTE temp1, temp2,temp3;
	float tpBuffer;
	short maxVal,minVal,difVal;

	width=this->GetWidth()/4;
	height=this->GetHeight()/4;
	nWidth=width/2;
	nHeight=height/2;
	LONG lLineBytes = (this->GetWidth()*3+3)/4 *4;
	//������ʱ���ݿռ�
	temp1 = new BYTE[height*width];
	temp2 = new BYTE[height*width];
	temp3 = new BYTE[height*width];

	memset(temp1,0,height*width);
	memset(temp2,0,height*width);
	memset(temp3,0,height*width);

	//���豸�����л��ԭʼͼ������
	for(j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			b=m_pData[(j+height*3)*lLineBytes+3*i];
			g=m_pData[(j+height*3)*lLineBytes+3*i+1];
			r=m_pData[(j+height*3)*lLineBytes+3*i+2];
			temp1[(height-1-j)*width+i]=(BYTE)(0.3*r+0.59*g+0.11*b);  
		}
	}
	
	for(j=0; j<nHeight; j++)
	{
		for( i=0; i<width; i++)
		{
			int h=j*2;
			temp2[h*width+i]=temp1[j*width+i];
			temp2[(h+1)*width+i]=temp1[j*width+i]+temp1[(j+nHeight)*width+i]-128;
		}
	}

	for( i=0; i<nWidth-1; i++)
	{
		for(j=0; j<height; j++)
		{
			int w=i*2;
			temp3[j*width+w]=temp2[j*width+i];
			temp3[j*width+w+1]=temp2[j*width+i]+temp2[j*width+nWidth+i]-128;
		}
	}

	maxVal=temp3[0*width+0];
	minVal=temp3[0*width+0];
	//�õ�ͼ��С��ϵ���ļ���ֵ�뼫Сֵ
	for( j=0; j<(int)height; j++)
	{
		for( i=0; i<(int)width; i++)
		{
			if(maxVal<temp3[j*width+i])
				maxVal=temp3[j*width+i];
			if(minVal>temp3[j*width+i])
				minVal=temp3[j*width+i];
		}
	}
	//�����ȡͼ��С��ϵ���ļ�ֵ��
	difVal=maxVal-minVal;
	//С����������󣬷�����ʾ������
    for(j=0; j<(int)height; j++)
	{
		for(i=0; i<(int)width; i++)
		{
		//��ΪС���任���С��ϵ���п��ܳ���255�������࣬��ô�ͽ�
		//С��ϵ���ķ�Χӳ�䵽0~255�����ڣ��Ժ�������ƵĴ���Ŀ�Ķ���һ����
			tpBuffer=temp3[(height-1-j)*width+i];
			tpBuffer-=minVal;
			tpBuffer*=255;
			tpBuffer/=difVal;
			m_pData[(j+height*3)*lLineBytes+3*i]  = (BYTE)tpBuffer;
			m_pData[(j+height*3)*lLineBytes+3*i+1]= (BYTE)tpBuffer;
			m_pData[(j+height*3)*lLineBytes+3*i+2]= (BYTE)tpBuffer;
		}
	}
	//ɾ����ʱ�����ݿռ�
	delete temp1;
	delete temp2;
	delete temp3;
	layer3=FALSE;
}

void CWvltTransDib::LowFilter()
{
	int i,j;
	LONG width,height,nWidth,nHeight;
	width=this->GetWidth();
	height=this->GetHeight();
	nWidth=width/2;
	nHeight=height/2;
	LONG lLineBytes = (width*3+3)/4 *4;	
	
	Once();
	for(j=0;j<height;j++)
	{
		for(i=0;i<width;i++)
		{
			if(!((i<nWidth)&&(j>nHeight)))
			{
				m_pData[j*lLineBytes+3*i]  = (BYTE)128;
				m_pData[j*lLineBytes+3*i+1]= (BYTE)128;
				m_pData[j*lLineBytes+3*i+2]= (BYTE)128;
			}
		}
	}
	IDWT_Once();

}

void CWvltTransDib::HighFilter()
{
	int i,j;
	LONG width,height,nWidth,nHeight;
	width=this->GetWidth();
	height=this->GetHeight();
	nWidth=width/2;
	nHeight=height/2;
	LONG lLineBytes = (width*3+3)/4 *4;	
	
	Once();
	for(j=0;j<height;j++)
	{
		for(i=0;i<width;i++)
		{
			if((i<nWidth)&&(j>nHeight))
			{
				m_pData[j*lLineBytes+3*i]  = (BYTE)128;
				m_pData[j*lLineBytes+3*i+1]= (BYTE)128;
				m_pData[j*lLineBytes+3*i+2]= (BYTE)128;
			}
		}
	}
	IDWT_Once();
}
