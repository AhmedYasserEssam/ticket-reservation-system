#include "GUItesting.h"
#include "Customer.h"
#include "Movie.h"
#include "Schedule.h"
#include <ctime>
#include <QMessageBox>

#pragma warning(disable : 4996)

using namespace std;
GUItesting::GUItesting(QWidget* parent) : QMainWindow(parent)
{
    M[0] = Movie(" 1", 2006, 120);
    M[1] = Movie("Awlad Ragb 2", 2011, 185);
    M[2] = Movie("Awlad Ragb 3", 2017, 190);

    string hours[3] = { "10:00 AM","2:00 PM","8:15 PM" };
    
    /*auto ctime = time(nullptr);
    const int daySeconds = 24 * 60 * 60;
    for (int i = 0; i < 3; i++)
    {
        tm* nextDay = localtime(&ctime);
        char buffer[80];
        strftime(buffer, 80, "%A", nextDay);
        ctime += daySeconds;
    }*/
    ui.setupUi(this);
    this->setFixedSize(800, 600);
    ReturnButton = new QPushButton("Return Back", this);
    ReturnButton->hide();
    connect(ui.User, &QPushButton::clicked, this, &GUItesting::DisplayMovies);
}

GUItesting::~GUItesting()
{}

void GUItesting::DisplayMovies()
{
    QPushButton* BtnClicked = qobject_cast<QPushButton*>(sender());
    if (BtnClicked->text() == ReturnButton->text())
    {           
        for(int i=0;i<3;i++)
        {
            delete Day_tab[i];
            Day_tab[i] = nullptr;
        }
        delete Days_tabs;
        Days_tabs = nullptr;
    }
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
    ReturnButton->show();
    connect(ReturnButton, &QPushButton::clicked, this, &GUItesting::MainMenu);
}


void GUItesting::MainMenu() {
    for (int i = 0; i < 3; i++) 
    {
        delete Movie_button[i];
        Movie_button[i] = nullptr;
    }

    ReturnButton->hide();
    ui.Admin->show();
    ui.label->setText("Main Menu");
    ui.User->show();

    connect(ReturnButton, &QPushButton::clicked, this, &GUItesting::MainMenu);
}
void GUItesting::DisplaySessions()
{
    QPushButton* BtnClicked = qobject_cast<QPushButton*>(sender());
    int index;
    for (index = 0; index < 3; index++)
    {
        if (BtnClicked->text().toStdString() == M[index].getTitle())
        {
            break;
        }
    }

    Days_tabs = new QTabWidget(this);

    for (int i = 0; i < 3; ++i)
    {
        Movie_button[i]->hide();
        
        QString Day_name = QString::fromStdString(sessions[i);
        Day_tab[i] = new QWidget();
        Days_tabs->addTab(Day_tab[i], Day_name);
        Day_tab[i]->setGeometry(20 * (1 + i), 40, 20, 20);

    }
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            Days_buttons[k] = new QPushButton(QString::fromStdString(sessions[k].getHour()), Day_tab[j]);
            Days_buttons[k]->setGeometry((80 * (k + 1)+(160)*k), 150, 150, 50);
        }
    }
    Days_tabs->show();
    Days_tabs->setGeometry(0,100, 1000, 500);
    connect(ReturnButton, &QPushButton::clicked, this,&GUItesting::DisplayMovies);
}



void GUItesting::CreateCustomer()
{
    Customer C;
    //C.setName(ui.Namebar->text().toStdString());
   // QMessageBox msg;
    //msg.setText(QString::fromStdString(C.getName()));
    //msg.exec();
}
