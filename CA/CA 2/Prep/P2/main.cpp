#include<iostream>
#include "BinaryTree.h"
#include "TreeNode.h"
using namespace std;


int main() {

	BinaryTree<int> tree;

	tree.add(5);
	tree.add(4);
	tree.add(3);
	tree.add(2);
	tree.add(7);
	tree.add(6);
	tree.add(8);

	cout << tree.height() << endl;

	cout << "In order transversal" << endl;
	tree.inOrderTransversal();
	cout << endl;

	cout << "Pre order transversal" << endl;
	tree.preOrderTransversal();
	cout << endl;

	cout << "Post order transversal" << endl;
	tree.postOrderTransversal();
	cout << endl;

	bool twelve, eight;
	twelve = tree.find(12);
	eight = tree.find(8);
	cout << twelve << " " << eight << endl;


	system("pause");
	return 0;
}