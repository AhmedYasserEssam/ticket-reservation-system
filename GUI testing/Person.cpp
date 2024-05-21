#include "Person.h"
#include <iostream>
#include<string>
using namespace std;
Person::Person(){}
Person::Person(string N, string E, string I, int A)
{
	Name = N;
	Email = E;
	ID = I;
	Age = A;
}

void Person::setName(string N)
{
	Name = N;
}

void Person::setEmail(string E)
{
	bool flag = false;
	int l = E.length();
	char arr1[4] = { 'm','o','c','.'};
	for (int j = 0; j < 4; j++) {
		for (int x = l - 1; x >= l - 4; x--) {
			if (arr1[j] != E[x]) {
				cout << "Please enter a valid email";
				break;
				for (int i = 0; i < l; i++) {
					if (i == '@') {
						flag = true;
					}
					cout << "Please enter a valid email";
					break;
				}
			} 
				}
	}
	
	

}

void Person::setID(string I)
{
	ID = I;
}

void Person::setAge(int A)
{
	if(Age > 0) {
		Age = A;
	}
	else {
		cout << "Invalid Age" << endl;
	}
	
}

string Person::getName()
{
	return Name;
}

string Person::getEmail()
{
	return Email;
}

string Person::getID()
{
	return ID;
}

int Person::getAge()
{
	return Age;
}
