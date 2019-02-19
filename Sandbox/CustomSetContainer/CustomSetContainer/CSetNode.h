#pragma once
using namespace std;

template <class KeyType>
class CSetNode
{
public:
	CSetNode* LeftChild;
	CSetNode* RightChild;

	bool isRed() { return is_red; }
	void setKey(const KeyType& param) { key = param; }
	void getKey() { return key; }

	CSetNode* getLeftChild() { return LeftChild; }
	CSetNode* getRightChild() { return RightChild; }

	CSetNode(const KeyType& param) : key(param), is_red(false) {}
	CSetNode() = default;
	~CSetNode() = default;
private:
	bool is_red;
	KeyType key;
};
