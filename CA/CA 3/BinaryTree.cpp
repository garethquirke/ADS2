#include "BinaryTree.h"
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

/*
Note: 
Regarding sources, most methods below are based on previous labs I completed.
These were modified to suit the assignment of having a city object on the node
and the other requirements mentioned in the CA.

my original source for many of the methods was from stanford university and can
be accessed through the following URL: http://cslibrary.stanford.edu/110/BinaryTrees.html
*/

void BinaryTree::add(TreeNode *node, TreeNode *root)
{
	// check if in tree first
	bool verify = checkIFInTree(node->city, root);
	bool withinRange = checkCoordinates(node->city->getCoordinates());
	if (verify == true) {
		cout << "Co-Ordinates already exsist in tree" << endl;
	}
	else if (withinRange == false) {
		cout << "coordinate not within range" << endl;
		cout << "must be between 0 -> 90 and 0 to 180 degrees" << endl;
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

bool BinaryTree::checkCoordinates(pair<double,double> coordinates)
{
	if (coordinates.first >= 0 && coordinates.first <= 90 && coordinates.second >= 0 && coordinates.second <= 180) {
		//  latitude degrees will be in the northern hemisphere and all longitude degrees will be west of the Prime Meridian
		return true;
	}
	return false;
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

/*
Source: chqrlie's answer on stackoverflow
Availible from: http://stackoverflow.com/questions/245628/c-binary-search-tree-recursive-search-function
Usage: Based on
*/
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

void BinaryTree::inRange(pair<double, double> point, pair<double, double> distance, TreeNode *root)
{
	double x1 = point.first, y1 = point.second, x2 = distance.first, y2 = distance.second;
	bool check;
	/*
	|	     .(x2, y2)
	|       /
	|      /     **********************************
	|     /      Any points in here will be printed
	|    /       **********************************
	|   /
	|  .(x1,y1)
	|
	|_____________________________
	*/

	// in order transversal, if within specified range -> output it

	if (root != NULL) {
		
		inRange(point, distance, root->left);
		check = isInRange(x1, y1, x2, y2, root);
		if (check == true) {
			cout << root->city;
		}
		inRange(point, distance, root->right);
	}
}

bool BinaryTree::isInRange(double x1, double y1, double x2, double y2, TreeNode *node)
{
	int check = 0;

	if (node->city->getCoordinates().first >= x1) {
		check++;
	}
	if (node->city->getCoordinates().first <= x2) {
		check++;
	}
	if (node->city->getCoordinates().second >= y1) {
		check++;
	}
	if (node->city->getCoordinates().second <= y2) {
		check++;
	}


	if (check == 4) {
		return true;
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

void BinaryTree::inRange(pair<double, double> point, pair<double, double> distance)
{
	bool check = checkCoordinates(point);
	bool check2 = checkCoordinates(distance);
	if (check == true && check2 == true) {
		inRange(point, distance, root);
	}
	else {
		cout << "Not within correct range" << endl;
	}
}
