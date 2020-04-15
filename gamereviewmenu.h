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

private slots:
    void on_gameReviewEdit_clicked();

    void on_gameReviewCancel_clicked();

private:
    Ui::GameReviewMenu *ui;
};

#endif // GAMEREVIEWMENU_H
