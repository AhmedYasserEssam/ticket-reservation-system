#include "Cinema.h"


Cinema::Cinema(){
	times[0] = { "10:00 AM" }; times[1] = { "2:30 PM" }; times[2] = { "6:15 PM" };

	filmCnt = 3; filmList = new Movie[filmCnt];
	filmList[0] = Movie("Ashoush 1", "Action", 2005, 120);
	filmList[1] = Movie("Ashoush 2", "Action", 2006, 120);
	filmList[2] = Movie("Ashoush 3", "Action", 2007, 120);

	halls[0] = Hall(10, 10, "H-01");
	halls[1] = Hall(6, 6, "H-02");
	halls[2] = Hall (10, 10, "H-03");

	// slotCnt = 27;  slots = new Session[slotCnt]; int slotsIndex = 0;
	for (int i = 0; i < timetable.getDays(); i++) {
		for (int j = 0; j < filmCnt; j++) {
			for (int k = 0; k < filmCnt; k++) 
				timetable.addShowtime(Session(filmList[k], halls[k], timetable.getDayDate(i)), i);
		}
	}
}


void Cinema::setTimings(){ //try to make more dynamic after testing//
	for (int i = 0; i < timetable.getDays(); ++i) {
		for (int j = 0; j < timetable.getDailyMaxShowtimes(); ++j) {
			if (timetable.getShowtimes()[i][j] != nullptr && j >= 0 && j <= 2)
				timetable.getShowtimes()[i][j]->setTiming(times[0]);
			else if (timetable.getShowtimes()[i][j] != nullptr && j >= 3 && j <= 5)
				timetable.getShowtimes()[i][j]->setTiming(times[1]);
			else timetable.getShowtimes()[i][j]->setTiming(times[2]);
		}
	}
}


int Cinema::getFilmCnt() const{
	return filmCnt;
}


int Cinema::getHallsCnt() const{
	return sizeof(halls) / sizeof(Hall);
}


int Cinema::getTimesCnt() const{
	return sizeof(times) / sizeof(string);
}


void Cinema::addFilm(const string& title, const string& genre, const int& year, const int& duration){
	Movie m(title, genre, year, duration);
	filmList[++filmCnt] = m;
}


void Cinema::removeFilm(const string& title){
	for (int i = 0; i < filmCnt; ++i) {
		if (filmList[i].getTitle() == title) {
			for (int j = i; j < filmCnt - 1; ++j) filmList[j] = filmList[j + 1];
			filmCnt--;
			return;
		}
	}
	cout << "Movie does not exist in your list.";
}


