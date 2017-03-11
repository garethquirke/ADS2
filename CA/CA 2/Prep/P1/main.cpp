#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;


int main() {
	
	BinaryTree<int> tree;
	tree.add(5);
	tree.add(8);
	tree.add(2);
	tree.add(9);
	tree.add(10);
	tree.add(12);


	cout << "Height" << endl;
	cout << tree.height() << endl;

	cout << "In order" << endl;
	tree.inOrderTransversal();
	cout << endl;

	cout << "Pre Order transversal" << endl;
	tree.preOrderTransversal();
	cout << endl;

	cout << "Post order transversal" << endl;
	tree.postOrderTransversal();
	cout << endl;

	system("pause");
	return 0;
}