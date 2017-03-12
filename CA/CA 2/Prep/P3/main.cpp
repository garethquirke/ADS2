#include <iostream>
#include "BinaryTree.h"
#include "TreeNode.h"
using namespace std;



int main() {

	BinaryTree<int> tree;


	tree.add(5);
	tree.add(4);
	tree.add(3);
	tree.add(2);
	tree.add(1);
	tree.add(7);
	tree.add(8);
	tree.add(9);
	tree.add(10);


	cout << tree.height() << endl;

	bool f = tree.find(10);
	cout << f << endl;


	cout << "height using isLeaf()" << endl;
	cout << tree.heightisLeaf() << endl;

	system("pause");
	return 0;
}