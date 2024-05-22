#include <string>

#include "Session.h"
#include "Movie.h"
#include "Hall.h"


Session::Session() {}


Session::Session(const Movie& f, const Hall& l, const string& dt){
	film = f; location = l; dayDate = dt;
	reservationCnt = 0; attendances = new Reservation[reservationCnt];
}


void Session::setMovie(const Movie& film){
	this->film = film;
}


void Session::setHall(const Hall& location){
	this->location = location;
}


void Session::setDayDate(const string& dateTime){
	this->dayDate = dateTime;
}

void Session::setTiming(const string& timing){
	this->timing = timing;
}


Movie Session::getMovie() const{
	return film;
}


Hall Session::getHall() const{
	return location;
}


string Session::getDayDate() const{
	return dayDate;
}


string Session::getTiming() const{
	return timing;
}


int Session::getReservationCount(){
	return reservationCnt;
}


void Session::addReservation(const Reservation& r){
	reservationCnt++;
	attendances[reservationCnt - 1] = r;
}


void Session::removeReservation(const string& id){
	for (int i = 0; i < reservationCnt; ++i) {
		if (attendances[i].getOrderID() == id) {
			for (int j = i; j < reservationCnt - 1; ++j) {
				attendances[j] = attendances[j + 1];
			}
		}
	}
	reservationCnt--;
}


int Session::calculateSeatsTaken(){
	int seatsTaken = 0;
	for (int i = 0; i < reservationCnt; ++i) seatsTaken += attendances[i].getSeatCnt();
	return seatsTaken;
}


void Session::display() const
{
	cout << "Showtime: " << dayDate << endl;
	cout << this->getMovie();
}


Session& Session::operator=(const Session& s){
	if (this == &s) return *this;

	delete[] attendances;

	film = s.film;
	location = s.location;
	dateTime = s.dateTime;
	reservationCnt = s.reservationCnt;

	if (s.attendances != nullptr){
		attendances = new Reservation[reservationCnt];
		for (int i = 0; i < reservationCnt; ++i) attendances[i] = s.attendances[i];
	}
	else attendances = nullptr;

	return *this;
}









