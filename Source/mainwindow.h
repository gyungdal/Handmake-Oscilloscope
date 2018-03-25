#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    typedef struct {
        uint16_t raw : 12;
        uint16_t reverse : 1;
        uint16_t channel : 3;
        double voltage;
    } adc_item_t;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QChartView chart;
    void setupChartView();

};

#endif // MAINWINDOW_H
