#pragma once
#include <QWidget>

class QLCDNumber;
class QLabel;
class QPushButton;
class TetrixBoard;

class TetrixWindow : public QWidget
{
    Q_OBJECT

public:
    TetrixWindow(QWidget* parent = nullptr);

private:
    QLabel* createLabel(const QString& text);

    TetrixBoard* board;
    QLabel* nextPieceLabel;
    QLCDNumber* scoreLcd;
    QLCDNumber* levelLcd;
    QLCDNumber* linesLcd;
    QPushButton* startButton;
    QPushButton* quitButton;
    QPushButton* pauseButton;
};
