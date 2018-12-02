#include "stdafx.h"
#include "PLine.h"


void PLine::mouseDown(CPoint & point, CpaintDoc * doc, unsigned long color, int width)
{
	MyFigure.frstP = point;
	MyFigure.color = color;
	MyFigure.width = width;
}

void PLine::mouseMove(CPoint &, CpaintDoc * doc, unsigned long color, int width)
{
}

void PLine::mouseUp(CPoint & point, CpaintDoc * doc, unsigned long color, int width)
{
	MyFigure.color = color;
	MyFigure.width = width;
	MyFigure.secP = point;
	doc->addPoint(MyFigure);
}

void PLine::Draw(CDC * pDC, const figure & Figire)
{
	pDC->MoveTo(Figire.frstP);
	pDC->LineTo(Figire.secP);
}

PLine::PLine(unsigned long color, int width) : BasicPaintType(color, width)
{
	MyFigure.figureName = L"PLine";
}


PLine::~PLine()
{
}
