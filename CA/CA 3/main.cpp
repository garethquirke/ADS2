#include "City.h"
#include "BinaryTree.h"
#include "TreeNode.h"
#include <string>
#include <iostream>
using namespace std;

int main() {

	City *c1 = new City("Dublin", make_pair(53.3498, 6.2603), 4500, 14.8);
	City *c2 = new City("Dundee", make_pair(41.9, 76.8), 5000, 12.4);
	City *c3 = new City("Humberside", make_pair(51.02, 8.1), 9000, 14.8);
	City *c4 = new City("London", make_pair(12.456, 3.928), 12000, 15.2);
	City *c5 = new City("Birmingham", make_pair(53.3498, 6.2603), 2900, 17.8);
	City *c6 = new City("Aberdeen", make_pair(61.209, 8.56), 4000, 9.8);
	City *c7 = new City("Reykjavík ", make_pair(45.998, 12.3), 5000, 3.1);
	City *c8 = new City("Rio", make_pair(97.562, 192.162), 7000, 19.8);


	cout << "Test of overloaded operator for output" << endl;
	cout << c1 << endl;

	cout << "Creating a new BST and adding data" << endl;
	// Dublin and Birmingham have a match in one of the coordinates
	// Birminingham should not be added
	BinaryTree tree;
	tree.add(c1);
	tree.add(c2);
	tree.add(c3);
	tree.add(c4);
	tree.add(c5);
	tree.add(c6);
	tree.add(c7);
	// adding a city outside of the specified coordinates
	tree.add(c8);
	cout << endl;

	cout << "Transversal (in order) and height outputted" << endl;
	tree.inOrderTransversal();
	cout << "Height of Tree: " << tree.height() << endl;
	cout << endl;

	cout << "Delete method tests" << endl;
	cout << "Attempt to delete node with a city name of Aberdeen" << endl;
	tree.deleteNode("Aberdeen");
	tree.inOrderTransversal();
	cout << "Attempt to delete node with a city name of Foo" << endl;
	tree.deleteNode("Foo");


	cout << "Search test" << endl;
	bool find = tree.search("Humberside");
	if (find) {
		cout << "Humberside was found" << endl;
	}
	else {
		cout << "Humberside was not found" << endl;
	}
	cout << endl << endl;



	cout << "Finding locations within a range" << endl;
	// Testing out of bounds location
	pair<double, double> point = make_pair(1.2, 5.9);
	pair<double, double> range = make_pair(4.3, 8.9);
	tree.inRange(point, range);

	// Testing range with valid range
	point = make_pair(0, 0);
	range = make_pair(90, 120);
	tree.inRange(point, range);

	
	system("pause");
	return 0;
}