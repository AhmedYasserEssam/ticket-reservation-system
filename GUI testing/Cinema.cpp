#include "Cinema.h"
#include "Session.h"
#include <iostream>
#include <fstream>
using namespace std;


Cinema::Cinema()
{
	times[0] = "10:00 AM";
	times[1] = "2:30 PM";
	times[2] = "6:15 PM";


	filmCnt = 3; filmList = new Movie[filmCnt];
	filmList[0] = Movie("Cars 1", "Action", 2005, 120);
	filmList[1] = Movie("Godzilla X kong", "Action", 2024, 120);
	filmList[2] = Movie("Al Serb", "Action", 2024, 120);

	halls[0] = Hall(10, 10, "H-1");
	halls[1] = Hall(6, 6, "H-2");
	halls[2] = Hall(10, 10, "H-3");
	string filename = "Sessionss.txt";
	ofstream file(filename);
	if (file.is_open())
	{
		for (int i = 0; i < tt.getDays(); i++)
		{
			tt.getCurrentDateString(i);
			for (int j = 0; j < filmCnt; j++)
			{
				for (int k = 0; k < filmCnt; k++)
				{

					Session s(filmList[i], halls[k], tt.getDayDate(j), times[k]);
					tt.addShow(s, i, ((j * filmCnt) + k) % 10);
				}
			}
		}
	}
}


//void Cinema::setTimings()
//{
//	times[0] = { "10:00 AM" }; times[1] = { "2:30 PM" }; times[2] = { "6:15 PM" };
//	for (int i = 0; i < tt.getDays(); ++i) {
//		for (int j = 0; j < tt.getDailyMaxShowtimes(); ++j)
//		{
//			Session s = tt.getTime(i, j);
//			if (j <= 2)
//			{
//				s.setTiming(times[0]);
//			}
//			else if (j >= 3 && j <= 5)
//			{
//				s.setTiming(times[1]);
//			}
//			else
//			{
//				s.setTiming(times[2]);
//			}
//		}
//	}
//}


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

TimeTable Cinema::getSchedule()
{
	return tt;
}