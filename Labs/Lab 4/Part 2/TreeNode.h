#pragma once
class TreeNode {

	friend class BinaryTree;

private:

	TreeNode *left;
	int number;
	TreeNode *right;

public:
	TreeNode(int);
	~TreeNode();
};