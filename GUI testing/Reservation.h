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
	Reservation(int, Customer, Movie);

	void setSeatCnt(int);
	void setOrderID(string);
	void setClient(Customer);
	void setFilm(Movie);
	void setReserved(Seat*);

	int getSeatCnt() const;
	string getOrderID() const;
	Customer getClient() const;
	Movie getFilm() const;
	Seat* getReserved() const;

	void changeSeat(string, string);
	//void addSeat(char,int);
	void removeSeat(string);
	void cancelReservation();

	~Reservation();
};

