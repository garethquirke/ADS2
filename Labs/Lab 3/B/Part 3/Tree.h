#pragma once

template<typename T>
class BinaryTree {
private:
	TreeNode<T> *root;

	void add(TreeNode<T> *node, TreeNode<T> *root);
	int height(TreeNode<T> *root);
	bool search(T query, TreeNode*root);
	void InOrderTransversal(TreeNode<T> *root);

public:
	BinaryTree();
	~BinaryTree();

	void add(T);
	bool search();
	int height();
	void sort();
};

// changes: adding in the same h file so the linker recognizes both templates
template<typename T>
class TreeNode {

private:
	TreeNode *left;
	T data;
	TreeNode *right;

public:
	TreeNode(T);
	~TreeNode();
};



template<type T>
void BinaryTree<T>::add(TreeNode *node, TreeNode *root)
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
int BinaryTree<T>::height(TreeNode *root)
{
	if (root == NULL) {
		return -1;
	}
	else {
		return 1 + max(height(root->left), height(root->right));
	}
}

template<typename T>
bool BinaryTree<T>::search(T query, TreeNode *start)
{
	if (start == NULL) {
		return false;
	}

	else if (start->data == query) {
		return search(data, start->left);
	}

	else if (root->data < query) {
		return search(data, start->right);
	}
}

template<typename T>
void BinaryTree<T>::InOrderTransversal(TreeNode *start)
{
	if (start != NULL) {
		InOrderTransversal(start->left);
		cout << start->data;
	}
}

template<typename T>
BinaryTree<T>::BinaryTree() : root(NULL)
{
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	delete root;
}

template<typename T>
void BinaryTree<T>::add(T data)
{
	TreeNode *node = new TreeNode(data);
	if (root == NULL) {
		root = node;
		return;
	}
	else {
		add(node, root);
	}
}

template<typename T>
bool BinaryTree<T>::search()
{
	return false;
}

template<typename T>
int BinaryTree<T>::height()
{
	return height(root);
}

template<typename T>
void BinaryTree<T>::sort()
{
	InOrderTransversal(root);
}





template<typename T>
inline TreeNode<T>::TreeNode(T dataIn)
{
	left = NULL;
	data = dataIn;
	right = NULL;
}

template<typename T>
inline TreeNode<T>::~TreeNode()
{
	delete left;
	delete data;
	delete right;
}
