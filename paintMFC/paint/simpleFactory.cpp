#include "stdafx.h"
#include "simpleFactory.h"


std::unique_ptr<BasicPaintType> SimpleFactory::createFigureInstance(CString typeName)
{
	if (typeName == L"PPoint")
		return std::unique_ptr<PPoint>(new PPoint());

	if (typeName == L"PLine")
		return  std::unique_ptr<PLine>(new PLine());

	if (typeName == L"PEllipse")
		return  std::unique_ptr<PEllipse>(new PEllipse());

	if (typeName == L"PRectangle")
		return  std::unique_ptr<PRectangle>(new PRectangle());

	if (typeName == L"PEraser")
		return  std::unique_ptr<PEraser>(new PEraser());

	return nullptr;
}

SimpleFactory::SimpleFactory()
{
}


SimpleFactory::~SimpleFactory()
{
}
