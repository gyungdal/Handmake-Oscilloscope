#ifndef __CHART_H__
#define __CHART_H__

#include <qwt_plot.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_curve.h>
#include <qwt_legend.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_plot_canvas.h>
#include <QVector>
#include "type.h"

class Chart: public QwtPlot
{
    Q_OBJECT
private:
    //data queue
    QVector<double> *data0;
    QVector<double> *data3;

    //canvas
    QwtPlotCanvas *canvas;

    QwtPlotCurve *curve0;
    QwtPlotCurve *curve3;
    QwtPlotMarker *marker0;
    QwtPlotMarker *marker3;

    void showData();

public:
    Chart(QWidget *parent = nullptr);
    void clear();

public Q_SLOTS:
    void adcUpdate(void);
};
#endif
