#include "Cinema.h"


Cinema::Cinema(){
	filmCnt = 3; filmList = new Movie[filmCnt];
	filmList[0] = Movie("Ashoush 1", 2005, 120);
	filmList[1] = Movie("Ashoush 2", 2006, 120);
	filmList[2] = Movie("Ashoush 3", 2007, 120);

	halls[0] = Hall(10, 10, "H-01");
	halls[1] = Hall(6, 6, "H-02");
	halls[2] = Hall (10, 10, "H-03");

	slotCnt = 27;  slots = new Session[slotCnt];
	for (int i = 0; i < timetable.getDays();i++ ){
		for (int j = 0; j < filmCnt; j++){
			for (int k = 0; k < 3; k++){
				slots[i * 9 + j * 3 + k] = Session(filmList[k], halls[k], timetable.getDayDate(i));
			}
		}
	}

	for (int i = 0; i < slotCnt; ++i) {
		cout << slots[i].getMovie() << 
	}


}
