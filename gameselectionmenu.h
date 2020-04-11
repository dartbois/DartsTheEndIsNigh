#ifndef GAMESELECTIONMENU_H
#define GAMESELECTIONMENU_H

#include <QDialog>
#include "scorerview.h"
#include "audienceview.h"
#include "matchstartdata.h"

namespace Ui {
class GameSelectionMenu;
}

class GameSelectionMenu : public QDialog
{
    Q_OBJECT

public:
    void FillGameList();
    explicit GameSelectionMenu(QWidget *parent = nullptr);
    ~GameSelectionMenu();

private slots:
    void on_pushButton_clicked();

signals:
    void sendScorerViewMSD(int startVal);

private:
    Ui::GameSelectionMenu *ui;
    AudienceView* audienceWindow;
    ScorerView* scorerWindow;

    public:
        MatchStartData myMSD;
};

#endif // GAMESELECTIONMENU_H
