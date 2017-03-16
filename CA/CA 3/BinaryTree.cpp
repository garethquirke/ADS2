#include "BinaryTree.h"
#include <algorithm>

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
bool BinaryTree::checkIFInTree(City* city, TreeNode *root)
{
	if (root == NULL) {
		return false;
	}
	else if (city->getCoordinates().first == root->city->getCoordinates().first) {
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

int BinaryTree::height(TreeNode *root)
{
	if (root == NULL) {
		return -1;
	}
	// TODO: clean code
	else if (isLeaf(root->left), isLeaf(root->right)) {
		return 1;
	}
	else {
		return 1 + max(height(root->left), height(root->right));
	}
}

bool BinaryTree::isLeaf(TreeNode *node)
{
	if (node == NULL) {
		return false;
	}
	else {
		if (node->left == NULL && node->right == NULL) {
			return true;
		}
	}
	return false;
}

void BinaryTree::inOrderTransversal(TreeNode *root)
{
	if (root != NULL) {
		inOrderTransversal(root->left);
		cout << root->city << endl;
		inOrderTransversal(root->right);
	}
}

	BinaryTree::BinaryTree() : root(NULL)
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

	int BinaryTree::height()
	{
		return height(root);
	}

	void BinaryTree::inOrderTransversal()
	{
		inOrderTransversal(root);
	}
