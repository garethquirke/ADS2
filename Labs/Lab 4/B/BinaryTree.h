#pragma once
#include "TreeNode.h"

class BinaryTree {

private:
	TreeNode *root;
	void add(TreeNode*, TreeNode*);
	int height(TreeNode*);

public:
	~BinaryTree();
	BinaryTree();
	void add(int);
	int height();
};