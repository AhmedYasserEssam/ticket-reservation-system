#include "TimeTable.h"

#include "Session.h"
#include <chrono>
#include <sstream>
#include <iomanip>
#include <ctime>


#pragma warning(disable:4996)
using namespace std;

string TimeTable::getCurrentDateString(int daysOffset = 0) {
    auto ctime = time(nullptr);
    const int daySeconds = (24 * 60 * 60) * (daysOffset + 1);
    tm* nextDay = localtime(&ctime);
    char buffer[80];
    strftime(buffer, 80, "%a", nextDay);

    auto now = chrono::system_clock::now();
    now += chrono::hours(24 * daysOffset);
    time_t t = chrono::system_clock::to_time_t(now);
    tm* tm = localtime(&t);

    ostringstream oss;
    oss << put_time(tm, "%d/%m");
    return oss.str() + " " + string(buffer);
}


TimeTable::TimeTable()
{
    DAYS = 3;
    DAILY_MAX_SHOWTIMES = 9;
    showtime = new Session * [DAYS];
    for (int i = 0; i < DAYS; ++i) {
        showtime[i] = new Session[DAILY_MAX_SHOWTIMES];
    }
    for (int i = 0; i < DAYS; ++i) {
        showtimeCounts[i] = 0;
        startDate[i] = getCurrentDateString(i);
        /*for (int j = 0; j < DAILY_MAX_SHOWTIMES; ++j) {
            showtimes[i][j] = nullptr;
        }*/
    }
}


TimeTable::~TimeTable()
{}


int TimeTable::getDays() const {
    return DAYS;
}


int TimeTable::getDailyMaxShowtimes() const {
    return DAILY_MAX_SHOWTIMES;
}


string TimeTable::getDayDate(int dayIndex) const {
    return startDate[dayIndex];
}

const Session& TimeTable::getTime(int dayIndex, int slotIndex) const
{
    return showtime[dayIndex][slotIndex];
}

void TimeTable::addShow(const Session& St, int dayIndex)
{
    if (dayIndex > 0 || dayIndex <= DAYS || showtimeCounts[dayIndex] <= DAILY_MAX_SHOWTIMES)
        showtime[dayIndex][showtimeCounts[dayIndex]++] = St;

}

bool TimeTable::removeShowtime(string title, string dateTime) {
    for (int i = 0; i < DAYS; ++i) {
        for (int j = 0; j < showtimeCounts[i]; ++j) {
            if (showtime[i][j].getMovie().getTitle() == title &&
                showtime[i][j].getDayDate() == dateTime) {
                for (int k = j; k < showtimeCounts[i] - 1; ++k) {
                    showtime[i][k] = showtime[i][k + 1];
                }
                showtimeCounts[i]--;
                return true;
            }
        }
    }
    return false;
}
//
//void Schedule::listShowtimes() const
//{
//    for (int i = 0; i < DAYS; ++i) {
//        cout << "Date: " << startDate[i] << "\n";
//        for (int j = 0; j < showtimeCounts[i]; ++j) {
//            showtime[i][j].display();
//        }
//    }
//}

