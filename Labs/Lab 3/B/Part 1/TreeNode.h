#pragma once

class TreeNode {
	friend class BinaryTree;
private:
	// each node has a integer number and pointers to left & right
	TreeNode *left;
	int number;
	TreeNode *right;
public:
	TreeNode(int);
};