#pragma once
#include <iostream>
#include <string>

using namespace std;


class Customer{
	string name;
	string email;

public:
	Customer();
	Customer(string, string);

	void setName(string);
	void setEmail(string);

	string getName() const;
	string getEmail() const;

	bool operator==(Customer);

	friend istream& operator>>(istream&, Customer&);
	friend ostream& operator<<(ostream&, Customer&);
};

