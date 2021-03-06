//-----------------------------------------------------------------------//
// This is a part of the GuiLib MFC Extention.							 //	
// Autor  :  Francisco Campos											 //
// (C) 2002 Francisco Campos <www.beyondata.com> All rights reserved     //
// This code is provided "as is", with absolutely no warranty expressed  //
// or implied. Any use is at your own risk.								 //		
// You must obtain the author's consent before you can include this code //
// in a software library.												 //
// If the source code in  this file is used in any application			 //
// then acknowledgement must be made to the author of this program		 //	
// fcampos@tutopia.com													 //
//-----------------------------------------------------------------------//

#if !defined(AFX_GUIEDIT_H__176ADD8B_D16A_4814_B29B_7C5159982E70__INCLUDED_)
#define AFX_GUIEDIT_H__176ADD8B_D16A_4814_B29B_7C5159982E70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GuiEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGuiEdit window
#include "GuiLib.h"
#include "GuiButton.h"

class GUILIBDLLEXPORT CGuiEdit : public CEdit
{
// Construction
public:
	CGuiEdit();
	enum Mask{
		MASK_HOUR12=0,
		MASK_HOUR24=1,
		MASK_HOURFREE=2,
		MASK_IPADDRESS=3,
		MASK_DATEDDMMYYYY=4,
		MASK_DATEMMDDYYYY=5,
		MASK_DATEYYYYDDMM=6,
		MASK_DATEYYYYMMDD=7,
		MASK_FREEMASK=8
	};
// Attributes
public:
	void SetToolTip(LPCTSTR	lpMsg);
	BOOL AddButton(HICON hIcon,UINT nID,CMenu* m_menu=NULL,CString mToolTip=_T(""));
	void RecalLayout();
	void SetMask(CString mszMask,CString mszShowMask,Mask enTypeMask=MASK_FREEMASK);
	void ValidMask(UINT nChar);
	int  GetNextPos(int start);
	BOOL IsValidChar(UINT nChar,int nStartPos);
	BOOL ValSpecialKey(int nStartPos,	int nEndPos);
	BOOL IsPosMask(int StartPos);
	void DeleteString(int nStartPos,int  nEndPos );
	void AjustaCadena(int nStartPos,int  nEndPos );
	int  NumCharNoMask();
	int  FindLasCharR();
	void DeleteAndAjust(int nStartPos,int  nEndPos );
	int  DifCharReal(int start, int fin);
	BOOL IsValPos(UINT nChar,int pos);
	//CString GetMask();
// Operations
protected:
	virtual void PreSubclassWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	CGuiButton m_bnt;
	CToolTipCtrl m_tooltipCtrl;
	CString m_szMask;
	CString m_szShowMask;
	Mask    m_enMask;
	CString StrToUse;
	CString m_cadResult;
	int		m_KeySpecial;
public:
	virtual ~CGuiEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CGuiEdit)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnSysColorChange();
	afx_msg void OnNcPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUIEDIT_H__176ADD8B_D16A_4814_B29B_7C5159982E70__INCLUDED_)
