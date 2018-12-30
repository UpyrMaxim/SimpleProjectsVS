#pragma once
#include "PPoint.h"
#include "PLine.h"
#include "PEllipse.h"
#include "PRectangle.h"
#include "PEraser.h"
#include <memory>

class SimpleFactory
{
public:
	std::unique_ptr<BasicPaintType> createFigureInstance(CString);
	SimpleFactory();
	~SimpleFactory();
};

