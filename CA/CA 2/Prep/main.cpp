#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;


int main() {
	
	BinaryTree<int> tree;
	tree.add(5);
	tree.add(8);
	tree.add(9);
	tree.add(10);
	tree.add(12);

	cout << tree.isLeaf();

	system("pause");
	return 0;
}