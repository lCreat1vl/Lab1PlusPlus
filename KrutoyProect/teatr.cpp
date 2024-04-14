#include "teatr.h"
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