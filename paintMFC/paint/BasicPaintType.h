#pragma once
#include "paintDoc.h"

//
//struct figure
//{
//	CPoint frstP;
//	CPoint secP;
//	unsigned long color;
//	int width;
//	CString figureName;
//};

class CpaintDoc;

class BasicPaintType
{
public:
	BasicPaintType();
	virtual ~BasicPaintType();
	virtual void mouseDown(CPoint &, CpaintDoc* doc, unsigned long color = 0, int width = 1) = 0;
	virtual bool mouseMove(CPoint &, CpaintDoc* doc) = 0;
	virtual void mouseUp(CPoint &,CpaintDoc* doc) = 0;
	virtual void Draw(CDC* pDC, const figure& Figire) = 0;
	void SetColor(unsigned long);
	void SetWidth(int);
	const figure & GetFigure();

protected:
	figure MyFigure;
};

