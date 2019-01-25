#include "chart.h"
Chart::Chart( QWidget *parent ):
    QwtPlot( parent ){
    data3 = new QVector<double>();
    data0 = new QVector<double>();
    canvas = new QwtPlotCanvas();

    setTitle("Hello Oscilloscope!");
    setAutoReplot( false );
    setCanvas(this->canvas);
    setCanvasBackground(Qt::white);

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
    //enableAxis( QwtPlot::yRight );
    setAxisTitle( QwtPlot::xBottom, "time [msec]" );
    setAxisTitle( QwtPlot::yLeft, "Volatage [V]" );
    //setAxisTitle( QwtPlot::yRight, "Phase [deg]" );
    setAxisScale( QwtPlot::yLeft, -1.8, +1.8);

    setAxisMaxMajor( QwtPlot::xBottom, 6 );
    setAxisMaxMinor( QwtPlot::xBottom, 9 );
    //setAxisScaleEngine( QwtPlot::xBottom, new QwtLogScaleEngine );


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

    // marker
    marker0 = new QwtPlotMarker();
    marker0->setLineStyle( QwtPlotMarker::HLine );
    marker0->setLabelAlignment( Qt::AlignRight | Qt::AlignBottom );
    marker0->setLinePen( QColor( 200, 150, 0 ), 0, Qt::DashDotLine );
    marker0->setSymbol( new QwtSymbol( QwtSymbol::Diamond, QColor( Qt::yellow ), QColor( Qt::green ), QSize( 8, 8 ) ) );
    marker0->attach( this );

    marker3 = new QwtPlotMarker();
    marker3->setValue( 0.0, 0.0 );
    marker3->setLineStyle( QwtPlotMarker::VLine );
    marker3->setLabelAlignment( Qt::AlignRight | Qt::AlignBottom );
    marker3->setLinePen( Qt::green, 0, Qt::DashDotLine );
    marker3->attach( this );

    QVector<double> list;
    for(int i = 0;i<100;i++){
        list.push_back(i);
        data0->push_back(fmod(rand(), 100) - 50);
        data3->push_back(fmod(rand(), 100) - 50);
    }
    curve0->setSamples(list, *data0);
    curve3->setSamples(list, *data3);
    //curve3->setSamples(list, data3);

    setAutoReplot( true );
}

void Chart::clear(){

}

void Chart::showData(){
}
void Chart::adcUpdate(){
    if(data0->size() > 5000){

    }
}
