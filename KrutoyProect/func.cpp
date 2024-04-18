#include "func.h"
#include <fstream>
#include <iostream>
using namespace std;


Teatr* Func::Read() {
	int n = 0;
	ifstream f("testik.txt");
	if (!f.is_open()) {
		return nullptr;
	}
	f >> n;
	if (n <= 0) {
		return nullptr;
	}
	Teatr* arr = new Teatr[n];
	for (int i = 0; i < n; i++) {
		string name;
		int price;
		int seats;
		f >> name >> price >> seats;
		arr[i].setName(name);
		arr[i].setPrice(price);
		arr[i].setSeats(seats);
	}
	f.close();
	return arr;
}
void Func::Save(Teatr* arr, int n) {
	ofstream f("testik.txt");
	if (!f.is_open())
		return;
	f << n << endl;
	for (int i = 0; i < n; i++) {
		f << arr[i].getName() << " " << arr[i].getPrice() << " " << arr[i].getSeats() << endl;
	}
	f.close();
	return ;
}

Teatr* Func::Delete(Teatr* arr,int m) {
	ifstream r("testik.txt");
	if (!r.is_open()) {
		return nullptr;
	}
	int n = 0;
	r >> n;
	if (n <= 0) {
		return arr;
	}
	r.close();
	Teatr* arr1 = new Teatr[n-1];
	string name;
	int price;
	int seats;
	for (int i = 0; i < n-1; i++) {
		if (i >= m-1) {
			name = arr[i+1].getName();
			price = arr[i+1].getPrice();
			seats = arr[i+1].getSeats();
			arr1[i].setName(name);
			arr1[i].setPrice(price);
			arr1[i].setSeats(seats);
			continue;
		}
		name = arr[i].getName();
		price = arr[i].getPrice();
		seats = arr[i].getSeats();
		arr1[i].setName(name);
		arr1[i].setPrice(price);
		arr1[i].setSeats(seats);
	}
	Save(arr1, n - 1);
	return arr1;
}

void Func::Dobavit(Teatr* arr1, int n) {
	ifstream r("testik.txt");
	if (!r.is_open()) {
		return ;
	}
	int count;
	if (!(r >> count))
		count = 0;
	r.close();
	Teatr *arr = Read();
	ofstream f("testik.txt");
	if (!f.is_open())
		return;
	f << n + count<<endl;
	for (int i = 0; i < count; i++) {
		f << arr[i].getName() << " " << arr[i].getPrice()<<" "<<arr[i].getSeats() << endl;
	}
	for (int i = 0; i < n; i++) {
		f << arr1[i].getName() << " " << arr1[i].getPrice() << " " << arr1[i].getSeats() << endl;
	}
	f.close();
	delete[]arr;
}
void Func::Find(Teatr* arr,int r) {
	ifstream f("testik.txt");
	if (!f.is_open()) {
		return;
	}
	int n = 0;
	f >> n;
	if (n <= 0) {
		return;
	}
	f.close();
	if (r == 1) {
		string name;
		int k = 0;
		cout << "Enter a title: ";
		cin >> name;
		for (int i = 0; i < n; i++) {
			if (!arr[i].getName().compare(name)) {
				k++;
				cout << k << ". " << arr[i];
			}
		}
		if (k < 1)
			cout << "Nothing was found " << endl;
	}
	else if (r == 2) {
		int price;
		int k = 0;
		cout << "Enter the price: ";
		cin >> price;
		for (int i = 0; i < n; i++) {
			if (arr[i].getPrice() == price) {
				k++;
				cout << k << ". " << arr[i];
			}
		}
		if (k < 1)
			cout << "Nothing was found " << endl;
	}
	else if (r == 3) {
		int seats;
		int k = 0;
		cout << "Enter the number of seats: ";
		cin >> seats;
		for (int i = 0; i < n; i++) {
			if (arr[i].getSeats() == seats) {
				k++;
				cout << k << ". " << arr[i];
			}
		}
		if (k < 1)
			cout << "Nothing was found " << endl;
	}
	return;
}
void Func::Edit(Teatr* arr, int r) {
	ifstream f("testik.txt");
	if (!f.is_open()) {
		return;
	}
	int n = 0;
	f >> n;
	if (n <= 0) {
		return;
	}
	f.close();
	int answer;
	cout << arr[r];
	cout << "What to edit: ";
	cin >> answer;
	if (answer == 1) {
		string name;
		cout << "Enter a name: ";
		cin >> name;
		arr[r].setName(name);
	}
	else if (answer == 2) {
		int price;
		cout << "Enter the price: ";
		if (!(cin >> price)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			arr[r].setPrice(price);
	}
	else if (answer == 3) {
		int seats;
		cout << "Enter the number of seats: ";
		if (!(cin >> seats)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			arr[r].setSeats(seats);
	}
	else {
		return;
	}
	Save(arr, n);
	return;
}
int Func::getLengthArr() {
	ifstream f("testik.txt");
	if (!f.is_open()) {
		return 0;
	}
	int n = 0;
	f >> n;
	f.close();
	return n;
}