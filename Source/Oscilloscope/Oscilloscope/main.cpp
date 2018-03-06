#include "stdafx.h"
#include "Oscilloscope.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Oscilloscope w;
	w.show();
	return a.exec();
}
