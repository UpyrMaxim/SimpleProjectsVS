#pragma once
class interval
{
public:
	typedef unsigned int uint;

	interval(uint left, uint right) : leftLimit(left), rightLimit(right)
	{}
	~interval() {}

	inline uint getLeft() const { return leftLimit; }
	inline uint getRight() const { return rightLimit; }
private:
	uint leftLimit;
	uint rightLimit;
};