
#include "adc.h"

#if defined(_WIN64) || defined(_WIN32)

#else
bool ADC::initAdc(){
    if ((this->fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
        #if DEBUG
            fprintf(stderr, "Unable to open /dev/mem\n");
        #endif
        return false;
    }


    this->adc = reinterpret_cast<adc_register_t*>(mmap(0, getpagesize(), PROT_READ | PROT_WRITE,
                    MAP_SHARED, fd, 0x12D10000));
    if (reinterpret_cast<long>(this->adc) < 0) {
        printf("mmap failed.\n");
        return false;
    }

    #if DEBUG
        fprintf(stdout, "INITAL : 0x%08jx - 0x%08jx\n",
                static_cast<uintmax_t>(adc[CON1].raw), static_cast<uintmax_t>(adc[CON2].raw));
    #endif

    this->adc[CON1].con1.SOFT_RESET = 0x2;
    this->adc[CON2].con2.OSEL = 0x1;
    this->adc[CON2].con2.ESEL = 0x1;
    this->adc[CON2].con2.HIGHF = 0x1;
    this->adc[CON2].con2.C_TIME = 0x0;

    #if DEBUG
        fprintf(stdout, "SETUP : 0x%08jx - 0x%08jx\n",
                static_cast<uintmax_t>(adc[CON1].raw), static_cast<uintmax_t>(adc[CON2].raw));
    #endif

    return true;
}

adc_item_t* ADC::read(uint8_t channel){
    if(channel == 3 | channel == 0){
        adc_item_t* result = new adc_item_t;
        this->adc[CON2].con2.ACH_SEL = channel;
        this->adc[CON1].con1.STC_EN = 0x1;

        #if DEBUG
            fprintf(stdout, "Channel %d : 0x%08jx- 0x%08jx\n", channel,
                        static_cast<uintmax_t>(adc[CON1].raw), static_cast<uintmax_t>(adc[CON2].raw));
        #endif

        //end when adc conversion
        while(!this->adc[STAT].status.FLAG);

        result->raw = this->adc[DATA].data.ADCDAT;
        result->scale = adc_scale_e::V1_8;
        result->channel = channel;
        result->reverse = 0;
        switch(result->scale){
            case V1_8 : {
                result->voltage = 1.8 * (result->raw / 4095);
                break;
            }
            default :
                break;
        }
        return result;
    }else
        return nullptr;
}


#endif
