#include "GUItesting.h"
#include <QtWidgets/QApplication>
#include <QLineEdit>
using namespace std;


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	GUItesting w;
	w.show();
	return a.exec();
}

//void createSchedules(Schedule s[], string d[], string h[])
//{
//	
//	cout << "SCHEDULE" << endl;
//}
//
//void setHalls(Hall H[])
//{
//	H[0] = Hall (10, 10, "H-01");
//	H[1] = Hall(6, 6, "H-02");
//	H[2] = Hall (10, 10, "H-03");
//	cout << "Halls" << endl;
//}
//
//void setCinemas(Cinema c[], const Movie[], const Hall H[], const Schedule s[])
//{
//	//
//	/*string days[3] = {};
//	createDays(days);
//	string hours[3] = { "10:30 AM","2:00 PM","7:45 PM" };
//	Schedule Sessions[9];
//	createSchedules(Sessions, days, hours);
//
//
//	Hall Halls[3];
//	setHalls(Halls);
//
//	Cinema Cinemas[9];
//	setCinemas(Cinemas, Movies, Halls, Sessions);*/
//}