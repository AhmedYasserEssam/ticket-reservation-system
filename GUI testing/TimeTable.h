#pragma once
#include <iostream>
#include "Session.h"

using namespace std;

class TimeTable
{
private:
    int DAYS, DAILY_MAX_SHOWTIMES;
    int showtimeCounts[3];
    string startDate[3];

    Session** showtime;
public:
    TimeTable();
    ~TimeTable();

    string getCurrentDateString(int);
    int getDays() const;
    int getDailyMaxShowtimes() const;
    string getDayDate(int) const;

    const Session& getTime(int, int) const;

    void addShow(const Session&, int dayIndex);
    bool removeShowtime(string, string);

    //void listShowtimes() const;
};

