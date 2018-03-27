#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <vector>

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    //ADC Item struct
    typedef struct {
        uint16_t raw : 12;
        uint16_t reverse : 1;
        uint16_t channel : 3;
        double voltage;
    } adc_item_t;

    MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:

    void scaleDialEventHadler(int);
    void speedDialEventHadler(int);

private:
    //Dial
    QDial* scaleDial;
    QDial* speedDial;

    //Infomation View
    QLabel* scaleView;
    QLabel* speedView;
    QLabel* sampleFreqView;

    //Chart!
    QChartView* chartView;

    QGridLayout* toolLayout;
    QGridLayout * mainLayout;

    QStringList scaleList;

    void setupChartView();
};

#endif // MAINWINDOW_H
