#include "Schedule.h"


string Schedule::getCurrentDateString(int daysOffset = 0)
{
    auto ctime = time(nullptr);
    const int daySeconds = (24 * 60 * 60) * (daysOffset+1);
    tm* nextDay = localtime(&ctime);
    char buffer[80];
    strftime(buffer, 80, "%a", nextDay);

    auto now = chrono::system_clock::now();
    now += chrono::hours(24 * daysOffset);
    time_t t = chrono::system_clock::to_time_t(now);
    tm* tm = localtime(&t);

    ostringstream oss;
    oss << put_time(tm, "%d/%m");
    return oss.str() + string(buffer);


}


Schedule::Schedule() {
    for (int i = 0; i < DAYS; ++i) {
        showtimeCounts[i] = 0;
        startDate[i] = getCurrentDateString(i);
        for (int j = 0; j < DAILY_MAX_SHOWTIMES; ++j) {
            showtimes[i][j] = nullptr;
        }
    }
}


Schedule::~Schedule()
{
    for (int i = 0; i < DAYS; ++i) {
        for (int j = 0; j < showtimeCounts[i]; ++j) {
            delete showtimes[i][j];
        }
    }
}


int Schedule::getDays() const {
    return DAYS;
}


string Schedule::getDayDate(int dayIndex) const{
    return startDate[dayIndex];
}


bool Schedule::addShowtime(const Session& showtime, int dayIndex) {
    if (dayIndex < 0 || dayIndex >= DAYS || showtimeCounts[dayIndex] >= DAILY_MAX_SHOWTIMES) return false;

    showtimes[dayIndex][showtimeCounts[dayIndex]] = new Session(showtime); // test if assignment operator is needed
    showtimeCounts[dayIndex]++;
    return true;
}


bool Schedule::removeShowtime(const string& title, const string& dateTime) {
    for (int i = 0; i < DAYS; ++i) {
        for (int j = 0; j < showtimeCounts[i]; ++j) {
            if (showtimes[i][j]->getMovie().getTitle() == title &&
                showtimes[i][j]->getDayDate() == dateTime){
                delete showtimes[i][j];
                for (int k = j; k < showtimeCounts[i] - 1; ++k) showtimes[i][k] = showtimes[i][k + 1];
                showtimes[i][--showtimeCounts[i]] = nullptr;
                return true;
            }
        }
    }
    return false;
}


void Schedule::listShowtimes() const {
    for (int i = 0; i < DAYS; ++i) {
        cout << "Date: " << startDate[i] << "\n";
        for (int j = 0; j < showtimeCounts[i]; ++j) {
            showtimes[i][j]->display();
        }
    }
}