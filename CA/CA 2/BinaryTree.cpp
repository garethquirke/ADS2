#include "BinaryTree.h"

void BinaryTree::add(TreeNode *node, TreeNode *root)
{
	// check if in tree first
	bool verify = checkIFInTree(node->city, root);
	if (verify == true) {
		cout << "Co-Ordinates already exsist in tree" << endl;
	}
	else {
		if (node->city->getName() < root->city->getName()) {
			if (root->left == NULL) {
				root->left = node;
			}
			else {
				add(node, root->left);
			}
		}
		else if (node->city->getName() > root->city->getName()) {
			if (root->right == NULL) {
				root->right = node;
			}
			else {
				add(node, root->right);
			}
		}
	}	
}

/*
Source: http://cslibrary.stanford.edu/110/BinaryTrees.html
Name: Binary tree lookup, stanford university
Usage: Based on
*/
bool BinaryTree::checkIFInTree(City* city,TreeNode *root)
{
	if (root == NULL) {
		return false;
	}
	else if (city->getCoordinates().first  == root->city->getCoordinates().first) {
		return true;
	}
	else if (city->getCoordinates().second == root->city->getCoordinates().second) {
		return true;
	}
	else {
		if (city->getName() < root->city->getName()) {
			return checkIFInTree(city, root->left);
		}
		else {
			return checkIFInTree(city, root->right);
		}
	}
}

BinaryTree::BinaryTree()  : root(NULL)
{
}

BinaryTree::~BinaryTree()
{
	root = NULL;
}

void BinaryTree::add(City* city)
{
	TreeNode *node = new TreeNode(city);
	if (root == NULL) {
		root = node;
	}

	else {
		add(node, root);
	}
}
