#include "stdafx.h"
#include "PPoint.h"


void PPoint::mouseDown(CPoint & point, CpaintDoc* doc, unsigned long color, int width )
{
	MyFigure.frstP = point;
	MyFigure.color = color;
	MyFigure.width = width;
}

void PPoint::mouseMove(CPoint & point, CpaintDoc* doc, unsigned long color, int width)
{
	MyFigure.color = color;
	MyFigure.width = width;
	MyFigure.secP = point;
	doc->addPoint(MyFigure);
	MyFigure.frstP = point;

}

void PPoint::mouseUp(CPoint & point, CpaintDoc* doc, unsigned long color, int width)
{
	MyFigure.color = color;
	MyFigure.width = width;
	MyFigure.secP = point;
	doc->addPoint(MyFigure);
}

void PPoint::Draw(CDC * pDC, const figure & Figire)
{
	pDC->MoveTo(Figire.frstP);
	pDC->LineTo(Figire.secP);
}

PPoint::PPoint(unsigned long color, int width) : BasicPaintType(color, width)
{
	MyFigure.figureName = L"PPoint";
}


PPoint::~PPoint()
{
}
