#pragma once

class TreeNode {

	friend class BinaryTree;
private:
	TreeNode *left;
	char letter;
	TreeNode *right;
public:
	TreeNode(char);
	~TreeNode();
};