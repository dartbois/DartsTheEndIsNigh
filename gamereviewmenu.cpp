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
    this->hide();
}

void GameReviewMenu::on_EditP1Throws_clicked()
{
    editThrowsMenu = new EditThrowsMenu();
    editThrowsMenu -> show();
}

void GameReviewMenu::on_EditP2Throws_clicked()
{
    editThrowsMenu = new EditThrowsMenu();
    editThrowsMenu -> show();
}

void GameReviewMenu::on_ChangeWinner_clicked()
{

}
