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
	void inRange(pair<double, double>, pair<double, double>, TreeNode*);
	bool isInRange(double,double,double,double,TreeNode*);

public:
	BinaryTree();
	~BinaryTree();

	// add and check if already in tree
	void add(City*);
	bool checkCoordinates(pair<double, double> coordinates);
	int height();
	void inOrderTransversal();

	void deleteNode(string);
	bool search(string);

	void inRange(pair<double, double>, pair<double, double>);
};