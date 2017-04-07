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

	TreeNode* deleteNode(TreeNode*, string);
	TreeNode* minValue(TreeNode*);

	bool search(TreeNode*, string);
	bool searchByCo(TreeNode*, pair<double, double>);

public:
	BinaryTree();
	~BinaryTree();

	// add and check if already in tree
	void add(City*);
	int height();
	void inOrderTransversal();

	void deleteNode(string);
	bool search(string);
	bool searchByCo(double, double);
};