#include "Customer.h"


Customer::Customer(){
	name = "";
	email = "";
}


Customer::Customer(string name, string email){
	this->name = name;
	this->email = email;
}


void Customer::setName(string name){
	this->name = name;
}


void Customer::setEmail(string email){
	this->email = email;
}


string Customer::getName() const{
	return name;
}


string Customer::getEmail() const{
	return email;
}


bool Customer::operator==(Customer c2){
	return name == c2.name && email == c2.email;
}


istream& operator>>(istream& ins, Customer& c) {
	string name, email;
	ins >> name >> email;
	c.setName(name);
	c.setEmail(email);
	return ins;
}


ostream& operator<<(ostream& outs, Customer& c){
	outs << "Name: " << c.name << endl << "Email: " << c.email << endl;
	return outs;
}
