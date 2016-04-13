/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_control_data.c
 *
 * Code generated for Simulink model 'motor_control'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Apr 13 10:52:48 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_control.h"
#include "motor_control_private.h"

/* Block parameters (auto storage) */
P_motor_control_T motor_control_P = {
  0.0F,                                /* Mask Parameter: DiscretePIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  1.0F,                                /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  100.0F,                              /* Mask Parameter: DiscretePIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  1.0F,                                /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  1200.0,                              /* Expression: 1200
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  80.0,                                /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  40.0,                                /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  600.0F,                              /* Computed Parameter: ref_Value
                                        * Referenced by: '<Root>/ref'
                                        */
  0.05F,                               /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.0F,                                /* Computed Parameter: Integrator_IC
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.05F,                               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S1>/Filter'
                                        */
  0.0F,                                /* Computed Parameter: Filter_IC
                                        * Referenced by: '<S1>/Filter'
                                        */
  50.0F                                /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
