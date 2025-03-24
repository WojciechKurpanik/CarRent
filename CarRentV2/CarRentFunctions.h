#ifndef CARRENTFUNCTIONS_H
#define CARRENTFUNCTIONS_H
#include "CarRentClassHeader.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

class CarRentFunctions
{
public:
    CarRentFunctions();  
};

//vector<car> CarStorage;
bool add_user(string, string);
bool add_car(string, string, string, string, string, string, string, string, string, string, string);
bool is_in_UserDatabase(string, string);
//bool CheckRent(user);
void getCar();
//stack<car*> Garage; nie działa jak na dzień 25.04

#endif // CARRENTFUNCTIONS_H
