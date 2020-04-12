#ifndef PLAYERADDEDITMENU_H
#define PLAYERADDEDITMENU_H

#include <QDialog>


namespace Ui {
class PlayerAddEditMenu;
}

class PlayerAddEditMenu : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerAddEditMenu(QWidget *parent = nullptr);
    ~PlayerAddEditMenu();

private:
    Ui::PlayerAddEditMenu *ui;
};

#endif // PLAYERADDEDITMENU_H
