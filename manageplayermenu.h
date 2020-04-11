#ifndef MANAGEPLAYERMENU_H
#define MANAGEPLAYERMENU_H

#include <QtWidgets/QDialog>
#include "playeraddeditmenu.h"

namespace Ui {
class ManagePlayerMenu;
}

class ManagePlayerMenu : public QDialog
{
    Q_OBJECT

public:
    void FillPlayerList(); 
    explicit ManagePlayerMenu(QWidget *parent = nullptr);
    ~ManagePlayerMenu();

private slots:
    void on_PlayerMenuAdd_clicked();

    void on_PlayerMenuEdit_clicked();

    void on_PlayerMenuRemove_clicked();

    void refreshPlayerAdded();

private:
    Ui::ManagePlayerMenu *ui;
     PlayerAddEditMenu* playerAddEditMenu;
};

#endif // MANAGEPLAYERMENU_H
