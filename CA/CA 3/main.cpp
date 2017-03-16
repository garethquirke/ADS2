#include "City.h"
#include "BinaryTree.h"
#include "TreeNode.h"
#include <string>
#include <iostream>
using namespace std;

int main() {

	City c1("Dublin", make_pair(53.3498, 6.2603), 4500, 14.8);
	City c2("Dundee", make_pair(41.9, 76.8), 5000, 12.4);
	City c3("Humberside", make_pair(53.3498, 6.2603), 9000, 14.8);
	cout << c1 << endl;
	cout << c2 << endl;

	BinaryTree tree;

	City* dublin = &c1;
	City* aberdeen = &c2;
	City* humberside = &c3;

	tree.add(dublin);
	tree.add(aberdeen);
	tree.add(humberside);

	cout << "Height of Tree: " << tree.height() << endl;




	// Method to add a node
	int choice = 0;
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
	}
	
	system("pause");
	return 0;
}