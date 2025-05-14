#pragma once
#include <QtWidgets/QMainWindow>
#include "Cinema.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include "ui_GUItesting.h"
#include "Customer.h"
#include "CreditCard.h";

class GUItesting : public QMainWindow
{
    Q_OBJECT

public:
    GUItesting(QWidget *parent = nullptr);
    ~GUItesting();

public slots:
    void getAdminPassword();
    void DisplayMovies();
    void DisplaySessions();
    void MainMenu();
    void DisplayHall();
    void Select();
    void rSelected();
    void Deselect();
    void rDeselect();
    void BookTickets();
    void CreateCustomer();
    void ConfirmPayment();
    void CancelReservation();
    void pswrdConfirmation();
    void ChangeMovie();
    void submitName();
private:
    Ui::GUItestingClass ui;

    QLabel* Header, *ButtonLabel[3],*Money;
    QPushButton *tickets, *Admin, *Movie_button[3], *ReturnButton, *sessionButtons[9], *Confirm, *Payment, *cancel,*adminConfirm , *EditMovie,*Submit;
    QLineEdit* Namebar, * Email, * CardNumber, * CardHolder, * CVV, *AdminPassword, *NewMovie;
    QComboBox *Month, * Year, *movies;
    QIcon rbutton, rseat, eseat, adminbtn, usericon,seseat;
    QPushButton*** Chairs;
    QTabWidget* Days;
    QWidget* Day[3];
    Cinema MainCinema;
    TimeTable schedule = MainCinema.getSchedule();
    Customer C;
    CreditCard visa;
    Movie M;
    Hall h;
    Session slot;
    Reservation *reservedChair;
    string MovieName;
    string DayDate;
    string timing;
    string HallIdentifier;
    string sessionfile;
    int hsize;
    bool Interface = false;
};
