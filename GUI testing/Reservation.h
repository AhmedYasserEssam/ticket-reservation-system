#pragma once
#include <iostream>
#include <string>
#include <format>

#include "Movie.h"
#include "Customer.h"
#include "Seat.h"
#include "Hall.h"


class Reservation{
	int seatCnt = 0;
	string orderID;
	Customer client;
	Movie film;
	Seat* reserved;
public:
	Reservation();
	Reservation(const int&, const Customer&, const Movie&);

	void setSeatCnt(const int&);
	void setOrderID(const string&);
	void setClient(const Customer&);
	void setFilm(const Movie&);
	void setReserved(Seat*);

	int getSeatCnt() const;
	string getOrderID() const;
	Customer getClient() const;
	Movie getFilm() const;
	Seat* getReserved() const;

	void changeSeat(const string&, const string&);
	//void addSeat(char,int);
	void removeSeat(const string&);
	void cancelReservation();

	~Reservation();
};

