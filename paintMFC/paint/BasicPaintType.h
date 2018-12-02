#pragma once
#include "paintDoc.h"


struct figure
{
	CPoint frstP;
	CPoint secP;
	unsigned long color;
	int width;
};


class BasicPaintType
{
public:
	BasicPaintType();
	~BasicPaintType();
	virtual void mouseDown() = 0;
	virtual void mouseMove() = 0;
	virtual void mouseUp() = 0;
	const figure & GetFigure();

private:
	figure MyFigure;
	CpaintDoc* pDoc;
};

