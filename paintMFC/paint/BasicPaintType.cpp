#include "stdafx.h"
#include "BasicPaintType.h"
#include <typeinfo>


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

const figure & BasicPaintType::GetFigure()
{
	// TODO: insert return statement here
	return MyFigure;
}
