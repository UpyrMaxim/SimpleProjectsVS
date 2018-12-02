#include "stdafx.h"
#include "BasicPaintType.h"


BasicPaintType::BasicPaintType(unsigned long color, int width)
{

	MyFigure.color = color;
	MyFigure.width = width;
}


BasicPaintType::~BasicPaintType()
{
}

//void BasicPaintType::mouseDown()
//{
//}
//
//void BasicPaintType::mouseMove()
//{
//}
//
//void BasicPaintType::mouseUp()
//{
//}

void BasicPaintType::SetColor(unsigned long color)
{
	MyFigure.color = color;
}

void BasicPaintType::SetWidth(int width)
{
	MyFigure.width = width;
}

const figure & BasicPaintType::GetFigure()
{
	// TODO: insert return statement here
	return MyFigure;
}