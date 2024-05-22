#include "Session.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>


class Schedule
{
	static const int DAYS = 3;
	static const int DAILY_MAX_SHOWTIMES = 9;

	typedef Session* ShowtimesArray[DAYS][DAILY_MAX_SHOWTIMES];
	ShowtimesArray showtimes;

	int showtimeCounts[DAYS];
	string startDate[DAYS];

	string getCurrentDateString(int daysOffset);

public:
	Schedule();
	~Schedule();

	int getDays() const;
	int getDailyMaxShowtimes() const;
	string getDayDate(const int&) const;
	const ShowtimesArray& getShowtimes() const;

	bool addShowtime(const Session&, const int&);
	bool removeShowtime(const string&, const string&);

	void listShowtimes() const;

};

