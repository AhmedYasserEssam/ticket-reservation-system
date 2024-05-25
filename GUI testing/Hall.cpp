#include "Hall.h"


Hall::Hall() {
	rows = 10, cols = 10; id = "H-0";
	auditorium = new Seat * [rows];
	char i = 'A';
	for (int k = 0; k < rows; ++i, ++k)
	{
		auditorium[k] = new Seat[cols];
		for (int j = 1, l = 0; l < cols; ++j, ++l)
		{
			auditorium[k][l] = Seat(i, j);
		}
	}
	//filmCnt = 3; showtimeCnt = 6;
	//filmList = new Movie[currentFilmCnt]; showtimes = new string[currentShowtimeCnt]; schedule = new Movie[currentShowtimeCnt];
}


Hall::Hall(const int& rows, const int& cols, const string& id){
	this->rows = rows; this->cols = cols; this->id = id;
	auditorium = new Seat*[rows];
	char i = 'A';
	for (int k = 0; k < rows; ++k)
	{
		auditorium[k] = new Seat[cols];

		for (int j = 1; j-1 < cols; ++j)
		{
			auditorium[k][j-1] = Seat(i, j);
		}
		i++;
	}

	//this->filmCnt = filmCnt; this->showtimeCnt = showtimeCnt;
	//filmList = new Movie[currentFilmCnt]; showtimes = new string[currentShowtimeCnt]; schedule = new Movie[currentShowtimeCnt];
}

/*
void Hall::setFilmCnt(int filmCnt){
	this->filmCnt = filmCnt;
}


void Hall::setShowtimeCnt(int showtimeCnt){
	this->showtimeCnt = showtimeCnt;
}


int Hall::getFilmCnt() const {
	return filmCnt;
}


int Hall::getShowtimeCnt() const {
	return showtimeCnt;
}


int Hall::getCurrentFilmCnt() const {
	return currentFilmCnt;
}


int Hall::getCurrentShowtimeCnt() const {
	return currentShowtimeCnt;
}

*/
bool Hall::isAvailable(const string& id) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (auditorium[i][j].getId() == id && auditorium[i][j].getState() == false) return false;
		}

	}
	return true;
}

/*
float Hall::checkPrice(string id) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (auditorium[i][j].getId() == id) return auditorium[i][j].getPrice();
		}
	}
}

*/
void Hall::bookSeat(const string& id)
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) 
		{
			if (auditorium[i][j].getId() == id && auditorium[i][j].getState() == true) 
			{
				cout<< auditorium[i][j].getId();
				auditorium[i][j].setState(false);
				
			}
		}
	}
	//cout << "Cannot book an already reserved seat.\n";
}


void Hall::freeSeat(const string& id){
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (auditorium[i][j].getId() == id && auditorium[i][j].getState() == false) {
				auditorium[i][j].setState(true);
				cout << "Seat was successfully unbooked!\n";
				return;
			}
		}
	}
	cout << "Cannot unbook an already free seat.\n";
}

Seat& Hall::getSeat(int x, int y)
{
	return auditorium[x][y];
}

int Hall::getSize()
{
	return rows;
}

string Hall::getID()
{
	return id;
}

bool Hall::operator==(const Hall& h)
{
	if (this->getID() == h.id)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
void Hall::addMovieToList(Movie& m){
	for (int i = 0; i < currentFilmCnt; ++i) {
		if (filmList[i] == m) {
			cout << "Movie is already in the list; try adding another movie.\n";
			return;
		}
	}

	if (currentFilmCnt >= filmCnt) { cout << "No more movies can be added to this hall!\n"; }
	else {
		currentFilmCnt++;
		filmList[currentFilmCnt - 1] = m;
	}
}


void Hall::addShowtime(string& s){
	for (int i = 0; i < currentShowtimeCnt; ++i) {
		if (showtimes[i] == s) {
			cout << "Showtime already exists; try adding another one.\n";
			return;
		}
	}
	if (currentShowtimeCnt >= showtimeCnt) { cout << "Showtime count limit for this hall reached!\n"; }
	else {
		currentShowtimeCnt++;
		showtimes[currentShowtimeCnt - 1] = s;
	}
}


void Hall::removeMovieFromList(Movie& m){
	for (int i = 0; i < currentFilmCnt; ++i) {
		if (filmList[i] == m) {
			for (int j = i; j < currentFilmCnt - 1; ++j) {
				filmList[j] = filmList[j + 1];
			}
		}
	}
	currentFilmCnt--;
}


void Hall::removeShowtime(string& s){
	for (int i = 0; i < currentShowtimeCnt; ++i) {
		if (showtimes[i] == s) {
			for (int j = i; j < currentShowtimeCnt - 1; ++j) {
				showtimes[j] = showtimes[j + 1];
			}
		}
	}
	currentShowtimeCnt--;
}


void Hall::changeScheduleSlot(Movie m, string& s){
	string tempShowtime = "";
	int slot;
	for (int i = 0; i < currentShowtimeCnt; ++i) {
		if (showtimes[i] == s) {
			tempShowtime = s;
			slot = i;
		}
	}
	if (tempShowtime == "") {
		cout << "This showtime is not available in your chosen hall.\n";
		return;
	}

	Movie tempMovie = Movie();
	for (int i = 0; i < currentFilmCnt; ++i) {
		if (filmList[i] == m) tempMovie = m;
	}
	if (tempMovie == Movie()) {
		cout << "This movie does not screen in the selected hall.\n";
		return;
	}

	schedule[slot] = m; schedule[slot].setTime(s);
}
*/


