/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_control.c
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
#include "motor_control_dt.h"

/* Block signals (auto storage) */
B_motor_control_T motor_control_B;

/* Block states (auto storage) */
DW_motor_control_T motor_control_DW;

/* Real-time model */
RT_MODEL_motor_control_T motor_control_M_;
RT_MODEL_motor_control_T *const motor_control_M = &motor_control_M_;

/* Model step function */
void motor_control_step(void)
{
  real_T rtb_PulseGenerator;
  real32_T rtb_Sum1;
  real32_T rtb_FilterCoefficient;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (motor_control_DW.clockTickCounter <
                        motor_control_P.PulseGenerator_Duty) &&
    (motor_control_DW.clockTickCounter >= 0L) ?
    motor_control_P.PulseGenerator_Amp : 0.0;
  if (motor_control_DW.clockTickCounter >= motor_control_P.PulseGenerator_Period
      - 1.0) {
    motor_control_DW.clockTickCounter = 0L;
  } else {
    motor_control_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/ref'
   */
  motor_control_B.Sum2 = (real32_T)(motor_control_P.ref_Value -
    rtb_PulseGenerator);

  /* S-Function (Encoder_read): '<Root>/Encoder' */
  Encoder_read_Outputs_wrapper( &motor_control_B.Encoder,
    &motor_control_DW.Encoder_DSTATE);

  /* Sum: '<Root>/Sum1' */
  rtb_Sum1 = motor_control_B.Sum2 - motor_control_B.Encoder;

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S1>/Filter'
   *  Gain: '<S1>/Derivative Gain'
   *  Sum: '<S1>/SumD'
   */
  rtb_FilterCoefficient = (motor_control_P.DiscretePIDController_D * rtb_Sum1 -
    motor_control_DW.Filter_DSTATE) * motor_control_P.DiscretePIDController_N;

  /* Sum: '<S1>/Sum' incorporates:
   *  DiscreteIntegrator: '<S1>/Integrator'
   *  Gain: '<S1>/Proportional Gain'
   */
  motor_control_B.Sum = (motor_control_P.DiscretePIDController_P * rtb_Sum1 +
    motor_control_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  motor_control_B.Sum_e = motor_control_B.Sum + motor_control_P.Constant_Value;

  /* S-Function (PWM_init): '<Root>/PWM' */
  PWM_init_Outputs_wrapper(&motor_control_B.Sum_e, &motor_control_DW.PWM_DSTATE);

  /* S-Function "Encoder_read_wrapper" Block: <Root>/Encoder */
  Encoder_read_Update_wrapper( &motor_control_B.Encoder,
    &motor_control_DW.Encoder_DSTATE);

  /* Update for DiscreteIntegrator: '<S1>/Integrator' incorporates:
   *  Gain: '<S1>/Integral Gain'
   */
  motor_control_DW.Integrator_DSTATE += motor_control_P.DiscretePIDController_I *
    rtb_Sum1 * motor_control_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S1>/Filter' */
  motor_control_DW.Filter_DSTATE += motor_control_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* S-Function "PWM_init_wrapper" Block: <Root>/PWM */
  PWM_init_Update_wrapper(&motor_control_B.Sum_e, &motor_control_DW.PWM_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.05s, 0.0s] */
    rtExtModeUpload(0, motor_control_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.05s, 0.0s] */
    if ((rtmGetTFinal(motor_control_M)!=-1) &&
        !((rtmGetTFinal(motor_control_M)-motor_control_M->Timing.taskTime0) >
          motor_control_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(motor_control_M, "Simulation finished");
    }

    if (rtmGetStopRequested(motor_control_M)) {
      rtmSetErrorStatus(motor_control_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  motor_control_M->Timing.taskTime0 =
    (++motor_control_M->Timing.clockTick0) * motor_control_M->Timing.stepSize0;
}

/* Model initialize function */
void motor_control_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)motor_control_M, 0,
                sizeof(RT_MODEL_motor_control_T));
  rtmSetTFinal(motor_control_M, -1);
  motor_control_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  motor_control_M->Sizes.checksums[0] = (2107225776U);
  motor_control_M->Sizes.checksums[1] = (1965539276U);
  motor_control_M->Sizes.checksums[2] = (1036431389U);
  motor_control_M->Sizes.checksums[3] = (618126809U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    motor_control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motor_control_M->extModeInfo,
      &motor_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motor_control_M->extModeInfo,
                        motor_control_M->Sizes.checksums);
    rteiSetTPtr(motor_control_M->extModeInfo, rtmGetTPtr(motor_control_M));
  }

  /* block I/O */
  (void) memset(((void *) &motor_control_B), 0,
                sizeof(B_motor_control_T));

  /* states (dwork) */
  (void) memset((void *)&motor_control_DW, 0,
                sizeof(DW_motor_control_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    motor_control_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  motor_control_DW.clockTickCounter = 0L;

  /* S-Function Block: <Root>/Encoder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        motor_control_DW.Encoder_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Integrator' */
  motor_control_DW.Integrator_DSTATE = motor_control_P.Integrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Filter' */
  motor_control_DW.Filter_DSTATE = motor_control_P.Filter_IC;

  /* S-Function Block: <Root>/PWM */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        motor_control_DW.PWM_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void motor_control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
