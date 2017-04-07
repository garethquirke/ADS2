#include "BinaryTree.h"
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

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
		cout << root->city;
		inOrderTransversal(root->right);
	}
}

/*
Source
Name: Association for Computing Machinery Blog
Usage: Based on
Availible from: https://helloacm.com/how-to-delete-a-node-from-a-binary-search-tree/
*/
TreeNode* BinaryTree::deleteNode(TreeNode *root, string city)
{
	if (root != NULL) {
		if (city < root->city->getName()) {
			root->left = deleteNode(root->left, city);
		}
		else if (city > root->city->getName()) {
			root->right = deleteNode(root->right, city);
		}

		else {
			if (isLeaf(root->left) && isLeaf(root->right)) {
				// no dingling nodes
				delete root;
				root = NULL;
			}

			else if (root->left == NULL) {
				// one dingling node on the right
				TreeNode *node = root;
				root = root->right;
				delete node;
				node = NULL;
			}

			else if (root->right == NULL) {
				// one dingling node on the left
				TreeNode *node = root;
				root = root->right;
				delete node;
				node = NULL;
			}

			else {
				// two dingling nodes
				TreeNode* node = minValue(root->right);
				root->city = node->city;
				root->right = deleteNode(root->right, node->city->getName());
			}
		}
	}
	return root;
}

TreeNode* BinaryTree::minValue(TreeNode *root)
{
	if (root == NULL) {
		return NULL;
	}
	else {
		if (root->left != NULL) {
			return minValue(root->left);
		}
		return root;
	}
}

// Search methods are based on the ones implemented in the previous labs
bool BinaryTree::search(TreeNode *root, string city)
{
	if (root == NULL) {
		return false;
	}
	else {
		if (root->city->getName() == city) {
			return true;
		}
		else if (city < root->city->getName()) {
			return search(root->left, city);
		}
		else if (city > root->city->getName()) {
			return search(root->right, city);
		}
	}
	return false;
}
/*
Source
*/
bool BinaryTree::searchByCo(TreeNode *root, pair<double, double> coordinates)
{
	if (root == NULL) {
		return false;
	}
	else {
		if (root->city->getCoordinates() == coordinates) {
			return true;
		}
		else {
			// search by left or right side till match and if it doesnt become a lost search ie null
			return searchByCo(root->left, coordinates) || searchByCo(root->right, coordinates);
		}
	}
	return false;
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

void BinaryTree::deleteNode(string city)
{
	deleteNode(root, city);
}

bool BinaryTree::search(string city)
{
	if (root == NULL) {
		return false;
	}
	else {
		return search(root, city);
	}
}

bool BinaryTree::searchByCo(double c1, double c2)
{
	if (root == NULL) {
		return false;
	}
	else {
		pair<double, double> coordinates;
		coordinates = make_pair(c1, c2);
		return searchByCo(root, coordinates);
	}
}
