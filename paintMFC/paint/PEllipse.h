#pragma once
#include "BasicPaintType.h"
class PEllipse :
	public BasicPaintType
{
public:
	void mouseDown(CPoint &, CpaintDoc* doc, unsigned long color = 0, int width = 1) override;
	bool mouseMove(CPoint &, CpaintDoc* doc) override;
	void mouseUp(CPoint &, CpaintDoc* doc) override;
	void Draw(CDC* pDC, const figure& Figire) override;
	PEllipse();
	~PEllipse();
};

