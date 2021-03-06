#pragma once
#include "TreeNode.h"

class BinaryTree {

private:
	TreeNode *root;
	void add(TreeNode*, TreeNode*);
	int height(TreeNode*);

	int hasPathSum(TreeNode*, int);
	void printPaths(TreeNode*, int path[], int pathLength);
	
public:
	~BinaryTree();
	BinaryTree();
	void add(int);
	int height();

	bool hasPathSum(int);
	void printPaths();
};