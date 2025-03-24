#include "carrentmain.h"
#include "adminpanel.h"
#include "userinterface.h"
#include "CarRentClassHeader.h"
#include "CarRentFunctions.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QButtonGroup>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CarRentMain w;
    w.show();
    //ifstream usersData, carsData;
    //usersData.open(":/resources/data/Resources/data/users.rtf");
    //carsData.open(":/resources/data/Resources/data/cars.rtf");


    return a.exec();
}
