#include "Reservation.h"


Reservation::Reservation(){
	orderID = "H000";
	client; film; 
	seatCnt = 1;
	reserved = new Seat[seatCnt];
}


Reservation::Reservation(const string& orderID, const Movie& film, const int& seatCnt){
	this->orderID = orderID;
	this->film = film;
	this->seatCnt = seatCnt;
	reserved = new Seat[seatCnt];
}


void Reservation::setSeatCnt(const int& seatCnt) {
	this->seatCnt = seatCnt;
}


void Reservation::setOrderID(const string& orderID){
	this->orderID = orderID;
}


void Reservation::setClient(const Customer& client){
	this->client = client;
}


void Reservation::setFilm(const Movie& film){
	this->film = film;
}


//void Reservation::setReserved(Seat* reserved){
//	this->reserved = reserved;
//}


int Reservation::getSeatCnt() const{
	return seatCnt;
}


string Reservation::getOrderID() const{
	return orderID;
}


Customer Reservation::getClient() const{
	return client;
}


Movie Reservation::getFilm() const{
	return film;
}


string Reservation::getReserved(int n) const {
	return reserved[n].getId();
}


//void Reservation::changeSeat(const string& idIn, const string& idOut){
//	for (int i = 0; i < seatCnt; ++i) 
//	{
//		if (reserved[i].getId() == idOut)
//		{
//			reserved[i].setState(true);
//		}
//		if (reserved[i].getId() == idIn)
//		{
//			reserved[i].setState(false);
//		}
//	}
//}


void Reservation::addSeat(Seat& s, int index)
{ 
	reserved[index] = s;
}


//void Reservation::removeSeat(const string& ID){
//	for (int i = 0; i < seatCnt; ++i) {
//		if (reserved[i].getId() == ID) {
//			reserved[i].setState(true); // freeSeat()?
//			for (int j = i; j < seatCnt - 1; ++j) {
//				reserved[j] = reserved[j + 1];
//			}
//		}
//	}
//	seatCnt--;
//}


//void Reservation::cancelReservation(){
//	for (int i = 0; i < seatCnt; ++i) {
//		reserved[i].setState(true);
//	}
//	delete[] reserved; //destructor?//
//}


Reservation::~Reservation(){
	delete[] reserved;
}







