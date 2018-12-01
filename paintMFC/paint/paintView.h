
// paintView.h : interface of the CpaintView class
//

#pragma once


class CpaintView : public CFormView
{
protected: // create from serialization only
	CpaintView() noexcept;
	DECLARE_DYNCREATE(CpaintView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_PAINT_FORM };
#endif

// Attributes
public:
	CpaintDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CpaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in paintView.cpp
inline CpaintDoc* CpaintView::GetDocument() const
   { return reinterpret_cast<CpaintDoc*>(m_pDocument); }
#endif

