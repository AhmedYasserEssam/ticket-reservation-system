#include "Seat.h"


Seat::Seat(){
	id = "";
	price = 0.0;
	state = 0;
};


Seat::Seat(char c,int n){
	id = c + to_string(n);
	state = true;

	char idLetter = id[0];
	switch (idLetter) {
		case 'A': price = 75.0; break;
		case 'B': price = 75.0; break;
		case 'C': price = 85.0; break;
		case 'D': price = 100.0; break;
		case 'E': price = 100.0; break;
		case 'F': price = 80.0; break;
		case 'G': price = 70.0; break;
		case 'H': price = 60.0; break;
		case 'I': price = 60.0; break;
	}
}


/*
Seat::Seat(char id, int num, bool state){
	this->id = id;
	this->state = state;

	switch (id) {
		case 'A': price = 75.0; break;
		case 'B': price = 75.0; break;
		case 'C': price = 85.0; break;
		case 'D': price = 100.0; break;
		case 'E': price = 100.0; break;
		case 'F': price = 80.0; break;
		case 'G': price = 70.0; break;
		case 'H': price = 60.0; break;
		case 'I': price = 60.0; break;
	}
}
*/


void Seat::setId(const string& id){
	this->id = id;
}


void Seat::setPrice(const float& price){
	this->price = price;
}


void Seat::setState(bool state){
	this->state = state;
}


string Seat::getId() const {
	return id;
}


float Seat::getPrice() const {
	return price;
}


bool Seat::getState() const {
	return state;
}


void Seat::operator=(Seat& s2){
	this->id = s2.getId();
	this->price = s2.getPrice();
	this->state = s2.getState();
}



