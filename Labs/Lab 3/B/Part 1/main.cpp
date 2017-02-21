// Author: Gareth Quirke
// Date: 20th February 2017
#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

int main() {
	BinaryTree tree;

	tree.add(5);
	tree.add(4);
	tree.add(7);
	tree.add(2);
	tree.add(6);

	cout << tree.height();

	system("pause");
	return 0;
}