#pragma once
#include "BasicPaintType.h"
class PPoint :
	public BasicPaintType
{	
public:
	void mouseDown() override;
	void mouseMove() override;
	void mouseUp() override;
	PPoint();
	~PPoint();
};

