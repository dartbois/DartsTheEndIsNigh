#ifndef GAMEREVIEWMENU_H
#define GAMEREVIEWMENU_H

#include <QDialog>

namespace Ui {
class GameReviewMenu;
}

class GameReviewMenu : public QDialog
{
    Q_OBJECT

public:
    explicit GameReviewMenu(QWidget *parent = nullptr);
    ~GameReviewMenu();

private:
    Ui::GameReviewMenu *ui;
};

#endif // GAMEREVIEWMENU_H
