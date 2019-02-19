#pragma once
#include "CSetNode.h"

template <class KeyType>
class CSet
{
public:
	CSet();
	~CSet();
	int push(KeyType &);
private:
	CSetNode<KeyType> root;
};

