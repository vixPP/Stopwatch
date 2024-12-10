#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Stopwatch; }
QT_END_NAMESPACE

class Stopwatch : public QMainWindow
{
    Q_OBJECT

public:
    Stopwatch(QWidget *parent = nullptr);
    ~Stopwatch();

private:
    Ui::Stopwatch *ui;
    QTimer *timer;
    int m, s, ms;
    bool flag = true;
    int lapTime, lapCount, previousLapTime, timeSinceLastLap;

private slots:
    void TimerSlots();

    void on_pushButton_start_clicked();
    void on_pushButton_reset_clicked();
    void on_pushButton_clicked();
};
#endif // STOPWATCH_H
