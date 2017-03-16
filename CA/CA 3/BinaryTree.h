#pragma once
#include "TreeNode.h"

class BinaryTree {

private:

	TreeNode* root;
	void add(TreeNode*, TreeNode*);
	bool checkIFInTree(City*, TreeNode*);
	int height(TreeNode*);
	bool isLeaf(TreeNode*);
	void inOrderTransversal(TreeNode*);

public:
	BinaryTree();
	~BinaryTree();

	// add and check if already in tree
	void add(City*);
	int height();
	void inOrderTransversal();
};