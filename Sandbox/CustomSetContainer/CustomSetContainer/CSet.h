#pragma once
#include "CSetNode.h"

template <class KeyType>
class CSet
{
public:
	CSet();
	~CSet();
private:
	CSetNode<KeyType> root;
};

