
// paintView.cpp : implementation of the CpaintView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "paint.h"
#endif

#include "paintDoc.h"
#include "paintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CpaintView

IMPLEMENT_DYNCREATE(CpaintView, CFormView)

BEGIN_MESSAGE_MAP(CpaintView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CpaintView construction/destruction

CpaintView::CpaintView() noexcept
	: CFormView(IDD_PAINT_FORM)
{
	// TODO: add construction code here

}

CpaintView::~CpaintView()
{
}

void CpaintView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CpaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CpaintView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CpaintView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CpaintView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CpaintView diagnostics

#ifdef _DEBUG
void CpaintView::AssertValid() const
{
	CFormView::AssertValid();
}

void CpaintView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CpaintDoc* CpaintView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CpaintDoc)));
	return (CpaintDoc*)m_pDocument;
}
#endif //_DEBUG


// CpaintView message handlers
