#include "mainwindow.h"

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    const QString temp("±1.8V,±5V,±18V,±180V");
    scaleList = temp.split(",");
    setupChartView();
}

void MainWindow::setupChartView(){

    QLineSeries *series = new QLineSeries();
    *series << QPointF(1, 0.5) << QPointF(3, .6) << QPointF(7, -0.6) << QPointF(9, -0.7)
        << QPointF(12, .6) << QPointF(16, .7) << QPointF(18, .5);
    series->setName("Channel 0");

    QLineSeries *series3 = new QLineSeries();
    *series3 << QPointF(1, -0.5) << QPointF(2, -2) << QPointF(6, 1.3);
    series3->setName("Channel 3");

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(series3);
    chart->setTitle("Test!");
    chart->createDefaultAxes();
    chart->axisX()->setRange(0, 20);
    chart->axisY()->setRange(-2, 2);
    chart->setTheme(QChart::ChartThemeDark);
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    mainLayout = new QGridLayout();
    toolLayout = new QGridLayout();

    scaleDial = new QDial();
    scaleDial->setMinimum(0);
    scaleDial->setMaximum(3);

    speedDial = new QDial();
    speedDial->setMinimum(0);
    speedDial->setMaximum(10);

    scaleView = new QLabel();
    scaleView->setText(scaleList[0]);
    speedView = new QLabel();
    speedView->setText("10ms");
    sampleFreqView = new QLabel();
    sampleFreqView->setText("1000/s");

    toolLayout->addWidget(scaleView, 0, 0);
    toolLayout->addWidget(scaleDial, 0, 1);
    toolLayout->addWidget(speedView, 0, 2);
    toolLayout->addWidget(speedDial, 0, 3);
    toolLayout->addWidget(sampleFreqView, 0, 4);

    mainLayout->addWidget(chartView, 0, 0);
    //mainLayout->addLayout(toolLayout, 0, 1);

    this->setLayout(mainLayout);
    this->resize(1280, 720);
}

void MainWindow::scaleDialEventHadler(int value){
    scaleView->setText(scaleList[value]);
}

void MainWindow::speedDialEventHadler(int value){
    char* text = new char[50];
    itoa(value, text, 10);
    speedView->setText(text);
    delete text;
}

MainWindow::~MainWindow() {
    delete chartView;
    delete toolLayout;
    delete mainLayout;
}
