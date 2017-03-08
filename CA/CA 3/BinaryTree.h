#pragma once
#include "TreeNode.h"

class BinaryTree {

private:

	TreeNode* root;
	void add(TreeNode*, TreeNode*);
	bool checkIFInTree(City*, TreeNode*);

public:
	BinaryTree();
	~BinaryTree();

	// add and check if already in tree
	void add(City*);
};