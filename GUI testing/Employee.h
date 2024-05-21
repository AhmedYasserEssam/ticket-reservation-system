#pragma once
#include "Person.h"
class Employee : public Person
{
private:
	int Salary;
	string Title;
	string Shift;
public:
	Employee();
	Employee(string N, string E, string I, int A, int S, string T, string SH);
	void setSalary(int S);
	void setTitle(string T);
	void setShift(string SH);
	int getSalary();
	string getTitle();
	string getShift();

};

