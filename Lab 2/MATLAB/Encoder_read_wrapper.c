

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#ifndef MATLAB_MEX_FILE
#define ARDUINO 100
#define TOP5 248
#define PPR 2000
#define ENC_SAMPLE_RATE 1000
#include <Arduino.h>
#include "encoder.h"
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void Encoder_read_Outputs_wrapper(real32_T *rpm_out,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
if (xD[0] == 1) {
    *rpm_out = rpm;
}
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void Encoder_read_Update_wrapper(const real32_T *rpm_out,
			real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE

if (xD[0] != 1) {

    

    
    void encoder_isr() {
        static int8_t lookup_table[] = {
        0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0      };
        static uint8_t enc_val = 0;

        enc_val = enc_val << 2;    // make room for new readings
        enc_val = enc_val | ((PINE & 0b110000) >> 4);  // mask in pin 4 and 5 in register pine

        enc_count = enc_count + lookup_table[enc_val & 0b1111];  // update encoder history
    }
    
    
    // reset registers
    TCCR3A = 0x00;
    TCCR3B = 0x00;
    // Set mode
    TCCR3B |= (1 << WGM32); // CTC mode
    // set clock source and prescaler
    TCCR3B |= (1 << CS30) | (1 << CS31); // internal clock source, prescaler 64
    // timer mask register set
    TIMSK3 |= (1 << OCIE3A);
    // counter variables
    OCR3A = TOP5*sample_time_ms;
    // ###### Define pin interrupts for encoder ########
    attachInterrupt(0, encoder_isr, CHANGE);
    attachInterrupt(1, encoder_isr, CHANGE);
    
    // only run first time
    xD[0] = 1;
}
#endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
