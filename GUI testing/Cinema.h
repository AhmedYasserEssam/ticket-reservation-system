#pragma once

#include "Movie.h"
#include "Session.h"
#include "Hall.h"
#include "Schedule.h"


class Cinema {
	Movie* filmList; int filmCnt;
	Hall halls[3];
	Schedule timetable;
	Session* slots; int slotCnt;
	string times[3];

public:
	Cinema();
	
	int getFilmCnt() const;
	int getHallsCnt() const;
	// int getSlotCnt() const;
	int getTimesCnt() const;

	void setTimings();
	void addFilm(const string&, const string&, const int&, const int&);
	void removeFilm(const string&);

	Movie getMovie(int);
	Hall getHall(int);
	Session getSession(int);
};

