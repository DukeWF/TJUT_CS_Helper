// DlgZhexianbianhuan.cpp : implementation file
//

#include "stdafx.h"
#include "DSplit.h"
#include "DlgZhexianbianhuan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgZhexianbianhuan dialog


CDlgZhexianbianhuan::CDlgZhexianbianhuan(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgZhexianbianhuan::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgZhexianbianhuan)
	m_bX1 = 0;
	m_bX2 = 0;
	m_bY1 = 0;
	m_bY2 = 0;
	//}}AFX_DATA_INIT
}


void CDlgZhexianbianhuan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgZhexianbianhuan)
	DDX_Text(pDX, IDC_EDIT_X1, m_bX1);
	DDX_Text(pDX, IDC_EDIT_X2, m_bX2);
	DDX_Text(pDX, IDC_EDIT_Y1, m_bY1);
	DDX_Text(pDX, IDC_EDIT_Y2, m_bY2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgZhexianbianhuan, CDialog)
	//{{AFX_MSG_MAP(CDlgZhexianbianhuan)
	ON_EN_KILLFOCUS(IDC_EDIT_X1, OnKillfocusEditX1)
	ON_EN_KILLFOCUS(IDC_EDIT_X2, OnKillfocusEditX2)
	ON_EN_KILLFOCUS(IDC_EDIT_Y1, OnKillfocusEditY1)
	ON_EN_KILLFOCUS(IDC_EDIT_Y2, OnKillfocusEditY2)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgZhexianbianhuan message handlers

BOOL CDlgZhexianbianhuan::OnInitDialog() 
{
	// ����Ĭ��OnInitDialog����
	CDialog::OnInitDialog();
	
	// ��ȡ����ֱ��ͼ�ı�ǩ
	CWnd* pWnd = GetDlgItem(IDC_COORD);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgZhexianbianhuan::OnOK() 
{
	// �ж��Ƿ����޳�������
	if (m_bX1 > m_bX2)
	{
		// ����
		BYTE bTemp = m_bX1;
		m_bX1 = m_bX2;
		m_bX2 = bTemp;
		bTemp = m_bY1;
		m_bY1 = m_bY2;
		m_bY2 = bTemp;
		
		// ����
		UpdateData(FALSE);
	}
	CDialog::OnOK();
}

void CDlgZhexianbianhuan::OnKillfocusEditX1() 
{
	// ����
	UpdateData(TRUE);
	
	// �ж��Ƿ����޳�������
	if (m_bX1 > m_bX2)
	{
		// ����
		BYTE bTemp = m_bX1;
		m_bX1 = m_bX2;
		m_bX2 = bTemp;
		
		// ����
		UpdateData(FALSE);
	}
	
	// �ػ�
	Invalidate();
}

void CDlgZhexianbianhuan::OnKillfocusEditX2() 
{
	// ����
	UpdateData(TRUE);
	
	// �ж��Ƿ����޳�������
	if (m_bX1 > m_bX2)
	{
		// ����
		BYTE bTemp = m_bX1;
		m_bX1 = m_bX2;
		m_bX2 = bTemp;
		
		// ����
		UpdateData(FALSE);
	}
	
	// �ػ�
	Invalidate();
}

void CDlgZhexianbianhuan::OnKillfocusEditY1() 
{
	UpdateData(TRUE);
	
	// �ж��Ƿ����޳�������
	if (m_bY1 > m_bY2)
	{
		// ����
		BYTE	bTemp = m_bY1;
		m_bY1 = m_bY2;
		m_bY2 = bTemp;
		
		// ����
		UpdateData(FALSE);
	}
	
	// �ػ�
	Invalidate();
}

void CDlgZhexianbianhuan::OnKillfocusEditY2() 
{
	// ����
	UpdateData(TRUE);
	
	// �ж��Ƿ����޳�������
	if (m_bY1 > m_bY2)
	{
		// ����
		BYTE bTemp = m_bY1;
		m_bY1 = m_bY2;
		m_bY2 = bTemp;
		
		// ����
		UpdateData(FALSE);
	}
	
	// �ػ�
	Invalidate();
}

void CDlgZhexianbianhuan::OnPaint() 
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
	pPenRed->CreatePen(PS_SOLID, 2, RGB(255,0,0));
	
	// �������ʶ���
	CPen* pPenBlue = new CPen;
	
	// ��ɫ����
	pPenBlue->CreatePen(PS_SOLID, 1, RGB(0,0, 255));
	
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
	pDC->SelectObject(pPenBlue);	
	
	// ��������ֵ
	str.Format("(%d, %d)", m_bX1, m_bY1);
	pDC->TextOut(m_bX1 + 10, 281 - m_bY1, str);
	str.Format("(%d, %d)", m_bX2, m_bY2);
	pDC->TextOut(m_bX2 + 10, 281 - m_bY2, str);
	
	// �����û�ָ���ı任ֱ��
	pDC->MoveTo(10, 280);
	pDC->LineTo(m_bX1 + 10, 280 - m_bY1);
	pDC->LineTo(m_bX2 + 10, 280 - m_bY2);
	pDC->LineTo(265, 25);
	
	// ���Ƶ��Ե��С����
	CBrush  brush;
	brush.CreateSolidBrush(RGB(0,255,0));
	
	// ѡ��ˢ��
	CGdiObject* pOldBrush = pDC->SelectObject(&brush);
	
	// ����С����
	pDC->Rectangle(m_bX1 + 10 - 2, 280 - m_bY1 - 2, m_bX1 + 12, 280 - m_bY1 + 2);
	pDC->Rectangle(m_bX2 + 10 - 2, 280 - m_bY2 - 2, m_bX2 + 12, 280 - m_bY2 + 2);
	
	// �ָ���ǰ�Ļ���
	pDC->SelectObject(pOldPen);	
	
	// ���Ʊ�Ե
	pDC->MoveTo(10,25);
	pDC->LineTo(265,25);
	pDC->LineTo(265,280);
	
	// ɾ���µĻ���
	delete pPenRed;
	delete pPenBlue;
	
	// Do not call CDialog::OnPaint() for painting messages
}
