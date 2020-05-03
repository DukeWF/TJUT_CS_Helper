#include "stdafx.h"
#include "cdib.h"
#include "windowsx.h"
#include "math.h"
#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4) 

CDib::CDib()
{
	size=0;
}

CDib::~CDib()
{
    GlobalFreePtr(m_pBitmapInfo);
}

void CDib::LoadFile(const char* dibFileName)
{
   strcpy(m_fileName,dibFileName);
    CFile dibFile(m_fileName, CFile::modeRead);
    dibFile.Read((void*)&bitmapFileHeader,sizeof(BITMAPFILEHEADER));
    if (bitmapFileHeader.bfType == 0x4d42)
    {
        DWORD fileLength = dibFile.GetLength();    
         size = fileLength -sizeof(BITMAPFILEHEADER);
         pDib =(BYTE*)GlobalAllocPtr(GMEM_MOVEABLE, size);
        dibFile.Read((void*)pDib, size);
        dibFile.Close();
        m_pBitmapInfo = (BITMAPINFO*) pDib;
        m_pBitmapInfoHeader = (BITMAPINFOHEADER*) pDib;
        m_pRGB = (RGBQUAD*)(pDib +
			m_pBitmapInfoHeader->biSize);
        int m_numberOfColors = GetNumberOfColors();
        if (m_pBitmapInfoHeader->biClrUsed == 0)
            m_pBitmapInfoHeader->biClrUsed =
			    m_numberOfColors;
        DWORD colorTableSize = m_numberOfColors *
            sizeof(RGBQUAD);
        m_pData = pDib + m_pBitmapInfoHeader->biSize
            + colorTableSize;
		if (m_pRGB == (RGBQUAD*)m_pData) // No color table
			m_pRGB = NULL;
        m_pBitmapInfoHeader->biSizeImage = GetSize();
		m_valid = TRUE;
    }    
    else
    {
        m_valid = FALSE;
        AfxMessageBox("This isn't a bitmap file!");
    }
}

BOOL CDib::IsValid()
{
    return m_valid;
}
        
char* CDib::GetFileName()
{
    return m_fileName;
}
        
UINT CDib::GetWidth()
{
    return (UINT) m_pBitmapInfoHeader->biWidth;
}
        
UINT CDib::GetHeight()
{
    return (UINT) m_pBitmapInfoHeader->biHeight;
}
        
DWORD CDib::GetSize()
{
    if (m_pBitmapInfoHeader->biSizeImage != 0)
        return m_pBitmapInfoHeader->biSizeImage;
	else
    {
        DWORD height = (DWORD) GetHeight();
        DWORD width = (DWORD) GetWidth();
        return height * width;
    }
}

UINT CDib::GetNumberOfColors()
{
	int numberOfColors;

    if ((m_pBitmapInfoHeader->biClrUsed == 0) &&
          (m_pBitmapInfoHeader->biBitCount < 9))
	{
		switch (m_pBitmapInfoHeader->biBitCount)
		{
		    case 1: numberOfColors = 2; break;
		    case 4: numberOfColors = 16; break;
		    case 8: numberOfColors = 256;
		}
	}
    else
		numberOfColors = (int) m_pBitmapInfoHeader->biClrUsed;

    return numberOfColors;
}
    
BYTE* CDib::GetData()
{
    return m_pData;
}

RGBQUAD* CDib::GetRGB()
{
    return m_pRGB;
}

BITMAPINFO* CDib::GetInfo()
{
    return m_pBitmapInfo;
}

WORD CDib::PaletteSize(LPBYTE lpDIB) 
{ 
    return (DIBNumColors(lpDIB) * sizeof(RGBTRIPLE)); 
} 

WORD CDib::DIBNumColors(LPBYTE lpDIB) 
{ 
    WORD wBitCount;  // DIB bit count 
    wBitCount = ((LPBITMAPCOREHEADER)lpDIB)->bcBitCount; 
    switch (wBitCount) 
    { 
        case 1: 
            return 2; 
        case 4: 
            return 16; 
        case 8: 
            return 256; 
        default: 
            return 0; 
    } 
} 

void CDib::SaveFile(const CString filename)
{ 
   strcpy(m_fileName,filename);
    CFile dibFile(m_fileName, CFile::modeCreate|CFile::modeWrite);
    dibFile.Write((void*)&bitmapFileHeader,sizeof(BITMAPFILEHEADER));
    dibFile.Write((void*)pDib, size);
    dibFile.Close();

}