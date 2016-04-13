/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_control.h
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

#ifndef RTW_HEADER_motor_control_h_
#define RTW_HEADER_motor_control_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef motor_control_COMMON_INCLUDES_
# define motor_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* motor_control_COMMON_INCLUDES_ */

#include "motor_control_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T Sum2;                       /* '<Root>/Sum2' */
  real32_T Encoder;                    /* '<Root>/Encoder' */
  real32_T Sum;                        /* '<S1>/Sum' */
  real32_T Sum_e;                      /* '<Root>/Sum' */
} B_motor_control_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Encoder_DSTATE;               /* '<Root>/Encoder' */
  real_T PWM_DSTATE;                   /* '<Root>/PWM' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  real32_T Integrator_DSTATE;          /* '<S1>/Integrator' */
  real32_T Filter_DSTATE;              /* '<S1>/Filter' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_motor_control_T;

/* Parameters (auto storage) */
struct P_motor_control_T_ {
  real32_T DiscretePIDController_D;    /* Mask Parameter: DiscretePIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  real32_T DiscretePIDController_I;    /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  real32_T DiscretePIDController_N;    /* Mask Parameter: DiscretePIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  real32_T DiscretePIDController_P;    /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1200
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real32_T ref_Value;                  /* Computed Parameter: ref_Value
                                        * Referenced by: '<Root>/ref'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real32_T Integrator_IC;              /* Computed Parameter: Integrator_IC
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real32_T Filter_gainval;             /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S1>/Filter'
                                        */
  real32_T Filter_IC;                  /* Computed Parameter: Filter_IC
                                        * Referenced by: '<S1>/Filter'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_control_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_motor_control_T motor_control_P;

/* Block signals (auto storage) */
extern B_motor_control_T motor_control_B;

/* Block states (auto storage) */
extern DW_motor_control_T motor_control_DW;

/* Model entry point functions */
extern void motor_control_initialize(void);
extern void motor_control_step(void);
extern void motor_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_control_T *const motor_control_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'motor_control'
 * '<S1>'   : 'motor_control/Discrete PID Controller'
 */
#endif                                 /* RTW_HEADER_motor_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
