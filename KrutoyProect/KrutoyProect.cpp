#include "func.h"
#include <fstream>
#include <iostream>
#include <typeinfo>


using namespace std;
using namespace Func;


int main() {
	int key = 1;
	int n = 0;
	int m = 0;
	int r = 0;
	int count = 0;
	Teatr* arr{};
	Teatr* arr1{};
	while (key) {
		int answer;
		cout << "1. New." << endl;
		cout << "2. Read file." << endl;
		cout << "3. Delete. " << endl;
		cout << "4. Output." << endl;
		cout << "5. Search. " << endl;
		cout << "6. Edit " << endl;
		cout << "Select an action: ";
		if (!(cin >> answer)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		switch (answer)
		{
		case 1:
			cout << "How much to add: ";
			if (!(cin >> n)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			arr1 = new Teatr[n];
			for (int i = 0; i < n; i++) {
				cin >> arr1[i];
			}
			Dobavit(arr1, n);
			delete[]arr1;
			count += n;
			break;
		case 2:
			arr = Read();
			count = 0;
			break;
		case 3:
			arr = Read();
			for (int i = 0; i < getLengthArr() - count; i++) {
				cout << i + 1 << endl;
				cout << arr[i] << endl;
			}
			count = 0;
			int m;
			cout << "What to delete: ";
			if (!(cin >> m)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			arr = Delete(arr, m);
			break;
		case 4:
			for (int i = 0; i < getLengthArr() - count; i++) {
				cout << i + 1 << endl;
				cout << arr[i] << endl;
			}
			break;
		case 5:
			cout << "Search by "<<endl;
			cout << "1. Title" << endl;
			cout << "2. Price" << endl;
			cout << "3. Number of seats" << endl;
			if (!(cin >> r)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			arr = Read();
			count = 0;
			Find(arr, r);
			delete[]arr;
			break;
		case 6:
			arr = Read();
			count = 0;
			for (int i = 0; i < getLengthArr() - count; i++) {
				cout << i + 1 << endl;
				cout << arr[i] << endl;
			}
			cout << "What to edit : " << endl;
			if (!(cin >> r)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			Edit(arr, r-1);
			delete[]arr;
		default:
			break;
		}

	}
	return 0;
}