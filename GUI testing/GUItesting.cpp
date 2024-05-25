#include <iostream>
#include <fstream>
#include "GUItesting.h"
#include "Customer.h"
#include "Movie.h"
#include "TimeTable.h"
#include <string>
#include <QPushButton>
#include <QApplication>
#include <QMessageBox>
#include <QRandomGenerator>

#pragma warning(disable : 4996)

GUItesting::GUItesting(QWidget* parent) : QMainWindow(parent)
{

    ui.setupUi(this);
    this->setFixedSize(1000, 750);

    usericon = QIcon("ticket.png");
    adminbtn = QIcon("admin.png");
    rbutton = QIcon("RB.png");
    eseat = QIcon("AvailableSeat.png");
    rseat = QIcon("ReservedSeat.png");
    seseat = QIcon("SelectedSeat.png");
    QFont font("Helvetica", 24, QFont::Bold);

    Header = new QLabel("Welcome to الشعب الصيني Cinema", this);
    tickets = new QPushButton(this);
    Admin = new QPushButton(this);

    tickets->setIcon(usericon);
    tickets->setIconSize(QSize(100, 100));
    tickets->setFixedSize(100, 100);
    tickets->setStyleSheet("border: none;");
    tickets->setGeometry(600, 200, 0, 0);

    Admin->setIcon(adminbtn);
    Admin->setIconSize(QSize(100, 100));
    Admin->setFixedSize(100, 100);
    Admin->setStyleSheet("border: none;");
    Admin->setGeometry(300, 200, 0, 0);

    Header->setFont(font);
    Header->setAlignment(Qt::AlignCenter);
    int labelWidth = 600;
    int labelHeight = 80;
    int x = (width() - labelWidth) / 2;
    int y = 30;
    Header->setGeometry(x, y, labelWidth, labelHeight);


    connect(tickets, &QPushButton::clicked, this, &GUItesting::DisplayMovies);
    ReturnButton = new QPushButton(this);
    ReturnButton->hide();
    ReturnButton->setIcon(rbutton);
    ReturnButton->setIconSize(QSize(50, 50));
    ReturnButton->setFixedSize(50, 50);
    ReturnButton->setStyleSheet("border: none;");
    ReturnButton->setGeometry(10, 2, 0, 0);
}

GUItesting::~GUItesting()
{}

void GUItesting::DisplayMovies()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton)
    {
        delete Days;
        Days = nullptr;   
    }
    ReturnButton->show();
    connect(ReturnButton, &QPushButton::clicked, this, &GUItesting::MainMenu);

    for (int i = 0; i < 3; i++)
    {
        slot = schedule.getTime(i, i);
        M = slot.getMovie();
        Movie_button[i] = new QPushButton(QString::fromStdString(M.getTitle()), this);
        Movie_button[i]->show();
        Movie_button[i]->setGeometry(225 + i * 200, 170, 170, 270);
    
        connect(Movie_button[i], &QPushButton::clicked, this, &GUItesting::DisplaySessions);

    }
    Admin->hide();
    tickets->hide();
    Header->setText("Choose A Movie");
   
}

void GUItesting::DisplaySessions()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    int hsize = h.getSize();
    if (clickedButton->text() == ReturnButton->text())
    {
        if (Chairs != nullptr) {
            for (int x = 0; x < hsize; x++) {
                if (Chairs[x] != nullptr) {
                    for (int y = 0; y < hsize; y++) {
                        delete Chairs[x][y];
                        Chairs[x][y] = nullptr;
                    }
                    delete[] Chairs[x];
                    Chairs[x] = nullptr;
                }
            }
            delete[] Chairs;
            Chairs = nullptr;
            MovieName = slot.getMovie().getTitle();
        }
    }
    else
    {
        MovieName = clickedButton->text().toStdString();
    }


    Days = new QTabWidget(this);
    int spacing = 100;
    for (int i = 0; i < 3; i++)
    {
        string name = schedule.getDayDate(i);
        Day[i] = new QWidget();
        Days->addTab(Day[i], QString::fromStdString(name));
        Day[i]->setGeometry(20 * (1 + i), 40, 20, 20);
        Movie_button[i]->hide();
    }
    int buttonIndex = 0;
   
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                slot = schedule.getTime(i, j);
                if (MovieName == slot.getMovie().getTitle())
                {
                    sessionButtons[buttonIndex] = new QPushButton(QString::fromStdString(slot.getTiming()), Day[j / 3]);
                    sessionButtons[buttonIndex]->show();
                    sessionButtons[buttonIndex]->setGeometry(250 + (j % 3) * 140, 100, 120, 80);
                    connect(sessionButtons[buttonIndex], &QPushButton::clicked, this, &GUItesting::DisplayHall);
                    buttonIndex++;
                }
            }
            if (buttonIndex == 9)
            {
                break;
            }
        }
    Days->show();
    Days->setGeometry(0,100, 1000, 500);
    connect(ReturnButton, &QPushButton::clicked, this, &GUItesting::DisplayMovies);

}

void GUItesting::MainMenu()
{
    for (int i = 0; i < 3; i++)
    {
        delete Movie_button[i];
        Movie_button[i] = nullptr;
    }
    ReturnButton->hide();
    Header->setText("Main Menu");
    Admin->show();
    tickets->show();
}

void GUItesting::DisplayHall()
{
    QMessageBox msg;
    
    Confirm = new QPushButton("Confirm", this);
    Confirm->show();
    connect(Confirm, &QPushButton::clicked, this, &GUItesting::BookTickets);
    connect(ReturnButton, &QPushButton::clicked, this, &GUItesting::DisplaySessions);

    bool flag = false;
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    timing = clickedButton->text().toStdString();
    int tabIndex = Days->indexOf(clickedButton->parentWidget());
    DayDate = Days->tabText(tabIndex).toStdString();


    delete Days;
    Days = nullptr;

    int indix = 0;
    int indiy = 0;
    for (int x = 0; x < 3; x++)
    {
        for (int  y =0 ; y < 9; y++)
        {
            slot = schedule.getTime(x, y);
           
            
            if (MovieName == slot.getMovie().getTitle() && timing == slot.getTiming() && DayDate == slot.getDayDate())
            {
                indix = x;
                indiy = y;
            }
        }
    }


    

    slot = schedule.getTime(indix, indiy);
    h = slot.getHall();
    
    int hsize = h.getSize();
   
    Chairs = new QPushButton * *[hsize];

    int seatWidth = 50;
    int seatHeight = 50; 

    string fname = "Session" + to_string(indix) + "-" + to_string(indiy) + ".txt";
    ifstream file(fname);
    string line;
    int lnum = 0;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line == "0") 
            {
                h.getSeat(lnum / 10, lnum % 10).setState(false);
            }
            else
            {
                h.getSeat(lnum / 10, lnum % 10).setState(true);
            }
            lnum++;
            
        }
        file.close();

    }
   
    for (int i = 0; i < hsize; i++)
    {
        Chairs[i] = new QPushButton * [hsize];
        for (int j = 0;  j < hsize; j++)
        {
            Seat chair = h.getSeat(i, j);
            QString seatId = QString::fromStdString(chair.getId());
            Chairs[i][j] = new QPushButton(seatId, this);
            if (chair.getState() == false)
            {
                Chairs[i][j]->setIcon(rseat);
                Chairs[i][j]->setEnabled(0);
            }
            else
            {
                Chairs[i][j]->setIcon(eseat);
                connect(Chairs[i][j], &QPushButton::clicked, this, &GUItesting::Select);
            }
            Chairs[i][j]->setIconSize(QSize(40, 40));
            Chairs[i][j]->setFixedSize(60, 60);
            Chairs[i][j]->setStyleSheet("QPushButton { color: transparent; border: none; }");
            
            int xPos = (j+5) * seatWidth;
            int yPos = (i+2.5) * seatHeight;

            // Set the geometry of the button
            Chairs[i][j]->setGeometry(xPos, yPos, seatWidth, seatHeight);

            // Show the button
            Chairs[i][j]->show();
        }
    }
    ButtonLabel[0] = new QLabel(this);
    ButtonLabel[0]->setPixmap(QPixmap("AvailableSeat.png").scaled(20, 20));
    ButtonLabel[0]->setText("Available Seat");
    ButtonLabel[0]->setContentsMargins(5, 5, 5, 5);

    

  

}

void GUItesting::Select()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    clickedButton->setIcon(seseat);
    connect(clickedButton, &QPushButton::clicked, this, &GUItesting::Deselect);
}

void GUItesting::Deselect()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    clickedButton->setIcon(eseat);
    connect(clickedButton, &QPushButton::clicked, this, &GUItesting::Select);

    
}

void GUItesting::BookTickets()
{
    connect(ReturnButton, &QPushButton::clicked, this, &GUItesting::MainMenu);
    QMessageBox msg;
    int hsize = h.getSize();
    Seat s;
    int numReserves = 0;

    int randomNumber = QRandomGenerator::global()->bounded(100, 1000);
    string num = std::to_string(randomNumber);
    HallIdentifier = h.getID()[0]; HallIdentifier += h.getID()[2]; HallIdentifier += num;

    for (int i = 0; i < hsize; i++)
    {
        for (int j = 0; j < hsize; j++)
        {
           
            QIcon btnicon = Chairs[i][j]->icon();
            QPixmap btnPixmap = btnicon.pixmap(btnicon.actualSize(QSize(100, 100)));
            QPixmap seseatPixmap = seseat.pixmap(seseat.actualSize(QSize(100, 100)));
            bool validity = btnPixmap.toImage() == seseatPixmap.toImage();
     
            if (validity)
            {
                numReserves++;
            }
        }
    }
    reservedChair = new Reservation(HallIdentifier, slot.getMovie(), numReserves);

    int placingIndex = 0;
    for (int i = 0; i < hsize; i++)
    {
        for (int j = 0; j < hsize; j++)
        {
            QIcon btnicon = Chairs[i][j]->icon();
            QPixmap btnPixmap = btnicon.pixmap(btnicon.actualSize(QSize(100, 100)));
            QPixmap seseatPixmap = seseat.pixmap(seseat.actualSize(QSize(100, 100)));
            bool validity = btnPixmap.toImage() == seseatPixmap.toImage();
            if (validity)
            {
                s = h.getSeat(i, j);
                h.getSeat(i, j).setState(false);
                reservedChair->addSeat(s, placingIndex++);
            }
        }
    }

    for (int i = 0; i < reservedChair->getSeatCnt(); ++i) {
        string messageID = reservedChair->getReserved(i);
        msg.setText(QString::fromStdString(messageID));
        msg.exec();
    }

    int indix, indiy;
    bool flag = false;
    for (int x =0 ; x < 3; x++)
    {
        for (int y =0; y < 9; y++)
        {
            if (schedule.getTime(x,y).getMovie().getTitle() == slot.getMovie().getTitle() && schedule.getTime(x, y).getHall().getID() == slot.getHall().getID() && schedule.getTime(x, y).getTiming() == slot.getTiming() && schedule.getTime(x, y).getDayDate() == slot.getDayDate())
            {
                indix = x; indiy = y;
            }
        }
    }
    string fname = "Session" + to_string(indix) + "-" + to_string(indiy) + ".txt";
    ofstream file(fname);
    if (file.is_open())
    {
        for (int i = 0; i < hsize; i++)
        {
            for (int j = 0; j < hsize; j++)
            {
                file << h.getSeat(i, j).getState();
                file << endl;
            }
        }
    }
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton->text() == Confirm->text())
    {
        if (Chairs != nullptr) {
            for (int x = 0; x < hsize; x++) {
                if (Chairs[x] != nullptr) {
                    for (int y = 0; y < hsize; y++) {
                        delete Chairs[x][y];
                        Chairs[x][y] = nullptr;
                    }
                    delete[] Chairs[x];
                    Chairs[x] = nullptr;
                }
            }
            delete[] Chairs;
            Chairs = nullptr;
        }
    }
    delete Confirm;
    Confirm = nullptr;
    delete Days;

    Days = nullptr;

    CreateCustomer();
}


void GUItesting::CreateCustomer()
{
    int width = 200;
    int height = 30;
    int x = (this->width() - width) / 2;
    int y = (this->height() - height) / 2;
    QString styleSheet = "QLineEdit {" "background-color: #f0f0f0;" "border: 1px solid #ccc;" "border-radius: 5px;" "padding: 5px;""}";
    Customer C;

    Namebar = new QLineEdit(this);
    Email = new QLineEdit(this);
    CardNumber = new QLineEdit(this);
    CardHolder = new QLineEdit(this);


    Namebar->show();
    Email->show();
    CardNumber->show();
    CardHolder->show();

    Namebar->setPlaceholderText("Name: ");
    Email->setPlaceholderText("E-mail: ");
    CardNumber->setPlaceholderText("Card Number: ");
    CardHolder->setPlaceholderText("Holder Name: ");

    Namebar->setStyleSheet(styleSheet);
    Email->setStyleSheet(styleSheet);
    CardNumber->setStyleSheet(styleSheet);
    CardHolder->setStyleSheet(styleSheet);


    C.setName(Namebar->text().toStdString());
    
    Namebar->setGeometry(x, y-250, width, height);
    Email->setGeometry(x, y-210, width, height);
    CardNumber->setGeometry(x, y - 170, width, height);
    CardHolder->setGeometry(x, y - 130, width, height);

   // QMessageBox msg;
    //msg.setText(QString::fromStdString(C.getName()));
    //msg.exec();
}
