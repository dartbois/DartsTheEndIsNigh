#include "scorerview.h"
#include "ui_scorerview.h"
#include "audienceview.h"
#include <String>
#include <QDebug>


ScorerView::ScorerView(AudienceView *audienceWindow) :
    //QDialog(parent),
    ui(new Ui::ScorerView)
{
    ui->setupUi(this);
    this->setWindowTitle("Scorer Window");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
    QString scoreString = "                                 ";
    SlingOneText = ui->SlingOne;
    SlingTwoText = ui ->SlingTwo;
    SlingThreeText = ui->SlineThree;


    //connect the show stats signals to the audience window slots
   connect(this, &ScorerView::sendPlayerOneStats, audienceWindow, &AudienceView::setPlayerOneStatsText);
   connect(this, &ScorerView::sendPlayerTwoStats, audienceWindow, &AudienceView::setPlayerTwoStatsText);
   connect(this, &ScorerView::sendPlayerOneAndPlayerTwoStats, audienceWindow, &AudienceView::setBothP1AndP2StatsText);
   connect(this, &ScorerView::sendCurrentPlayerStats, audienceWindow, &AudienceView::setCurrentPlayerText);
   connect(this, &ScorerView::sendNumberOf180s, audienceWindow, &AudienceView::setNumberOf180sText);
   connect(this, &ScorerView::sendWinPercentages, audienceWindow, &AudienceView::setWinPercentagesText);
   connect(this, &ScorerView::sendPersonalStats, audienceWindow, &AudienceView::setPersonalStatsText);
   connect(this, &ScorerView::sendMatchStats, audienceWindow, &AudienceView::setMatchStatsText);
   connect(this, &ScorerView::sendRankedStats, audienceWindow, &AudienceView::setRankedStatsText);


   //connect the label-clearing undo signals to the audience window slots
   connect(this, &ScorerView::sendRankedStatsUndo, audienceWindow, &AudienceView::undoRankedText);
   connect(this, &ScorerView::sendMatchStatsUndo, audienceWindow, &AudienceView::undoMatchStatsText);
   connect(this, &ScorerView::sendPlayerOneStatsUndo, audienceWindow, &AudienceView::undoPlayerOneStatsText);
   connect(this, &ScorerView::sendCurrentPlayerStatsUndo, audienceWindow, &AudienceView::undoCurrentPlayerText);
   connect(this, &ScorerView::sendPlayerOneAndPlayerTwoStatsUndo, audienceWindow, &AudienceView::undoBothP1AndP2StatsText);
   connect(this, &ScorerView::sendNumberOf180sUndo, audienceWindow, &AudienceView::undoNumberOf180sText);
   connect(this, &ScorerView::sendWinPercentagesUndo, audienceWindow, &AudienceView::undoWinPercentagesText);
   connect(this, &ScorerView::sendPersonalStatsUndo, audienceWindow, &AudienceView::undoPersonalStatsText);
   connect(this, &ScorerView::sendPlayerTwoStatsUndo, audienceWindow, &AudienceView::undoPlayerTwoStatsText);




}

ScorerView::~ScorerView()
{
    delete ui;
}

void ScorerView::on_PlayerOneStats_clicked()
{
    if(ui->PlayerOneStats->isChecked())
    {
        emit sendPlayerOneStats();
    }
    else
    {
        emit sendPlayerOneStatsUndo();
    }
}

void ScorerView::on_PlayerTwoStats_clicked()
{
    if(ui->PlayerTwoStats->isChecked())
    {
        emit sendPlayerTwoStats();
    }
    else
    {
        emit sendPlayerTwoStatsUndo();
    }
}

void ScorerView::on_PlayerOneAndPlayerTwoStats_clicked()
{
    if(ui->PlayerOneAndPlayerTwoStats->isChecked())
    {
        emit sendPlayerOneAndPlayerTwoStats();
    }
    else
    {
        emit sendPlayerOneAndPlayerTwoStatsUndo();
    }
}

void ScorerView::on_CurrentPlayerStats_clicked()
{
    if(ui->CurrentPlayerStats->isChecked())
    {
        emit sendCurrentPlayerStats();
    }
    else
    {
        emit sendCurrentPlayerStatsUndo();
    }
}

void ScorerView::on_NumberOf180s_clicked()
{
    if(ui->NumberOf180s->isChecked())
    {
        emit sendNumberOf180s();
    }
    else
    {
        emit sendNumberOf180sUndo();
    }
}

void ScorerView::on_WinPercentages_clicked()
{
    if(ui->WinPercentages->isChecked())
    {
        emit sendWinPercentages();
    }
    else
    {
        emit sendWinPercentagesUndo();
    }
}

void ScorerView::on_PersonalStats_clicked()
{
    if(ui->PersonalStats->isChecked())
    {
        emit sendPersonalStats();
    }
    else
    {
        emit sendPersonalStatsUndo();
    }
}

void ScorerView::on_MatchStats_clicked()
{
    if(ui->MatchStats->isChecked())
    {
        emit sendMatchStats();
    }
    else
    {
        emit sendMatchStatsUndo();
    }
}

void ScorerView::on_RankedStats_clicked()
{
    if(ui->RankedStats->isChecked())
    {
        emit sendRankedStats();
    }
    else
    {
        emit sendRankedStatsUndo();
    }
}

void ScorerView::set_SlingOneText(int score)
{
    SlingOneText -> setText(QString::number(score));
}

void ScorerView::set_SlingTwoText(int score)
{
    SlingTwoText -> setText(QString::number(score));
}

void ScorerView::set_SlingThreeText(int score)
{
    SlingThreeText -> setText(QString::number(score));
}

void ScorerView::on_ValadationYes_clicked()
{
    QString slingHolder = "";
    //code to get values from slings 1, 2, 3
    if (myP.active == true) { //if player 1 is active
        slingHolder = SlingOneText->text();
        myP.p1Slings.append(slingHolder);
        myP.p1Slings.append("-");
        slingHolder = SlingTwoText->text();
        myP.p1Slings.append(slingHolder);
        myP.p1Slings.append("-");
        slingHolder = SlingThreeText->text();
        myP.p1Slings.append(slingHolder);
        myP.p1Slings.append("/t");
    }
    else { //if myP.active is false, player2 is active
        slingHolder = SlingOneText->text();
        myP.p2Slings.append(slingHolder);
        myP.p2Slings.append("-");
        slingHolder = SlingTwoText->text();
        myP.p2Slings.append(slingHolder);
        myP.p2Slings.append("-");
        slingHolder = SlingThreeText->text();
        myP.p2Slings.append(slingHolder);
        myP.p2Slings.append("/t");
    }
    //code that does score calculation and stuff

    //flips a boolean value which controls which player is being affected by all this
    myP.active = !(myP.active);

    SlingOneText->clear();
    SlingTwoText->clear();
    SlingThreeText->clear();

    emit sendValidateTrue(false);    //sending false will unblock the scoring
}

void ScorerView::on_ValadationNo_clicked()
{
    SlingOneText->clear();
    SlingTwoText->clear();
    SlingThreeText->clear();
    emit sendValidateTrue(false);    //sending false will unblock the scoring
}

void ScorerView::on_SlingOne_linkActivated(const QString &link)
{

}

void ScorerView::on_SlingTwo_linkActivated(const QString &link)
{

}

void ScorerView::on_SlineThree_linkActivated(const QString &link)
{

}

void ScorerView::getMSD(MatchStartData myMSD){
    myM.currentScore[0] = myMSD.gameStartScore;
    myM.currentScore[1] = myMSD.gameStartScore;
    myM.startScore = myMSD.gameStartScore;
    myP.postInit(myMSD.gamePs[0], myMSD.gamePs[1]);
}
