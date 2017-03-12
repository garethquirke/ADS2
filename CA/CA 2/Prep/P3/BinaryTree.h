#pragma once
#include "TreeNode.h"
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class BinaryTree {

private:

	TreeNode<T> *root;

	void add(TreeNode<T> *node, TreeNode<T> *root);
	int height(TreeNode<T> *root);
	int minValue(TreeNode<T> *root);
	int maxValue(TreeNode<T> *root);

	void inOrderTransversal(TreeNode<T> *root);
	void preOrderTransversal(TreeNode<T> *root);
	void postOrderTransversal(TreeNode<T> *root);

	bool find(T data, TreeNode<T> *root);

	bool isLeaf(TreeNode<T> *root);
	int heightisLeaf(TreeNode<T> *root);

public:

	BinaryTree();
	~BinaryTree();


	void add(T data);
	int height();
	int minValue();
	int maxValue();

	void inOrderTransversal();
	void preOrderTransversal();
	void postOrderTransversal();

	bool find(T data);

	// height with isLeaf used
	int heightisLeaf();

};

template<typename T>
inline BinaryTree<T>::BinaryTree() : root(NULL)
{
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	delete root;
}

template<typename T>
inline void BinaryTree<T>::add(T data)
{
	TreeNode<T> *node = new TreeNode<T>(data);

	if (root == NULL) {
		root = node;
	}

	add(node, root);
}

template<typename T>
inline int BinaryTree<T>::height()
{
	return height(root);
}

template<typename T>
inline int BinaryTree<T>::minValue()
{
	if (root == NULL) {
		return 0;
	}
	return minValue(root);
}

template<typename T>
inline int BinaryTree<T>::maxValue()
{
	if (root == NULL) {
		return 0;
	}
	return maxValue(root);
}

template<typename T>
inline void BinaryTree<T>::inOrderTransversal()
{
	inOrderTransversal(root);
}

template<typename T>
inline void BinaryTree<T>::preOrderTransversal()
{
	preOrderTransversal(root);
}

template<typename T>
inline void BinaryTree<T>::postOrderTransversal()
{
	postOrderTransversal(root);
}

template<typename T>
inline bool BinaryTree<T>::find(T data)
{
	if (root == NULL) {
		return false;
	}
	else {
		return find(data, root);
	}
}

template<typename T>
inline int BinaryTree<T>::heightisLeaf()
{
	return height(root);
}

template<typename T>
inline void BinaryTree<T>::add(TreeNode<T>* node, TreeNode<T>* root)
{
	if (node->data < root->data) {
		if (root->left == NULL) {
			root->left = node;
		}
		else {
			add(node, root->left);
		}
	}

	else if (node->data > root->data) {
		if (root->right == NULL) {
			root->right = node;
		}
		else {
			add(node, root->right);
		}
	}
}

template<typename T>
inline int BinaryTree<T>::height(TreeNode<T>* root)
{
	if (root == NULL) {
		return -1;
	}
	else {
		return 1 + max(height(root->left), height(root->right));
	}
}

template<typename T>
inline int BinaryTree<T>::minValue(TreeNode<T>* root)
{
	if (root->left == NULL) {
		return root->data;
	}
	minValue(root->left);
}

template<typename T>
inline int BinaryTree<T>::maxValue(TreeNode<T>* root)
{
	if (root->right == NULL) {
		return root->data;
	}
	maxValue(root->right);
}

template<typename T>
inline void BinaryTree<T>::inOrderTransversal(TreeNode<T>* root)
{
	inOrderTransversal(root->left);
	cout << root->data << ",";
	inOrderTransversal(root->right);
}

template<typename T>
inline void BinaryTree<T>::preOrderTransversal(TreeNode<T>* root)
{
	cout << root->data << ",";
	preOrderTransversal(root->left);
	preOrderTransversal(root->right);
}

template<typename T>
inline void BinaryTree<T>::postOrderTransversal(TreeNode<T>* root)
{
	postOrderTransversal(root->left);
	postOrderTransversal(root->right);
	cout << root->data << ",";
}

template<typename T>
inline bool BinaryTree<T>::find(T data, TreeNode<T>* root)
{
	if (root == NULL) {
		return false;
	}

	else {
		if (root->data == data) {
			return true;
		}

		else if (data < root->data) {
			return find(data, root->left);
		}
		else if (data > root->data) {
			return find(data, root->right);
		}
	}
	return false;
}

template<typename T>
inline bool BinaryTree<T>::isLeaf(TreeNode<T> *root)
{
	if (root == NULL) {
		return false;
	}
	else {
		if (root->left == NULL && root->right == NULL) {
			return true;
		}
	}
	return false;
}

template<typename T>
inline int BinaryTree<T>::heightisLeaf(TreeNode<T>* root)
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


