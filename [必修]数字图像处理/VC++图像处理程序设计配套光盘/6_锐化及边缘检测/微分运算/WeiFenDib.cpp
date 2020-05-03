#include "stdafx.h"
#include "windowsx.h"
#include "math.h"
#include "WeiFenDib.h"
#include "MainFrm.h"
#include "DynSplitView2.h"
#include "CDIB.h"

WeiFenDib::WeiFenDib()
{
}

WeiFenDib::~WeiFenDib()
{
}

/***************************************************************/           
/*�������ƣ�ZongXiang()                                        */
/*�������ͣ�void                                               */
/*����ֵ������ɹ�����TRUE;����ʧ�ܷ���FALSE��                 */                                       
/*���ܣ���ͼ���������΢��                                     */
/***************************************************************/
void WeiFenDib::ZongXiang()
{    
    BYTE  *p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������	
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{	    
        LPBYTE   temp=new BYTE [wide*height];    //����ͼ��һ������
		memset(temp,255,wide*height);
		for(int j=1;j<height-1;j++)
			for(int i=1;i<wide-1;i++)
				//��ǰ���صĻҶ�ֵ������������ػҶ�ֵ֮��ľ���ֵ
				temp[wide*j+i]=abs(p_data[wide*j+i]-p_data[wide*j+(i-1)]);
		//���������е�ͼ���ƻ�ԭͼ������
		memcpy(p_data, temp,wide*height);
		//ɾ��������
		delete  temp;
	}
	else	//24λ��ɫ
	{    
		int DibWidth;    //ԭͼ������	
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		for(int j=1;j<height-1;j++)	// ÿ��
		{
			for(int i=3;i<DibWidth-3;i++)	// ÿ��
			{
				int pby_pt=0;
				pby_pt=*(p_data+(height-j-1)*DibWidth+i)-*(p_data+(height-j-1)*DibWidth+i-3);
                *(p_temp+(height-j-1)*DibWidth+i)=abs(pby_pt);
			}
		}
		memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
        delete []p_temp;  //ɾ����ʱ�����ڴ�
	}    
}

/***************************************************************/           
/*�������ƣ�HengXiang()                                        */
/*�������ͣ�void                                               */
/*����ֵ������ɹ�����TRUE;����ʧ�ܷ���FALSE��                 */                                       
/*���ܣ���ͼ����к���΢��                                     */
/***************************************************************/
void WeiFenDib::HengXiang()
{
    LPBYTE p_data;     //ԭͼ������ָ��
    int wide,height;    //ԭͼ������	
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{	    
        LPBYTE  temp=new BYTE [wide*height];    //����ͼ��һ������
		memset(temp,255,wide*height);
		for(int j=1;j<height-1;j++)
		    for(int i=1;i<wide-1;i++)
				//��ǰ���صĻҶ�ֵ��������Ϸ����ػҶ�ֵ֮��ľ���ֵ
				temp[wide*j+i]=abs(p_data[wide*j+i]-p_data[wide*(j-1)+i]);
        //���������е�ͼ���ƻ�ԭͼ������
		memcpy(p_data, temp,wide*height);
		//ɾ��������
		delete  temp;
	}
	else 	//24λ��ɫ
	{    
		int DibWidth;    //ԭͼ������	
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		for(int j=1;j<height-1;j++)	// ÿ��
		{
			for(int i=3;i<DibWidth-3;i++)	// ÿ��
			{
				int pby_pt=0;
				pby_pt=*(p_data+(height-j-1)*DibWidth+i)-*(p_data+(height-j)*DibWidth+i);
                *(p_temp+(height-j-1)*DibWidth+i)=abs(pby_pt);
			}
		}
		memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
        delete []p_temp;  //ɾ����ʱ�����ڴ�
	}    
}

/***************************************************************/           
/*�������ƣ�ShuangXiang()                                      */
/*�������ͣ�void                                               */
/*����ֵ������ɹ�����TRUE;����ʧ�ܷ���FALSE��                 */                                       
/*���ܣ���ͼ�����˫��һ��΢��                                 */
/***************************************************************/
void WeiFenDib::ShuangXiang()
{
    LPBYTE  p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������ 	
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{	    
        LPBYTE temp=new BYTE [wide*height];    //����ͼ��һ������
		memset(temp,255,wide*height);
		for(int j=1;j<height-1;j++)
			for(int i=1;i<wide-1;i++)
				//����˫��һ��΢�ֹ�ʽ���㵱ǰ���صĻҶ�ֵ
				temp[wide*j+i]=(int)sqrt((p_data[wide*j+i]-p_data[wide*j+(i-1)])*(p_data[wide*j+i]-p_data[wide*j+(i-1)])+(p_data[wide*j+i]-p_data[wide*(j-1)+i])*(p_data[wide*j+i]-p_data[wide*(j-1)+i]));
        //���������е�ͼ���ƻ�ԭͼ������
		memcpy(p_data, temp,wide*height);
		//ɾ��������
		delete  temp;
	}
	else	//24λ��ɫ
	{    
		int DibWidth;    //ԭͼ������	
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		for(int j=1;j<height-1;j++)	// ÿ��
		{
			for(int i=3;i<DibWidth-3;i++)	// ÿ��
			{
				int pby_pt1=0,pby_pt2=0;
				pby_pt1=*(p_data+(height-j-1)*DibWidth+i)-*(p_data+(height-j-1)*DibWidth+i-3);
                pby_pt2=*(p_data+(height-j-1)*DibWidth+i)-*(p_data+(height-j)*DibWidth+i);
                *(p_temp+(height-j-1)*DibWidth+i)=(int)sqrt(pby_pt1*pby_pt1+pby_pt2*pby_pt2);
			}
		}
		memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
        delete []p_temp;  //ɾ����ʱ�����ڴ�
	}	
}

/***************************************************************/           
/*�������ƣ�ErCi1()                                            */
/*�������ͣ�void                                               */
/*����ֵ������ɹ�����TRUE;����ʧ�ܷ���FALSE��                 */                                       
/*���ܣ���ͼ����ж���΢��                                     */
/*�������£�       +1  -2  +1                                  */
/*                 -2  +4  -2                                  */
/*                 +1  -2  +1                                  */
/*                                                             */
/***************************************************************/
void WeiFenDib::ErCi1()
{
    LPBYTE p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������	
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{	    
        LPBYTE   temp=new BYTE [wide*height];    //����ͼ��һ������
		memset(temp,255,wide*height);   //��ʼ��Ϊ255
		for(int j=1;j<height-1;j++)
		    for(int i=1;i<wide-1;i++)
				//�������Ӽ���ÿ�����صĻҶ�ֵ
				temp[wide*j+i]=abs(p_data[wide*(j-1)+(i-1)]-2*p_data[wide*(j-1)+i]+p_data[wide*(j-1)+(i+1)]-2*p_data[wide*j+(i-1)]+4*p_data[wide*j+i]-2*p_data[wide*j+(i+1)]+p_data[wide*(j+1)+(i-1)]-2*p_data[wide*(j+1)+i]+p_data[wide*(j+1)+(i+1)]);
        //���������е�ͼ���ƻ�ԭͼ������
		memcpy(p_data, temp,wide*height);
        //ɾ��������
		delete  temp;
	}
	else 	//24λ��ɫ
	{	
		int DibWidth;    //ԭͼ������	
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		for(int j=1;j<height-2;j++)	// ÿ��
		{
			for(int i=3;i<DibWidth-8;i++)	// ÿ��
			{
				int pby_pt=0;
				pby_pt=*(p_data+(height-j)*DibWidth+i-3)-2*(*(p_data+(height-j)*DibWidth+i))
					+*(p_data+(height-j)*DibWidth+i+3)-2*(*(p_data+(height-j-1)*DibWidth+i-3))
					+4*(*(p_data+(height-j-1)*DibWidth+i))-2*(*(p_data+(height-j-1)*DibWidth+i+3))
					+*(p_data+(height-j-2)*DibWidth+i-3)-2*(*(p_data+(height-j-2)*DibWidth+i))
					+*(p_data+(height-j-2)*DibWidth+i+3);
                *(p_temp+(height-j-1)*DibWidth+i)=abs(pby_pt);
			}
	    }
		memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
		delete []p_temp;  //ɾ����ʱ�����ڴ�
	}	
}

/***************************************************************/           
/*�������ƣ�ErCi2()                                            */
/*�������ͣ�void                                               */
/*����ֵ������ɹ�����TRUE;����ʧ�ܷ���FALSE��                 */                                       
/*���ܣ���ͼ����ж���΢��                                     */
/*�������£�    +1  +1  +1                                     */
/*              +1  -8  +1                                     */
/*              +1  +1  +1                                     */
/*                                                             */
/***************************************************************/
void WeiFenDib::ErCi2()
{
    LPBYTE  p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{	    
        LPBYTE  temp=new BYTE [wide*height];    //����ͼ��һ������
		memset(temp,255,wide*height);
		for(int j=1;j<height-1;j++)
			for(int i=1;i<wide-1;i++)
				temp[wide*j+i]=abs(p_data[wide*(j-1)+(i-1)]+p_data[wide*(j-1)+i]+p_data[wide*(j-1)+(i+1)]+p_data[wide*j+(i-1)]-8*p_data[wide*j+i]+p_data[wide*j+(i+1)]+p_data[wide*(j+1)+(i-1)]+p_data[wide*(j+1)+i]+p_data[wide*(j+1)+(i+1)]);
        memcpy(p_data, temp,wide*height);
		delete  temp;
	}
	else	//24λ��ɫ
	{    
		int DibWidth;    //ԭͼ������	
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		for(int j=1;j<height-2;j++)	// ÿ��
		{
			for(int i=3;i<DibWidth-8;i++)	// ÿ��
			{
				int pby_pt=0;
				pby_pt=*(p_data+(height-j)*DibWidth+i-3)+*(p_data+(height-j)*DibWidth+i)
					+*(p_data+(height-j)*DibWidth+i+3)+*(p_data+(height-j-1)*DibWidth+i-3)
					-8*(*(p_data+(height-j-1)*DibWidth+i))+*(p_data+(height-j-1)*DibWidth+i+3)
					+*(p_data+(height-j-2)*DibWidth+i-3)+*(p_data+(height-j-2)*DibWidth+i)
					+*(p_data+(height-j-2)*DibWidth+i+3);
                *(p_temp+(height-j-1)*DibWidth+i)=abs(pby_pt);
			}
		}
		memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
        delete []p_temp;  //ɾ����ʱ�����ڴ�
	}	
}

/***************************************************************/           
/*�������ƣ�ErCi3()                                            */
/*�������ͣ�void                                               */
/*����ֵ������ɹ�����TRUE;����ʧ�ܷ���FALSE��                 */                                       
/*���ܣ���ͼ����ж���΢��                                     */
/*�������£�    +1+1+1                                         */
/*              +1+1+1                                         */
/*              +1+1+1                                         */
/*        +1+1+1-4-4-4 +1+1+1                                  */
/*        +1+1+1-4-4-4 +1+1+1                                  */
/*        +1+1+1-4-4-4 +1+1+1                                  */
/*              +1+1+1                                         */
/*              +1+1+1                                         */
/*              +1+1+1                                         */
/*                                                             */
/***************************************************************/
void WeiFenDib::ErCi3()
{
    LPBYTE  p_data;     //ԭͼ������ָ��
	int wide,height;//ԭͼ������
    p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{		
	    int x,y;   //ѭ������
        int cent3x3,up3x3,down3x3,right3x3,left3x3;   //���ĵ����������ĸ�������ĺ�	
        BYTE**  temp1=new BYTE*  [height+8];
	    BYTE**	temp2=new BYTE*  [height];
	    for (y=0;y<height;y++)
		    temp2[y]=new BYTE [wide];
	    for (y=0;y<height+8;y++)
		     temp1[y]=new BYTE [wide+8];
	    for (y=0;y<height;y++)
		    for(x=0;x<wide;x++)
			    temp2[y][x]=0;
	   	for (y=0;y<height+8;y++)
	    	for(x=0;x<wide+8;x++)
		    	temp1[y][x]=0;
		for (y=0;y<height;y++)
		    for(x=0;x<wide;x++)
			    temp1[y+4][x+4]=p_data[wide*y+x];
		for (y=4;y<height+4;y++)
			for(x=4;x<wide+4;x++)
			{
				cent3x3=-4* temp1[y-1][x-1]-4* temp1[y-1][x]-4* temp1[y-1][x+1]-4* temp1[y][x-1]-4* temp1[y][x]-4* temp1[y][x+1]-4* temp1[y+1][x-1]-4* temp1[y+1][x]-4* temp1[y+1][x+1];
				up3x3= temp1[y-4][x-1]+ temp1[y-4][x]+ temp1[y-4][x+1]+ temp1[y-3][x-1]+ temp1[y-3][x]+ temp1[y-3][x+1]+ temp1[y-2][x-1]+ temp1[y-2][x]+ temp1[y-2][x+1];
				down3x3= temp1[y+2][x-1]+ temp1[y+2][x]+ temp1[y+2][x+1]+ temp1[y+3][x-1]+ temp1[y+3][x]+ temp1[y+3][x+1]+ temp1[y+4][x-1]+ temp1[y+4][x]+ temp1[y+4][x+1];
				right3x3=temp1[y-1][x+2]+ temp1[y-1][x+3]+ temp1[y-1][x+4]+ temp1[y][x+2]+ temp1[y][x+3]+ temp1[y][x+4]+ temp1[y+1][x+2]+ temp1[y+1][x+3]+ temp1[y+1][x+4];
				left3x3=temp1[y-1][x-4]+ temp1[y-1][x-3]+ temp1[y-1][x-2]+ temp1[y][x-4]+ temp1[y][x-3]+ temp1[y][x-2]+ temp1[y+1][x-4]+ temp1[y+1][x-3]+ temp1[y+1][x-2];
				temp2[y-4][x-4]=abs(cent3x3+up3x3+down3x3+right3x3+left3x3);
			}
		for (y=0;y<height;y++)
			 for(x=0;x<wide;x++)
			    p_data[wide*y+x]=temp2[y][x];
	}
	else 	//24λ��ɫ
	{	
		int DibWidth;    //ԭͼ������	
		DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
		BYTE *p_temp=new BYTE[height*DibWidth];
		for(int j=1;j<height-2;j++)	// ÿ��
		{
			for(int i=3;i<DibWidth-8;i++)	// ÿ��
			{
				int pby_pt=0;
				pby_pt=*(p_data+(height-j)*DibWidth+i-3)-2*(*(p_data+(height-j)*DibWidth+i))
					+*(p_data+(height-j)*DibWidth+i+3)-2*(*(p_data+(height-j-1)*DibWidth+i-3))
					+4*(*(p_data+(height-j-1)*DibWidth+i))-2*(*(p_data+(height-j-1)*DibWidth+i+3))
					+*(p_data+(height-j-2)*DibWidth+i-3)-2*(*(p_data+(height-j-2)*DibWidth+i))
					+*(p_data+(height-j-2)*DibWidth+i+3);
                *(p_temp+(height-j-1)*DibWidth+i)=abs(pby_pt);
			}
		}
		memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
		delete []p_temp;  //ɾ����ʱ�����ڴ�
		BYTE *p_temp1=new BYTE[height*DibWidth];
		for(int a=1;a<height-2;a++)	// ÿ��
		{
			for(int b=3;b<DibWidth-8;b++)	// ÿ��
			{
				int pby_pt=0;
				pby_pt=*(p_data+(height-a)*DibWidth+b-3)+*(p_data+(height-a)*DibWidth+b)
					+*(p_data+(height-a)*DibWidth+b+3)+*(p_data+(height-a-1)*DibWidth+b-3)
					-8*(*(p_data+(height-a-1)*DibWidth+b))+*(p_data+(height-a-1)*DibWidth+b+3)
					+*(p_data+(height-a-2)*DibWidth+b-3)+*(p_data+(height-a-2)*DibWidth+b)
					+*(p_data+(height-a-2)*DibWidth+b+3);
                *(p_temp1+(height-a-1)*DibWidth+b)=abs(pby_pt);
			}
		}
		memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
		delete []p_temp1;  //ɾ����ʱ�����ڴ�
	}
}