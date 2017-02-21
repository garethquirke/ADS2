#pragma once
#include "TreeNode.h"
// the binary tree maintains a pointer to the root/head of list
class BinaryTree {
	friend class TreeNode;
private:
	TreeNode *root;
	void add(TreeNode*, TreeNode*);
	int height(TreeNode*);
public:
	BinaryTree();

	// recursion methods
	void add(int);
	int height();
};