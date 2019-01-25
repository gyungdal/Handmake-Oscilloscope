
#include "adc.h"

#if defined(_WIN64) || defined(_WIN32)

#else
bool ADC::initAdc(){
    if ((this->fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
        fprintf(stderr, "Unable to open /dev/mem\n");
        return false;
    }


    this->adc = (adc_register_t*)mmap(0, getpagesize(), PROT_READ | PROT_WRITE,
                    MAP_SHARED, fd, 0x12D10000);
    if (reinterpret_cast<long>(this->adc) < NULL) {
        printf("mmap failed.\n");
        return false;
    }

    #if DEBUG
        fprintf(stdout, "INITAL : %X - %X\n", this->adc[CON1], this->adc[CON2]);
    #endif

    this->adc[CON1].con1.SOFT_RESET = 0x2;
    this->adc[CON2].con2.OSEL = 0x1;
    this->adc[CON2].con2.ESEL = 0x1;
    this->adc[CON2].con2.HIGHF = 0x1;
    this->adc[CON2].con2.C_TIME = 0x0;

    #if DEBUG
        fprintf(stdout, "SETUP : %X - %X\n", this->adc[CON1] ,this->adc[CON2]);
    #endif

    return true;
}


void ADC::setScale(uint8_t channel, adc_scale_e scale){

}

adc_item_t ADC::getAdc(uint8_t channel){

}

uint16_t ADC::readAdcChannel(uint8_t channel){
    if(channel == 3 && channel == 0){
        this->adc[CON2].adc_con2.ACH_SEL = channel;
        this->adc[CON1].adc_con1.STC_EN = 0x1;

        #ifdef DEBUG
            fprintf(stdout, "Channel%d : %X - %X\n", channel,
                        this->adc[CON1], this->adc[CON2]);
        #endif

        //end when adc conversion
        while(!this->adc[STAT].adc_status.FLAG);

        uint16_t result = this->adc[DATA].adc_dat.ADCDAT;

        return result;
    }else
        return 0;
}


#endif
