#pragma once
#include <string>
class Teatr {
private:
	std::string _name;
	int _price;
	int _seats;
public:
	std::string getName();
	int getPrice();
	int getSeats();
	void setName(std::string name);
	void setPrice(int age);
	void setSeats(int seats);
};