#ifndef SCORERVIEW_H
#define SCORERVIEW_H

#include <QtWidgets/QDialog>
#include "audienceview.h"
#include "mathclass.h"
#include <QLabel>
#include "matchstartdata.h"
#include "player.h"

namespace Ui {
class ScorerView;
}

class ScorerView : public QDialog
{
    Q_OBJECT

public:
    explicit ScorerView(AudienceView *audienceWindow);
    ~ScorerView();

public slots:
    void on_PlayerOneStats_clicked();

    void on_PlayerTwoStats_clicked();

    void on_PlayerOneAndPlayerTwoStats_clicked();

    void on_CurrentPlayerStats_clicked();

    void on_RankedStats_clicked();

    void on_MatchStats_clicked();

    void on_PersonalStats_clicked();

    void on_WinPercentages_clicked();

    void on_NumberOf180s_clicked();

    void set_SlingOneText(int score);

    void set_SlingTwoText(int score);

    void set_SlingThreeText(int score);

    void getMSD(MatchStartData myMSD);



signals:

    //These signals will show the stats in the audience window
    void sendPlayerOneStats();

    void sendPlayerTwoStats();

    void sendPlayerOneAndPlayerTwoStats();

    void sendCurrentPlayerStats();

    void sendRankedStats();

    void sendMatchStats();

    void sendPersonalStats();

    void sendWinPercentages();

    void sendNumberOf180s();

    //These signals will clear the stats from the audience window
    void sendRankedStatsUndo();

    void sendMatchStatsUndo();

    void sendPersonalStatsUndo();

    void sendWinPercentagesUndo();

    void sendNumberOf180sUndo();

    void sendPlayerOneStatsUndo();

    void sendPlayerTwoStatsUndo();

    void sendPlayerOneAndPlayerTwoStatsUndo();

    void sendCurrentPlayerStatsUndo();

    //These signals will be used for validation of the scores
    void sendValidateTrue(bool unblockScore);

    void sendActivePlayer(player Activeplayer);




public:
    Ui::ScorerView *ui;
    QLabel *StatisticsDisplay;
    QLabel *Player2Stats;
    QLabel *BothP1AndP2Stats;
    QLabel *CurrentPlayer;
    QLabel *NumberOf180s;
    QLabel *WinPercentages;
    QLabel *PersonalStats;
    QLabel *MatchStats;
    QLabel *RankedStats;
    QLabel *SlingOneText;
    QLabel *SlingTwoText;
    QLabel *SlingThreeText;
    player *ActivePlayer;



private slots:
    void on_ValadationYes_clicked();
    void on_ValadationNo_clicked();
    void on_SlingOne_linkActivated(const QString &link);
    void on_SlingTwo_linkActivated(const QString &link);
    void on_SlineThree_linkActivated(const QString &link);

public:
    mathClass myM;
    int beginScore;
    player myP;

};

#endif // SCORERVIEW_H
