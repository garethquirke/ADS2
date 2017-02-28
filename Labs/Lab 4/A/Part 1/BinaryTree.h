#pragma once
#include "TreeNode.h"

class BinaryTree {

private:
	TreeNode *root;
	void add(TreeNode*, TreeNode*);
	int height(TreeNode*);
	bool search(char, TreeNode*);

	void InOrderTransverse(TreeNode*);
	void PreOrderTransverse(TreeNode*);
	void PostOrderTransverse(TreeNode*);

public:
	BinaryTree();
	~BinaryTree();

	void add(char);
	int height();
	bool search(char);

	void sortInOrder();
	void sortPreOrder();
	void sortPostOrder();
};

/*
Notes:
Traversal is a process to visit all the nodes of a tree and may print
their values too. Because, all nodes are connected via edges (links) we
always start from the root (head) node. That is, we cannot randomly access
a node in a tree. There are three ways which we use to traverse a tree −

In-order Traversal (left,root,right) -> results in ascending order
Pre-order Traversal (root, left, right)
Post-order Traversal (left, right, root)
*/