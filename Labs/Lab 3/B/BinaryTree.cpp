#include <iostream>
#include "BinaryTree.h"
#include "TreeNode.h"
using namespace std;

// Private recursive methods add and height
void BinaryTree::add(TreeNode *, TreeNode *)
{
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
}

int BinaryTree::height()
{
	// start at root, recursively span across the tree
	return height(root);
}
