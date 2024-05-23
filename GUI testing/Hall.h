#pragma once
#include <iostream>
#include <string>

#include "Seat.h"
#include "Movie.h"

using namespace std;


class Hall{
	int rows, cols;
	string id;
	Seat** auditorium;
	 
	//int filmCnt, showtimeCnt;  //limit per hall object//
	//int currentFilmCnt = 0, currentShowtimeCnt = 0;
	//string* showtimes; //chronological order expected//
	//Movie* schedule;

public:
	Hall();
	Hall(const int&, const int&, const string&);

	bool isAvailable(const string&);
	void bookSeat(const string&);
	void freeSeat(const string&);
	//void setFilmCnt(int);
	//void setShowtimeCnt(int);

	//int getFilmCnt() const;
	//int getShowtimeCnt() const;
	//int getCurrentFilmCnt() const;
	//int getCurrentShowtimeCnt() const;

	//float checkPrice(string);

	//void addMovieToList(Movie&);
	//void addShowtime(string&);
	//void removeMovieFromList(Movie&);
	//void removeShowtime(string&);
	//void changeScheduleSlot(Movie, string&);
};

