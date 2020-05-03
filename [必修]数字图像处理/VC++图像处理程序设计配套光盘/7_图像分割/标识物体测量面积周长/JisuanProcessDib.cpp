// JisuanProcessDib.cpp: implementation of the JisuanProcessDib class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DSplit.h"
#include "JisuanProcessDib.h"
#include "SquareDlg.h"
#include "LINEDLG.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JisuanProcessDib::JisuanProcessDib()
{
	x_sign=0;
	m_temp=0;
	x_temp=0;
	y_temp=0;
    p_temp=0;
	stop=0;
}

JisuanProcessDib::~JisuanProcessDib()
{
	
}

/***************************************************************/
/*�������ƣ�erzhihua(int yuzhi_gray)                           */
/*�������ͣ�void                                               */
/*������int yuzhi_gray���û���������ֵ                         */
/*���ܣ���ͼ��ʹ�ù̶���ֵ�����ж�ֵ����                       */
/***************************************************************/
void JisuanProcessDib::erzhihua(int yuzhi_gray)
{
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
    if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		for(int j=0;j<height;j++)	// ÿ��
			for(int i=0;i<wide;i++)	// ÿ��
			{
				int temp=0;
				temp= *(p_data+(height-j-1)*wide+i);
				if(temp<yuzhi_gray)
					*(p_data+(height-j-1)*wide+i)=0;
				else
					*(p_data+(height-j-1)*wide+i)=255;
			}
	}
	else	//24λ��ɫ
	{
		for(int j=0;j<height;j++)	// ÿ��
			for(int i=0;i<wide;i++)	// ÿ��
			{
				int temp=0;
				temp= *(p_data+(height-j-1)*wide*3+i*3);
				if(temp<yuzhi_gray)
				{
					*(p_data+(height-j-1)*wide*3+i*3)=0;
					*(p_data+(height-j-1)*wide*3+i*3+1)=0;
					*(p_data+(height-j-1)*wide*3+i*3+2)=0;
				}
				else
				{
					*(p_data+(height-j-1)*wide*3+i*3)=255;
					*(p_data+(height-j-1)*wide*3+i*3+1)=255;
					*(p_data+(height-j-1)*wide*3+i*3+2)=255;
				}
			}
	}
}

/***************************************************************/
/*�������ƣ�xiaochugulidianHEI()                               */
/*�������ͣ�void                                               */
/*���ܣ����������ڵ㡣                                         */
/***************************************************************/
void JisuanProcessDib::xiaochugulidianHEI()
{
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		for(int j=1;j<height-1;j++)	// ÿ��
			for(int i=1;i<wide-1;i++)	// ÿ��
			{
				int temp=0;	
				if(*(p_data+(height-j-1)*wide+i)==0)//����Ϊ�ڵ�
				{
					for(int m=0;m<3;m++)
						for(int n=0;n<3;n++)
						{
							temp+=*(p_data+(height-j-m)*wide+i+n-1);
						}
					if(temp>=255*6)///��Χ8���е��д��ڵ���6���׵�
						*(p_data+(height-j-1)*wide+i)=255;
				}
			}
	}
	else	//24λ��ɫ
	{
		for(int j=1;j<height-1;j++)	// ÿ��
			for(int i=1;i<wide-1;i++)	// ÿ��
			{
				int temp=0;	
				if(*(p_data+(height-j-1)*wide*3+i*3)==0)//����Ϊ�ڵ�
				{
					for(int m=0;m<3;m++)
						for(int n=0;n<3;n++)
						{
							temp+=*(p_data+(height-j-m)*wide*3+(i+n-1)*3);
						}
					if(temp>=255*6)///��Χ8���е��д��ڵ���6���׵�
					{
						*(p_data+(height-j-1)*wide*3+i*3)=255;
						*(p_data+(height-j-1)*wide*3+i*3+1)=255;
						*(p_data+(height-j-1)*wide*3+i*3+2)=255;
					}
				}
			}
	}
}

/***************************************************************/
/*�������ƣ�xiaochugulidianBAI()                               */
/*�������ͣ�void                                               */
/*���ܣ����������׵㡣                                         */
/***************************************************************/
void JisuanProcessDib::xiaochugulidianBAI()
{
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		for(int j=1;j<height-1;j++)	// ÿ��
			for(int i=1;i<wide-1;i++)	// ÿ��
			{
				int temp=0;			;
				if(*(p_data+(height-j-1)*wide+i)==255)//����Ϊ�׵�
				{
					for(int m=0;m<3;m++)
						for(int n=0;n<3;n++)
						{
							temp+=*(p_data+(height-j-m)*wide+i+n-1);
						}
					if(temp<=255*3)///��Χ8��������С�ڵ���2���׵�
						*(p_data+(height-j-1)*wide+i)=0;
				}
			}
	}
	else	//24λ��ɫ
	{
		for(int j=1;j<height-1;j++)	// ÿ��
			for(int i=1;i<wide-1;i++)	// ÿ��
			{
				int temp=0;			;
				if(*(p_data+(height-j-1)*wide*3+i*3)==255)//����Ϊ�׵�
				{
					for(int m=0;m<3;m++)
						for(int n=0;n<3;n++)
						{
							temp+=*(p_data+(height-j-m)*wide*3+(i+n-1)*3);
						}
					if(temp<=255*3)///��Χ8��������С�ڵ���2���׵�
					{
						*(p_data+(height-j-1)*wide*3+i*3)=0;
						*(p_data+(height-j-1)*wide*3+i*3+1)=0;
						*(p_data+(height-j-1)*wide*3+i*3+2)=0;
					}
				}
			}
	}
}

/***************************************************************/
/*�������ƣ�biaoji()                                           */
/*�������ͣ�void                                               */
/*���ܣ���ͼ����б��,���ֳɲ�ͬ����ͨ����                  */
/***************************************************************/
void JisuanProcessDib::biaoji()
{
	x_sign=0; 
	m_temp=0;
	x_temp=0;
	y_temp=0;
	stop=0;
	memset(flag,0,255);
	p_data=this->GetData ();   //ȡ��ԭͼ��������ָ��
    wide=this->GetWidth ();  //ȡ��ԭͼ�����������
    height=this->GetHeight ();   //ȡ��ԭͼ���������߶�
    if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		p_temp=new BYTE[wide*height];//����һ����ʱ�ڴ���
		memset(p_temp,255,wide*height);
		//�����ұ��
		for(int j=1;j<height-1;j++)	// ÿ��
		{
			if(stop==1)//�ж���ͨ���Ƿ�̫��
				break;
			for(int i=1;i<wide-1;i++)	// ÿ��
			{
				if(x_sign>250)
				{
					AfxMessageBox("��ͨ����Ŀ̫��,��������ֵ");
					stop=1;
					break;
				}
				if(*(p_data+(height-j-1)*wide+i)==0)//����ǰ��Ϊ�ڵ�
				{
					if(*(p_data+(height-j-1+1)*wide+i+1)==0)//����
					{
						*(p_temp+(height-j-1)*wide+i)=*(p_temp+(height-j-1+1)*wide+i+1);
						x_temp=*(p_temp+(height-j-1+1)*wide+i+1);
						flag[x_temp]+=1;
						if(*(p_data+(height-j-1)*wide+i-1)==0&&*(p_temp+(height-j-1)*wide+i-1)!=x_temp)//��ǰ
						{
							y_temp=*(p_temp+(height-j-1)*wide+i-1);
							for(int m=1;m<=height-1;m++)
								for(int n=1;n<=wide-1;n++)
								{
									if(*(p_temp+(height-m-1)*wide+n)==y_temp)
									{	
										flag[y_temp]=0;
										*(p_temp+(height-m-1)*wide+n)=x_temp;
										flag[x_temp]+=1;
									}
								}
						}//end//��ǰ
						if(*(p_data+(height-j-1+1)*wide+i-1)==0&&*(p_temp+(height-j-1+1)*wide+i-1)!=x_temp)//����
						{
							y_temp=*(p_temp+(height-j-1+1)*wide+i-1);
							for(int m=1;m<=height-1;m++)
								for(int n=1;n<=wide-1;n++)
								{
									if(*(p_temp+(height-m-1)*wide+n)==y_temp)
									{	
										flag[y_temp]=0;
										*(p_temp+(height-m-1)*wide+n)=x_temp;
										flag[x_temp]+=1;
									}
								}
						}//end//����
					}
					else if(*(p_data+(height-j-1+1)*wide+i)==0)//����
					{
						*(p_temp+(height-j-1)*wide+i)=*(p_temp+(height-j-1+1)*wide+i);
						x_temp=*(p_temp+(height-j-1+1)*wide+i);
						flag[x_temp]+=1;
					}
					else if(*(p_data+(height-j-1+1)*wide+i-1)==0)//����
					{
						*(p_temp+(height-j-1)*wide+i)=*(p_temp+(height-j-1+1)*wide+i-1);
						x_temp=*(p_temp+(height-j-1+1)*wide+i-1);
						flag[x_temp]+=1;
					}
					else if(*(p_data+(height-j-1)*wide+i-1)==0)//��ǰ
					{
						*(p_temp+(height-j-1)*wide+i)=*(p_temp+(height-j-1)*wide+i-1);
						x_temp=*(p_temp+(height-j-1)*wide+i-1);
						flag[x_temp]+=1;
					}
					else//û��
					{				
						++x_sign;
						m_temp=x_sign;
						*(p_temp+(height-j-1)*wide+i)=m_temp;
						flag[m_temp]=1;
						
					}
				}//end if
			}// ÿ��
		}//end ÿ��
	}
	else	//24λ��ɫ
	{
		p_temp=new BYTE[wide*height];//����һ����ʱ�ڴ���
		memset(p_temp,255,wide*height);
		//�����ұ��
		for(int j=1;j<height-1;j++)	// ÿ��
		{
			if(stop==1)//�ж���ͨ���Ƿ�̫��
				break;
			for(int i=1;i<wide-1;i++)	// ÿ��
			{
				if(x_sign>250)
				{
					AfxMessageBox("��ͨ����Ŀ̫��,��������ֵ");
					stop=1;
					break;
				}
				if(*(p_data+(height-j-1)*wide*3+i*3)==0)//����ǰ��Ϊ�ڵ�
				{
					
					if(*(p_data+(height-j-1+1)*wide*3+(i+1)*3)==0)//����
					{
						*(p_temp+(height-j-1)*wide+i)=*(p_temp+(height-j-1+1)*wide+(i+1));
						x_temp=*(p_temp+(height-j-1+1)*wide+(i+1));
						flag[x_temp]+=1;
						if(*(p_data+(height-j-1)*wide*3+(i-1)*3)==0&&*(p_temp+(height-j-1)*wide+(i-1))!=x_temp)//��ǰ
						{
							y_temp=*(p_temp+(height-j-1)*wide+(i-1));
							for(int m=1;m<=height-1;m++)
								for(int n=1;n<=wide-1;n++)
								{
									if(*(p_temp+(height-m-1)*wide+n)==y_temp)
									{	
										flag[y_temp]=0;
										*(p_temp+(height-m-1)*wide+n)=x_temp;
										
										flag[x_temp]+=1;
									}
								}
						}//end//��ǰ
						if(*(p_data+(height-j-1+1)*wide*3+(i-1)*3)==0&&*(p_temp+(height-j-1+1)*wide+(i-1))!=x_temp)//����
						{
							y_temp=*(p_temp+(height-j-1+1)*wide+(i-1));
							for(int m=1;m<=height-1;m++)
								for(int n=1;n<=wide-1;n++)
								{
									if(*(p_temp+(height-m-1)*wide+n)==y_temp)
									{	
										flag[y_temp]=0;
										*(p_temp+(height-m-1)*wide+n)=x_temp;
										
										flag[x_temp]+=1;
									}
								}
						}//end//����
					}
					else if(*(p_data+(height-j-1+1)*wide*3+i*3)==0)//����
					{
						*(p_temp+(height-j-1)*wide+i)=*(p_temp+(height-j-1+1)*wide+i);
						x_temp=*(p_temp+(height-j-1+1)*wide+i);
						flag[x_temp]+=1;
					}
					else if(*(p_data+(height-j-1+1)*wide*3+(i-1)*3)==0)//����
					{
						*(p_temp+(height-j-1)*wide+i)=*(p_temp+(height-j-1+1)*wide+(i-1));
						x_temp=*(p_temp+(height-j-1+1)*wide+(i-1));
						flag[x_temp]+=1;
					}
					else if(*(p_data+(height-j-1)*wide*3+(i-1)*3)==0)//��ǰ
					{
						*(p_temp+(height-j-1)*wide+i)=*(p_temp+(height-j-1)*wide+i-1);
						x_temp=*(p_temp+(height-j-1)*wide+(i-1));
						flag[x_temp]+=1;
					}
					else//û��
					{				
						++x_sign;
						m_temp=x_sign;
						*(p_temp+(height-j-1)*wide+i)=m_temp;
						
						flag[m_temp]=1;
					}
				}//end if
			}// ÿ��
		}//end ÿ��
	}
}

/***************************************************************/
/*�������ƣ�LianTong()                                         */
/*�������ͣ�void                                               */
/*���ܣ�����ͨ������,���ÿ����ͨ���������                    */
/***************************************************************/
void JisuanProcessDib::LianTong()
{
	biaoji();  //���ñ�Ǻ���
	if(stop!=1)//�ж���ͨ���Ƿ�̫��
	{
		int fg[255]={0};//����һ������
		memset(fg,0,255);//��ʼ����ֵ��Ϊ0
		int y_sign=0;
		int m_Area=0;//����һ�����
		for(int i=1;i<=x_sign;i++)
		{
			if(flag[i]!=0)
			{
				if(fg[y_sign]==0)
				{
					fg[y_sign]=flag[i];
					++y_sign;
				}			
			}
			m_Area+=flag[i];
		}
		SquareDlg  dlg;//����Ի���
		dlg.m_number=y_sign;//�����ͨ�������
		dlg.m_squareALL=m_Area;//�����ͨ������ܻ�
		CString ss[20];
		//�ڶԻ��������ÿ����ͨ����������������ظ�����
		for(i=0;i<y_sign;i++)
		{
			ss[i].Format("��ͨ����%3d  �������:%10.0d",i+1,fg[i]);
			dlg.m_ShuChu+=ss[i];
		}
		dlg.DoModal();
		for(i=0;i<255;i++) //��������pp_area��Ϊ0
		{
			pppp[i].pp_area=0;
		}
		for(int t=1;t<=x_sign;t++)
		{	pppp[t].pp_number=t;
		for(int j=1;j<height-1;j++)
			for(int i=1;i<wide-1;i++)
			{
				if(*(p_temp+(height-j-1)*wide+i)==t)
				{
					pppp[t].pp_x=i;
					pppp[t].pp_y=j;
					pppp[t].pp_area=flag[t];
					break;
				}				
			}
		}
	}//end if(stop!=1)
}

/***************************************************************/
/*�������ƣ�ClearSMALL(int m_value)                            */
/*�������ͣ�void                                               */
/*������int m_value���û���������ֵ                            */
/*���ܣ��������С�ڸ�������ֵ��С����                       */
/***************************************************************/
void JisuanProcessDib::ClearSMALL(int m_value)
{
	biaoji();  //���ñ�Ǻ���
    if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		if(stop!=1)//�ж���ͨ���Ƿ�̫��
		{
			for(int i=1;i<=x_sign;i++)
			{
				if(flag[i]<m_value)//�ж���ͨ������������ظ������Ƿ�����
				{
					for(int m=1;m<height-1;m++)
						for(int n=1;n<wide-1;n++)
						{
							if(*(p_temp+(height-m-1)*wide+n)==i)
								*(p_data+(height-m-1)*wide+n)=255;
						}		
				}
			}
		}
	}
	else	//24λ��ɫ
	{
		if(stop!=1)//�ж���ͨ���Ƿ�̫��
		{
			for(int i=1;i<=x_sign;i++)
			{
				if(flag[i]<m_value)//�ж���ͨ������������ظ������Ƿ�����
				{
					for(int m=1;m<height-1;m++)
						for(int n=1;n<wide-1;n++)
						{
							if(*(p_temp+(height-m-1)*wide+n)==i)
							{
								*(p_data+(height-m-1)*wide*3+n*3)=255;
								*(p_data+(height-m-1)*wide*3+n*3+1)=255;
								*(p_data+(height-m-1)*wide*3+n*3+2)=255;
							}
						}		
				}
			}
		}
	}
}

/***************************************************************/
/*�������ƣ�Borderline()                                       */
/*�������ͣ�void                                               */
/*���ܣ���ÿ����ͨ�����б߽���٣���ȡ�߽磬����ܳ���         */
/***************************************************************/
void JisuanProcessDib::Borderline()
{
	biaoji();  //���ñ�Ǻ���
	LPBYTE	lpSrc;  // ָ��Դͼ���ָ��
	LPBYTE	lpDst;	// ָ�򻺴�ͼ���ָ��
	LPBYTE	temp;  // ָ�򻺴�DIBͼ���ָ��
    int pixel;	//����ֵ
	bool bFindStartPoint;	//�Ƿ��ҵ���ʼ�㼰�ص���ʼ��
	bool bFindPoint;	//�Ƿ�ɨ�赽һ���߽��
	Point StartPoint,CurrentPoint;	//��ʼ�߽���뵱ǰ�߽��
	//�˸��������ʼɨ�跽��
	int Direction[8][2]={{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0}};
	int BeginDirect;
	if(m_pBitmapInfoHeader->biBitCount<9)	//�Ҷ�ͼ��
	{
		temp = new BYTE[wide*height]; 	// ��ʱ�����ڴ棬�Ա�����ͼ��
		lpDst = temp;	// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
		memset(lpDst, (BYTE)255, wide * height);
		if(stop!=1)//�ж���ͨ���Ƿ�̫��
		{
			//���ҵ������Ϸ��ı߽��
			for(int t=1;t<=x_sign;t++)
			{
				if(flag[t]!=0)
				{	
					bFindStartPoint = false;
					for (int j = 0;j < height && !bFindStartPoint;j++)
					{
						for(int i = 0;i < wide && !bFindStartPoint;i++)
						{
							// ָ��Դͼ������j�У���i�����ص�ָ��			
							lpSrc =  (LPBYTE)(p_temp + wide * j + i);			
							//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
							pixel =  *lpSrc;			
							if(pixel ==t)
							{
								bFindStartPoint = true;
								StartPoint.Height = j;
								StartPoint.Width = i;
								// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
								lpDst = (LPBYTE)(temp + wide * j + i);	
								*lpDst =  t;
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
							lpSrc = (LPBYTE)(p_temp + wide * ( CurrentPoint.Height + Direction[BeginDirect][1])
								+ (CurrentPoint.Width + Direction[BeginDirect][0]));
							pixel =  *lpSrc;
							if(pixel == t)
							{
								bFindPoint = true;
								CurrentPoint.Height = CurrentPoint.Height + Direction[BeginDirect][1];
								CurrentPoint.Width = CurrentPoint.Width + Direction[BeginDirect][0];
								if(CurrentPoint.Height == StartPoint.Height && CurrentPoint.Width == StartPoint.Width)
								{
									bFindStartPoint = true;
								}
								lpDst =  (LPBYTE)(temp + wide * CurrentPoint.Height + CurrentPoint.Width);
								*lpDst = t;
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
						}//////end{while(!bFindPoint)}
					}//////end{while(!bFindStartPoint)}
				}//////end{if(flag[t]!=0)}
			}//////end{for(int t=1;t<=x_sign;t++)}
			memcpy(p_data, temp, wide * height);// ���Ƶ�ԭ������
			delete[] temp; 	// �ͷ��ڴ�
			/////////////////////////////////////////////////
			int x_line=0;
			int fm[255]={0};//����һ������
			memset(fm,0,255);//��ʼ����ֵ��Ϊ0
			//ͳ��ÿ���߽�����ظ���
			for(int j=0;j<height;j++)
			{
				for(int i=0;i<wide;i++)
				{
					if(*(p_data+(height-j-1)*wide+i)!=0)
					{
						x_line=*(p_data+(height-j-1)*wide+i);
						++fm[x_line];
					}
				}
			}	
			int fn[255]={0};//����һ������
			memset(fn,0,255);//��ʼ����ֵ��Ϊ0
			int y_line=0;
			int m_line=0;//����һ�������
			for(int i=0;i<x_line;i++)
			{
				if(fm[i]!=0)
				{
					if(fn[y_line]==0)
					{
						fn[y_line]=fm[i];
						++y_line;
					}			
				}
				m_line+=fm[i];
			}
			LINEDLG  dlg;//����Ի���
			dlg.m_shumu=y_line;//�����ͨ�������
			dlg.m_zongshu=m_line;//�����ͨ������ܻ�
			CString ss[20];
			//�ڶԻ��������ÿ����ͨ�����ܳ����߽����ظ�����
			for(i=0;i<y_line;i++)
			{
				ss[i].Format("��ͨ����%3d  �����ܳ�:%10.0d",i+1,fn[i]);
				dlg.m_line+=ss[i];
			}
			dlg.DoModal();
			/////////////////////////////////////////////////////////////////
			for(i=0;i<255;i++) //��������pp_lin��Ϊ0
			{
				pppp[i].pp_line=0;
			}
			for(t=1;t<=x_line;t++)
			{	
				for(int j=1;j<height-1;j++)
					for(int i=1;i<wide-1;i++)
					{
						if(*(p_temp+(height-j-1)*wide+i)==t)
						{
							pppp[t].pp_x=i;
							pppp[t].pp_y=j;
							pppp[t].pp_line=fm[t];
							break;
						}				
					}
			}
		}//end if(stop!=1)
	}
	else	//24λ��ɫ
	{
		p_data=this->GetData();
		temp = new BYTE[wide*height*3]; 	// ��ʱ�����ڴ棬�Ա�����ͼ��
		lpDst = temp;	// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
		memset(lpDst, (BYTE)255, wide * height*3);
		if(stop!=1)//�ж���ͨ���Ƿ�̫��
		{
			//���ҵ������Ϸ��ı߽��
			for(int t=1;t<=x_sign;t++)
			{
				if(flag[t]!=0)
				{	
					bFindStartPoint = false;
					for (int j = 0;j < height && !bFindStartPoint;j++)
					{
						for(int i = 0;i < wide && !bFindStartPoint;i++)
						{
							// ָ��Դͼ������j�У���i�����ص�ָ��			
							lpSrc =  (LPBYTE)(p_temp + wide * j + i);			
							//ȡ�õ�ǰָ�봦������ֵ��ע��Ҫת��Ϊunsigned char��
							pixel =  *lpSrc;			
							if(pixel ==t)
							{
								bFindStartPoint = true;
								StartPoint.Height = j;
								StartPoint.Width = i;
								// ָ��Ŀ��ͼ������j�У���i�����ص�ָ��			
								lpDst = (LPBYTE)(temp + wide * j*3 + i*3);	
								*lpDst =  t;
								*(lpDst+1) =  t;
								*(lpDst+2) =  t;
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
							lpSrc = (LPBYTE)(p_temp + wide * ( CurrentPoint.Height + Direction[BeginDirect][1])
								+ (CurrentPoint.Width + Direction[BeginDirect][0]));
							pixel =  *lpSrc;
							if(pixel == t)
							{
								bFindPoint = true;
								CurrentPoint.Height = CurrentPoint.Height + Direction[BeginDirect][1];
								CurrentPoint.Width = CurrentPoint.Width + Direction[BeginDirect][0];
								if(CurrentPoint.Height == StartPoint.Height && CurrentPoint.Width == StartPoint.Width)
								{
									bFindStartPoint = true;
								}
								lpDst =  (LPBYTE)(temp + 3*wide * CurrentPoint.Height + CurrentPoint.Width*3);
								*lpDst = t;
								*(lpDst+1) = t;
								*(lpDst+2) = t;
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
							
						}//////end{while(!bFindPoint)}
					}//////end{while(!bFindStartPoint)}
				}//////end{if(flag[t]!=0)}
			}//////end{for(int t=1;t<=x_sign;t++)}
			memcpy(p_data, temp, wide * height*3);// ���Ƶ�ԭ������
			delete[] temp; 	// �ͷ��ڴ�
			/////////////////////////////////////////////////
			int x_line=0;
			int fm[255]={0};//����һ������
			memset(fm,0,255);//��ʼ����ֵ��Ϊ0
			//ͳ��ÿ���߽�����ظ���
			for(int j=0;j<height;j++)
				for(int i=0;i<wide;i++)
				{
					if(*(p_data+(height-j-1)*wide*3+i*3)!=0)
					{
						x_line=*(p_data+(height-j-1)*wide*3+i*3);
						++fm[x_line];
					}
				}
			int fn[255]={0};//����һ������
			memset(fn,0,255);//��ʼ����ֵ��Ϊ0
			int y_line=0;
			int m_line=0;//����һ�������
			for(int i=0;i<x_line;i++)
			{
				if(fm[i]!=0)
				{
					if(fn[y_line]==0)
					{
						fn[y_line]=fm[i];
						++y_line;
					}			
				}
				m_line+=fm[i];
			}
			LINEDLG  dlg;//����Ի���
			dlg.m_shumu=y_line;//�����ͨ�������
			dlg.m_zongshu=m_line;//�����ͨ������ܻ�
			CString ss[20];
			//�ڶԻ��������ÿ����ͨ�����ܳ����߽����ظ�����
			for(i=0;i<y_line;i++)
			{
				ss[i].Format("��ͨ����%3d  �����ܳ�:%10.0d",i+1,fn[i]);
				dlg.m_line+=ss[i];
			}
			dlg.DoModal();
			/////////////////////////////////////////////////////////////////
			for(i=0;i<255;i++) //��������pp_lin��Ϊ0
			{
				pppp[i].pp_line=0;
			}
			for(t=1;t<=x_line;t++)
			{	
				for(int j=1;j<height-1;j++)
					for(int i=1;i<wide-1;i++)
					{
						if(*(p_temp+(height-j-1)*wide+i)==t)
						{
							pppp[t].pp_x=i;
							pppp[t].pp_y=j;
							pppp[t].pp_line=fm[t];
							break;
						}				
					}
			}
		}//end if(stop!=1)
	}
}

//��24λ��ɫͼ��ת��Ϊ24λ�Ҷ�ͼ
void JisuanProcessDib::MakeGray()
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
			BYTE* pbyRed = p_data++;    //�� ����ɫֵ
			BYTE r = *pbyRed;
			BYTE g = *pbyGreen;
			BYTE b = *pbyBlue;
			int gray=0;
			gray=(30*r+59*g+11*b)/100;		
			*pbyBlue = gray;     
			*pbyGreen = gray;    
			*pbyRed = gray;	    	
		}
}

//����δ�����ԭͼ��
void JisuanProcessDib::Baoliu(LPBYTE temp)
{
	// ָ��DIB����ָ��
	LPBYTE p_data;
	// ָ�򻺴�ͼ���ָ��
	LPBYTE	lpDst;
	// �ҵ�DIBͼ��������ʼλ��
	p_data= GetData();
	// DIB�Ŀ��
	LONG wide = GetDibWidthBytes();
	// DIB�ĸ߶�
	LONG height = GetHeight();	
	// ��ʼ���·�����ڴ棬�趨��ʼֵΪ255
	lpDst = (LPBYTE)temp;
	memset(lpDst, (BYTE)255, wide * height);
	memcpy(lpDst,p_data,wide*height);
}
