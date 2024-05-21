#pragma once

#include <QtWidgets/QMainWindow>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Movie.h"
#include "Schedule.h"
#include "ui_GUItesting.h"

class GUItesting : public QMainWindow
{
    Q_OBJECT

public:
    GUItesting(QWidget *parent = nullptr);
    ~GUItesting();


public slots:
    void CreateCustomer();
    void DisplayMovies();
    void DisplaySessions();
    void MainMenu();
private:
    Movie M[3];
    Schedule sessions[9];
    Ui::GUItestingClass ui;
    QPushButton* Movie_button[3];
    QTabWidget* Days_tabs;
    QWidget* Day_tab[3];
    QPushButton* Days_buttons[9];
    QPushButton* ReturnButton;
};
