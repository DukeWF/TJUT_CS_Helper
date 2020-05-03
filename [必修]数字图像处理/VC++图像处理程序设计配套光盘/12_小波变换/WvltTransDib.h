// WvltTrans.h: interface for the CWvltTrans class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WVLTTRANS_H__ADB84B9A_B6D4_4770_B795_CCC4F2554D50__INCLUDED_)
#define AFX_WVLTTRANS_H__ADB84B9A_B6D4_4770_B795_CCC4F2554D50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Cdib.h"
#include "math.h"
class CWvltTransDib :public CDib  
{
public:
	//void GetDucument();
	CWvltTransDib();
	virtual ~CWvltTransDib();

public:
	void HighFilter(int n);
	void LowFilter(int n);
	void IDWT(int n);
	void Once(int n);
	void Liebianhuan();
	void Hangbianhuan();
	//ͼ��С���任����任
	//����С���任
	//����С���任
	//һ��С���任
	//��ֱ�����С���任
	//ˮƽ�����С���任


};


#endif // !defined(AFX_WVLTTRANS_H__ADB84B9A_B6D4_4770_B795_CCC4F2554D50__INCLUDED_)
