// DynSplitView2.cpp : implementation file
//

#include "stdafx.h"
#include "DSplit.h"
#include "DynSplitView2.h"
#include "DlgPingYi.h"
#include "DlgSuoFang.h"
#include "math.h"
#include "DlgXuanZhuan.h"
#include "JiHeBianHuanDib.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynSplitView2

IMPLEMENT_DYNCREATE(CDynSplitView2, CView)

CDynSplitView2::CDynSplitView2()
{
	state2=0;
	state3=1;
}

/*��ʼ��ͼ������*/
void CDynSplitView2::clearmem()
{
	CDSplitDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc ->statedoc=0;
    state2=1;
	CDibNew1=&pDoc->CDibNew;
    CDib1=&pDoc->CDib;
    long int  size;
	if(CDibNew1->m_pBitmapInfoHeader->biBitCount<9)	
		size=CDib1->GetHeight()*CDib1->GetWidth();
	else
		size=CDib1->GetHeight()*CDib1->GetWidth()*3;

    memcpy(CDibNew1->m_pData,CDib1->m_pData,size);
	CDibNew1->SetHeight(CDib1->GetHeight());
    CDibNew1->SetWidth(CDib1->GetWidth());
}

CPalette * CDynSplitView2::CreateBitmapPalette(JiHeBianHuanDib * pBitmap)
{
	struct
	{
		WORD Version;
		WORD NumberOfEntries;
		PALETTEENTRY aEntries[256];
	} palette = { 0x300, 256 };
	
	LPRGBQUAD pRGBTable = pBitmap->GetRGB();
	UINT numberOfColors = pBitmap->GetNumberOfColors();
	
	for(UINT x=0; x<numberOfColors; ++x)
	{
		palette.aEntries[x].peRed =
			pRGBTable[x].rgbRed;
		palette.aEntries[x].peGreen =
			pRGBTable[x].rgbGreen;
		palette.aEntries[x].peBlue =
			pRGBTable[x].rgbBlue;
		palette.aEntries[x].peFlags = 0;
	}
	
	hPalette.CreatePalette((LPLOGPALETTE)&palette);
	return &hPalette;
}

CDynSplitView2::~CDynSplitView2()
{
}

CDSplitDoc* CDynSplitView2::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDSplitDoc)));
	return (CDSplitDoc*)m_pDocument;
}


BEGIN_MESSAGE_MAP(CDynSplitView2, CView)
	//{{AFX_MSG_MAP(CDynSplitView2)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_FILESAVE, OnFilesave)
	ON_COMMAND(ID_Tuxiangpingyi, OnTuxiangpingyi)
	ON_COMMAND(ID_Shuipingjingxiang, OnShuipingjingxiang)
	ON_COMMAND(ID_Chuizhijingxiang, OnChuizhijingxiang)
	ON_COMMAND(ID_Zhuanzhi, OnZhuanzhi)
	ON_COMMAND(ID_Xuanzhuan, OnXuanzhuan)
	ON_COMMAND(ID_Fangda, OnFangda)
	ON_COMMAND(ID_SuoXiao, OnSuoXiao)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynSplitView2 drawing

void CDynSplitView2::OnDraw(CDC* pDC)
{	
	CDSplitDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	if(!pDoc ->statedoc&&state2==1)
	{
        BYTE* pBitmapData = CDibNew1->GetData();
        LPBITMAPINFO pBitmapInfo = CDibNew1->GetInfo();
        int bitmapHeight = CDibNew1->GetHeight();
        int bitmapWidth = CDibNew1->GetWidth();
		int scaledWidth = (int)(bitmapWidth * 1);
		int scaledHeight = (int)(bitmapHeight * 1);
		if (CDibNew1->GetRGB()) // Has a color table
		{
			CPalette * hPalette1=CreateBitmapPalette(CDibNew1);
            CPalette * hOldPalette =
                pDC->SelectPalette(hPalette1, true);
            pDC->RealizePalette();
			::StretchDIBits(pDC->GetSafeHdc(),0,0, bitmapWidth, bitmapHeight,
				0, 0, bitmapWidth , bitmapHeight ,
				pBitmapData, pBitmapInfo,
				DIB_RGB_COLORS, SRCCOPY);
            pDC->SelectPalette(hOldPalette, true);
            hPalette.DeleteObject();
			CDibNew1->SetWidth(bitmapWidth);
			CDibNew1->SetHeight(bitmapHeight);
		}
		else
		{
			
            ::StretchDIBits(pDC->GetSafeHdc(),
                0, 0, scaledWidth, scaledHeight,
                0, 0, bitmapWidth, bitmapHeight,
				pBitmapData, pBitmapInfo,
				DIB_RGB_COLORS, SRCCOPY);
			CDibNew1->SetWidth(bitmapWidth);
			CDibNew1->SetHeight(bitmapHeight);
		}
	}
	
    
}


/////////////////////////////////////////////////////////////////////////////
// CDynSplitView2 diagnostics

#ifdef _DEBUG
void CDynSplitView2::AssertValid() const
{
	CView::AssertValid();
}

void CDynSplitView2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynSplitView2 message handlers

BOOL CDynSplitView2::OnEraseBkgnd(CDC* pDC) 
{
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(&rect,::GetSysColor(COLOR_WINDOW));
	return TRUE;
}
 
void CDynSplitView2::OnFilesave() 
{
	CFileDialog dlg(FALSE,_T("BMP"),_T("*.BMP"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("λͼ�ļ�(*.BMP)|*.BMP|"));	
    if(IDOK==dlg.DoModal())
		CString  filename;
    filename.Format ("%s",dlg.GetPathName() );    
    CDibNew1->SaveFile(filename);
	state2=1;
	Invalidate();
}

/*ƽ����Ϣӳ��*/
void CDynSplitView2::OnTuxiangpingyi() 
{
	int x,y;
	if(state3==0)
		CDibNew1->clearmem2(); 
	MessageBox("������ʾ����������������������ʾ��������������");
	//��ʼ��ͼ������
	clearmem();
	// �����Ի���
	CDlgPingYi  dlg;
	dlg.m_Xmove=10;
	dlg.m_Ymove=10;

	// ��ʾ�Ի�����ʾ�û��趨����������
	if (dlg.DoModal() != IDOK)
		return;// ����

	x=dlg.m_Xmove;
	y=dlg.m_Ymove;
	
	// ɾ���Ի���
	delete dlg;	
	CDibNew1->PingYi(x,y); 
	Invalidate();           //����ˢ�º���
	state3=1;
}

/*ˮƽ������Ϣӳ��*/
void CDynSplitView2::OnShuipingjingxiang() 
{
	clearmem();
	CDibNew1->JingXiang(TRUE);             //����ˮƽ��������
    Invalidate();           //����ˢ�º���
}

/*��ֱ������Ϣӳ��*/
void CDynSplitView2::OnChuizhijingxiang() 
{
	clearmem();
	CDibNew1->JingXiang(FALSE);             //���ô�ֱ��������
    Invalidate();           //����ˢ�º���
}

/*ת����Ϣӳ��*/
void CDynSplitView2::OnZhuanzhi() 
{
	clearmem();	
	CDibNew1->Zhuanzhi();             //����ת�ô�����
    Invalidate(); //����ˢ�º���
    state3=0;
}
 



void CDynSplitView2::OnXuanzhuan() 
{
	MessageBox("�Ƕ�ӦΪ90�ȵ�����������ͼ��ĸߺͿ�����ͬ");
	clearmem();
	
	int iRotateAngle;			// ��ת�Ƕ�
	CDlgXuanZhuan dlg;			// �����Ի���
	dlg.m_iRotateAngle = 90;	// ��ʼ������ֵ
	
	// ��ʾ�Ի�����ʾ�û��趨��ת�Ƕ�
	if (dlg.DoModal() != IDOK)
	{
		return;// ����
	}
	
	// ��ȡ�û��趨����ת��
	iRotateAngle = dlg.m_iRotateAngle;
	CDibNew1->Xuanzhuan(iRotateAngle);
	this->Invalidate();
}

//ͼ��Ŵ���Ϣӳ��
void CDynSplitView2::OnFangda() 
{
	if(state3==0)
		CDibNew1->clearmem2(); 
	clearmem();	
	float xzoom,yzoom;
	CDlgSuoFang  dlg;		// ����Ի���
	dlg.m_XZoom=2.0;
	dlg.m_YZoom=2.0;

	// ��ʾ�Ի�����ʾ�û��趨����������
	if (dlg.DoModal() != IDOK)
	{
		return;				// ����
	}
    xzoom=dlg.m_XZoom;
    yzoom=dlg.m_YZoom;
	delete dlg;				// ɾ���Ի���

	// Դͼ��Ŀ�Ⱥ͸߶�
	LONG	wide;
	LONG	height;
	
	// ���ź�ͼ��Ŀ�Ⱥ͸߶�
	LONG	newwide;
	LONG	newheight;
	LONG	newLineBytes;
	LPBYTE	temp;
	
	// ��ȡͼ��Ŀ�Ⱥ͸߶�
	wide = CDibNew1->GetWidth();
	height = CDibNew1->GetHeight();

	if(CDibNew1->m_pBitmapInfoHeader->biBitCount<9)
	{
		// �������ź��ͼ���Ⱥ͸߶�
		newwide = (LONG) (wide * xzoom +0.5);
		newheight = (LONG) (height * yzoom+0.5);
		newLineBytes=(newwide*8+31)/32*4;

		// �����ڴ棬�Ա�����DIB
		temp = new BYTE[ newLineBytes * newheight ];
		memset(temp,0,newLineBytes * newheight);
		CDibNew1->m_pData=CDibNew1->FangDa(temp,xzoom,yzoom,wide,height,newLineBytes,newheight);  
		CDibNew1->SetWidth(newwide);
		CDibNew1->SetHeight(newheight);
		Invalidate();           //����ˢ�º���
	}
	else
	{
		// �������ź��ͼ���Ⱥ͸߶�
		newwide = (LONG) (wide * xzoom*3);
		newheight = (LONG) (height * yzoom);
		
		// �����ڴ棬�Ա�����DIB
		temp = new BYTE[ newwide * newheight];
		memset(temp,0,newwide * newheight);
		CDibNew1->m_pData=CDibNew1->FangDa(temp,xzoom,yzoom,wide,height,newwide,newheight); 
		CDibNew1->SetWidth(newwide/3);
		CDibNew1->SetHeight(newheight);
		Invalidate();           //����ˢ�º���
	}
}

//ͼ����С��Ϣӳ��
void CDynSplitView2::OnSuoXiao() 
{
	if(state3==0)
		CDibNew1->clearmem2(); 

	float x,y;					//��С����
	clearmem();	
	CDlgSuoFang  dlg;			//�����Ի���
	dlg.m_XZoom=0.5;
	dlg.m_YZoom=0.5;

	// ��ʾ�Ի�����ʾ�û��趨����������
	if (dlg.DoModal() != IDOK)
	{
		return;					//����
	}
	x=dlg.m_XZoom;
	y=dlg.m_YZoom;

	delete dlg;					//ɾ���Ի���	 
	CDibNew1->SuoXiao( x, y );	//������С������
    Invalidate();				//����ˢ�º���
	state3=1;
}

void CDynSplitView2::clearmem(float xzoom, float yzoom)
{
	CDSplitDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->statedoc=0;
    state2=1;
	CDibNew1=&pDoc->CDibNew;
    CDib1=&pDoc->CDib;
	long int  size=CDib1->GetHeight()*CDib1->GetDibWidthBytes()*xzoom;
	memcpy(CDibNew1->m_pData,CDib1->m_pData,size);
}
