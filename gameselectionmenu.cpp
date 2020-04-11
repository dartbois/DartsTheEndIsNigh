#include "gameselectionmenu.h"
#include "ui_gameselectionmenu.h"
#include "datahandler.h"

GameSelectionMenu::GameSelectionMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameSelectionMenu)
{
    ui->setupUi(this);
    audienceWindow = new AudienceView();
    scorerWindow = new ScorerView(audienceWindow);
    FillGameList();
}

GameSelectionMenu::~GameSelectionMenu()
{
    delete ui;
}

void GameSelectionMenu::on_pushButton_clicked()
{
    scorerWindow->show();
    audienceWindow->show();
    this->hide();
}

void GameSelectionMenu::FillGameList(){
    //Instance of datahandler
    DataHandler myD;

    //Begin by clearing the list
    ui->listWidget->clear();

    //Return a string of game info from sqlhandler. \n delimited.
    std::string gameInfo;
    gameInfo = myD.sqlGet("1:gameInfoList");
    QString QgameInfo;
    QgameInfo = QString::fromStdString(gameInfo);

    //Split the info by \n
    QStringList gameInfoList = QgameInfo.split('\n');

    //Add list to listWidget
    ui->listWidget->addItems(gameInfoList);
}
