#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

int main() {


	BinaryTree<char> tree;
	tree.add('g');
	tree.add('r');
	tree.add('e');
	tree.add('p');

	cout << "Height: " << tree.height() << endl;
	cout << "Tree Sort" << endl;
	tree.sort();

	system("pause");
	return 0;
}