#include "stdafx.h"
#include "PRectangle.h"


void PRectangle::mouseDown(CPoint & point, CpaintDoc * doc, unsigned long color, int width)
{
	MyFigure.frstP = point;
	MyFigure.color = color;
	MyFigure.width = width;
}

bool PRectangle::mouseMove(CPoint &, CpaintDoc * doc)
{
	return false;
}

void PRectangle::mouseUp(CPoint & point, CpaintDoc * doc)
{
	MyFigure.secP = point;
	doc->addPoint(MyFigure);
}

void PRectangle::Draw(CDC * pDC, const figure & Figire)
{
	pDC->Rectangle(Figire.frstP.x, Figire.frstP.y, Figire.secP.x, Figire.secP.y);
}

PRectangle::PRectangle()
{
	MyFigure.figureName = L"PRectangle";
}


PRectangle::~PRectangle()
{
}
