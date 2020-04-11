#ifndef MANAGEGAMEMENU_H
#define MANAGEGAMEMENU_H

#include <QtWidgets/QDialog>
#include "gameaddeditmenu.h"


namespace Ui {
class ManageGameMenu;
}

class ManageGameMenu : public QDialog
{
    Q_OBJECT

public:
    void FillGameList();
    explicit ManageGameMenu(QWidget *parent = nullptr);
    ~ManageGameMenu();

private slots:
    void on_GameMenuAdd_clicked();

    void on_GameMenuEdit_clicked();

    void on_GameMenuRemove_clicked();

    void refreshGameAdded();

private:
    Ui::ManageGameMenu *ui;
    GameAddEditMenu* gameAddEditMenu;

};

#endif // MANAGEGAMEMENU_H
