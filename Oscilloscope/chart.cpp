#include "chart.h"
Chart::Chart( QWidget *parent ):
    QwtPlot( parent ), hz(0.5) {
    data3 = new QVector<double>();
    data0 = new QVector<double>();
    canvas = new QwtPlotCanvas();

    setTitle("Hello Oscilloscope!");
    setAutoReplot( false );
    setCanvas(this->canvas);
    setCanvasBackground(Qt::black);

    canvas->setBorderRadius(5);

    // legend
    QwtLegend *legend = new QwtLegend;
    insertLegend( legend, QwtPlot::BottomLegend );

    // grid
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin( true );
    grid->setMajorPen( Qt::white, 0, Qt::DotLine );
    //grid->setMinorPen( Qt::gray, 0 , Qt::DotLine );
    grid->attach( this );

    // axes
    setAxisTitle( QwtPlot::xBottom, "time [msec]" );
    setAxisScale( QwtPlot::xBottom, 0, 2000000);
    setAxisTitle( QwtPlot::yLeft, "Volatage [V]" );
    setAxisScale( QwtPlot::yLeft, -1.8, +1.8);

    curve0 = new QwtPlotCurve("Channel 0");
    curve0->setRenderHint( QwtPlotItem::RenderAntialiased );
    curve0->setPen( Qt::cyan );
    curve0->setLegendAttribute( QwtPlotCurve::LegendShowLine );
    curve0->setYAxis( QwtPlot::yRight );
    curve0->attach(this);

    curve3 = new QwtPlotCurve("Channel 3");
    curve3->setRenderHint( QwtPlotItem::RenderAntialiased );
    curve3->setPen( Qt::yellow );
    curve3->setLegendAttribute( QwtPlotCurve::LegendShowLine );
    curve3->setYAxis( QwtPlot::yLeft );
    curve3->attach( this );
    for(int i = 0;i<100;i++){
        data0->push_back(fmod(rand(), 100) - 50);
        data3->push_back(fmod(rand(), 100) - 50);
    }
    showData();
    setAutoReplot( true );
}

void Chart::frequncyUpdate(double hz){
    this->hz = hz;
    setAxisScale( QwtPlot::xBottom, 0, 2000000 / hz);
    showData();
}

void Chart::clear(){

}

void Chart::showData(){
    QVector<double> list;
    for(int i = 0;i<data0->size();i++){
        list.push_back(i * (2000 / hz));
    }
    curve0->setSamples(list, *data0);
    curve3->setSamples(list, *data3);

}
void Chart::adcUpdate(){
    if(data0->size() > 5000){

    }
}
