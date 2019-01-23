#ifndef __ADC_H__
#define __ADC_H__
//ODROID ADC RANGE 0 ~ 1.8 VOLTAGE

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#include "type.h"

class ADC {
    private:
        int fd;
        adc_scale_e* channelScale;
        adc_register_t* adc;
        uint16_t readAdcChannel(uint8_t);


        bool initAdc();
    public:
        void setScale(uint8_t channel, adc_scale_e scale);
        adc_item_t getAdc(uint8_t channel);

        ADC(){
            channelScale = (adc_scale_e*)malloc(sizeof(adc_scale_e) * 2);
            for(int i = 0;i<2;i++){
                channelScale = V1_8;
            }
            initAdc();
        }
};


#endif
