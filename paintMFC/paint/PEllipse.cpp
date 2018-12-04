#include "stdafx.h"
#include "PEllipse.h"


void PEllipse::mouseDown(CPoint & point, CpaintDoc * doc, unsigned long color, int width)
{
	MyFigure.frstP = point;
	MyFigure.color = color;
	MyFigure.width = width;
}

bool PEllipse::mouseMove(CPoint &, CpaintDoc * doc)
{
	return false;
}

void PEllipse::mouseUp(CPoint & point, CpaintDoc * doc)
{
	MyFigure.secP = point;
	doc->addPoint(MyFigure);
}

void PEllipse::Draw(CDC * pDC, const figure & Figire)
{
	pDC->Ellipse(Figire.frstP.x, Figire.frstP.y, Figire.secP.x, Figire.secP.y);
}

PEllipse::PEllipse()
{
	MyFigure.figureName = L"PEllipse";
}


PEllipse::~PEllipse()
{
}
