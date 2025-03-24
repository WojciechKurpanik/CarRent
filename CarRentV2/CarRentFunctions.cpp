#include "carrentmain.h"
#include "./ui_carrentmain.h"
#include "CarRentFunctions.h"
#include "CarRentClassHeader.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

bool add_user(string login, string password){ // sprawdzanie czy można utworzyć konto ( czy login nie jest zajęty)
    ifstream userDataRead;
    userDataRead.open("/Users/wojtekkurpanik/Desktop/Studia/CP/CarRent/Resources/data/users.txt");
    if(!userDataRead.is_open())
        cerr << "User data file error";
    string line;
    while(getline(userDataRead, line)){
        cout << line << endl;
        istringstream LineFromUserDataRead(line);
        string login_from_file, password_from_file;
        LineFromUserDataRead >> login_from_file >> password_from_file;
        if(login == login_from_file)
            return false; //użytkownik o taki loginie już istnieje
    }
    userDataRead.close();
    ofstream userDataWrite;
    userDataWrite.open("/Users/wojtekkurpanik/Desktop/Studia/CP/CarRent/Resources/data/users.txt", ios::app);
    if (!userDataWrite.is_open())
        cerr << "User data file error";
    userDataWrite << login << " " << password;
    userDataWrite << endl;
    userDataWrite.close();
    return true;
}

bool add_car(string vin , string brand, string model, string gas_type, string engine_type, string country, string power, string production_year, string engine_capacity, string rent_price, string status){
    ifstream carsDataRead;
    carsDataRead.open("/Users/wojtekkurpanik/Desktop/Studia/CP/CarRent/Resources/data/cars.txt");
    if(!carsDataRead.is_open())
        cerr << "Cars file opening error";
    string line;
    while(getline(carsDataRead, line)){
        istringstream LineFromCarsDataRead(line);
        string brand_from_file, model_from_file, gas_type_from_file, engine_type_from_file, country_from_file, vin_from_file;
        string power_from_file, production_year_from_file, engine_capacity_from_file, rent_price_from_file;
        string status_from_file;
        LineFromCarsDataRead >> vin_from_file >> brand_from_file >> model_from_file >> gas_type_from_file >> engine_type_from_file >> country_from_file >> power_from_file >> production_year_from_file >> engine_capacity_from_file >> rent_price_from_file >> status_from_file;
        if(vin == vin_from_file)
            return false; //ten samochód znajduje się juz w bazie
    }
    carsDataRead.close();
    ofstream carsDataWrite;
    carsDataWrite.open("/Users/wojtekkurpanik/Desktop/Studia/CP/CarRent/Resources/data/cars.txt", ios::app);
    if (!carsDataWrite.is_open())
        cerr << "Cars file opening error";
    carsDataWrite << vin << " " <<  brand << " " <<  model << " " <<  gas_type << " " <<  engine_type << " " <<  country << " " <<  power << " " <<  production_year << " " <<  engine_capacity << " " <<  rent_price << " " << status;
    carsDataWrite << endl;
    carsDataWrite.close();
    return true;
}

bool is_in_UserDatabase(string login, string password){
    ifstream userLoginDataRead;
    userLoginDataRead.open("/Users/wojtekkurpanik/Desktop/Studia/CP/CarRent/Resources/data/users.txt");
    if(!userLoginDataRead.is_open())
        cerr << "User data file error";
    string line;
    while(getline(userLoginDataRead, line)){
        istringstream LineFromLoginUserDataRead(line);
        string login_from_Database, password_from_Database;
        LineFromLoginUserDataRead >> login_from_Database >> password_from_Database;
        if(login == login_from_Database){
            if(password == password_from_Database)
                return true;
        }
    }
    userLoginDataRead.close();
    return false;
}

void getCar(){
    ifstream carsDataRead;
    carsDataRead.open("/Users/wojtekkurpanik/Desktop/Studia/CP/CarRent/Resources/data/cars.txt");
    if(!carsDataRead.is_open())
        cerr << "Cars file opening error";
    string line;
    while(getline(carsDataRead, line)){
        istringstream LineFromCarsDataRead(line);
        string brand_from_file, model_from_file, gas_type_from_file, engine_type_from_file, country_from_file, vin_from_file;
        string power_from_file, production_year_from_file, engine_capacity_from_file, rent_price_from_file;
        string status_from_file;
        LineFromCarsDataRead >> vin_from_file >> brand_from_file >> model_from_file >> gas_type_from_file >> engine_type_from_file >> country_from_file >> power_from_file >> production_year_from_file >> engine_capacity_from_file >> rent_price_from_file >> status_from_file;
        //car* currentCar = new car(vin_from_file, brand_from_file, model_from_file, gas_type_from_file, engine_type_from_file, country_from_file, power_from_file, production_year_from_file, engine_capacity_from_file, rent_price_from_file, status_from_file);
        //Garage.push(currentCar);
        //car.CarStorage.push_back(currentCar); //jak na razie nei działa
    }
}

/*bool CheckRent(user currentUser){
    ifstream DoIHaveARent;
    DoIHaveARent.open("/Users/wojtekkurpanik/Desktop/Studia/CP/CarRent/Resources/data/rents.txt");
    if(!DoIHaveARent.is_open())
        cerr << "Cars file opening error";
    string line;
    while(getline(DoIHaveARent, line)){
        istringstream LineFromRentsFile(line);
        string login_from_rents, vin_from_rents, brand_from_rents, model_from_rents, date_from_from_rents, date_to_from_rents;
        LineFromRentsFile >> login_from_rents >> vin_from_rents >> brand_from_rents >> model_from_rents >> date_from_from_rents >> date_to_from_rents;
        if(currentUser.login == login_from_rents){
            return true;
        }
    }

}*/

CarRentFunctions::CarRentFunctions()
{

}
