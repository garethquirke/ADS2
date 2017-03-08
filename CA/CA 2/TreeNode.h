#pragma once
#include "City.h"

class TreeNode {

	friend class BinaryTree;

private:
	TreeNode *left;
	City *city;
	TreeNode *right;

public:
	TreeNode(City*);
	~TreeNode();

	bool isLeaf();
};