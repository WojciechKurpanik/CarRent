#include "adminpanel.h"
#include "ui_adminpanel.h"
#include "CarRentClassHeader.h"
#include "CarRentFunctions.h"
#include <fstream>
#include <QMessageBox>
#include <QPixmap>

AdminPanel::AdminPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::on_pushButton_AddNewCar_clicked()
{
    QString vin = ui->lineEdit_VinInput->text();
    QString brand = ui->lineEdit_BrandInput->text();
    QString model= ui->lineEdit_ModelInput->text();
    QString gas_type = ui->lineEdit_GastypeInput->text();
    QString engine_type = ui->lineEdit_EngineTypeInput->text();
    QString country = ui->lineEdit_CountryInput->text();
    QString power = ui->lineEdit_PowerInput->text();
    QString production_year = ui->lineEdit_YearInput->text();
    QString engine_capacity = ui->lineEdit_capacityInput->text();
    QString rent_price = ui->lineEdit_PriceInput->text();

    if (vin.toStdString() !="" &&  brand.toStdString() !="" &&  model.toStdString() !="" &&  gas_type.toStdString() !="" &&  engine_type.toStdString() !="" &&  country.toStdString() !="" &&  power.toStdString() !="" &&  production_year.toStdString() !="" &&  engine_capacity.toStdString() !="" &&  rent_price.toStdString() !=""){
        //car nowy = new car(vin, brand, model, gas_type, engine_type, country, power, production_year, engine_capacity, rent_price);
        string status = "false";
        if (add_car(vin.toStdString() , brand.toStdString(), model.toStdString(), gas_type.toStdString(), engine_type.toStdString(), country.toStdString(), power.toStdString(), production_year.toStdString(), engine_capacity.toStdString(), rent_price.toStdString(), status)){
            ui->lineEdit_VinInput->clear();
            ui->lineEdit_BrandInput->clear();
            ui->lineEdit_ModelInput->clear();
            ui->lineEdit_GastypeInput->clear();
            ui->lineEdit_EngineTypeInput->clear();
            ui->lineEdit_CountryInput->clear();
            ui->lineEdit_PowerInput->clear();
            ui->lineEdit_YearInput->clear();
            ui->lineEdit_capacityInput->clear();
            ui->lineEdit_PriceInput->clear();
            ui->lineEdit_capacityInput->clear();
        }else{
            QMessageBox::warning(this,"404","Car adding error");
        }

    }
}

