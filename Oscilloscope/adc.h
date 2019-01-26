#ifndef __ADC_H__
#define __ADC_H__
//ODROID ADC RANGE 0 ~ 1.8 VOLTAGE

#include <cstdlib>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <utility>
#include "config.h"
#include "type.h"

class ADC {
    private:
        int fd;
        adc_register_t* adc;
        bool initAdc();
    public:
        static ADC& getInstance(){
            static ADC instance;
            return instance;
        }

        adc_item_t* read(uint8_t);
        std::pair<double, double> readAllVoltages();
        double readVoltage(uint8_t);
    private:
        ADC(){
            initAdc();
        }
        ~ADC(){
            munmap(adc, getpagesize());
            close(fd);
        }
        ADC(const ADC&)= delete;
        ADC& operator=(const ADC&)= delete;
};

#endif
