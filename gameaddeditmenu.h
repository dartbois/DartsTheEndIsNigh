#ifndef GAMEADDEDITMENU_H
#define GAMEADDEDITMENU_H

#include <QDialog>
#include "matchstartdata.h"

namespace Ui {
class GameAddEditMenu;
}

class GameAddEditMenu : public QDialog
{
    Q_OBJECT

public:
    MatchStartData initNewGame();
    int oGID;
    explicit GameAddEditMenu(QWidget *parent = nullptr);
    ~GameAddEditMenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void refreshGList();

private:
    Ui::GameAddEditMenu *ui;
};

#endif // GAMEADDEDITMENU_H
