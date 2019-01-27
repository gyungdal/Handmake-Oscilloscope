#ifndef __ADC_HPP__
#define __ADC_HPP__
//ODROID ADC RANGE 0 ~ 1.8 VOLTAGE

#include <cstdlib>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <utility>
#include <QThread>

#include "config.h"
#include "type.h"

class ADC : public QThread{
    Q_OBJECT
    private:
        int fd;
        adc_register_t* adc;
        bool initAdc();
        void run();

    public:
        explicit ADC(QObject *parent = nullptr);
        ~ADC(){
            munmap(adc, static_cast<size_t>(getpagesize()));
            close(fd);
        }
        ADC(const ADC&)= delete;
        ADC& operator=(const ADC&)= delete;
        adc_item_t* read(uint8_t);
        double readVoltage(uint8_t);

    signals:
        void readAllVoltages(std::pair<double, double>);
    public slots:

};

#endif
