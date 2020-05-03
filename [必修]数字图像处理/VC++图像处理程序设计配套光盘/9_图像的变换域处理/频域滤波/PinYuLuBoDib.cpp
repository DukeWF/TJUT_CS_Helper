#include "stdafx.h"
#include "windowsx.h"
#include "math.h"
#include "PinYuLuBoDib.h"
#include "malloc.h"
#include "MainFrm.h"
#include "DSplitView.h"
#include "Cdib.h"
#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4) 


#define SWAP(a,b) tempr=(a);(a)=(b);(b)=tempr
#define pi 3.14159265359
 
 
PinYuLuBoDib::PinYuLuBoDib()
{
}
PinYuLuBoDib::~PinYuLuBoDib()
{
}

CNumber PinYuLuBoDib::Add(CNumber c1,CNumber c2)
{
	CNumber c;
	c.re=c1.re+c2.re;
	c.im=c1.im+c2.im;
	return c;
}
CNumber PinYuLuBoDib::Sub(CNumber c1,CNumber c2)
{
	CNumber c;
	c.re=c1.re-c2.re;
	c.im=c1.im-c2.im;
	return c;
}
CNumber PinYuLuBoDib::Mul(CNumber c1,CNumber c2)
{
	CNumber c;
	c.re=c1.re*c2.re-c1.im*c2.im;
	c.im=c1.re*c2.im+c2.re*c1.im;
	return c;
}

///////////////////////////////////////////////////
//�˺���ʵ�ֿ��ٸ���Ҷ�任
//����t��f�ֱ���ָ��ʱ���Ƶ���ָ�룬power��2������
///////////////////////////////////////////////////
void PinYuLuBoDib::QFC(CNumber* t,CNumber* f,int power)
{
	long count;//����Ҷ�任����
	int i,j,k,p,bfsize;
	CNumber *w,*x,*a,*b;//�����ṹ���͵�ָ�����������wָ���Ȩϵ��
	double angle;//�����Ȩϵ�����õĽǶ�ֵ
	count=1<<power;//���㸵��Ҷ�任����
	//������������ռ�
	w=new CNumber[count/2];
	a=new CNumber[count];
	b=new CNumber[count];
	//�����Ȩϵ��
	for(i=0;i<count/2;i++)
	{
		angle=-i*pi*2/count;
		w[i].re=cos(angle);
		w[i].im=sin(angle);
	}
	memcpy(a,t,sizeof(CNumber)*count);
	//����Ƶ�ʷֽⷨ���е�������
	for(k=0;k<power;k++)
	{
		for(j=0;j<1<<k;j++)
		{
			bfsize=1<<(power-k);
			for(i=0;i<bfsize/2;i++)
			{
				p=j*bfsize;
				b[i+p]=Add(a[i+p],a[i+p+bfsize/2]);
				b[i+p+bfsize/2]=Mul(Sub(a[i+p],a[i+p+bfsize/2]),w[i*(1<<k)]);
			}
		}
		x=a;
		a=b;
		b=x;
	}
	//������ı任������������
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<power;i++)
		{
			if(j&(1<<i))
				p+=1<<(power-i-1);
		}
		f[j]=a[p];
	}
	//�ͷŴ洢���ռ�
	delete w;
	delete a;
	delete b;
}

///////////////////////////////////////////////
//�˺�������ʵ��ͼ��ĸ���Ҷ�任
//���ε��ÿ��ٸ���Ҷ�任QFC()ʵ�ֶ�ά����Ҷ�任
///////////////////////////////////////////////
void PinYuLuBoDib::QuickFourier()
{
	LPBYTE  p_data, p;//ָ��ԭͼ��������ָ��
	int width,height;//ԭͼ��Ŀ�Ⱥ͸߶�       
	long w=1,h=1;//���и���Ҷ�任�Ŀ�Ⱥ͸߶ȣ�2�������η���
	int wp=0,hp=0;//��������
	int i,j;
	double temp;//�м����
	CNumber *t,*f;
    if(this->byBitCount==8)	//�Ҷ�ͼ��
		   p_data=this->GetData();//ָ��ԭͼ��������
	else	//24λ���ɫ
		   p_data=this->GetData2();
	width=this->GetWidth();//�õ�ͼ����
	height=this->GetHeight();//�õ�ͼ��߶�
    long lLineBytes=WIDTHBYTES(width*8);//����ͼ��ÿ�е��ֽ���
	while(w*2<=width)//������и���Ҷ�任�Ŀ�ȣ�2�������η���
	{
		w*=2;
		wp++;
	}
	while(h*2<=height)//������и���Ҷ�任�ĸ߶ȣ�2�������η���
	{
		h*=2;
		hp++;
	}
	t=new CNumber[w*h];//����洢���ռ�
	f=new CNumber[w*h];
	for(j=0;j<h;j++)
	{
		for(i=0;i<w;i++)
		{
			p=p_data+lLineBytes*(height-j-1)+i;//ָ���i�е�j������
			t[i+w*j].re=*(p);//��ʱ��ֵ
			t[i+w*j].im=0;
		}
	}
	for(j=0;j<h;j++)//�ڴ�ֱ�����Ͻ��п��ٸ���Ҷ�任
	{
		QFC(&t[w*j],&f[w*j],wp);
	}
	for(j=0;j<h;j++)//ת���任���
	{
		for(i=0;i<w;i++)
		{
			t[j+h*i]=f[i+w*j];
		}
	}
	for(j=0;j<w;j++)//ˮƽ������п��ٸ���Ҷ�任
	{
		QFC(&t[j*h],&f[j*h],hp);
	}
	for(j=0;j<h;j++)
	{
		for(i=0;i<w;i++)
		{
			temp=sqrt(f[i*h+j].re*f[i*h+j].re+f[i*h+j].im*f[i*h+j].im)/100;
			if(temp>255)
				temp=255;
			
			p=p_data+lLineBytes*(height-(j<h/2?j+h/2:j-h/2)-1)+
				(i<w/2?i+w/2:i-w/2);//���任���ԭ���Ƶ�����
			
			*(p)=(BYTE)(temp);
		}
	}
	delete t;
	delete f;
}

///////////////////////////////////////////////
//�˺�������ʵ��ͼ��ĸ���Ҷ�任(û�жԴ�������ʾ�������ƽ��)
//���ε��ÿ��ٸ���Ҷ�任QFC()ʵ�ֶ�ά����Ҷ�任
///////////////////////////////////////////////
void PinYuLuBoDib::FirstQuickFourier()
{
	LPBYTE  p_data,p;//ָ��ԭͼ��������ָ��
	int width,height;//ԭͼ��Ŀ�Ⱥ͸߶�       
	long w=1,h=1;//���и���Ҷ�任�Ŀ�Ⱥ͸߶ȣ�2�������η���
	int wp=0,hp=0;//��������
	int i,j;
	double temp;//�м����
	CNumber *t,*f;
    if(this->byBitCount==8)//�Ҷ�ͼ��
		   p_data=this->GetData();//ָ��ԭͼ��������
	else//24λ���ɫ
		   p_data=this->GetData2();
	width=this->GetWidth();//�õ�ͼ����
	height=this->GetHeight();//�õ�ͼ��߶�
    long lLineBytes=WIDTHBYTES(width*8);//����ͼ��ÿ�е��ֽ���
	while(w*2<=width)//������и���Ҷ�任�Ŀ�ȣ�2�������η���
	{
		w*=2;
		wp++;
	}
	while(h*2<=height)//������и���Ҷ�任�ĸ߶ȣ�2�������η���
	{
		h*=2;
		hp++;
	}
	t=new CNumber[w*h];//����洢���ռ�
	f=new CNumber[w*h];
	for(j=0;j<h;j++)
	{
		for(i=0;i<w;i++)
		{
			p=p_data+lLineBytes*(height-j-1)+i;//ָ���i�е�j������
			t[i+w*j].re=*(p);//��ʱ��ֵ
			t[i+w*j].im=0;
		}
	}
	for(j=0;j<h;j++)//�ڴ�ֱ�����Ͻ��п��ٸ���Ҷ�任
	{
		QFC(&t[w*j],&f[w*j],wp);
	}
	for(j=0;j<h;j++)//ת���任���
	{
		for(i=0;i<w;i++)
		{
			t[j+h*i]=f[i+w*j];
		}
	}
	for(j=0;j<w;j++)//ˮƽ������п��ٸ���Ҷ�任
	{
		QFC(&t[j*h],&f[j*h],hp);
	}
	for(j=0;j<h;j++)
	{
		for(i=0;i<w;i++)
		{
			temp=sqrt(f[i*h+j].re*f[i*h+j].re+f[i*h+j].im*f[i*h+j].im)/100;
			if(temp>255)
				temp=255;
			p=p_data+lLineBytes*(height-(j<h/2?j+h/2:j-h/2)-1)+
				(i<w/2?i+w/2:i-w/2);//���任���ԭ���Ƶ�����
			p=p_data+lLineBytes*(height-(j<h/2?j:j)-1)+
				(i<w/2?i:i);
			*(p)=(BYTE)(temp);
		}
	}
	delete t;
	delete f;
}


//////////////////////////////////////////////////////////////
//�ú�������ʵ�ֶ�ά����Ҷ�任
//����height��width�ֱ��ʾͼ��ĸ߶ȺͿ�ȣ�ising��ʾ�����任
//////////////////////////////////////////////////////////////
void PinYuLuBoDib::fourier(double * data, int height, int width, int isign)
{
	int idim;
	unsigned long i1,i2,i3,i2rev,i3rev,ip1,ip2,ip3,ifp1,ifp2;
	unsigned long ibit,k1,k2,n,nprev,nrem,ntot,nn[3];
	double tempi,tempr;
	double theta,wi,wpi,wpr,wr,wtemp;	
	ntot=height*width; 
	nn[1]=height;
	nn[2]=width;
	nprev=1;
	for (idim=2;idim>=1;idim--) 
	{
		n=nn[idim];
		nrem=ntot/(n*nprev);
		ip1=nprev << 1;
		ip2=ip1*n;
		ip3=ip2*nrem;
		i2rev=1;
		for (i2=1;i2<=ip2;i2+=ip1)
		{
			if (i2 < i2rev) 
			{
				for (i1=i2;i1<=i2+ip1-2;i1+=2) 
				{
					for (i3=i1;i3<=ip3;i3+=ip2)
					{
						i3rev=i2rev+i3-i2;
						SWAP(data[i3],data[i3rev]);
						SWAP(data[i3+1],data[i3rev+1]);
					}
				}
			}
			ibit=ip2 >> 1;
			while (ibit >= ip1 && i2rev > ibit)
			{
				i2rev -= ibit;
				ibit >>= 1;
			}
			i2rev += ibit;
		}
		ifp1=ip1;
		while (ifp1 < ip2) 
		{
			ifp2=ifp1 << 1;
			theta=isign*pi*2/(ifp2/ip1);
			wtemp=sin(0.5*theta);
			wpr = -2.0*wtemp*wtemp;
			wpi=sin(theta);
			wr=1.0;
			wi=0.0;
			for (i3=1;i3<=ifp1;i3+=ip1)
			{
				for (i1=i3;i1<=i3+ip1-2;i1+=2) 
				{
					for (i2=i1;i2<=ip3;i2+=ifp2) 
					{
						k1=i2;
						k2=k1+ifp1;
						tempr=wr*data[k2]-wi*data[k2+1];
						tempi=wr*data[k2+1]+wi*data[k2];
						data[k2]=data[k1]-tempr;
						data[k2+1]=data[k1+1]-tempi;
						data[k1] += tempr;
						data[k1+1] += tempi;
					}
				}
				wr=(wtemp=wr)*wpr-wi*wpi+wr;
				wi=wi*wpr+wtemp*wpi+wi;
			}
			ifp1=ifp2;
		}
		nprev *= n;
	}
}

/*************************************************************************
* ������BWFilterL(int u,int v,int u1,int v1)
*������u��v�ֱ��ǽ�ֹƵ�ʵ�x��y����ֵ�����û�����
*���ܣ��˺�������ʵ��ͼ��Ĳ�����˹��ͨ�˲�
/*************************************************************************/

void PinYuLuBoDib::BWFilterL(int u,int v,int n)
{
	LPBYTE  p_data, p;//ָ��ԭͼ��������ָ��
	int width,height;//ԭͼ��Ŀ�Ⱥ͸߶�       
	int i,j;
	double max=0.0,d0,d;//�м����
	double *t,*H;
	if(this->byBitCount==8)//�Ҷ�ͼ��
		   p_data=this->GetData();//ָ��ԭͼ��������
	else//24λ���ɫ
		   p_data=this->GetData2();//ָ��ԭͼ��������
	width=this->GetWidth();//�õ�ͼ����
	height=this->GetHeight();//�õ�ͼ��߶�
    long lLineBytes=WIDTHBYTES(width*8);//����ͼ��ÿ�е��ֽ���
	t=new double [height*lLineBytes*2+1];//����洢���ռ�
	H=new double [height*lLineBytes*2+1];
	d0=sqrt(u*u+v*v);//�����ֹƵ��d0
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;//ָ���i�е�j������
			t[(2*lLineBytes)*j+2*i+1]=*(p);//��ʱ��ֵ
			t[(2*lLineBytes)*j+2*i+2]=0.0;
			d=sqrt(i*i+j*j);
			H[2*i+(2*lLineBytes)*j+1]=1/(1+pow((d/d0),(2*n)));
			H[2*i+(2*lLineBytes)*j+2]=0.0;
		}
	}
    fourier(t,height,lLineBytes,1);
	for(j=1;j<height*lLineBytes*2;j+=2)
	{
		t[j]=t[j]*H[j]-t[j+1]*H[j+1];
		t[j+1]=t[j]*H[j+1]+t[j+1]*H[j];
	}
	fourier(t,height,lLineBytes,-1);
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			t[(2*lLineBytes)*j+2*i+1]=sqrt(t[(2*lLineBytes)*j+2*i+1]*t[(2*lLineBytes)*j+2*i+1]+t[(2*lLineBytes)*j+2*i+2]*t[(2*lLineBytes)*j+2*i+2]);
			if(max<t[(2*lLineBytes)*j+2*i+1])
				max=t[(2*lLineBytes)*j+2*i+1];
		}
	}
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;
			*(p)=(BYTE)(t[(2*lLineBytes)*j+2*i+1]*255.0/max);
		}
	}
	delete t;
	delete H;
}



////////////////////////////////////////////////
//�˺�������ʵ��ͼ��Ĳ�����˹��ͨ�˲�
//����u��v�ֱ��ǽ�ֹƵ�ʵ�x��y����ֵ�����û�����
////////////////////////////////////////////////
void PinYuLuBoDib::BWFilterH(int u,int v,int n)
{
	LPBYTE p_data,p;//ָ��ԭͼ��������ָ��
	int width,height;//ԭͼ��Ŀ�Ⱥ͸߶�       
	int i,j;
	double max=0.0,d0,d;//�м����
	double *t,*H;
	if(this->byBitCount==8)//�Ҷ�ͼ��
		   p_data=this->GetData();//ָ��ԭͼ��������
	else//24λ���ɫ
		   p_data=this->GetData2();//ָ��ԭͼ��������
	width=this->GetWidth();//�õ�ͼ����
	height=this->GetHeight();//�õ�ͼ��߶�
    long lLineBytes=WIDTHBYTES(width*8);//����ͼ��ÿ�е��ֽ���
	t=new double [height*lLineBytes*2+1];//����洢���ռ�
	H=new double [height*lLineBytes*2+1];
	d0=sqrt(u*u+v*v);//�����ֹƵ��d0
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;//ָ���i�е�j������
			t[(2*lLineBytes)*j+2*i+1]=*(p);//��ʱ��ֵ
			t[(2*lLineBytes)*j+2*i+2]=0.0;
			d=sqrt(j*j+i*i);
			H[2*i+(2*lLineBytes)*j+1]=1/(1+pow((d0/d),(2*n)));
			H[2*i+(2*lLineBytes)*j+2]=0.0;
		}
	}
    fourier(t,height,lLineBytes,1);
	for(j=1;j<height*lLineBytes*2;j+=2)
	{
		t[j]=t[j]*H[j]-t[j+1]*H[j+1];
		t[j+1]=t[j]*H[j+1]+t[j+1]*H[j];
	}
	fourier(t,height,lLineBytes,-1);
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			t[(2*lLineBytes)*j+2*i+1]=sqrt(t[(2*lLineBytes)*j+2*i+1]*t[(2*lLineBytes)*j+2*i+1]+t[(2*lLineBytes)*j+2*i+2]*t[(2*lLineBytes)*j+2*i+2]);
			if(max<t[(2*lLineBytes)*j+2*i+1])
				max=t[(2*lLineBytes)*j+2*i+1];
		}
	}
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;
			*(p)=(BYTE)(t[(2*lLineBytes)*j+2*i+1]*255.0/max);
		}
	}
	delete t;
	delete H;
}


/*************************************************************************
* ������PerfectFilterL(int u,int v)
*������u��v�ֱ��ǽ�ֹƵ�ʵ�x��y����ֵ�����û�����
*���ܣ��˺�������ʵ��ͼ��������ͨ�˲�
/*************************************************************************/

 void PinYuLuBoDib::PerfectFilterL(int u,int v)
{
	LPBYTE  p_data, p;//ָ��ԭͼ��������ָ��
	int width,height;//ԭͼ��Ŀ�Ⱥ͸߶�       
	int i,j;
	double d0,max=0.0;//�м����
	double *t,*H;
	if(this->byBitCount==8)//�Ҷ�ͼ��
		p_data=this->GetData();//ָ��ԭͼ��������
	else//24λ���ɫ
		p_data=this->GetData2();//ָ��ԭͼ��������
	width=this->GetWidth();//�õ�ͼ����
	height=this->GetHeight();//�õ�ͼ��߶�
    long lLineBytes=WIDTHBYTES(width*8);//����ͼ��ÿ�е��ֽ���
	t=new double [height*lLineBytes*2+1];//����洢���ռ�
	H=new double [height*lLineBytes*2+1];
	d0=sqrt(u*u+v*v);//�����ֹƵ��d0
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;//ָ���i�е�j������
			t[(2*lLineBytes)*j+2*i+1]=*(p);//��ʱ��ֵ
			t[(2*lLineBytes)*j+2*i+2]=0.0;
			if((sqrt(i*i+j*j))<=d0)
				H[2*i+(2*lLineBytes)*j+1]=1.0;
			else
				H[2*i+(2*lLineBytes)*j+1]=0.0;
			H[2*i+(2*lLineBytes)*j+2]=0.0;
		}
	}
    fourier(t,height,lLineBytes,1);
	for(j=1;j<height*lLineBytes*2;j+=2)
	{
		t[j]=t[j]*H[j]-t[j+1]*H[j+1];
		t[j+1]=t[j]*H[j+1]+t[j+1]*H[j];
	}
	fourier(t,height,lLineBytes,-1);
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			t[(2*lLineBytes)*j+2*i+1]=sqrt(t[(2*lLineBytes)*j+2*i+1]*t[(2*lLineBytes)*j+2*i+1]+t[(2*lLineBytes)*j+2*i+2]*t[(2*lLineBytes)*j+2*i+2]);
			if(max<t[(2*lLineBytes)*j+2*i+1])
				max=t[(2*lLineBytes)*j+2*i+1];
		}
	}
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;
			*(p)=(BYTE)(t[(2*lLineBytes)*j+2*i+1]*255.0/max);
		}
	}
	delete t;
	delete H;
}


////////////////////////////////////////////////
//�˺�������ʵ��ͼ��������ͨ�˲�
//����u��v�ֱ��ǽ�ֹƵ�ʵ�x��y����ֵ�����û�����
////////////////////////////////////////////////
void PinYuLuBoDib::PerfectFilterH(int u,int v)
{
	LPBYTE  p_data, p;//ָ��ԭͼ��������ָ��
	int width,height;//ԭͼ��Ŀ�Ⱥ͸߶�       
	int i,j;
	double d0,max=0.0;//�м����
	double *t,*H;
	if(this->byBitCount==8)//�Ҷ�ͼ��
		p_data=this->GetData();//ָ��ԭͼ��������
	else//24λ���ɫ
		p_data=this->GetData2();//ָ��ԭͼ��������
	width=this->GetWidth();//�õ�ͼ����
	height=this->GetHeight();//�õ�ͼ��߶�
    long lLineBytes=WIDTHBYTES(width*8);//����ͼ��ÿ�е��ֽ���
	t=new double [height*lLineBytes*2+1];//����洢���ռ�
	H=new double [height*lLineBytes*2+1];
	d0=sqrt(u*u+v*v);//�����ֹƵ��d0
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;//ָ���i�е�j������
			t[(2*lLineBytes)*j+2*i+1]=*(p);//��ʱ��ֵ
			t[(2*lLineBytes)*j+2*i+2]=0.0;
			if((sqrt(i*i+j*j))<=d0)
				H[2*i+(2*lLineBytes)*j+1]=0.0;
			else
				H[2*i+(2*lLineBytes)*j+1]=1.0;
			H[2*i+(2*lLineBytes)*j+2]=0.0;
		}
	}
    fourier(t,height,lLineBytes,1);
	for(j=1;j<height*lLineBytes*2;j+=2)
	{
		t[j]=t[j]*H[j]-t[j+1]*H[j+1];
		t[j+1]=t[j]*H[j+1]+t[j+1]*H[j];
	}
	fourier(t,height,lLineBytes,-1);
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			t[(2*lLineBytes)*j+2*i+1]=sqrt(t[(2*lLineBytes)*j+2*i+1]*t[(2*lLineBytes)*j+2*i+1]+t[(2*lLineBytes)*j+2*i+2]*t[(2*lLineBytes)*j+2*i+2]);
			if(max<t[(2*lLineBytes)*j+2*i+1])
				max=t[(2*lLineBytes)*j+2*i+1];
		}
	}
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;
			*(p)=(BYTE)(t[(2*lLineBytes)*j+2*i+1]*255.0/max);
		}
	}
	delete t;
	delete H;
}

/*************************************************************************
* ������TLFilter(int u,int v,int u1,int v1)
*������u��v�ֱ��ǽ�ֹƵ�ʵ�x��y����ֵ�����û�����
*���ܣ��˺�������ʵ��ͼ������ε�ͨ�˲�
/*************************************************************************/

void PinYuLuBoDib::TLFilter(int u,int v,int u1,int v1)
{
	LPBYTE  p_data, p;//ָ��ԭͼ��������ָ��
	int width,height;//ԭͼ��Ŀ�Ⱥ͸߶�       
	int i,j;
	double max=0.0,d0,d,d1;//�м����
	double *t,*H;

	if(this->byBitCount==8)//�Ҷ�ͼ��
		   p_data=this->GetData();//ָ��ԭͼ��������
	else//24λ���ɫ
		   p_data=this->GetData2();//ָ��ԭͼ��������
	width=this->GetWidth();//�õ�ͼ����
	height=this->GetHeight();//�õ�ͼ��߶�
    long lLineBytes=WIDTHBYTES(width*8);//����ͼ��ÿ�е��ֽ���
	t=new double [height*lLineBytes*2+1];//����洢���ռ�
	H=new double [height*lLineBytes*2+1];
	d0=sqrt(u*u+v*v);//�����ֹƵ��d0
	d1=sqrt(u1*u1+v1*v1);
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;//ָ���i�е�j������
			t[(2*lLineBytes)*j+2*i+1]=*(p);//��ʱ��ֵ
			t[(2*lLineBytes)*j+2*i+2]=0.0;
			d=sqrt(i*i+j*j);
			if(d<d0)
			{
				H[2*i+(2*lLineBytes)*j+1]=1;
				H[2*i+(2*lLineBytes)*j+2]=0.0;
			}
			if(d>d1)
			{
				H[2*i+(2*lLineBytes)*j+1]=0.0;
				H[2*i+(2*lLineBytes)*j+2]=0.0;
			}
			else
			{
				H[2*i+(2*lLineBytes)*j+1]=(d-d1)/(d0-d1);
				H[2*i+(2*lLineBytes)*j+2]=0.0;
			}				
		}
	}
    fourier(t,height,lLineBytes,1);
	for(j=1;j<height*lLineBytes*2;j+=2)
	{
		t[j]=t[j]*H[j]-t[j+1]*H[j+1];
		t[j+1]=t[j]*H[j+1]+t[j+1]*H[j];
	}
	fourier(t,height,lLineBytes,-1);
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			t[(2*lLineBytes)*j+2*i+1]=sqrt(t[(2*lLineBytes)*j+2*i+1]*t[(2*lLineBytes)*j+2*i+1]+t[(2*lLineBytes)*j+2*i+2]*t[(2*lLineBytes)*j+2*i+2]);
			if(max<t[(2*lLineBytes)*j+2*i+1])
				max=t[(2*lLineBytes)*j+2*i+1];
		}
	}
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;
			*(p)=(BYTE)(t[(2*lLineBytes)*j+2*i+1]*255.0/max);
		}
	}
	delete t;
	delete H;
}


////////////////////////////////////////////////
//�˺�������ʵ��ͼ������θ�ͨ�˲�
//����u��v�ֱ��ǽ�ֹƵ�ʵ�x��y����ֵ�����û�����
////////////////////////////////////////////////
void PinYuLuBoDib::THFilter(int u,int v,int u1,int v1)
{
	LPBYTE  p_data, p;//ָ��ԭͼ��������ָ��
	int width,height;//ԭͼ��Ŀ�Ⱥ͸߶�       
	int i,j;
	double max=0.0,d0,d,d1;//�м����
	double *t,*H;
	if(this->byBitCount==8)//�Ҷ�ͼ��
		p_data=this->GetData();//ָ��ԭͼ��������
	else//24λ���ɫ
		p_data=this->GetData2();//ָ��ԭͼ��������
	width=this->GetWidth();//�õ�ͼ����
	height=this->GetHeight();//�õ�ͼ��߶�
    long lLineBytes=WIDTHBYTES(width*8);//����ͼ��ÿ�е��ֽ���
	t=new double [height*lLineBytes*2+1];//����洢���ռ�
	H=new double [height*lLineBytes*2+1];
	d0=sqrt(u*u+v*v);//�����ֹƵ��d0
	d1=sqrt(u1*u1+v1*v1);
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;//ָ���i�е�j������
			t[(2*lLineBytes)*j+2*i+1]=*(p);//��ʱ��ֵ
			t[(2*lLineBytes)*j+2*i+2]=0.0;
			d=sqrt(i*i+j*j);
			
			if(d<d0)
			{
				H[2*i+(2*lLineBytes)*j+1]=0;
				H[2*i+(2*lLineBytes)*j+2]=0.0;
			}
			if(d>d1)
			{
				H[2*i+(2*lLineBytes)*j+1]=1;
				H[2*i+(2*lLineBytes)*j+2]=0.0;
			}
			else
			{
				H[2*i+(2*lLineBytes)*j+1]=(d-d0)/(d1-d0);
				H[2*i+(2*lLineBytes)*j+2]=0.0;
			}						
		}
	}
    fourier(t,height,lLineBytes,1);
	for(j=1;j<height*lLineBytes*2;j+=2)
	{
		t[j]=t[j]*H[j]-t[j+1]*H[j+1];
		t[j+1]=t[j]*H[j+1]+t[j+1]*H[j];
	}
	fourier(t,height,lLineBytes,-1);
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			t[(2*lLineBytes)*j+2*i+1]=sqrt(t[(2*lLineBytes)*j+2*i+1]*t[(2*lLineBytes)*j+2*i+1]+t[(2*lLineBytes)*j+2*i+2]*t[(2*lLineBytes)*j+2*i+2]);
			if(max<t[(2*lLineBytes)*j+2*i+1])
				max=t[(2*lLineBytes)*j+2*i+1];
		}
	}
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;
			*(p)=(BYTE)(t[(2*lLineBytes)*j+2*i+1]*255.0/max);
		}
	}
	delete t;
	delete H;
}

/*************************************************************************
* ������ZLFilter(int u,int v,int u1,int v1)
*������u��v�ֱ��ǽ�ֹƵ�ʵ�x��y����ֵ�����û�����
*���ܣ��˺�������ʵ��ͼ���ָ����ͨ�˲�
///////////////////////////////////////////////*/
void PinYuLuBoDib::ZLFilter(int u,int v,int n)
{
	LPBYTE  p_data, p;//ָ��ԭͼ��������ָ��
	int width,height;//ԭͼ��Ŀ�Ⱥ͸߶�       
	int i,j;
	double max=0.0,d0,d;//�м����
	double *t,*H;
	if(this->byBitCount==8)//�Ҷ�ͼ��
		p_data=this->GetData();//ָ��ԭͼ��������
	else//24λ���ɫ
		p_data=this->GetData2();//ָ��ԭͼ��������
	width=this->GetWidth();//�õ�ͼ����
	height=this->GetHeight();//�õ�ͼ��߶�
    long lLineBytes=WIDTHBYTES(width*8);//����ͼ��ÿ�е��ֽ���
	t=new double [height*lLineBytes*2+1];//����洢���ռ�
	H=new double [height*lLineBytes*2+1];
	d0=sqrt(u*u+v*v);//�����ֹƵ��d0
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;//ָ���i�е�j������
			t[(2*lLineBytes)*j+2*i+1]=*(p);//��ʱ��ֵ
			t[(2*lLineBytes)*j+2*i+2]=0.0;
			d=sqrt(i*i+j*j);
			H[2*i+(2*lLineBytes)*j+1]=exp(-pow((d/d0),n));
			H[2*i+(2*lLineBytes)*j+2]=0.0;
		}
	}
    fourier(t,height,lLineBytes,1);
	for(j=1;j<height*lLineBytes*2;j+=2)
	{
		t[j]=t[j]*H[j]-t[j+1]*H[j+1];
		t[j+1]=t[j]*H[j+1]+t[j+1]*H[j];
	}
	fourier(t,height,lLineBytes,-1);
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			t[(2*lLineBytes)*j+2*i+1]=sqrt(t[(2*lLineBytes)*j+2*i+1]*t[(2*lLineBytes)*j+2*i+1]+t[(2*lLineBytes)*j+2*i+2]*t[(2*lLineBytes)*j+2*i+2]);
			if(max<t[(2*lLineBytes)*j+2*i+1])
				max=t[(2*lLineBytes)*j+2*i+1];
		}
	}
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;
			*(p)=(BYTE)(t[(2*lLineBytes)*j+2*i+1]*255.0/max);
		}
	}
	delete t;
	delete H;
}


////////////////////////////////////////////////
//�˺�������ʵ��ͼ���ָ����ͨ�˲�
//����u��v�ֱ��ǽ�ֹƵ�ʵ�x��y����ֵ�����û�����
////////////////////////////////////////////////
void PinYuLuBoDib::ZHFilter(int u,int v,int n)
{
	LPBYTE  p_data, p;//ָ��ԭͼ��������ָ��
	int width,height;//ԭͼ��Ŀ�Ⱥ͸߶�       
	int i,j;
	double max=0.0,d0,d;//�м����
	double *t,*H;
	if(this->byBitCount==8)//�Ҷ�ͼ��
		p_data=this->GetData();//ָ��ԭͼ��������
	else//24λ���ɫ
		p_data=this->GetData2();//ָ��ԭͼ��������
	width=this->GetWidth();//�õ�ͼ����
	height=this->GetHeight();//�õ�ͼ��߶�
    long lLineBytes=WIDTHBYTES(width*8);//����ͼ��ÿ�е��ֽ���
	t=new double [height*lLineBytes*2+1];//����洢���ռ�
	H=new double [height*lLineBytes*2+1];
	d0=sqrt(u*u+v*v);//�����ֹƵ��d0
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;//ָ���i�е�j������
			t[(2*lLineBytes)*j+2*i+1]=*(p);//��ʱ��ֵ
			t[(2*lLineBytes)*j+2*i+2]=0.0;
			d=sqrt(i*i+j*j);
			H[2*i+(2*lLineBytes)*j+1]=exp(-pow((d0/d),n));
			H[2*i+(2*lLineBytes)*j+2]=0.0;
		}
	}
    fourier(t,height,lLineBytes,1);
	for(j=1;j<height*lLineBytes*2;j+=2)
	{
		t[j]=t[j]*H[j]-t[j+1]*H[j+1];
		t[j+1]=t[j]*H[j+1]+t[j+1]*H[j];
	}
	fourier(t,height,lLineBytes,-1);
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			t[(2*lLineBytes)*j+2*i+1]=sqrt(t[(2*lLineBytes)*j+2*i+1]*t[(2*lLineBytes)*j+2*i+1]+t[(2*lLineBytes)*j+2*i+2]*t[(2*lLineBytes)*j+2*i+2]);
			if(max<t[(2*lLineBytes)*j+2*i+1])
				max=t[(2*lLineBytes)*j+2*i+1];
		}
	}       
	for(j=0;j<height;j++)
	{
		for(i=0;i<lLineBytes;i++)
		{
			p=p_data+lLineBytes*j+i;
			*(p)=(BYTE)(t[(2*lLineBytes)*j+2*i+1]*255.0/max);
		}
	}
	delete t;
	delete H;
}
