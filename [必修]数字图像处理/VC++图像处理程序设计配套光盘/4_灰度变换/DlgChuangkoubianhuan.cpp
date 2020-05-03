// DlgChuangkoubianhuan.cpp : implementation file
//

#include "stdafx.h"
#include "DSplit.h"
#include "DlgChuangkoubianhuan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgChuangkoubianhuan dialog


CDlgChuangkoubianhuan::CDlgChuangkoubianhuan(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgChuangkoubianhuan::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgChuangkoubianhuan)
	m_bLow = 0;
	m_bUp = 0;
	//}}AFX_DATA_INIT
}


void CDlgChuangkoubianhuan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgChuangkoubianhuan)
	DDX_Text(pDX, IDC_EDIT_Low, m_bLow);
	DDX_Text(pDX, IDC_EDIT_Up, m_bUp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgChuangkoubianhuan, CDialog)
	//{{AFX_MSG_MAP(CDlgChuangkoubianhuan)
	ON_EN_KILLFOCUS(IDC_EDIT_Low, OnKillfocusEDITLow)
	ON_EN_KILLFOCUS(IDC_EDIT_Up, OnKillfocusEDITUp)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgChuangkoubianhuan message handlers

BOOL CDlgChuangkoubianhuan::OnInitDialog() 
{
	
	CDialog::OnInitDialog();
	
	// ��ȡ����ֱ��ͼ�ı�ǩ
	CWnd* pWnd = GetDlgItem(IDC_COORD);
	
	// �����������¼�����Ч����
	CRect rect;
	GetClientRect(rect);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgChuangkoubianhuan::OnKillfocusEDITLow() 
{
	// ����
	UpdateData(TRUE);
	
	// �ж��Ƿ����޳�������
	if (m_bLow > m_bUp)
	{
		// ����
		BYTE bTemp = m_bLow;
		m_bLow = m_bUp;
		m_bUp = bTemp;
		
		// ����
		UpdateData(FALSE);
	}
	
	// �ػ�
	Invalidate();
}

void CDlgChuangkoubianhuan::OnKillfocusEDITUp() 
{
	// ����
	UpdateData(TRUE);
	
	// �ж��Ƿ����޳�������
	if (m_bLow > m_bUp)
	{
		// ����
		BYTE bTemp = m_bLow;
		m_bLow = m_bUp;
		m_bUp = bTemp;
		
		// ����
		UpdateData(FALSE);
	}
	
	// �ػ�
	Invalidate();
}

void CDlgChuangkoubianhuan::OnOK() 
{
	// �ж��Ƿ����޳�������
	if (m_bLow > m_bUp)
	{
		// ����
		BYTE bTemp = m_bLow;
		m_bLow = m_bUp;
		m_bUp = bTemp;
	}
	
	// Ĭ�ϴ����¼�
	CDialog::OnOK();
}

void CDlgChuangkoubianhuan::OnPaint() 
{
	// �ַ���
	CString str;
	
	// �豸������
	CPaintDC dc(this);
	
	// ��ȡ����������ı���
	CWnd* pWnd = GetDlgItem(IDC_COORD);
	
	// ָ��
	CDC* pDC = pWnd->GetDC();
	pWnd->Invalidate();
	pWnd->UpdateWindow();
	
	pDC->Rectangle(0,0,330,300);
	
	// �������ʶ���
	CPen* pPenRed = new CPen;
	
	// ��ɫ����
	pPenRed->CreatePen(PS_SOLID,2,RGB(255,0,0));
	
	// �������ʶ���
	CPen* pPenBlue = new CPen;
	
	// ��ɫ����
	pPenBlue->CreatePen(PS_SOLID,2,RGB(0,0, 255));
	
	// �������ʶ���
	CPen* pPenGreen = new CPen;
	
	// ��ɫ����
	pPenGreen->CreatePen(PS_DOT,1,RGB(0,255,0));
	
	// ѡ�е�ǰ��ɫ���ʣ���������ǰ�Ļ���
	CGdiObject* pOldPen = pDC->SelectObject(pPenRed);
	
	// ����������
	pDC->MoveTo(10,10);
	
	// ��ֱ��
	pDC->LineTo(10,280);
	
	// ˮƽ��
	pDC->LineTo(320,280);
	
	// д����
	str.Format("0");
	pDC->TextOut(10, 281, str);
	
	str.Format("255");
	pDC->TextOut(265, 281, str);
	pDC->TextOut(11, 25, str);
	
	// ����X���ͷ
	pDC->LineTo(315,275);
	pDC->MoveTo(320,280);
	pDC->LineTo(315,285);
	
	// ����X���ͷ
	pDC->MoveTo(10,10);
	pDC->LineTo(5,15);
	pDC->MoveTo(10,10);
	pDC->LineTo(15,15);
	
	// ���ĳ���ɫ����
	pDC->SelectObject(pPenGreen);	
	
	// ���ƴ���������
	pDC->MoveTo(m_bLow + 10, 25);
	pDC->LineTo(m_bLow + 10, 280);
	
	pDC->MoveTo(m_bUp + 10, 25);
	pDC->LineTo(m_bUp + 10, 280);
	
	// ���ĳ���ɫ����
	pDC->SelectObject(pPenBlue);	
	
	// ��������ֵ
	str.Format("(%d, %d)", m_bLow, m_bLow);
	pDC->TextOut(m_bLow + 10, 281 - m_bLow, str);
	str.Format("(%d, %d)", m_bUp, m_bUp);
	pDC->TextOut(m_bUp + 10, 281 - m_bUp, str);
	
	// �����û�ָ���Ĵ��ڣ�ע��ת������ϵ��
	pDC->MoveTo(10, 280);
	pDC->LineTo(m_bLow + 10, 280);
	pDC->LineTo(m_bLow + 10, 280 - m_bLow);
	pDC->LineTo(m_bUp + 10, 280 - m_bUp);
	pDC->LineTo(m_bUp + 10, 25);
	pDC->LineTo(265, 25);
	
	// �ָ���ǰ�Ļ���
	pDC->SelectObject(pOldPen);	
	
	// ���Ʊ�Ե
	pDC->MoveTo(10,25);
	pDC->LineTo(265,25);
	pDC->LineTo(265,280);
	
	// ɾ���µĻ���
	delete pPenRed;
	delete pPenBlue;
	delete pPenGreen;
	
	// Do not call CDialog::OnPaint() for painting messages
}
