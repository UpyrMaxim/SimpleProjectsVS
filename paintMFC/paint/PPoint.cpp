#include "stdafx.h"
#include "PPoint.h"


void PPoint::mouseDown(CPoint & point, CpaintDoc* doc, unsigned long color, int width )
{
	MyFigure.frstP = point;
	MyFigure.color = color;
	MyFigure.width = width;
}

bool PPoint::mouseMove(CPoint & point, CpaintDoc* doc)
{
	MyFigure.secP = point;
	doc->addPoint(MyFigure);
	MyFigure.frstP = point;
	return true;

}

void PPoint::mouseUp(CPoint & point, CpaintDoc* doc)
{
	MyFigure.secP = point;
	doc->addPoint(MyFigure);
}

void PPoint::Draw(CDC * pDC, const figure & Figire)
{
	pDC->MoveTo(Figire.frstP);
	pDC->LineTo(Figire.secP);
}

PPoint::PPoint()
{
	MyFigure.figureName = L"PPoint";
}


PPoint::~PPoint()
{
}
