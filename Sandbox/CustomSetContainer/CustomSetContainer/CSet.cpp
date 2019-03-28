#include "pch.h"
#include "CSet.h"

template<class KeyType, class DataType>
inline CSet<KeyType, DataType>::CSet()
{
}

template<class KeyType, class DataType>
inline CSet<KeyType, DataType>::~CSet()
{
}

template<class KeyType, class DataType>
inline int CSet<KeyType, DataType>::push(KeyType &)
{
	return 0;
}

template<class KeyType, class DataType>
inline DataType & CSet<KeyType, DataType>::find(KeyType & Key)
{
	CSet tmpNode = root;
	while (tmpNode != nullptr)
	{
		if (tmpNode.getKey() == Key)
			return tmpNode.getContent();
		if (tmpNode.getKey() > Key)
			tmpNode = tmpNode.getLeftChild();
		if (tmpNode.getKey() < Key)
			tmpNode = tmpNode.getRightChild();
	}

	// need to return smth ^(
}