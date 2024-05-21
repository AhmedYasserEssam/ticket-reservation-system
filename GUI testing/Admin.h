#pragma once
#include <iostream>
#include "Person.h"
#include "Employee.h"
using namespace std;

class Admin : public Person, public Employee
{
protected:
	string Key;
public:
	Admin();
	void setKey(string K);
	string getKey();
};

