#include "mainwindow.h"

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    scaleList.append("±1.8V");
    scaleList.append("±5V");
    scaleList.append("±18V");
    scaleList.append("±180V");

    chartChannel0 = new QLineSeries();
    chartChannel0->setName("Channel 0");
    chartChannel0->setUseOpenGL(true);
    chartChannel3 = new QLineSeries();
    chartChannel3->setName("Channel 3");
    chartChannel3->setUseOpenGL(true);

    setupChartView();

}

void MainWindow::setupChartView(){

    mainLayout = new QGridLayout();
    toolLayout = new QGridLayout();

#ifdef TEST
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(chartUpdateTest()));
    timer->start(1);
#endif

    QChart* chart = new QChart();
    chart->addSeries(chartChannel0);
    chart->addSeries(chartChannel3);
    chart->setTitle("Test!");
    chart->createDefaultAxes();
    chart->axisX()->setRange(0, 1000);
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

#ifdef TEST
void MainWindow::chartUpdateTest(){
    static int index;

    QRandomGenerator* random = new QRandomGenerator(index);
    if(index == 2000)
        index = 0;
    random->bounded(0, 2);

    chartChannel0->append(index, random->generateDouble());
    chartChannel3->append(index, random->generateDouble());

    if(chartChannel0->count() > 1000){
        chartChannel0->removePoints(i % 1000, 1);
        chartChannel3->removePoints(i % 1000, 1);
    }

    if(index == 0){
        chartView->chart()->axisX()->setRange(index, 1000);
    }
    if(index > 1000){
        chartChannel0->insert(0, index % 1000);
        chartChannel0->append(index, random->generateDouble());
        chartChannel3->append(index, random->generateDouble());

        chartView->chart()->axisX(chartChannel0)->setRange(index, index + 1000);
        chartView->chart()->axisX(chartChannel3)->setRange(index, index + 1000);
    }
    index++;
    chartView->repaint();
}
#endif

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
