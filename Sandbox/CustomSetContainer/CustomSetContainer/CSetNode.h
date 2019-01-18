#pragma once

template <class KeyType>
class CSetNode
{
public:
	CSetNode * LeftChild;
	CSetNode * RightChild;

	bool isRed() { return isRed; }
	void setKey(const KeyType& param) { key = param; }
	void getKey() { return key; }

	CSetNode(const KeyType& param) : key(param), isRed(false) {}
	CSetNode() = default;
	~CSetNode() = default;
private:
	bool isRed;
	KeyType key;
};

