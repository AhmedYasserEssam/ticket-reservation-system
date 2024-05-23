#include "GUItesting.h"
#include "Customer.h"
#include "Movie.h"
#include "TimeTable.h"
#include <QMessageBox>

#pragma warning(disable : 4996)

GUItesting::GUItesting(QWidget* parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setFixedSize(800, 600);
    connect(ui.User, &QPushButton::clicked, this, &GUItesting::DisplayMovies);
    

}

GUItesting::~GUItesting()
{}

void GUItesting::DisplayMovies()
{
    for (int i = 0; i < 3; i++)
    {
        Movie M = MainCinema.getMovie(i);
        Movie_button[i] = new QPushButton(QString::fromStdString(M.getTitle()), this);
        Movie_button[i]->show();
        Movie_button[i]->setGeometry(120 + i * 200, 120, 170, 270);
    
        connect(Movie_button[i], &QPushButton::clicked, this, &GUItesting::DisplaySessions);

    }
    ui.Admin->hide();
    ui.User->hide();
    ui.label->setText("Choose A Movie");
   
}

void GUItesting::DisplaySessions()
{
   
    Days = new QTabWidget(this);
    for(int i = 0;i<3;i++)
    {
        TimeTable schedule = MainCinema.getSchedule();
        string name = schedule.getDayDate(2);
        Day[i] = new QWidget();
        Days->addTab(Day[i], QString::fromStdString(name));
        Day[i]->setGeometry(20 * (1 + i), 40, 20, 20);
        Movie_button[i]->hide(); 
    }

    Days->show();
    Days->setGeometry(0,100, 1000, 500);
}

void GUItesting::CreateCustomer()
{
    Customer C;
    //C.setName(ui.Namebar->text().toStdString());
   // QMessageBox msg;
    //msg.setText(QString::fromStdString(C.getName()));
    //msg.exec();
}
