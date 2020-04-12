#include "gameaddeditmenu.h"
#include "ui_gameaddeditmenu.h"

GameAddEditMenu::GameAddEditMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameAddEditMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Game addintion/Edit ");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
}

GameAddEditMenu::~GameAddEditMenu()
{
    delete ui;
}
