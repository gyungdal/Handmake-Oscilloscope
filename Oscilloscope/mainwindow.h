#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QWidget>

#include "knob.h"
#include "chart.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow( QWidget * = nullptr );

    void start();

    double frequency() const;

Q_SIGNALS:
    void frequencyChanged( double );

private:
    Knob *freqencyControl;
    Chart *chart;
};

#endif // MAINWINDOW_H
