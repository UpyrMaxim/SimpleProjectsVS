#include "stdafx.h"
#include "PEraser.h"


void PEraser::mouseDown(CPoint &point, CpaintDoc * doc, unsigned long color, int width)
{
	MyFigure.frstP.x = point.x - width * 10;
	MyFigure.frstP.y = point.y - width * 10;
	MyFigure.color = RGB(255,255,255);
	MyFigure.width = width;
}

void PEraser::mouseMove(CPoint & point, CpaintDoc * doc, unsigned long color, int width)
{
	MyFigure.color = RGB(255, 255, 255);
	MyFigure.secP.x = point.x + width * 10;
	MyFigure.secP.y = point.y + width * 10;
	doc->addPoint(MyFigure);
	MyFigure.frstP.x = point.x - width * 10;
	MyFigure.frstP.y = point.y - width * 10;
}

void PEraser::mouseUp(CPoint &, CpaintDoc * doc, unsigned long color, int width)
{
}

void PEraser::Draw(CDC * pDC, const figure & Figire)
{
	pDC->Ellipse(Figire.frstP.x, Figire.frstP.y, Figire.secP.x, Figire.secP.y);
}

PEraser::PEraser(unsigned long color, int width) : BasicPaintType(color, width)
{
	MyFigure.figureName = L"PEraser";
}


PEraser::~PEraser()
{
}
