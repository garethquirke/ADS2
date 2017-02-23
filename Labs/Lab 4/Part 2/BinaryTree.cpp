#include <iostream>
#include <algorithm>
#include "BinaryTree.h"
#include "TreeNode.h"
using namespace std;

// Private recursive methods add and height
void BinaryTree::add(TreeNode *node, TreeNode *root)
{
	// work left to right
	if (node->number < root->number) {
		// left is empty add it 
		if (root->left == NULL) {
			root->left = node;
		}
		else {
			// recursive call working down the tree
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
/*
Source: height in C
Usage: used
Availible From: http://www.techcrashcourse.com/2016/06/program-to-find-height-of-binary-tree.html
*/
int BinaryTree::height(TreeNode *root)
{
	// check for empty tree
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + max(height(root->left), height(root->right));
	}
}

int BinaryTree::hasPathSum(TreeNode *root, int sum)
{
	if (root == NULL) {
		return false;
	}
	if (root->number == sum && root->right == NULL && root->left == NULL) {
		return true;
	}

	return hasPathSum(root->left,(sum - root->number) || (root->right , (sum - root->number)));
}


BinaryTree::BinaryTree() : root(NULL)
{
}

BinaryTree::~BinaryTree()
{
	delete root;
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
	// start at root, recursively span across the tree
	return height(root);
}

bool BinaryTree::hasSum(int sum)
{
	return hasPathSum(root, sum);
}
