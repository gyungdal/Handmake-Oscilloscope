#ifndef __ADC_H__
#define __ADC_H__
//ODROID ADC RANGE 0 ~ 1.8 VOLTAGE

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#include "config.h"
#include "type.h"

class ADC {
    private:
        int fd;
        adc_register_t* adc;
        bool initAdc();
    public:
        ADC(){
            initAdc();
        }
        adc_item_t* read(uint8_t);
};

#endif
