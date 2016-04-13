/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_control_private.h
 *
 * Code generated for Simulink model 'motor_control'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Apr 13 11:07:35 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motor_control_private_h_
#define RTW_HEADER_motor_control_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void Encoder_read_Outputs_wrapper(real32_T *rpm_out,
  const real_T *xD);
extern void Encoder_read_Update_wrapper(const real32_T *rpm_out,
  real_T *xD);
extern void PWM_init_Outputs_wrapper(const real32_T *duty,
  const real_T *xD);
extern void PWM_init_Update_wrapper(const real32_T *duty,
  real_T *xD);

#endif                                 /* RTW_HEADER_motor_control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
