#include "BinaryTree.h"
#include <algorithm>
#include <iostream>
using namespace std;

void BinaryTree::add(TreeNode *node, TreeNode *root)
{
	if (node->letter < root->letter) {
		if (root->left == NULL) {
			root->left = node;
		}
		else {
			add(node, root->left);
		}
	}
	else if (node->letter > root->letter) {
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
/*
Source: chqrlie's answer on stackoverflow
Availible from: http://stackoverflow.com/questions/245628/c-binary-search-tree-recursive-search-function
Usage: Based on 
*/
bool BinaryTree::search(char letter, TreeNode *root)
{
	if (root == NULL) {
		return false;
	}
	
	else if (root->letter == letter) {
		return true;
	}

	else if (root->letter > letter) {
		return search(letter,root->left);
	}

	else if (root->letter < letter) {
		return search(letter, root->right);
	}
}

void BinaryTree::InOrderTransverse(TreeNode *root)
{
	if (root != NULL) {
		InOrderTransverse(root->left);
		cout << root->letter << endl;
		InOrderTransverse(root->right);
	}
}

void BinaryTree::PreOrderTransverse(TreeNode *root)
{
	// pre order: visit root, left then right
	if (root == NULL) {
		return;
	}
	cout << root->letter << endl;
	PreOrderTransverse(root->left);
	PreOrderTransverse(root->right);
}

void BinaryTree::PostOrderTransverse(TreeNode *root)
{
	// left, right, root
	if (root == NULL) {
		return;
	}
	PostOrderTransverse(root->left);
	PostOrderTransverse(root->right);
	cout << root->letter << endl;
}

BinaryTree::BinaryTree(): root(NULL)
{
}

BinaryTree::~BinaryTree()
{
	root = NULL;
}

void BinaryTree::add(char letter)
{
	TreeNode *node = new TreeNode(letter);
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

bool BinaryTree::search(char letter)
{
	// call the recursive function, start at the root and return the findings of our quest
	return search(letter, root);
}

void BinaryTree::sortInOrder()
{
	// call the recursive method to sort in ascending order by the suitable transversal
	InOrderTransverse(root);
}

void BinaryTree::sortPreOrder()
{
	PreOrderTransverse(root);
}

void BinaryTree::sortPostOrder()
{
	PostOrderTransverse(root);
}
