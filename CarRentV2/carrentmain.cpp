#include "carrentmain.h"
#include "./ui_carrentmain.h"
#include "CarRentFunctions.h"
#include <fstream>
#include <QMessageBox>
#include <QPixmap>
using namespace std;

CarRentMain::CarRentMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CarRentMain)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/Resources/img/audi-rs6.png");
    int w = ui->label_car->width();
    int h = ui->label_car->height();
    ui->label_car->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //niewidzialne pole wpisowe
    ui->lineEdit_setpassword->setVisible(false);
    ui->SetPasswordLabel->setVisible(false);
    ui->CreateAccount_2->setVisible(false);
}

CarRentMain::~CarRentMain()
{
    delete ui;
}

void CarRentMain::on_loginButton_clicked()
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    if (login.toStdString() == "admin" && password.toStdString() == "admin"){
        close();
        adminpanel = new AdminPanel(this);
        adminpanel -> show();

    }
    else if(is_in_UserDatabase(login.toStdString(), password.toStdString())){
        close();
        userinterface = new UserInterface(this);
        userinterface -> show();
        //CheckRent(currentUser);
    }
    else{
        QMessageBox::warning(this,"Login","Login and password are incorrect!");
    }

}


void CarRentMain::on_CreateAccount_clicked(bool checked)
{
    ui->lineEdit_setpassword->setVisible(true);
    ui->SetPasswordLabel->setVisible(true);
    ui->CreateAccount_2->setVisible(true);
    ui->CreateAccount->setVisible(false);
}

void CarRentMain::on_CreateAccount_2_clicked(bool checked)
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    QString setpassword = ui->lineEdit_setpassword->text();
    if (login !=""){
        if (password == setpassword){
            if (add_user(login.toStdString(), password.toStdString())){
                close();
                userinterface = new UserInterface(this);
                userinterface -> show();
            }
            else{
                QMessageBox::warning(this,"404","Database not responding");
            }
        }
    }
    else{
        QMessageBox::warning(this,"Login","Login is incorrect!");
    }
}



