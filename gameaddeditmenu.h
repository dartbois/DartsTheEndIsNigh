#ifndef GAMEADDEDITMENU_H
#define GAMEADDEDITMENU_H

#include <QDialog>

namespace Ui {
class GameAddEditMenu;
}

class GameAddEditMenu : public QDialog
{
    Q_OBJECT

public:
    explicit GameAddEditMenu(QWidget *parent = nullptr);
    ~GameAddEditMenu();

private:
    Ui::GameAddEditMenu *ui;
};

#endif // GAMEADDEDITMENU_H
