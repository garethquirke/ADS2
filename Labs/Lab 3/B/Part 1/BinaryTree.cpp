#include <iostream>
#include <ctime>
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
			root->right == node;
		}
		else {
			add(node, root->right);
		}
	}
}
/*
Source: Maths HWS EDU
Usage: used
Availible From: http://math.hws.edu/eck/cs225/s03/binary_trees/
*/
int BinaryTree::height(TreeNode *root)
{
	// check for empty tree
	if (root == NULL) {
		return 0;
	}
	else {
		// count the first node at the root
		int count = 1;
		// count subtree nodes
		count += height(root->left);
		count += height(root->right);
		return count;
	}
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
	// start at root, recursively span across the tree
	return height(root);
}
