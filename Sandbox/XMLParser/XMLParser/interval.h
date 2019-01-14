#pragma once
class interval
{
public:
	typedef unsigned int uint;

	interval(uint l, uint r) :
		leftLimit(l),
		rightLimit(r)
	{}
	~interval() {}

	inline uint getLeft() const { return leftLimit; }
	inline uint getRight() const { return rightLimit; }
private:
	uint leftLimit;
	uint rightLimit;
};