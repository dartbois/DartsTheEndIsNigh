#include "gameselectionmenu.h"
#include "ui_gameselectionmenu.h"
#include "datahandler.h"
#include "matchstartdata.h"

GameSelectionMenu::GameSelectionMenu(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::GameSelectionMenu)
{
    ui->setupUi(this);
    audienceWindow = new AudienceView();
    scorerWindow = new ScorerView(audienceWindow);
    FillGameList();
    connect(this, SIGNAL(sendScorerViewMSD(int)), scorerWindow, SLOT(getMSD(int)));
}

GameSelectionMenu::~GameSelectionMenu()
{
    delete ui;
}

void GameSelectionMenu::on_pushButton_clicked()
{
    //DataHandler myD;
    //get the ID of the selected list item
    //put it in a matchstartdata then send it to scorerview
    QListWidgetItem * myGame = ui->listWidget->currentItem();
    QStringList gameString = myGame->text().split("\t");
    QString gameIDstring = gameString[0];
    int gameID = gameIDstring.toInt();
    myMSD.postInit(gameID);
    //myD.matchGSMtoSV(scorerWindow, myMSD.gameStartScore);
    emit sendScorerViewMSD(myMSD.gameStartScore);

    scorerWindow->show();
    audienceWindow->show();
    this->hide();
}

void GameSelectionMenu::FillGameList(){
    //Instance of datahandler
    DataHandler myD;

    //Begin by clearing the list
    ui->listWidget->clear();

    QString header = "Game ID\tGame Name\tDate\tLocation\tPlayer1 ID\tPlayer2 ID";
    ui->listWidget->addItem(header);

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

/*
void GameSelectionMenu::sendScorerViewMSD(int startVal){
    //i'm tryin'
    return;
}
*/
