#ifndef __ADC_H__
#define __ADC_H__
//ODROID ADC RANGE 0 ~ 1.8 VOLTAGE

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#include "type.h"

class ADC {
    public:
        void setScale(uint8_t channel, adc_scale_e scale);
        adc_item_t getAdc(uint8_t channel);

        ADC(){
            initAdc();
        }
    private:

        int fd;
        uint16_t readAdcChannel(uint8_t);

        adc_scale_e channelScale[] = {
            V1_8,
            V1_8
        };

        bool initAdc();
        adc_format_t* adc;
};

#endif
