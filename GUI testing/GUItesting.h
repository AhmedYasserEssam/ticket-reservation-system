#pragma once
#include <QtWidgets/QMainWindow>
#include "Cinema.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "ui_GUItesting.h"


class GUItesting : public QMainWindow
{
    Q_OBJECT

public:
    GUItesting(QWidget *parent = nullptr);
    ~GUItesting();

public slots:
    void DisplayMovies();
    void DisplaySessions();
    void MainMenu();
    void DisplayHall();
    void Select();
    void Deselect();
    void BookTickets();
    void CreateCustomer();
private:
    Ui::GUItestingClass ui;

    QLabel* Header, *ButtonLabel[3];
    QPushButton *tickets, *Admin, *Movie_button[3], *ReturnButton, *sessionButtons[9], *Confirm;
    QLineEdit* Namebar, * Email, * CardNumber, * CardHolder, * CVV;
    QIcon rbutton, rseat, eseat, adminbtn, usericon,seseat;
    QPushButton*** Chairs;
    QTabWidget* Days;
    QWidget* Day[3];
    Cinema MainCinema;
    TimeTable schedule = MainCinema.getSchedule();
    Movie M;
    Hall h;
    Session slot;
    Reservation *reservedChair;
    string MovieName;
    string DayDate;
    string timing;
    string HallIdentifier;
};
