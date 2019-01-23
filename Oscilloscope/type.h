#ifndef __TYPE_H__
#define __TYPE_H__

#if defined __UINT32_MAX__ or UINT32_MAX
    #include <inttypes.h>
#else
    typedef unsigned char uint8_t;
    typedef unsigned short uint16_t;
    typedef unsigned long uint32_t;
    typedef unsigned long long uint64_t;
#endif

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

typedef enum _adc_index_e {
    CON1 = 0,
    CON2 = 1,
    STAT = 2,
    DATA = 3
} adc_index_e;

typedef struct _adc_con1_t {
    uint32_t RSVD : 29;
    uint32_t SOFT_RESET : 2;
    uint32_t STC_EN : 1;
} adc_con1_t;

typedef struct _adc_con2_t {
    uint32_t RSVD_1 : 21;
    uint32_t OSEL : 1;
    uint32_t ESEL : 1;
    uint32_t HIGHF : 1;
    uint32_t RSVD_2 : 1;
    uint32_t C_TIME : 3;
    uint32_t ACH_SEL : 4;
} adc_con2_t;

typedef struct _adc_status_t{
    uint32_t STATUS_RSVD : 29;
    uint32_t FLAG : 1;
    uint32_t RSVD : 2;
} adc_status_t;

typedef struct _adc_data_t{
    uint32_t DAT_RSVD : 20;
    uint32_t ADCDAT : 12;
} adc_data_t;

typedef struct _adc_interrupt_enable_t{
    uint32_t INT_EN_RSVD : 31;
    uint32_t INT_EN : 1;
} adc_interrupt_enable_t;

typedef struct _adc_interrupt_status_t{
    uint32_t INT_STATUS_RSVD : 31;
    uint32_t INT_STATUS : 1;
} adc_interrupt_status_t;

typedef struct _adc_version_t{
    uint32_t ADC_VERSION_INFO;
} adc_version_t;

typedef struct {
    union{
        adc_con1_t con1;
        adc_con2_t con2;
        adc_status_t status;
        adc_data_t data;
        adc_interrupt_enable_t interruptEnable;
        adc_interrupt_status_t interruptStatus;
        adc_version_t version;
        uint32_t raw;
    };
} adc_register_t;
#endif
