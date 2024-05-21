#pragma once
# include <iostream>
using namespace std;

class Person
{
private: 
	string Name;
	string Email;
	string ID;
	int Age;
public:
	Person();
	Person(string N, string E, string I, int A);
	void setName(string N);
	void setEmail(string E);
	void setID(string I);
	void setAge(int A);
	string getName();
	string getEmail();
	string getID();
	int getAge();
};
