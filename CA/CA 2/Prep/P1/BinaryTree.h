#pragma once
#include <iostream>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

template<typename T>
class BinaryTree {

private:
	TreeNode<T> *root;

	void add(TreeNode<T> *node, TreeNode<T> *root);
	int height(TreeNode<T> *root);

	void inOrderTransversal(TreeNode<T> *root);
	void preOrderTransversal(TreeNode<T> *root);
	void postOrderTransversal(TreeNode<T> *root);

public:
	BinaryTree();
	~BinaryTree();

	void add(T data);
	int height();

	void inOrderTransversal();
	void preOrderTransversal();
	void postOrderTransversal();

};

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
inline void BinaryTree<T>::inOrderTransversal(TreeNode<T>* root)
{
	if (root != NULL) {
		inOrderTransversal(root->left);
		cout << root->data << ",";
		inOrderTransversal(root->right);
	}
}

template<typename T>
inline void BinaryTree<T>::preOrderTransversal(TreeNode<T>* root)
{
	if (root != NULL) {
		cout << root->data << ",";
		preOrderTransversal(root->left);
		preOrderTransversal(root->right);
	}
}

template<typename T>
inline void BinaryTree<T>::postOrderTransversal(TreeNode<T>* root)
{
	if (root != NULL) {
		postOrderTransversal(root->left);
		postOrderTransversal(root->right);
		cout << root->data << ",";
	}
}

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
		return;
	}
	else {
		add(node, root);
	}
}

template<typename T>
inline int BinaryTree<T>::height()
{
	return height(root);
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