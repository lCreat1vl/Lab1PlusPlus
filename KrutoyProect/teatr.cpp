#include "teatr.h"
#include <iostream>
#include <string>
using namespace std;
int Teatr::getPrice() {
	return _price;
}
int Teatr::getSeats() {
	return _seats;
}
string Teatr::getName() {
	return _name;
}
void Teatr::setName(string name) {
	if (_name != name)
		_name = name;
}
void Teatr::setPrice(int price) {
	if (_price != price)
		_price = price;
}
void Teatr::setSeats(int seats) {
	if (_seats != seats)
		_seats = seats;
}
ostream& operator<<(ostream& out, const Teatr& teatr) {
	out << "---------------------------------------" << endl;
	out << "Title : " << teatr._name << endl;
	out << "Price : " << teatr._price << endl;
	out << "Number of seats : " << teatr._seats << endl;
	out << "---------------------------------------" << endl;
	return out;
}
istream& operator>>(istream& in, Teatr& teatr){
	cout << "Title: ";
	in >> teatr._name;
	cout << "Price: ";
	if(!(in >> teatr._price)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		teatr._price = 0;
	}
	cout << "Number of seats: ";
	if (!(in >> teatr._seats)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		teatr._seats = 0;
	}
	return in;

}

