#include "Employee.h"
#include <iostream>
using namespace std;
Employee::Employee(){}


Employee::Employee(string N, string E, string I, int A, int S, string T, string SH ) : Person(N, E, I, A)
{
	Salary = S;
	Title = T;
	Shift = SH;
	
}

void Employee::setSalary(int S)
{
	Salary = S;
}

void Employee::setTitle(string T)
{
	Title = T;
}

void Employee::setShift(string SH)
{
	Shift = SH;
}

int Employee::getSalary()
{
	return Salary;
}

string Employee::getTitle()
{
	return Title;

}

string Employee::getShift()
{
	return Shift;
}
