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
	cout << "Search by coordinate" << endl;
	find = tree.searchByCo(45.998, 12.3);
	if (find) {
		cout << "Reykjavík was found by it's coordinates" << endl;
	}
	else {
		cout << "Reykjavík was not found" << endl;
	}

	// Method to add a node
	cout << endl << endl;

	/*int choice = 0;
	while (choice != 3) {
		cout << "Enter 1 to add a node" << endl;
		cout << "Enter 2 to print the tree in order by name" << endl;
		cout << "Enter 3 to exit" << endl;
		cin >> choice;

		if (choice == 1) {
			string cityName;
			int population;
			double avgTemp;
			pair<double, double> coordinates;
			cout << "Enter city name: ";
			cin >> cityName;
			cout << "Enter co-ordinates for North: ";
			cin >> coordinates.first;
			cout << "Enter co-ordinates for West: ";
			cin >> coordinates.second;
			cout << "Enter population: ";
			cin >> population;
			cout << "Enter the average temperature: ";
			cin >> avgTemp;

			City city(cityName, coordinates, population, avgTemp);
			City* c = &city;
			tree.add(c);
		}
		else if (choice == 2) {
			tree.inOrderTransversal();
		}
		else if (choice == 3) {
			break;
		}
		else {
			cout << "Invalid choice" << endl;
			cout << "Choice: ";
			cin >> choice;
		}
	}*/
	
	system("pause");
	return 0;
}