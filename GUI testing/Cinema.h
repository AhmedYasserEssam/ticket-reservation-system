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
	string times[3] = { "10:00 AM","2:30 PM", "6:15 PM" };

public:
	Cinema();

};

