#include "stdafx.h"
#include "simpleFactory.h"


BasicPaintType* SimpleFactory::createFigureInstance(CString typeName)
{
	if (typeName == L"PPoint")
		return new PPoint();

	if (typeName == L"PLine")
		return new PLine();

	if (typeName == L"PEllipse")
		return new PEllipse();

	if (typeName == L"PRectangle")
		return new PRectangle();

	if (typeName == L"PEraser")
		return new PEraser();

	return nullptr;
}

SimpleFactory::SimpleFactory()
{
}


SimpleFactory::~SimpleFactory()
{
}
