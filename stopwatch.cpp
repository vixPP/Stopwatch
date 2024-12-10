#include "stopwatch.h"
#include "./ui_stopwatch.h"

Stopwatch::Stopwatch(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Stopwatch)
{
    ui->setupUi(this);
    m = 0;
    s = 0;
    ms = 0;
    lapTime = 0;
    lapCount = 0;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stopwatch::TimerSlots);


    ui->pushButton_start->setText("СТАРТ");
    ui->pushButton_reset->setText("СБРОС");
    ui->pushButton->setText("КРУГ");
}

Stopwatch::~Stopwatch()
{
    delete ui;
}

void Stopwatch::TimerSlots()
{
    ms++;
    if (ms >= 1000)
    {
        ms = 0;
        s++;
    }
    if (s >= 60)
    {
        s = 0;
        m++;
    }

    ui->label_m->setText(QString::number(m) + "   :");
    ui->label_S->setText(QString::number(s) + "   :");
    ui->label_ms->setText(QString::number(ms));
}


void Stopwatch::on_pushButton_start_clicked()
{
    flag = !flag;
    if(flag)
    {
        ui->pushButton_start->setText("СТАРТ");
        timer->stop();
    }
    else
    {
        ui->pushButton_start->setText("СТОП");
        timer->start(1);
    }
}


void Stopwatch::on_pushButton_reset_clicked()
{
    m = 0;
    s = 0;
    ms = 0;
    lapTime = 0;
    lapCount = 0;

    ui->label_m->setText(QString::number(m) + "   :");
    ui->label_S->setText(QString::number(s) + "   :");
    ui->label_ms->setText(QString::number(ms));

    ui->textBrowser->clear();
}


void Stopwatch::on_pushButton_clicked()
{
    lapCount++;
    lapTime = m * 60 + s + ms / 1000.0;

    // Проверка на первый круг
    if (lapCount == 1) {
        timeSinceLastLap = lapTime; // Устанавливаем время первого круга
    } else {
        timeSinceLastLap = lapTime - previousLapTime; // Разница для последующих кругов
    }

    previousLapTime = lapTime;
    ui->textBrowser->append(QString("Круг %1, время: %2 сек").arg(lapCount).arg(timeSinceLastLap));
}


