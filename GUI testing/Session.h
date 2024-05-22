#pragma once

#include "Movie.h"
#include "Hall.h"
#include "Reservation.h"
#include "Schedule.h"

using namespace std;


class Session{
	Movie film;
	Hall location;
	string dayDate;
	string timing;
	Reservation* attendances; int reservationCnt;

public:
	Session();
	Session(const Movie&, const Hall&, const string&);

	void setMovie(const Movie&);
	void setHall(const Hall&);
	void setDayDate(const string&);
	void setTiming(const string&);

	Movie getMovie() const;
	Hall getHall() const;
	string getDayDate() const;
	string getTiming() const;
	int getReservationCount();

	void addReservation(const Reservation&);
	void removeReservation(const string&);
	int calculateSeatsTaken();
	void display() const;

	Session& operator=(const Session&);
};