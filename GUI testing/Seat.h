#pragma once
#include <iostream>
#include <string>
#include <format>

using namespace std;


class Seat{
	string id;
	float price;
	bool state; //true = not reserved

public:
	Seat();
	Seat(char,int);
	//Seat(char, int, bool);

	void setId(string);
	void setPrice(float);
	void setState(bool);

	string getId();
	float getPrice();
	bool getState();

	//friend member ostream& operator<<(ostream& os, const Seat& s); 
	void operator=(Seat);
};

