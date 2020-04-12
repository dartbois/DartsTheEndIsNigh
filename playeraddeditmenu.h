#ifndef PLAYERADDEDITMENU_H
#define PLAYERADDEDITMENU_H

#include <QDialog>
#include "player.h"


namespace Ui {
class PlayerAddEditMenu;
}

class PlayerAddEditMenu : public QDialog
{
    Q_OBJECT

public:
    player initNewPlayer();
    int oPID;
    explicit PlayerAddEditMenu(QWidget *parent = nullptr);
    ~PlayerAddEditMenu();

private slots:
    void on_AddPlayerInfo_clicked();

    void on_EditPlayerInfo_clicked();

signals:
    void refreshList();

private:
    Ui::PlayerAddEditMenu *ui;
};

#endif // PLAYERADDEDITMENU_H
