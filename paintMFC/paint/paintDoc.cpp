
// paintDoc.cpp : implementation of the CpaintDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "paint.h"
#endif

#include "paintDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CpaintDoc

IMPLEMENT_DYNCREATE(CpaintDoc, CDocument)

BEGIN_MESSAGE_MAP(CpaintDoc, CDocument)
END_MESSAGE_MAP()


// CpaintDoc construction/destruction

CpaintDoc::CpaintDoc() noexcept
{
	// TODO: add one-time construction code here

}

CpaintDoc::~CpaintDoc()
{
}

BOOL CpaintDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_figures.clear();
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CpaintDoc serialization

void CpaintDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here


		int size = m_figures.size();
		ar << size;
		for each (auto point in m_figures)
		{
			ar << point.color;
			ar << point.figureName;
			ar << point.width;
			ar << point.frstP;
			ar << point.secP;
			ar << point.color;}
	}
	else
	{
		// TODO: add loading code here


		m_figures.clear();

		int size;
		ar >> size;
		figure point;
		for(int i = 0; i < size; i++)
		{
			ar >> point.color;
			ar >> point.figureName;
			ar >> point.width;
			ar >> point.frstP;
			ar >> point.secP;
			ar >> point.color;
			m_figures.push_back(point);
		}
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CpaintDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CpaintDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CpaintDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CpaintDoc diagnostics

#ifdef _DEBUG
void CpaintDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CpaintDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}

#endif //_DEBUG


// CpaintDoc commands
void CpaintDoc::addPoint(const figure point)
{
	m_figures.push_back(point);
}
const std::vector<figure> & CpaintDoc::getVector()
{
	return m_figures;
}