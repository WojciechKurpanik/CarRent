#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QDialog>

namespace Ui {
class UserInterface;
}

class UserInterface : public QDialog
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = nullptr);
    ~UserInterface();

private slots:
    void on_comboBox_ChooseACar_currentIndexChanged(int index);

    void on_comboBox_CarSelect_activated(int index);

private:
    Ui::UserInterface *ui;
};

#endif // USERINTERFACE_H
