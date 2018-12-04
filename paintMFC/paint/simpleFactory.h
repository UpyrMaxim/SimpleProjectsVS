#pragma once
#include "PPoint.h"
#include "PLine.h"
#include "PEllipse.h"
#include "PRectangle.h"
#include "PEraser.h"

class SimpleFactory
{
public:
	BasicPaintType* createFigureInstance(CString);
	SimpleFactory();
	~SimpleFactory();
};

