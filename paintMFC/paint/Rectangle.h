#pragma once
#include "BasicPaintType.h"
class PRectangle :
	public BasicPaintType
{
public:
	PRectangle(unsigned long color, int width);
	~PRectangle();
};

