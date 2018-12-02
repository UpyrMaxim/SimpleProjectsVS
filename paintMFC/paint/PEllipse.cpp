#include "stdafx.h"
#include "PEllipse.h"


void PEllipse::mouseDown(CPoint & point, CpaintDoc * doc, unsigned long color, int width)
{
	MyFigure.frstP = point;
	MyFigure.color = color;
	MyFigure.width = width;
}

void PEllipse::mouseMove(CPoint &, CpaintDoc * doc, unsigned long color, int width)
{
}

void PEllipse::mouseUp(CPoint & point, CpaintDoc * doc, unsigned long color, int width)
{
	MyFigure.color = color;
	MyFigure.width = width;
	MyFigure.secP = point;
	doc->addPoint(MyFigure);
}

void PEllipse::Draw(CDC * pDC, const figure & Figire)
{
	pDC->Ellipse(Figire.frstP.x, Figire.frstP.y, Figire.secP.x, Figire.secP.y);
}

PEllipse::PEllipse(unsigned long color, int width) : BasicPaintType(color, width)
{
	MyFigure.figureName = L"PEllipse";
}


PEllipse::~PEllipse()
{
}
