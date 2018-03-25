#include "mainwindow.h"

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
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
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    this->setCentralWidget(chartView);
    this->resize(1280, 720);
}

MainWindow::~MainWindow() {

}
