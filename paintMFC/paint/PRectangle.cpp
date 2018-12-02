#include "stdafx.h"
#include "PRectangle.h"


void PRectangle::mouseDown(CPoint & point, CpaintDoc * doc, unsigned long color, int width)
{
	MyFigure.frstP = point;
	MyFigure.color = color;
	MyFigure.width = width;
}

void PRectangle::mouseMove(CPoint &, CpaintDoc * doc, unsigned long color, int width)
{
}

void PRectangle::mouseUp(CPoint & point, CpaintDoc * doc, unsigned long color, int width)
{
	MyFigure.color = color;
	MyFigure.width = width;
	MyFigure.secP = point;
	doc->addPoint(MyFigure);
}

void PRectangle::Draw(CDC * pDC, const figure & Figire)
{
	pDC->Rectangle(Figire.frstP.x, Figire.frstP.y, Figire.secP.x, Figire.secP.y);
}

PRectangle::PRectangle(unsigned long color, int width) : BasicPaintType(color, width)
{
	MyFigure.figureName = L"PRectangle";
}


PRectangle::~PRectangle()
{
}
