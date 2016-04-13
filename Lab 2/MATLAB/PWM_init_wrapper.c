

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
#ifndef MATLAB_MEX_FILE
#define ARDUINO 100
#define TOP4 160
#include <Arduino.h>
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
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
void PWM_init_Outputs_wrapper(const real32_T *duty,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
if (xD[0] == 1) {
    int duty_ticks;
    float input = *duty; // dereferencing of pointer value of input
    
    //Boundary value correction to become between 0-100
    if (input > 100) {
    input = 100;
    }
    else if (input < 0) {
    input = 0;
    }
    duty_ticks = (int) (input * TOP4/100); // calculate number of ticks in compare register
    OCR4B = duty_ticks;  //set dutycycle
}
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void PWM_init_Update_wrapper(const real32_T *duty,
			real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
if (xD[0] != 1) {
    pinMode(7, OUTPUT); //OCR4B
    // reset registers
    TCCR4A = 0x00;
    TCCR4B = 0x00;

    // Set mode
    TCCR4A |= (1 << WGM40) | (1 << WGM41); // phase correct mode
    TCCR4B |= (1 << WGM43);
    //
    TCCR4A |= (1 << COM4B1);
    // set clock source and prescaler
    TCCR4B |= (1 << CS40); // internal clock source, no prescaler

    // counter variables
    OCR4A = TOP4;
    
    // only run first time
    xD[0] = 1;
}
#endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
