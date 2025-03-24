#ifndef CARRENTCLASSHEADER_H
#define CARRENTCLASSHEADER_H
#include <string>
#include <vector>
#include <stack>
using namespace std;

class user{
private:
    string login, password;
public:
    //string login;
    //string password;

    user(string login, string password){
        this->login = login;
        this->password = password;
    }

    /*~user(){
        delete password;
        delete login;
    }*/
};

class car{
public:
    string vin;
    string brand, model, gas_type, engine_type, country;
    string power, production_year, engine_capacity, rent_price;
    string status; //czy dostępny - tak lub nie

    car(string vin, string brand, string model, string gas_type, string engine_type, string country, string power, string production_year, string engine_capacity, string rent_price, string status="false"){
        this->vin = vin;
        this->brand = brand;
        this->model = model;
        this->gas_type = gas_type;
        this->engine_type =engine_type;
        this->country = country;
        this->power = power;
        this->production_year = production_year;
        this->engine_capacity = engine_capacity;
        this->rent_price = rent_price;
        this->status = status;
    }
};

#endif // CARRENTCLASSHEADER_H
