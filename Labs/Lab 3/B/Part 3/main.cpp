#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

// function to simlifity search test with template type T
template <class T>
void find(T data, BinaryTree<char> tree) {
	bool result;
	result = tree.search(data);

	if (result == true) {
		cout << "Query for: " << data << " was found" << endl;
	}
	else {
		cout << "Query for: " << data << "not found" << endl;
	}
}

int main() {


	BinaryTree<char> tree;
	tree.add('g');
	tree.add('r');
	tree.add('e');
	tree.add('p');

	cout << "Height: " << tree.height() << endl;
	cout << "Tree Sort" << endl;
	tree.sort();

	//find('g', tree);
	//find('a', tree);
	//find('r', tree);


	system("pause");
	return 0;
}