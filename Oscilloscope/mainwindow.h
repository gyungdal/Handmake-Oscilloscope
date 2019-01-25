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

    double frequency() const;

private:
    Knob *freqencyControl;
    Chart *chart;
};

#endif // MAINWINDOW_H
