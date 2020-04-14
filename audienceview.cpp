#include "audienceview.h"
#include "ui_audienceview.h"
#include "scorerview.h"
#include "datahandler.h"
#include "player.h"


AudienceView::AudienceView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AudienceView)
{
    ui->setupUi(this);
    this->setWindowTitle("Audience View");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);


    QString Stats = "                                 ";
    StatisticsDisplay = ui->StatisticsDisplay;
    Player2Stats = ui->Player2Stats;
    BothP1AndP2Stats = ui->BothP1AndP2Stats;
    CurrentPlayer = ui->CurrentPlayer;
    NumberOf180s = ui->NumberOf180s;
    WinPercentages = ui->WinPercentages;
    PersonalStats = ui->PersonalStats;
    MatchStats = ui->MatchStats;
    RankedStats = ui->RankedStats;
    playerCounter = 1;
}

AudienceView::~AudienceView()
{
    delete ui;
}

void AudienceView::on_StatisticsDisplay_linkActivated(const QString &link)
{

}

void AudienceView::on_Player2Stats_linkActivated(const QString &link)
{

}

void AudienceView::on_BothP1AndP2Stats_linkActivated(const QString &link)
{

}

void AudienceView::on_CurrentPlayer_linkActivated(const QString &link)
{

}

void AudienceView::on_NumberOf180s_linkActivated(const QString &link)
{

}

void AudienceView::on_WinPercentages_linkActivated(const QString &link)
{

}

void AudienceView::on_PersonalStats_linkActivated(const QString &link)
{

}

void AudienceView::on_MatchStats_linkActivated(const QString &link)
{

}

void AudienceView::on_RankedStats_linkActivated(const QString &link)
{

}

void AudienceView::setPlayerOneStatsText()
{
    DataHandler myD;
    player myP(1,3);

    QString stats;
    QString statsName, statsHome, statsRank, statsAvg180s;
    QString temp2;

    statsName = "Name: ";
    string temp = myP.playerFirst[0];
    temp2 = QString::fromStdString(temp);
    statsName.append(temp2);
    statsName.append(" ");
    temp = myP.playerLast[0];
    temp2 = QString::fromStdString(temp);
    statsName.append(temp2);
    statsName.append("\n");

    statsHome = "Hometown: ";
    temp = myP.playerHometown[0];
    temp2 = QString::fromStdString(temp);
    statsHome.append(temp2);
    statsHome.append("\n");

    statsRank = "League Rank: ";
    int tempInt = myP.playerRanking[0];
    temp2 = QString::number(tempInt);
    statsRank.append(temp2);
    statsRank.append("\n");

    statsAvg180s = "Average 180s per Match: ";
    float tempFloat = myP.playerAvg180s[0];
    temp2 = QString::number(tempFloat);
    statsAvg180s.append(temp2);
    statsAvg180s.append("\n");

    stats = "";
    stats.append(statsName);
    stats.append(statsHome);
    stats.append(statsRank);
    stats.append(statsAvg180s);

    ui->StatisticsDisplay->setText(stats);
}

void AudienceView::setPlayerTwoStatsText()
{
    DataHandler myD;
    player myP(1,3);

    QString stats;
    QString statsName, statsHome, statsRank, statsAvg180s;
    QString temp2;

    statsName = "Name: ";
    string temp = myP.playerFirst[1];
    temp2 = QString::fromStdString(temp);
    statsName.append(temp2);
    statsName.append(" ");
    temp = myP.playerLast[1];
    temp2 = QString::fromStdString(temp);
    statsName.append(temp2);
    statsName.append("\n");

    statsHome = "Hometown: ";
    temp = myP.playerHometown[1];
    temp2 = QString::fromStdString(temp);
    statsHome.append(temp2);
    statsHome.append("\n");

    statsRank = "League Rank: ";
    int tempInt = myP.playerRanking[1];
    temp2 = QString::number(tempInt);
    statsRank.append(temp2);
    statsRank.append("\n");

    statsAvg180s = "Average 180s per Match: ";
    float tempFloat = myP.playerAvg180s[1];
    temp2 = QString::number(tempFloat);
    statsAvg180s.append(temp2);
    statsAvg180s.append("\n");

    stats = "";
    stats.append(statsName);
    stats.append(statsHome);
    stats.append(statsRank);
    stats.append(statsAvg180s);


    ui->Player2Stats->setText(stats);
}

void AudienceView::setBothP1AndP2StatsText()
{
    ui->BothP1AndP2Stats->setText("Player One and Player Two Statistics : ");
}

void AudienceView::setCurrentPlayerText()
{
    ui->CurrentPlayer->setText("Current Player Statistics : ");
}

void AudienceView::setNumberOf180sText()
{
    ui->NumberOf180s->setText("Number of 180s : ");
}

void AudienceView::setWinPercentagesText()
{
    ui->WinPercentages->setText("Win Percentages : ");
}

void AudienceView::setPersonalStatsText()
{
    ui->PersonalStats->setText("Personal Statistics : ");
}

void AudienceView::setMatchStatsText()
{
    ui->MatchStats->setText("Match Statistics : ");
}

void AudienceView::setRankedStatsText()
{
    ui->RankedStats->setText("Ranked Statistics : ");
}

void AudienceView::undoRankedText()         //Experimental
{
    ui->RankedStats->clear();
}

void AudienceView::undoMatchStatsText()
{
    ui->MatchStats->clear();
}

void AudienceView::undoPlayerTwoStatsText()
{
    ui->Player2Stats->clear();
}

void AudienceView::undoBothP1AndP2StatsText()
{
    ui->BothP1AndP2Stats->clear();
}
void AudienceView::undoCurrentPlayerText()
{
    ui->CurrentPlayer->clear();
}

void AudienceView::undoNumberOf180sText()
{
    ui->NumberOf180s->clear();
}

void AudienceView::undoWinPercentagesText()
{
    ui->WinPercentages->clear();
}

void AudienceView::undoPersonalStatsText()
{
    ui->PersonalStats->clear();
}

void AudienceView::undoPlayerOneStatsText()
{
    ui->StatisticsDisplay->clear();
}

void AudienceView::setLatestThrowText(QString *latestThrow)
{
    if(playerCounter % 2 == 1)
    {
        ui->PlayerOneLastThrowLabel->setText(*latestThrow);
    }
    else
    {
        ui->PlayerTwoLastThrowLabel->setText(*latestThrow);
    }
    playerCounter++;
}
