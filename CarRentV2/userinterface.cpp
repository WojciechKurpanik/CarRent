#include "userinterface.h"
#include "ui_userinterface.h"
#include "carrentmain.h"
#include "adminpanel.h"
#include "CarRentClassHeader.h"
#include "CarRentFunctions.h"
using namespace std;

UserInterface::UserInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
}

UserInterface::~UserInterface()
{
    delete ui;
}

void UserInterface::on_comboBox_ChooseACar_currentIndexChanged(int index)
{
    /*car ShownCar = CarStorage.begin(); //przypisanie pierwszego samochodu od wyświetlanego
    CarStorage.cbegin(); //usunięcie pierwsego samochodu
    CarStorage.push_back(ShownCar); //przypisanie wyświetlanego samochodu jako ostatni
    QPixmap carpix(ShownCar.carphoto);*/

}


void UserInterface::on_comboBox_CarSelect_activated(int index)
{

}

