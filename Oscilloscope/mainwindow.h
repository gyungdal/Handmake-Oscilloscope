#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    typedef enum {
        V1_8,
        V5,
        V50,
        V180
    } adc_scale_e;

    typedef struct {
        uint16_t reverse : 1;
        uint16_t channel : 3;
        uint16_t raw : 12;
        adc_scale_e scale;
        double voltage;
    } adc_item_t;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
