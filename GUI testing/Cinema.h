#pragma once

#include "Movie.h"
#include "Session.h"
#include "Hall.h"
#include "TimeTable.h"


class Cinema {
	Movie* filmList; int filmCnt;
	Hall halls[3];
	
	string times[3];
	TimeTable tt;

public:
	
	Cinema();
	
	int getFilmCnt() const;
	int getHallsCnt() const;
	int getTimesCnt() const;

	void addFilm(const string&, const string&, const int&, const int&);
	void removeFilm(const string&);

	TimeTable getSchedule();
};

