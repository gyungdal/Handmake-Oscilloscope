#ifndef __KNOB_H__
#define __KNOB_H__

#include <QWidget>

class QwtKnob;
class QLabel;

class Knob: public QWidget
{
    Q_OBJECT

    Q_PROPERTY( QColor theme READ theme WRITE setTheme )

public:
    Knob( const QString &title,
        double min, double max, QWidget *parent = nullptr);

    virtual QSize sizeHint() const;

    void setValue( double value );
    double value() const;

    void setTheme( const QColor & );
    QColor theme() const;

Q_SIGNALS:
    double valueChanged( double );

protected:
    virtual void resizeEvent( QResizeEvent * );

private:
    QwtKnob *d_knob;
    QLabel *d_label;
};

#endif // KNOB_H
//SOURCE : QWT EXAMPLE
