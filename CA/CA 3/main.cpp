#include "City.h"
#include "BinaryTree.h"
#include "TreeNode.h"
#include <string>
#include <iostream>
using namespace std;

int main() {

	City c1("Dublin", make_pair(53.3498, 6.2603), 4500, 14.8);
	City c2("Aberdeen", make_pair(41.9, 76.8), 5000, 12.4);
	cout << c1 << endl;
	cout << c2 << endl;

	BinaryTree tree;

	City* dublin = &c1;
	City* aberdeen = &c2;

	tree.add(dublin);
	tree.add(aberdeen);

	
	system("pause");
	return 0;
}