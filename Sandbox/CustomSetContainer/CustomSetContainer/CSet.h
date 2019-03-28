#pragma once
#include "CSetNode.h"

template <class KeyType,class DataType>
class CSet
{
public:
	CSet();
	~CSet();
	int push(KeyType &);
	DataType &find(KeyType &);
private:
	CSetNode<KeyType, DataType> root;
};


