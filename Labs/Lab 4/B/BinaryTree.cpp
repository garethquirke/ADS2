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

int BinaryTree::hasPathSum(TreeNode *root, int sum)
{
	if (root == NULL) {
		return (sum == 0);
	}
	else {
		int summary = sum - root->number;
		return(hasPathSum(root->left, summary) || hasPathSum(root->right, summary));
	}
}

void printArray(int path[], int length) {
	for (int i = 0; i < length; i++) {
		cout << path[i] << ",";
	}
	cout << endl;
}

void BinaryTree::printPaths(TreeNode *root, int path[], int pathLength)
{
	if (root == NULL) {
		return;
	}

	path[pathLength] = root->number;
	pathLength++;

	if ((root->left == NULL) && (root->right == NULL)) {
		printArray(path, pathLength);
	}
	else {
		printPaths(root->left, path, pathLength);
		printPaths(root->right, path, pathLength);
	}
}

int BinaryTree::minValue(TreeNode *root)
{
	if (root->left == NULL) {
		return root->number;
	}
	minValue(root->left);
}

int BinaryTree::maxValue(TreeNode *root)
{
	if (root->right == NULL) {
		return root->number;	
	}
	maxValue(root->right);
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

bool BinaryTree::hasPathSum(int sum)
{
	return hasPathSum(root, sum);
}

void BinaryTree::printPaths()
{
	int path[1000];
	printPaths(root, path, 0);
}

int BinaryTree::minValue()
{
	if (root == NULL) {
		return 0;
	}
	return minValue(root);
}

int BinaryTree::maxValue()
{
	if (root == NULL) {
		return 0;
	}

	return maxValue(root);
}

int BinaryTree::isBst()
{
	return isBST(root);
}

int BinaryTree::isBSTEff()
{
	return(isBSTEff(root, INT_MIN, INT_MAX));
}

/*
Source: standford university binary trees
Availible From: cslibrary.stanford.edu/110/BinaryTrees.html
Usage: Used
*/

// Uses the helper functions min and max
int BinaryTree::isBST(TreeNode *root)
{
	if (root == NULL) {
		return 1;
	}

	/* To Check
	 * is the max on the left leaf greater than current?
	 * is the min on ghe right less than or equal to current?
	 */

	if (root->left != NULL && maxValue(root->left) > root->number) {
		return false;
	}

	if (root->right != NULL && minValue(root->right) <= root->number) {
		return false;
	}

	if (!isBST(root->left) || !isBST(root->right)) {
		return false;
	}

	return true;
}
/*
Same standord source, this time for the efficient version
*/
int BinaryTree::isBSTEff(TreeNode *root, int min, int max)
{
	if (root == NULL) {
		return true;
	}
	// false if this node violates the min/max constraint 
	if (root->number < min || root->number > max) return(false);

	// otherwise check the subtrees recursively, 
	// tightening the min or max constraint 
	return isBSTEff(root->left, min, root->number) && isBSTEff(root->right, root->number + 1, max);
		
}
