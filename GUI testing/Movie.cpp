#include "Movie.h"
#include "Movie.h"


Movie::Movie(){
	title = "";
	year = 0000;
	duration = 00.00;
}


Movie::Movie(string title, int year, int duration){
	this->title = title;
	this->year = year;
	this->duration = duration;
}


void Movie::setTitle(string title){
	this->title = title;
}


void Movie::setYear(int year){
	this->year = year;
}


void Movie::setDuration(int duration){
	this->duration = duration;
}


string Movie::getTitle() const {
	return title;
}


int Movie::getYear() const {
	return year;
}


int Movie::getDuration() const {
	return duration;
}



void Movie::operator=(Movie m2)
{
	title = m2.getTitle();
	duration = m2.getDuration();
	year = m2.getYear();

}

bool Movie::operator==(Movie m2) {
	return title == m2.title && year == m2.year && duration == m2.duration;
}


istream& operator>>(istream& ins, Movie& m){
	string title, time;
	int year;
	int duration;
	ins >> title >> year >> duration >> time;
	m.setTitle(title);
	m.setYear(year);
	m.setDuration(duration);
	return ins;
}


ostream& operator<<(ostream& outs, Movie& m){
	outs << "Title: " << m.title << endl << "Release Year: " << m.year << endl 
	<< "Duration: " << m.duration << endl;
	return outs;
}