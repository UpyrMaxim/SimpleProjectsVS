#include "stdafx.h"
#include "simpleFactory.h"


std::shared_ptr<BasicPaintType> SimpleFactory::createFigureInstance(CString typeName)
{
	if (typeName == L"PPoint")
		return std::shared_ptr<PPoint>(new PPoint());

	if (typeName == L"PLine")
		return  std::shared_ptr<PLine>(new PLine());

	if (typeName == L"PEllipse")
		return  std::shared_ptr<PEllipse>(new PEllipse());

	if (typeName == L"PRectangle")
		return  std::shared_ptr<PRectangle>(new PRectangle());

	if (typeName == L"PEraser")
		return  std::shared_ptr<PEraser>(new PEraser());

	return nullptr;
}

SimpleFactory::SimpleFactory()
{
}


SimpleFactory::~SimpleFactory()
{
}
