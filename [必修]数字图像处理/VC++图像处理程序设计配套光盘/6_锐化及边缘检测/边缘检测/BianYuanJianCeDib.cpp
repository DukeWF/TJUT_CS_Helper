#include "stdafx.h"
#include "windowsx.h"
#include "math.h"
#include "BianYuanJianCeDib.h"
#include "MainFrm.h"
#include "DynSplitView2.h"
 
BianYuanJianCeDib::BianYuanJianCeDib()
{
  
}
BianYuanJianCeDib::~BianYuanJianCeDib()
{
}

/***************************************************************/
/*�������ƣ�Templat(BYTE *m_pdata, int wide, int height, int tempH, int tempW, int tempMX, int tempMY, float *fpArray, float fCoef)                                         */
/*�������ͣ�void                                               */
/*������BYTE* m_pdata:ָ��ԭDIBͼ��ָ��                        */
/*      int wide:ԭͼ����                                    */
/*      int height:ԭͼ��߶�                                  */
/*      int tempH:ģ��߶�                                     */
/*      int tempW:ģ����                                     */
/*      int tempMX:ģ�������Ԫ��X����(<tempW-1)               */
/*      int tempMY:ģ�������Ԫ��Y����(<tempH-1)               */
/*      float *fpArray:ָ��ģ�������ָ��                      */
/*      float fCoef��ģ��ϵ��                                  */
/*����ֵ������ɹ�����TRUE;����ʧ�ܷ���FALSE��                 */
/*���ܣ���ָ��ģ��ԻҶ�ͼ����в�����                         */
/***************************************************************/
void BianYuanJianCeDib::Templat(BYTE *m_pdata, int wide, int height, int tempH, int tempW, int tempMX, int tempMY, float *fpArray, float fCoef)
{   
	int i,j,k,l;  //ѭ������
    BYTE*  temp=new BYTE[wide*height];    //��ͼ�񻺳���
	//��ʼ����ͼ��Ϊԭʼͼ��
    memcpy( temp,m_pdata,wide*height);
    float fResult;    //����ֵ������
	for(j=tempMY;j<height-tempH+tempMY+1;j++)
		for(i=tempMX;i<wide-tempW+tempMX+1;i++)
		{
			//��������ֵ
			fResult=0;
			for(k=0;k<tempH;k++)
				for(l=0;l<tempW;l++)
					fResult=fResult+m_pdata[(j-tempMY+k)*wide+(i-tempMX+l)]*fpArray[k*tempW+l];
			//����ϵ��
			fResult*=fCoef;
			//ȡ����ֵ
			fResult=(float)fabs(fResult);
			//�ж��Ƿ񳬹�255
			if(fResult>255)
				//������255��ֱ�Ӹ�ֵΪ255
                temp[j*wide+i]=255;
			else
				//δ����255����ֵΪ������
				temp[j*wide+i]=(int)(fResult+0.5);
		}
    memcpy(m_pdata, temp,wide*height);   //���ƴ�����ͼ��
	delete  temp;
}

/***************************************************************/
/*�������ƣ�Templat24bit(BYTE *m_pdata, int DibWidth, int height, int tempH, int tempW, int tempMX, int tempMY, float *fpArray, float fCoef)                                         */
/*�������ͣ�void                                               */
/*������BYTE* m_pdata:ָ��ԭDIBͼ��ָ��                        */
/*      int DibWidth:ԭͼ����                                */
/*      int height:ԭͼ��߶�                                  */
/*      int tempH:ģ��߶�                                     */
/*      int tempW:ģ����                                     */
/*      int tempMX:ģ�������Ԫ��X����(<tempW-1)               */
/*      int tempMY:ģ�������Ԫ��Y����(<tempH-1)               */
/*      float *fpArray:ָ��ģ�������ָ��                      */
/*      float fCoef��ģ��ϵ��                                  */
/*����ֵ������ɹ�����TRUE;����ʧ�ܷ���FALSE��                 */
/*���ܣ���ָ��ģ���24λ��ɫͼ����в�����                     */
/***************************************************************/
void BianYuanJianCeDib::Templat24bit(BYTE *m_pdata, int DibWidth, int height, int tempH, int tempW, int tempMX, int tempMY, float *fpArray, float fCoef)
{
    int i,j,k,l;  //ѭ������
    BYTE*  p_temp=new BYTE[DibWidth*height];    //��ͼ�񻺳���
	//��ʼ����ͼ��Ϊԭʼͼ��
    memcpy( p_temp,m_pdata,DibWidth*height);
    float fResult;    //����ֵ������
	for(j=tempMY;j<height-tempH+tempMY+1;j++)
		for(i=3*tempMX;i<DibWidth-3*tempW+3*tempMX+1;i++)
		{
			//��������ֵ
			fResult=0;
			for(k=0;k<tempH;k++)
				for(l=0;l<tempW;l++)
					fResult=fResult+m_pdata[(j-tempMY+k)*DibWidth+(i-3*tempMX+l*3)]*fpArray[k*tempW+l];
			//����ϵ��
			fResult*=fCoef;
			//ȡ����ֵ
			fResult=(float)fabs(fResult);
			//�ж��Ƿ񳬹�255
			if(fResult>255)
				//������255��ֱ�Ӹ�ֵΪ255
                p_temp[j*DibWidth+i]=255;
			else
				//δ����255����ֵΪ������
				p_temp[j*DibWidth+i]=(int)(fResult+0.5);
		}
    memcpy(m_pdata, p_temp,DibWidth*height);   //���ƴ�����ͼ��
	delete  []p_temp;
}

///***************************************************************/           
/*�������ƣ�Robert()                                      
/*�������ͣ�void                                     
/*���ܣ����޲������Ӷ�ͼ����б�Ե��⡣            
/***************************************************************/ 
void BianYuanJianCeDib::Robert()
{    
	LPBYTE  p_data;     //ԭͼ������ָ��
	int wide,height,DibWidth;    //ԭͼ������
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
	int i,j;  //ѭ������
    if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{
	    int pixel[4];   //Robert����
		LPBYTE   temp=new BYTE[wide*height];    //��ͼ�񻺳���
 	    memset(temp,255,wide*height);  //�趨��ͼ���ֵΪ255
	    //����ʹ��2*2��ģ�壬Ϊ��ֹԽ�磬���Բ��������±ߺ����ұߵ���������
	    for(j=0;j<height-1;j++)
		    for(i=0;i<wide-1;i++)
			{
		        //����Robert����
				pixel[0]=p_data[j*wide+i];
                pixel[1]=p_data[j*wide+i+1];
				pixel[2]=p_data[(j+1)*wide+i];
				pixel[3]=p_data[(j+1)*wide+i+1];
				//����ǰ����
				 temp[j*wide+i]=(int)sqrt((pixel[0]-pixel[3])*(pixel[0]-pixel[3])+(pixel[1]-pixel[2])*(pixel[1]-pixel[2]));
			}
		//���������е����ݸ��Ƶ�ԭͼ������
		memcpy(p_data, temp,wide*height);
		//ɾ��������
		delete  temp;
	}
  else		//24λ��ɫ
  {
	 int pixel[4];   //Robert����
     BYTE *p_temp=new BYTE[height*DibWidth];

	 for(j=0;j<height-1;j++)
		for(i=0;i<DibWidth-3;i++)
		{
			//����Robert����
			pixel[0]=p_data[j*DibWidth+i];
            pixel[1]=p_data[j*DibWidth+i+3];
			pixel[2]=p_data[(j+1)*DibWidth+i];
			pixel[3]=p_data[(j+1)*DibWidth+i+3];
			//����ǰ����
			p_temp[j*DibWidth+i]=(int)sqrt((pixel[0]-pixel[3])*(pixel[0]-pixel[3])+(pixel[1]-pixel[2])*(pixel[1]-pixel[2]));
		}
     memcpy(p_data,p_temp,height*DibWidth);  // ���ƴ�����ͼ��
     delete []p_temp;  //ɾ����ʱ�����ڴ�  
  }
}
 
///***************************************************************/           
/*�������ƣ�PreWitt()                                      
/*�������ͣ�void                                     
/*���ܣ�������ά�����Ӷ�ͼ����б�Ե��⡣            
/***************************************************************/
void BianYuanJianCeDib::PreWitt()
{
	int tempH;  //ģ��߶�
	int tempW;  //ģ����
	float tempC;  //ģ��ϵ��
	int tempMY;   //ģ������Ԫ��Y����
	int tempMX;   //ģ������Ԫ��X����
	float Template[9];   //ģ������	
	LPBYTE  p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{	
		LPBYTE   temp1=new BYTE[wide*height];    //��ͼ�񻺳���
        LPBYTE   temp2=new BYTE[wide*height];    //��ͼ�񻺳���
        //����ԭͼ�񵽻���ͼ��
		memcpy( temp1,p_data,wide*height);
        memcpy( temp2,p_data,wide*height);
	 	//����Prewittģ��1����
		tempW=3;
		tempH=3;
		tempC=1.0;
		tempMY=1;
		tempMX=1;
		Template[0]=-1.0;
        Template[1]=-1.0;
		Template[2]=-1.0;
		Template[3]=0.0;
		Template[4]=0.0;
		Template[5]=0.0;
		Template[6]=1.0;
		Template[7]=1.0;
		Template[8]=1.0;
		//����Templat()����
		Templat( temp1,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����Prewittģ��2����
        Template[0]=1.0;
        Template[1]=0.0;
		Template[2]=-1.0;
		Template[3]=1.0;
		Template[4]=0.0;
		Template[5]=-1.0;
		Template[6]=1.0;
		Template[7]=0.0;
		Template[8]=-1.0;
		//����Templat()����
		Templat( temp2,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC);
		//����������ͼ������ֵ
		for(int j=0;j<height;j++)
			for(int i=0;i<wide;i++)
				if( temp2[j*wide+i]> temp1[j*wide+i])
					 temp1[j*wide+i]= temp2[j*wide+i];
        memcpy(p_data, temp1,wide*height);   //���ƴ�����ͼ��
		delete  temp1;
		delete  temp2;
	}
	else	//24λ��ɫ
	{	    
	    int DibWidth;    //ԭͼ������    	
	    DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
        BYTE *p_temp1=new BYTE[height*DibWidth];
		BYTE *p_temp2=new BYTE[height*DibWidth];
		//�������е�ͼ���Ƶ�ԭͼ������
		memcpy(p_temp1,p_data,DibWidth*height);
		memcpy(p_temp2,p_data,DibWidth*height);
		//����Prewittģ��1����
		tempW=3;
		tempH=3;
		tempC=1.0;
		tempMY=1;
		tempMX=1;
		Template[0]=-1.0;
        Template[1]=-1.0;
		Template[2]=-1.0;
		Template[3]=0.0;
		Template[4]=0.0;
		Template[5]=0.0;
		Template[6]=1.0;
		Template[7]=1.0;
		Template[8]=1.0;
		Templat24bit( p_temp1,DibWidth,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����Prewittģ��2����
        Template[0]=1.0;
        Template[1]=0.0;
		Template[2]=-1.0;
		Template[3]=1.0;
		Template[4]=0.0;
		Template[5]=-1.0;
		Template[6]=1.0;
		Template[7]=0.0;
		Template[8]=-1.0;
		Templat24bit( p_temp2,DibWidth,height,tempH,tempW,tempMX,tempMY,Template,tempC);
		//����������ͼ������ֵ
		for(int j=0;j<height;j++)
			for(int i=0;i<DibWidth;i++)
				if( p_temp2[j*DibWidth+i]> p_temp1[j*DibWidth+i])
					 p_temp1[j*DibWidth+i]= p_temp2[j*DibWidth+i];
	   memcpy(p_data,p_temp1,height*DibWidth);  // ���ƴ�����ͼ��
	   delete []p_temp1;  //ɾ����ʱ�����ڴ�
	   delete []p_temp2;  //ɾ����ʱ�����ڴ�
	}	
}

///***************************************************************/           
/*�������ƣ�Sobel()                                      
/*�������ͣ�void                                     
/*���ܣ������������Ӷ�ͼ����б�Ե��⡣            
/***************************************************************/
void BianYuanJianCeDib::Sobel()
{
	int tempH;  //ģ��߶�
	int tempW;  //ģ����
	float tempC;  //ģ��ϵ��
	int tempMY;   //ģ������Ԫ��Y����
	int tempMX;   //ģ������Ԫ��X����
	float Template[9];   //ģ������
	LPBYTE  p_data;     //ԭͼ������ָ��
    int wide,height;    //ԭͼ������
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{        
		LPBYTE   temp1=new BYTE[wide*height];    //��ͼ�񻺳���
        LPBYTE   temp2=new BYTE[wide*height];    //��ͼ�񻺳���
        //����ԭͼ�񵽻���ͼ��
		memcpy( temp1,p_data,wide*height);
        memcpy( temp2,p_data,wide*height);
		//����Sobelģ�����
		tempW=3;
		tempH=3;
		tempC=1.0;
		tempMY=1;
		tempMX=1;
		Template[0]=-1.0;
        Template[1]=-2.0;
		Template[2]=-1.0;
		Template[3]=0.0;
		Template[4]=0.0;
		Template[5]=0.0;
		Template[6]=1.0;
		Template[7]=2.0;
		Template[8]=1.0;
		//����Templat()����
		Templat( temp1,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC); 
        //����Sobelģ�����
        Template[0]=-1.0;
        Template[1]=0.0;
		Template[2]=1.0;
		Template[3]=-2.0;
		Template[4]=0.0;
		Template[5]=2.0;
		Template[6]=-1.0;
		Template[7]=0.0;
		Template[8]=1.0;
		//����Templat()����
		Templat( temp2,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC); 
		//����������ͼ������ֵ
		for(int j=0;j<height;j++)
			for(int i=0;i<wide;i++)
				if( temp2[j*wide+i]> temp1[j*wide+i])
					 temp1[j*wide+i]= temp2[j*wide+i];
        //�������е�ͼ���Ƶ�ԭͼ������
		memcpy(p_data, temp1,wide*height);
		//ɾ��������
		delete  temp1;
		delete  temp2;
	}
	else	//24λ��ɫ
	{	    
	    int DibWidth;    //ԭͼ������    	
	    DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
        BYTE *p_temp1=new BYTE[height*DibWidth];
		BYTE *p_temp2=new BYTE[height*DibWidth];
		//�������е�ͼ���Ƶ�ԭͼ������
		memcpy(p_temp1,p_data,DibWidth*height);
		memcpy(p_temp2,p_data,DibWidth*height);
		//����Sobelģ�����
		tempW=3;
		tempH=3;
		tempC=1.0;
		tempMY=1;
		tempMX=1;
		Template[0]=-1.0;
        Template[1]=-2.0;
		Template[2]=-1.0;
		Template[3]=0.0;
		Template[4]=0.0;
		Template[5]=0.0;
		Template[6]=1.0;
		Template[7]=2.0;
		Template[8]=1.0;
		Templat24bit( p_temp1,DibWidth,height,tempH,tempW,tempMX,tempMY,Template,tempC); 
        //����Sobelģ�����
        Template[0]=-1.0;
        Template[1]=0.0;
		Template[2]=1.0;
		Template[3]=-2.0;
		Template[4]=0.0;
		Template[5]=2.0;
		Template[6]=-1.0;
		Template[7]=0.0;
		Template[8]=1.0;
		Templat24bit( p_temp2,DibWidth,height,tempH,tempW,tempMX,tempMY,Template,tempC); 
		//����������ͼ������ֵ
		for(int j=0;j<height;j++)
			for(int i=0;i<wide;i++)
				if( p_temp2[j*DibWidth+i]> p_temp1[j*DibWidth+i])
					 p_temp1[j*DibWidth+i]= p_temp2[j*DibWidth+i];
	   memcpy(p_data,p_temp1,height*DibWidth);  // ���ƴ�����ͼ��
	   delete []p_temp1;  //ɾ����ʱ�����ڴ�
	   delete []p_temp2;  //ɾ����ʱ�����ڴ�
	}
}

///***************************************************************/           
/*�������ƣ�Laplacian()                                      
/*�������ͣ�void                                     
/*���ܣ���������˹���Ӷ�ͼ���Ե��⡣            
/***************************************************************/ 
void BianYuanJianCeDib::Laplacian()
{
	int tempH;  //ģ��߶�
	int tempW;  //ģ����
	float tempC;  //ģ��ϵ��
	int tempMY;   //ģ������Ԫ��Y����
	int tempMX;   //ģ������Ԫ��X����
	float Template[9];   //ģ������
	LPBYTE p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{    
		LPBYTE   temp1=new BYTE[wide*height];    //��ͼ�񻺳���
        //����ԭͼ�񵽻���ͼ��
		memcpy( temp1,p_data,wide*height);
		//����Laplacianģ�� ����
		tempW=3;
		tempH=3;
		tempC=1.0;
		tempMY=1;
		tempMX=1;
		Template[0]=-1.0;
        Template[1]=-1.0;
		Template[2]=-1.0;
		Template[3]=-1.0;
		Template[4]=8.0;
		Template[5]=-1.0;
		Template[6]=-1.0;
		Template[7]=-1.0;
		Template[8]=-1.0;
		//����Templat()����
		Templat( temp1,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        memcpy(p_data, temp1,wide*height);   //���ƴ�����ͼ��
		delete  temp1;
	}
	else	//24λ��ɫ
	{    
	    int DibWidth;    //ԭͼ������    	
	    DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
        BYTE *p_temp1=new BYTE[height*DibWidth];
		//�������е�ͼ���Ƶ�ԭͼ������
		memcpy(p_temp1,p_data,DibWidth*height);
		//����Laplacianģ�� ����
		tempW=3;
		tempH=3;
		tempC=1.0;
		tempMY=1;
		tempMX=1;
		Template[0]=-1.0;
        Template[1]=-1.0;
		Template[2]=-1.0;
		Template[3]=-1.0;
		Template[4]=8.0;
		Template[5]=-1.0;
		Template[6]=-1.0;
		Template[7]=-1.0;
		Template[8]=-1.0;
		Templat24bit( p_temp1,DibWidth,height,tempH,tempW,tempMX,tempMY,Template,tempC);
		memcpy(p_data,p_temp1,height*DibWidth);  // ���ƴ�����ͼ��
	    delete []p_temp1;  //ɾ����ʱ�����ڴ�
	}
}

///***************************************************************/           
/*�������ƣ�Guasslaplacian()                                      
/*�������ͣ�void                                    
/*���ܣ��ø�˹������˹���Ӷ�ͼ���Ե��⡣            
/***************************************************************/ 
void BianYuanJianCeDib::Guasslaplacian()
{
	int tempH;  //ģ��߶�
	int tempW;  //ģ����
	float tempC;  //ģ��ϵ��
	int tempMY;   //ģ������Ԫ��Y����
	int tempMX;   //ģ������Ԫ��X����
	float Template[25];   //ģ������
	LPBYTE  p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{        
		LPBYTE   temp1=new BYTE[wide*height];    //��ͼ�񻺳���
        LPBYTE   temp2=new BYTE[wide*height];    //��ͼ�񻺳���
        //����ԭͼ�񵽻���ͼ��
		memcpy( temp1,p_data,wide*height);
        memcpy( temp2,p_data,wide*height);
		//����Guasslaplacianģ�����
		tempW=5;
		tempH=5;
		tempC=0.25;
		tempMY=4;
		tempMX=4;
		Template[0]=-2.0;
        Template[1]=-4.0;
		Template[2]=-4.0;
		Template[3]=-4.0;
		Template[4]=-2.0;
		Template[5]=-4.0;
		Template[6]=0.0;
		Template[7]=8.0;
		Template[8]=0.0;
		Template[9]=-4.0;
		Template[10]=-4.0;
		Template[11]=8.0;
		Template[12]=24.0;
		Template[13]=8.0;
		Template[14]=-4.0;
		Template[15]=-4.0;
		Template[16]=0.0;
		Template[17]=8.0;
		Template[18]=0.0;
		Template[19]=-4.0;
		Template[20]=-2.0;
		Template[21]=-4.0;
		Template[22]=-4.0;
		Template[23]=-4.0;
		Template[24]=-2.0;
		//����Templat()����
		Templat( temp1,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        memcpy(p_data, temp1,wide*height);   //���ƴ�����ͼ��
		delete  temp1;         //�ͷ��ڴ�
		delete  temp2;
	}
	else	//24λ��ɫ
	{
	    int DibWidth;
	    DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
        BYTE *p_temp1=new BYTE[height*DibWidth];
		//�������е�ͼ���Ƶ�ԭͼ������
		memcpy(p_temp1,p_data,DibWidth*height);
		//����Guasslaplacianģ�����
		tempW=5;
		tempH=5;
		tempC=0.25;
		tempMY=4;
		tempMX=4;
		Template[0]=-2.0;
        Template[1]=-4.0;
		Template[2]=-4.0;
		Template[3]=-4.0;
		Template[4]=-2.0;
		Template[5]=-4.0;
		Template[6]=0.0;
		Template[7]=8.0;
		Template[8]=0.0;
		Template[9]=-4.0;
		Template[10]=-4.0;
		Template[11]=8.0;
		Template[12]=24.0;
		Template[13]=8.0;
		Template[14]=-4.0;
		Template[15]=-4.0;
		Template[16]=0.0;
		Template[17]=8.0;
		Template[18]=0.0;
		Template[19]=-4.0;
		Template[20]=-2.0;
		Template[21]=-4.0;
		Template[22]=-4.0;
		Template[23]=-4.0;
		Template[24]=-2.0;
		//����Templat24bit()����
		Templat24bit( p_temp1,DibWidth,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        memcpy(p_data,p_temp1,height*DibWidth);  // ���ƴ�����ͼ��
	    delete []p_temp1;  //ɾ����ʱ�����ڴ�
	}
}

///***************************************************************/           
/*�������ƣ�Krisch()                                      
/*�������ͣ�void                                     
/*���ܣ��ÿ���˹���Ӷ�ͼ���Ե��⡣            
/***************************************************************/ 
void BianYuanJianCeDib::Krisch()
{
	int tempH;  //ģ��߶�
	int tempW;  //ģ����
	float tempC;  //ģ��ϵ��
	int tempMY;   //ģ������Ԫ��Y����
	int tempMX;   //ģ������Ԫ��X����
	float Template[9];   //ģ������
	LPBYTE  p_data;     //ԭͼ������ָ��
	int wide,height;    //ԭͼ������ 	 
	p_data=this->GetData ();
    wide=this->GetWidth ();
    height=this->GetHeight ();
	if (m_pBitmapInfoHeader->biBitCount<9)		//�Ҷ�ͼ��
	{    
		LPBYTE   temp1=new BYTE[wide*height];    //��ͼ�񻺳���
        LPBYTE   temp2=new BYTE[wide*height];    //��ͼ�񻺳���
        //����ԭͼ�񵽻���ͼ��
		memcpy( temp1,p_data,wide*height);
        memcpy( temp2,p_data,wide*height);
		//����Kirschģ��1����
		tempW=3;
		tempH=3;
		tempC=0.5;
		tempMY=1;
		tempMX=1;
		Template[0]=5.0;
        Template[1]=5.0;
		Template[2]=5.0;
		Template[3]=-3.0;
		Template[4]=0.0;
		Template[5]=-3.0;
		Template[6]=-3.0;
		Template[7]=-3.0;
		Template[8]=-3.0;
        //����Templat()����
		Templat( temp1,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����Kirschģ��2����
        Template[0]=-3.0;
        Template[1]=5.0;
		Template[2]=5.0;
		Template[3]=-3.0;
		Template[4]=0.0;
		Template[5]=5.0;
		Template[6]=-3.0;
		Template[7]=-3.0;
		Template[8]=-3.0;
		//����Templat()����
		Templat( temp2,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����������ͼ������ֵ
		for(int j=0;j<height;j++)
			for(int i=0;i<wide;i++)
				if( temp2[j*wide+i]> temp1[j*wide+i])
					 temp1[j*wide+i]= temp2[j*wide+i];
		//����ԭͼ�񵽻���ͼ��2��
        memcpy( temp2,p_data,wide*height);
        //����Kirschģ��3����
        Template[0]=-3.0;
        Template[1]=-3.0;
		Template[2]=5.0;
		Template[3]=-3.0;
		Template[4]=0.0;
		Template[5]=5.0;
		Template[6]=-3.0;
		Template[7]=-3.0;
		Template[8]=5.0;
		//����Templat()����
	    Templat( temp2,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����������ͼ������ֵ
		for(j=0;j<height;j++)
			for(int i=0;i<wide;i++)
				if( temp2[j*wide+i]> temp1[j*wide+i])
					 temp1[j*wide+i]= temp2[j*wide+i];
        //����ԭͼ�񵽻���ͼ��2��
        memcpy( temp2,p_data,wide*height);
        //����Kirschģ��4����
        Template[0]=-3.0;
        Template[1]=-3.0;
		Template[2]=-3.0;
		Template[3]=-3.0;
		Template[4]=0.0;
		Template[5]=5.0;
		Template[6]=-3.0;
		Template[7]=5.0;
		Template[8]=5.0;
		//����Templat()����
		Templat( temp2,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����������ͼ������ֵ
		for(j=0;j<height;j++)
			for(int i=0;i<wide;i++)
				if( temp2[j*wide+i]> temp1[j*wide+i])
					 temp1[j*wide+i]= temp2[j*wide+i];
		//����ԭͼ�񵽻���ͼ��2��
        memcpy( temp2,p_data,wide*height);
		//����Kirschģ��5����
        Template[0]=-3.0;
        Template[1]=-3.0;
		Template[2]=-3.0;
		Template[3]=-3.0;
		Template[4]=0.0;
		Template[5]=-3.0;
		Template[6]=5.0;
		Template[7]=5.0;
		Template[8]=5.0;
		//����Templat()����
		Templat( temp2,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC);
		//����ԭͼ�񵽻���ͼ��2��
        memcpy( temp2,p_data,wide*height);
        //����������ͼ������ֵ
		for(j=0;j<height;j++)
			for(int i=0;i<wide;i++)
				if( temp2[j*wide+i]> temp1[j*wide+i])
					 temp1[j*wide+i]= temp2[j*wide+i];
		//����ԭͼ�񵽻���ͼ��2��
        memcpy( temp2,p_data,wide*height);
		//����Kirschģ��6����
        Template[0]=-3.0;
        Template[1]=-3.0;
		Template[2]=-3.0;
		Template[3]=5.0;
		Template[4]=0.0;
		Template[5]=-3.0;
		Template[6]=5.0;
		Template[7]=5.0;
		Template[8]=-3.0;
		//����Templat()����
		Templat( temp2,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����������ͼ������ֵ
		for(j=0;j<height;j++)
			for(int i=0;i<wide;i++)
				if( temp2[j*wide+i]> temp1[j*wide+i])
					 temp1[j*wide+i]= temp2[j*wide+i];
		//����ԭͼ�񵽻���ͼ��2��
        memcpy( temp2,p_data,wide*height);
		//����Kirschģ��7����
        Template[0]=5.0;
        Template[1]=-3.0;
		Template[2]=-3.0;
		Template[3]=5.0;
		Template[4]=0.0;
		Template[5]=-3.0;
		Template[6]=5.0;
		Template[7]=-3.0;
		Template[8]=-3.0;
		//����Templat()����
		Templat( temp2,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����������ͼ������ֵ
		for(j=0;j<height;j++)
			for(int i=0;i<wide;i++)
				if( temp2[j*wide+i]> temp1[j*wide+i])
					 temp1[j*wide+i]= temp2[j*wide+i];
		//����ԭͼ�񵽻���ͼ��2��
        memcpy( temp2,p_data,wide*height);
		//����Kirschģ��8����
        Template[0]=5.0;
        Template[1]=5.0;
		Template[2]=-3.0;
		Template[3]=5.0;
		Template[4]=0.0;
		Template[5]=-3.0;
		Template[6]=-3.0;
		Template[7]=-3.0;
		Template[8]=-3.0;
		//����Templat()����
	    Templat( temp2,wide,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����������ͼ������ֵ
		for(j=0;j<height;j++)
			for(int i=0;i<wide;i++)
				if( temp2[j*wide+i]> temp1[j*wide+i])
					 temp1[j*wide+i]= temp2[j*wide+i];
		memcpy(p_data, temp1,wide*height);   //���ƴ�����ͼ��
		delete  temp1;
		delete  temp2;
	}
	else	//24λ��ɫ
	{	    
	    int DibWidth;    //ԭͼ������    	
	    DibWidth=this->GetDibWidthBytes();   //ȡ��ԭͼ��ÿ���ֽ���
        BYTE *p_temp1=new BYTE[height*DibWidth];
		BYTE *p_temp2=new BYTE[height*DibWidth];
		 //�������е�ͼ���Ƶ�ԭͼ������
		memcpy(p_temp1,p_data,DibWidth*height);
		memcpy(p_temp2,p_data,DibWidth*height);
		//����Kirschģ��1����
		tempW=3;
		tempH=3;
		tempC=0.5;
		tempMY=1;
		tempMX=1;
		Template[0]=5.0;
        Template[1]=5.0;
		Template[2]=5.0;
		Template[3]=-3.0;
		Template[4]=0.0;
		Template[5]=-3.0;
		Template[6]=-3.0;
		Template[7]=-3.0;
		Template[8]=-3.0;
		Templat24bit(p_temp1,DibWidth,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����Kirschģ��2����
        Template[0]=-3.0;
        Template[1]=5.0;
		Template[2]=5.0;
		Template[3]=-3.0;
		Template[4]=0.0;
		Template[5]=5.0;
		Template[6]=-3.0;
		Template[7]=-3.0;
		Template[8]=-3.0;
		Templat24bit(p_temp2,DibWidth,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����������ͼ������ֵ
		for(int j=0;j<height;j++)
			for(int i=0;i<DibWidth;i++)
				if( p_temp2[j*DibWidth+i]> p_temp1[j*DibWidth+i])
					 p_temp1[j*DibWidth+i]= p_temp2[j*DibWidth+i];
		//����ԭͼ�񵽻���ͼ��2��
        memcpy(p_temp2,p_data,DibWidth*height);
        //����Kirschģ��3����
        Template[0]=-3.0;
        Template[1]=-3.0;
		Template[2]=5.0;
		Template[3]=-3.0;
		Template[4]=0.0;
		Template[5]=5.0;
		Template[6]=-3.0;
		Template[7]=-3.0;
		Template[8]=5.0;
		Templat24bit(p_temp2,DibWidth,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����������ͼ������ֵ
		for(j=0;j<height;j++)
			for(int i=0;i<DibWidth;i++)
				if( p_temp2[j*DibWidth+i]> p_temp1[j*DibWidth+i])
					 p_temp1[j*DibWidth+i]= p_temp2[j*DibWidth+i];
		//����ԭͼ�񵽻���ͼ��2��
        memcpy(p_temp2,p_data,DibWidth*height);
        //����Kirschģ��4����
        Template[0]=-3.0;
        Template[1]=-3.0;
		Template[2]=-3.0;
		Template[3]=-3.0;
		Template[4]=0.0;
		Template[5]=5.0;
		Template[6]=-3.0;
		Template[7]=5.0;
		Template[8]=5.0;
		Templat24bit(p_temp2,DibWidth,height,tempH,tempW,tempMX,tempMY,Template,tempC);
        //����������ͼ������ֵ
		for(j=0;j<height;j++)
			for(int i=0;i<DibWidth;i++)
				if( p_temp2[j*DibWidth+i]> p_temp1[j*DibWidth+i])
					 p_temp1[j*DibWidth+i]= p_temp2[j*DibWidth+i];
		//����ԭͼ�񵽻���ͼ��2��
        memcpy(p_temp2,p_data,DibWidth*height);
		//����Kirschģ��5����
        Template[0]=-3.0;
        Template[1]=-3.0;
		Template[2]=-3.0;
		Template[3]=-3.0;
		Template[4]=0.0;
		Template[5]=-3.0;
		Template[6]=5.0;
		Template[7]=5.0;
		Template[8]=5.0;
        //����������ͼ������ֵ
		for(j=0;j<height;j++)
			for(int i=0;i<DibWidth;i++)
				if( p_temp2[j*DibWidth+i]> p_temp1[j*DibWidth+i])
					 p_temp1[j*DibWidth+i]= p_temp2[j*DibWidth+i];
		//����ԭͼ�񵽻���ͼ��2��
        memcpy(p_temp2,p_data,DibWidth*height);
		//����Kirschģ��6����
        Template[0]=-3.0;
        Template[1]=-3.0;
		Template[2]=-3.0;
		Template[3]=5.0;
		Template[4]=0.0;
		Template[5]=-3.0;
		Template[6]=5.0;
		Template[7]=5.0;
		Template[8]=-3.0;
        //����������ͼ������ֵ
		for(j=0;j<height;j++)
			for(int i=0;i<DibWidth;i++)
				if( p_temp2[j*DibWidth+i]> p_temp1[j*DibWidth+i])
					 p_temp1[j*DibWidth+i]= p_temp2[j*DibWidth+i];
		//����ԭͼ�񵽻���ͼ��2��
        memcpy(p_temp2,p_data,DibWidth*height);
		//����Kirschģ��7����
        Template[0]=5.0;
        Template[1]=-3.0;
		Template[2]=-3.0;
		Template[3]=5.0;
		Template[4]=0.0;
		Template[5]=-3.0;
		Template[6]=5.0;
		Template[7]=-3.0;
		Template[8]=-3.0;
       //����������ͼ������ֵ
		for(j=0;j<height;j++)
			for(int i=0;i<DibWidth;i++)
				if( p_temp2[j*DibWidth+i]> p_temp1[j*DibWidth+i])
					 p_temp1[j*DibWidth+i]= p_temp2[j*DibWidth+i];
		//����ԭͼ�񵽻���ͼ��2��
        memcpy(p_temp2,p_data,DibWidth*height);
		//����Kirschģ��8����
        Template[0]=5.0;
        Template[1]=5.0;
		Template[2]=-3.0;
		Template[3]=5.0;
		Template[4]=0.0;
		Template[5]=-3.0;
		Template[6]=-3.0;
		Template[7]=-3.0;
		Template[8]=-3.0;
        //����������ͼ������ֵ
		for(j=0;j<height;j++)
			for(int i=0;i<DibWidth;i++)
				if( p_temp2[j*DibWidth+i]> p_temp1[j*DibWidth+i])
					 p_temp1[j*DibWidth+i]= p_temp2[j*DibWidth+i];
	    memcpy(p_data,p_temp1,height*DibWidth);  // ���ƴ�����ͼ��
	    delete []p_temp1;  //ɾ����ʱ�����ڴ�
	    delete []p_temp2;  //ɾ����ʱ�����ڴ�
	}
}