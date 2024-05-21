#include "Session.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>


class Schedule
{
	static const int DAYS = 3;
	static const int DAILY_MAX_SHOWTIMES = 9;
	Session* showtimes[DAYS][DAILY_MAX_SHOWTIMES];
	int showtimeCounts[DAYS];
	string startDate[DAYS];

	string getCurrentDateString(int daysOffset);

public:
	Schedule();
	~Schedule();

	int getDays() const;
	string getDayDate(int) const;

	bool addShowtime(const Session&, int);
	bool removeShowtime(const string&, const string&);

	void listShowtimes() const;

};

