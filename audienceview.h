#ifndef AUDIENCEVIEW_H
#define AUDIENCEVIEW_H

#include <QDialog>
#include <QLabel>



namespace Ui {
class AudienceView;
}

class AudienceView : public QDialog
{
    Q_OBJECT

public:
    explicit AudienceView(QWidget *parent = nullptr);
    ~AudienceView();

public slots:

    void on_StatisticsDisplay_linkActivated(const QString &link);

    //The setText slots show the stats on the bottom pane of the audience view
    void setPlayerOneStatsText();
    void setPlayerTwoStatsText();
    void setBothP1AndP2StatsText();
    void setCurrentPlayerText();
    void setNumberOf180sText();
    void setWinPercentagesText();
    void setPersonalStatsText();
    void setMatchStatsText();
    void setRankedStatsText();
    void setLatestThrowText(QString *latestThrow);

    //The undo signals clear the bottom pane stats labels on the audience view
    void undoRankedText();      //Experimental
    void undoMatchStatsText();
    void undoPlayerTwoStatsText();
    void undoBothP1AndP2StatsText();
    void undoCurrentPlayerText();
    void undoNumberOf180sText();
    void undoWinPercentagesText();
    void undoPersonalStatsText();
    void undoPlayerOneStatsText();
public:
   Ui::AudienceView *ui;
   QLabel *StatisticsDisplay;
   QLabel *Player2Stats;
   QLabel *BothP1AndP2Stats;
   QLabel *CurrentPlayer;
   QLabel *NumberOf180s;
   QLabel *WinPercentages;
   QLabel *PersonalStats;
   QLabel *MatchStats;
   QLabel *RankedStats;


private slots:
   void on_Player2Stats_linkActivated(const QString &link);
   void on_BothP1AndP2Stats_linkActivated(const QString &link);
   void on_CurrentPlayer_linkActivated(const QString &link);
   void on_NumberOf180s_linkActivated(const QString &link);
   void on_WinPercentages_linkActivated(const QString &link);
   void on_PersonalStats_linkActivated(const QString &link);
   void on_MatchStats_linkActivated(const QString &link);
   void on_RankedStats_linkActivated(const QString &link);
};

#endif // AUDIENCEVIEW_H
