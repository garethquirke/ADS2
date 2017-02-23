#pragma once
#include "BinaryTree.h"

template<typename T>
class TreeNode {

	template<class T>friend class BinaryTree;

private:
	TreeNode<T> *left;
	T data;
	TreeNode<T> *right;

public:
	TreeNode(T data);
	~TreeNode();
};

template<typename T>
inline TreeNode<T>::TreeNode(T data) : left(NULL), data(data), right(NULL)
{
}

template<typename T>
inline TreeNode<T>::~TreeNode()
{
	delete left;
	data = NULL;
	delete right;
}
