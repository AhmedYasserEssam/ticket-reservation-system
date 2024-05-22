#include "GUItesting.h"
#include "Customer.h"
#include "Movie.h"
#include <ctime>
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
    Movie M[3];
    M[0] = Movie("Cars 1", 2006, 120);
    M[1] = Movie("Cars 2", 2011, 185);
    M[2] = Movie("Cars 3", 2017, 190);

    for (int i = 0; i < 3; i++)
    {
        Movie_button[i] = new QPushButton(QString::fromStdString(M[i].getTitle()), this);
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
    auto ctime = time(nullptr);
    const int daySeconds = 24 * 60 * 60;
    Days = new QTabWidget(this);
    for (int i = 0; i < 3; ++i)
    {

        tm* nextDay = localtime(&ctime);
        ctime += daySeconds;
        char buffer[80];
        strftime(buffer, 80, "%A", nextDay);
        QString d = QString::fromStdString(std::string(buffer));

        Day[i] = new QWidget();
        Days->addTab(Day[i], d);
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
