#include "mainwindow.h"

MainWindow::MainWindow( QWidget *parent ):
    QWidget( parent ) {

    chart = new Chart(this);
    adc = new ADC(this);

    freqencyControl = new Knob( "Frequency [Hz]", 0.5, 1000.0, this );
    freqencyControl->setValue(0.5);

    //Tool bar
    pauseButton = new QPushButton(tr("Pause"));
    QVBoxLayout* toolbar = new QVBoxLayout();
    toolbar->addWidget(pauseButton);
    toolbar->addWidget(freqencyControl);

    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->addWidget(chart, 10 );
    layout->addLayout(toolbar);

    connect(freqencyControl, SIGNAL( valueChanged( double ) ),
      chart,  SLOT(frequncyUpdate( double )));
    connect(adc, SIGNAL(readAllVoltages(std::pair<double, double>))
            , chart, SLOT(adcUpdate(std::pair<double, double>)));
    //adc->start();
}

double MainWindow::frequency() const
{
    return freqencyControl->value();
}
