#ifndef WIDGET_H
#define WIDGET_H
#pragma once
#include <QtWidgets/QWidget>
#include <QtCharts/QPieSeries>
#include <QLabel>

QT_CHARTS_USE_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    int score = 0;
    int dartNumber;
    bool validateState;
public slots:
    //This will be called every time that a pie slice has been clicked
    void addScore();

    //This will block the user from using the dartboard until the score has been validated or rejected
    void validationBlocker(bool blockForValidation);

 signals:
    void scoreSignalOne(int i);
    void scoreSignalTwo(int i);
    void scoreSignalThree(int i);
    void needsValidation(bool run);


private:
    QList<QPieSeries *> m_donuts;
    QWidget* theParent;
    QLabel *scoreDisplayer;
};

#endif // WIDGET_H
