#include "mainwindow.h"

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    scaleList.append("±1.8V");
    scaleList.append("±5V");
    scaleList.append("±18V");
    scaleList.append("±180V");

    setupChartView();

}

void MainWindow::setupChartView(){

    mainLayout = new QGridLayout();
    toolLayout = new QGridLayout();


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

    scaleDial = new QDial();
    scaleDial->setMinimum(0);
    scaleDial->setMaximum(3);

    speedDial = new QDial();
    speedDial->setMinimum(0);
    speedDial->setMaximum(10);

    scaleView = new QLabel();
    scaleView->setText(scaleList[0]);
    scaleView->setAlignment(Qt::AlignCenter);
    speedView = new QLabel();
    speedView->setText("10ms");
    speedView->setAlignment(Qt::AlignCenter);
    sampleFreqView = new QLabel();
    sampleFreqView->setText("1000/s");
    sampleFreqView->setAlignment(Qt::AlignCenter);


    toolLayout->addWidget(scaleView, 0, 0);
    toolLayout->addWidget(scaleDial, 1, 0);
    toolLayout->addWidget(speedView, 2, 0);
    toolLayout->addWidget(speedDial, 3, 0);
    toolLayout->addWidget(sampleFreqView, 4, 0);


    mainLayout->addWidget(chartView, 0, 0);
    //mainLayout->addWidget(chartView, 0, 0);
    mainLayout->addItem(toolLayout, 0, 1);

    //this->setLayout(mainLayout);
    //this->setCentralWidget(chartView);
    QWidget* widget = new QWidget(this);
    widget->setLayout(mainLayout);

    connect(scaleDial, SIGNAL(valueChanged(int)),
                this, SLOT(scaleDialEventHadler(int)));
    connect(speedDial, SIGNAL(valueChanged(int)),
                this, SLOT(speedDialEventHadler(int)));

    this->setCentralWidget(widget);
    this->resize(1280, 720);
}

void MainWindow::scaleDialEventHadler(int index){
#ifdef DEBUG
    fprintf(stdout, "[INFO] Scale Didal Index Change : %d", index);
#endif
    const static double list[] = {1.8, 5, 18, 180};
    nowScale = list[index];
    scaleView->setText(scaleList[index]);
}

void MainWindow::speedDialEventHadler(int value){
#ifdef DEBUG
    fprintf(stdout, "[INFO] Speed Didal Index Change : %d", value);
#endif
    speedView->setNum(value);
}

MainWindow::~MainWindow() {
    disconnect(scaleDial, SIGNAL(valueChanged(int)),
                this, SLOT(scaleDialEventHadler(int)));
    disconnect(speedDial, SIGNAL(valueChanged(int)),
                this, SLOT(speedDialEventHadler(int)));
}
