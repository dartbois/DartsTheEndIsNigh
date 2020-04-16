#include "editthrowsmenu.h"
#include "ui_editthrowsmenu.h"

EditThrowsMenu::EditThrowsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditThrowsMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Edit Throws Menu");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
}

EditThrowsMenu::~EditThrowsMenu()
{
    delete ui;
}

void EditThrowsMenu::on_pushButton_clicked()
{
    this->hide();
}

void EditThrowsMenu::on_Edit_clicked()
{

}
