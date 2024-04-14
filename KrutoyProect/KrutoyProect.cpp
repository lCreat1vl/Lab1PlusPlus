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
	setlocale(LC_ALL, "Russian");
	while (key) {
		int answer;
		cout << "1. Добавить." << endl;
		cout << "2. Считать данные из файла." << endl;
		cout << "3. Удалить." << endl;
		cout << "4. Вывести данные." << endl;
		cout << "5. Поиск по файлу. " << endl;
		cout << "6. Редактировать данные. " << endl;
		cout << "Что сделать: ";
		if (!(cin >> answer)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		switch (answer)
		{
		case 1:
			cout << "Сколько добавить: ";
			if (!(cin >> n)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			arr1 = new Teatr[n];
			for (int i = 0; i < n; i++) {
				int price;
				int seats;
				string name;
				cout << "Название спектакля = ";
				cin >> name;
				cout << "Цена = ";
				if (!(cin >> price)) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					price = 0;
				}
				cout << "Кол-во мест = ";
				if (!(cin >> seats)) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					seats = 0;
				}
				arr1[i].setPrice(price);
				arr1[i].setName(name);
				arr1[i].setSeats(seats);
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
			count = 0;
			Vivod(arr, count);
			int m;
			cout << "Что удалить: ";
			if (!(cin >> m)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			arr = Delete(arr, m);
			break;
		case 4:
			Vivod(arr,count);
			break;
		case 5:
			cout << "Поиск по "<<endl;
			cout << "1. Названию" << endl;
			cout << "2. Цене" << endl;
			cout << "3. Количеству мест" << endl;
			if (!(cin >> r)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			arr = Read();
			count = 0;
			Find(arr, r);
			break;
		case 6:
			arr = Read();
			count = 0;
			Vivod(arr, count);
			cout << "Что редактировать : " << endl;
			if (!(cin >> r)) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			Edit(arr, r-1);
		default:
			break;
		}

	}
	return 0;

}