#include "stdafx.h"
#include "PLine.h"


void PLine::mouseDown(CPoint & point, CpaintDoc * doc, unsigned long color, int width)
{
	MyFigure.frstP = point;
	MyFigure.color = color;
	MyFigure.width = width;
}

bool PLine::mouseMove(CPoint &, CpaintDoc * doc)
{
	return false;
}

void PLine::mouseUp(CPoint & point, CpaintDoc * doc)
{
	MyFigure.secP = point;
	doc->addPoint(MyFigure);
}

void PLine::Draw(CDC * pDC, const figure & Figire)
{
	pDC->MoveTo(Figire.frstP);
	pDC->LineTo(Figire.secP);
}

PLine::PLine()
{
	MyFigure.figureName = L"PLine";
}


PLine::~PLine()
{
}
