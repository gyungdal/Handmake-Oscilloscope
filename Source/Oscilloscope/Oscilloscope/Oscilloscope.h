#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Oscilloscope.h"

class Oscilloscope : public QMainWindow
{
	Q_OBJECT

public:
	Oscilloscope(QWidget *parent = Q_NULLPTR);

private:
	Ui::OscilloscopeClass ui;
};
