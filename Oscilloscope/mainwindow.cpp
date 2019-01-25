#include "mainwindow.h"
#include "knob.h"
#include <QLabel>
#include <QLayout>

#include <qwt_scale_engine.h>

MainWindow::MainWindow( QWidget *parent ):
    QWidget( parent )
{
    const double intervalLength = 10.0; // seconds
    chart = new Chart(this);
    //d_plot->setIntervalLength( intervalLength );

    freqencyControl = new Knob( "Frequency [Hz]", 0.1, 20.0, this );
    freqencyControl->setValue( 17.8 );

    //Vertical
    QVBoxLayout* vLayout1 = new QVBoxLayout();
    vLayout1->addWidget(freqencyControl);

    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->addWidget(chart, 10 );
    layout->addLayout(vLayout1);

    connect(freqencyControl, SIGNAL( valueChanged( double ) ),
        SIGNAL( frequencyChanged( double ) ) );
}

void MainWindow::start()
{
   // d_plot->start();
}

double MainWindow::frequency() const
{
    return freqencyControl->value();
}
