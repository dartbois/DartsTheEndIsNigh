#include "playeraddeditmenu.h"
#include "ui_playeraddeditmenu.h"

PlayerAddEditMenu::PlayerAddEditMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerAddEditMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Player Addition/Edit");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
}

PlayerAddEditMenu::~PlayerAddEditMenu()
{
    delete ui;
}
