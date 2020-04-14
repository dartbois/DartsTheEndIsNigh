#include "gamereviewmenu.h"
#include "ui_gamereviewmenu.h"

GameReviewMenu::GameReviewMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameReviewMenu)
{

    ui->setupUi(this);
    this->setWindowTitle("Game Review  ");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);

}

GameReviewMenu::~GameReviewMenu()
{

    delete ui;

}

void GameReviewMenu::on_gameReviewEdit_clicked()
{

}

void GameReviewMenu::on_gameReviewCancel_clicked()
{

}
