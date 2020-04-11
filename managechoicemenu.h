#ifndef MANAGECHOICEMENU_H
#define MANAGECHOICEMENU_H

#include <QtWidgets/QDialog>
#include "managegamemenu.h"
#include "manageplayermenu.h"

namespace Ui {
class ManageChoiceMenu;
}

class ManageChoiceMenu : public QDialog
{
    Q_OBJECT

public:
    explicit ManageChoiceMenu(QWidget *parent = nullptr);
    ~ManageChoiceMenu();


public slots:
    void on_pushButton_clicked();
    void changeWindow();
    void on_managePlayers_clicked();

private:
    Ui::ManageChoiceMenu *ui;
    ManageGameMenu* manageGame;
    ManagePlayerMenu* managePlayers;
};

#endif // MANAGECHOICEMENU_H
