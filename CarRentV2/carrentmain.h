#ifndef CARRENTMAIN_H
#define CARRENTMAIN_H

#include <QMainWindow>
#include "adminpanel.h"
#include "userinterface.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class CarRentMain; }
QT_END_NAMESPACE

class CarRentMain : public QMainWindow
{
    Q_OBJECT

public:
    CarRentMain(QWidget *parent = nullptr);
    ~CarRentMain();

private slots:
    void on_loginButton_clicked();

    void on_CreateAccount_clicked(bool checked);

    void on_CreateAccount_2_clicked(bool checked);

private:
    Ui::CarRentMain *ui;
    UserInterface *userinterface;
    AdminPanel *adminpanel;
};

#endif // CARRENTMAIN_H
