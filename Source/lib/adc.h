#ifndef __ADC_H__
#define __ADC_H__
#pragma once

//ODROID ADC RANGE 0 ~ 1.8 VOLTAGE

#ifdef linux
#include <stdio.h>
#include <inttypes.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>


class ADC {
    public:
        typedef enum {
            V1_8,
            V5,
            V50,
            V180
        } adc_scale_e;

        typedef struct {
            uint16_t raw : 12;
            uint16_t reverse : 1;
            uint16_t channel : 3;
            adc_scale_e scale;
            double voltage;
        } adc_item_t;


        void setScale(uint8_t channel, adc_scale_e scale);
        adc_item_t getAdc(uint8_t channel);

        ADC(){
            initAdc();
        }
    private:        
        enum ADC_INDEX {
            CON1 = 0,
            CON2 = 1,
            STAT = 2,
            DATA = 3
        };

        typedef struct {
            union{
                struct{
                    uint32_t CON1_RSVD : 29;
                    uint32_t SOFT_RESET : 2;
                    uint32_t STC_EN : 1;
                } adc_con1;
                struct{
                    uint32_t CON2_RSVD : 21;
                    uint32_t OSEL : 1;
                    uint32_t ESEL : 1;
                    uint32_t HIGHF : 1;
                    uint32_t CON2_RSVD_2 : 1;
                    uint32_t C_TIME : 3;
                    uint32_t ACH_SEL : 4;
                } adc_con2;
                struct{
                    uint32_t STATUS_RSVD : 29;
                    uint32_t FLAG : 1;
                    uint32_t RSVD : 2;
                } adc_status;
                struct{
                    uint32_t DAT_RSVD : 20;
                    uint32_t ADCDAT : 12;
                } adc_dat;
                struct{
                    uint32_t INT_EN_RSVD : 31;
                    uint32_t INT_EN : 1;
                } adc_int_en;
                struct{
                    uint32_t INT_STATUS_RSVD : 31;
                    uint32_t INT_STATUS : 1;
                } adc_int_status;
                struct{
                    uint32_t ADC_VERSION_INFO;
                } adc_version;
                uint32_t raw;
            };
        } adc_format_t;

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

#endif
