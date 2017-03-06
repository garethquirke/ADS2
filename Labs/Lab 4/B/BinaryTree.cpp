#include "BinaryTree.h"
#include <iostream>
#include <algorithm>
using namespace std;

void BinaryTree::add(TreeNode *node, TreeNode *root)
{
	if (node->number < root->number) {
		if (root->left == NULL) {
			root->left = node;
		}
		else {
			add(node, root->left);
		}
	}
	else if (node->number > root->number) {
		if (root->right == NULL) {
			root->right = node;
		}
		else {
			add(node, root->right);
		}
	}
}

int BinaryTree::height(TreeNode *root)
{

	if (root == NULL) {
		return -1;
	}

	// return 1 and then recursively run this method again based on the higher value of either side
	else {
		return 1 + max(height(root->left), height(root->right));
	}
}

BinaryTree::~BinaryTree()
{
	root = NULL;
}

BinaryTree::BinaryTree() : root(NULL)
{
}

void BinaryTree::add(int number)
{
	TreeNode *node = new TreeNode(number);
	if (root == NULL) {
		root = node;
		return;
	}
	else {
		add(node, root);
	}
}

int BinaryTree::height()
{
	return height(root);
}