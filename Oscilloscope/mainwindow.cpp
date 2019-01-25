#include "mainwindow.h"
#include "knob.h"
#include <QLabel>
#include <QLayout>

MainWindow::MainWindow( QWidget *parent ):
    QWidget( parent ) {
    chart = new Chart(this);
    //d_plot->setIntervalLength( intervalLength );

    freqencyControl = new Knob( "Frequency [Hz]", 0.5, 1000.0, this );
    freqencyControl->setValue(0.5);

    //Vertical
    QVBoxLayout* vLayout1 = new QVBoxLayout();
    vLayout1->addWidget(freqencyControl);

    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->addWidget(chart, 10 );
    layout->addLayout(vLayout1);

    connect(freqencyControl, SIGNAL( valueChanged( double ) ),
      chart,  SLOT(frequncyUpdate( double )));
}

double MainWindow::frequency() const
{
    return freqencyControl->value();
}
