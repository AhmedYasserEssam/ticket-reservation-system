#pragma once
#include <QtWidgets/QMainWindow>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "Movie.h"
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
private:
    Ui::GUItestingClass ui;
    QPushButton* Movie_button[3];
    QTabWidget* Days;
    QWidget* Day[3];
};
