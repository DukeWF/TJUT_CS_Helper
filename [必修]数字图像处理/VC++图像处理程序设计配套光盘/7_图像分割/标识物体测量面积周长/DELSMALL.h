#if !defined(AFX_DELSMALL_H__D42AF56A_17EC_4054_A131_CD4A30604464__INCLUDED_)
#define AFX_DELSMALL_H__D42AF56A_17EC_4054_A131_CD4A30604464__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DELSMALL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DELSMALL dialog

class DELSMALL : public CDialog
{
// Construction
public:
	DELSMALL(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DELSMALL)
	enum { IDD = IDD_DELSMALL_DLG };
	int		m_delsmall;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DELSMALL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DELSMALL)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELSMALL_H__D42AF56A_17EC_4054_A131_CD4A30604464__INCLUDED_)
