#include "stdafx.h"
#include "BasicPaintType.h"


BasicPaintType::BasicPaintType()
{
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