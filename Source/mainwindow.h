#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <vector>
#include <QRandomGenerator>

#define TEST

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    //ADC Item struct
    typedef enum {
        V1_8,
        V5,
        V50,
        V180
    } adc_scale_e;

    typedef struct {
        uint16_t raw : 12;
        uint16_t reverse : 1;
        uint16_t channel : 3;
        adc_scale_e scale;
        double voltage;
    } adc_item_t;

    MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:

    void scaleDialEventHadler(int);
    void speedDialEventHadler(int);

#ifdef TEST
    void chartUpdateTest();
#endif
private:
    double nowScale;
    //Dial
    QDial* scaleDial;
    QDial* speedDial;

    //Infomation View
    QLabel* scaleView;
    QLabel* speedView;
    QLabel* sampleFreqView;

    //Chart!
    QChartView* chartView;
    QLineSeries* chartChannel0;
    QLineSeries* chartChannel3;


    QGridLayout* toolLayout;
    QGridLayout * mainLayout;

    QStringList scaleList;

    std::vector<adc_item_t> Channel0;
    std::vector<adc_item_t> Channel3;

    void setupChartView();

#ifdef CHART_UPDATE_TEST

#endif
};

#endif // MAINWINDOW_H
