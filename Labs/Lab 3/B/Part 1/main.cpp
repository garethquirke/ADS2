// Author: Gareth Quirke
// Date: 20th February 2017
#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

int main() {
	BinaryTree tree;
	
	tree.add(10);
	tree.add(15);
	tree.add(5);
	tree.add(25);

	cout << tree.height() << endl;

	system("pause");
	return 0;
}