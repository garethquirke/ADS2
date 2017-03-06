#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

int main() {


	BinaryTree tree;
	tree.add(5);
	tree.add(4);
	tree.add(8);
	tree.add(11);
	tree.add(13);
	tree.add(4);
	tree.add(7);
	tree.add(2);
	tree.add(1);

	cout << "Height: " << tree.height() << endl << endl;
	bool result;

	// 0: false, 1:true
	result = tree.hasPathSum(20);
	cout << result << endl;
	result = tree.hasPathSum(9);
	cout << result << endl;;
	result = tree.hasPathSum(14);
	cout << result << endl;
	result = tree.hasPathSum(10);
	cout << result << endl;
	cout << endl;

	tree.printPaths();
	cout << endl;

	cout << "Lab4 B extensions" << endl;
	cout << "Minimum value found in tree: " << tree.minValue() << endl;
	cout << "Maximum value found in tree: " << tree.maxValue() << endl;
	cout << "Is BST? 0: no, 1: yes" << endl;
	cout << "using the helper methods (Uneffecient)" << endl;
	cout << tree.isBst() << endl;
	cout << "Using effiecient version" << endl;
	cout << tree.isBSTEff() << endl;

	system("pause");
	return 0;
}