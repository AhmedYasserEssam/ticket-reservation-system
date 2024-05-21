#pragma once
#include <iostream>
#include <string>
#include <format>

using namespace std;


class Movie{
	string title, time;
	//enum genre;
	int year;
	int duration;

public:
	Movie();
	Movie(string, int, int);

	void setTitle(string);
	//void setGenre(genre);
	void setYear(int);
	void setDuration(int);

	string getTitle() const;
	//genre getGenre() const;
	int getYear() const;
	int getDuration() const;
	

	void operator=(Movie);
	bool operator==(Movie);

	friend istream& operator>>(istream&, Movie&);
	friend ostream& operator<<(ostream&, Movie&);
};