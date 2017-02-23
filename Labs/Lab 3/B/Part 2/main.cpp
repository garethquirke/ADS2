#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

// search function
void result(char letter, BinaryTree t) {
	bool result;
	result = t.search(letter);
	if (result == true) {
		cout << letter << " was found" << endl;
	}
	else {
		cout << letter << " was not found" << endl;
	}
}

int main() {
	BinaryTree tree;

	tree.add('m');
	tree.add('j');
	tree.add('a');
	tree.add('l');
	tree.add('k');
	tree.add('o');
	tree.add('p');
	tree.add('h');
	tree.add('r');
	tree.add('v');
	cout << "Height of tree: " << tree.height() << endl;

	result('y', tree);
	result('v', tree);
	cout << endl << endl;
	cout << "in order sort" << endl;
	tree.sort();



	system("pause");
	return 0;
}