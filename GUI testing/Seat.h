#pragma once
#include <iostream>
#include <string>
#include <format>

using namespace std;


class Seat{
	string id;
	float price;
	bool state; //true = not reserved//

public:
	Seat();
	Seat(char, int);
	Seat(int, int, bool);

	void setId(const string&);
	void setPrice(const float&);
	void setState(bool);

	string getId() const;
	float getPrice() const;
	bool getState() const;

	//friend member ostream& operator<<(ostream& os, const Seat& s); 
	void operator=(const Seat&);
};

