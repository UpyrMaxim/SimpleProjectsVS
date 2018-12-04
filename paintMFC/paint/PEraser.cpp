#include "stdafx.h"
#include "PEraser.h"


void PEraser::mouseDown(CPoint &point, CpaintDoc * doc, unsigned long color, int width)
{
	MyFigure.frstP.x = point.x - width * 20;
	MyFigure.frstP.y = point.y - width * 20;
	MyFigure.color = RGB(255,255,255);
	MyFigure.width = width;
}

bool PEraser::mouseMove(CPoint & point, CpaintDoc * doc)
{
	MyFigure.color = RGB(255, 255, 255);
	doc->addPoint(MyFigure);
	MyFigure.frstP.x = point.x - MyFigure.width * 20;
	MyFigure.frstP.y = point.y - MyFigure.width * 20;
	return true;
}

void PEraser::mouseUp(CPoint &, CpaintDoc * doc)
{
}

void PEraser::Draw(CDC * pDC, const figure & Figire)
{
	pDC->Ellipse(Figire.frstP.x, Figire.frstP.y, Figire.secP.x, Figire.secP.y);
}

PEraser::PEraser()
{
	MyFigure.figureName = L"PEraser";
}


PEraser::~PEraser()
{
}
