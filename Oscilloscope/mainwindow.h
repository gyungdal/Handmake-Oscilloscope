#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>

#include "adc.hpp"
#include "knob.h"
#include "chart.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow( QWidget * = nullptr );

    double frequency() const;

private:
    QPushButton *pauseButton;
    Knob *freqencyControl;
    Chart *chart;
    ADC *adc;

};

#endif // MAINWINDOW_H
