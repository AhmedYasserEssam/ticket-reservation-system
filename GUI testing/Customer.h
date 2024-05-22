#pragma once
#include <iostream>
#include <string>

using namespace std;


class Customer{
	string name;
	string email;

public:
	Customer();
	Customer(const string&, const string&);

	void setName(const string&);
	void setEmail(const string&);

	string getName() const;
	string getEmail() const;

	bool operator==(const Customer&);

	friend istream& operator>>(istream&, Customer&);
	friend ostream& operator<<(ostream&, Customer&);
};

