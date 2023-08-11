/*
 * Deployment_Dispositivo_Gruppo8.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Deployment_Dispositivo_Gruppo8".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Sat Jun 17 16:18:17 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Deployment_Dispositivo_Gruppo8_h_
#define RTW_HEADER_Deployment_Dispositivo_Gruppo8_h_
#ifndef Deployment_Dispositivo_Gruppo8_COMMON_INCLUDES_
#define Deployment_Dispositivo_Gruppo8_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#endif                     /* Deployment_Dispositivo_Gruppo8_COMMON_INCLUDES_ */

#include "Deployment_Dispositivo_Gruppo8_types.h"
#include <stddef.h>
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define Deployment_Dispositivo_Gruppo8_M (Deployment_Dispositivo_Grupp_M)

/* Block signals (default storage) */
typedef struct {
  real_T periodo_led_potenza;          /* '<Root>/Fornello' */
  boolean_T led_stato;                 /* '<Root>/Fornello' */
  boolean_T led_errore;                /* '<Root>/Fornello' */
  boolean_T DigitalRead3;              /* '<Root>/Digital Read3' */
  boolean_T DigitalRead2;              /* '<Root>/Digital Read2' */
  boolean_T DigitalRead1;              /* '<Root>/Digital Read1' */
  boolean_T DigitalRead;               /* '<Root>/Digital Read' */
} B_Deployment_Dispositivo_Grup_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_DigitalRead_Deployment_D_T obj; /* '<Root>/Digital Read3' */
  mbed_DigitalRead_Deployment_D_T obj_o;/* '<Root>/Digital Read2' */
  mbed_DigitalRead_Deployment_D_T obj_b;/* '<Root>/Digital Read1' */
  mbed_DigitalRead_Deployment_D_T obj_m;/* '<Root>/Digital Read' */
  mbed_DigitalWrite_Deployment__T obj_d;/* '<Root>/Digital Write2' */
  mbed_DigitalWrite_Deployment__T obj_i;/* '<Root>/Digital Write1' */
  mbed_DigitalWrite_Deployment__T obj_m4;/* '<Root>/Digital Write' */
  real_T selected_power;               /* '<Root>/Fornello' */
  int32_T sfEvent;                     /* '<Root>/Fornello' */
  uint32_T temporalCounter_i1;         /* '<Root>/PWM' */
  uint32_T temporalCounter_i3;         /* '<Root>/Fornello' */
  uint32_T temporalCounter_i4;         /* '<Root>/Fornello' */
  uint32_T temporalCounter_i5;         /* '<Root>/Fornello' */
  uint16_T temporalCounter_i1_o;       /* '<Root>/Fornello' */
  uint16_T temporalCounter_i2;         /* '<Root>/Fornello' */
  uint8_T is_c5_Deployment_Dispositivo_Gr;/* '<Root>/PWM' */
  uint8_T is_active_c5_Deployment_Disposi;/* '<Root>/PWM' */
  uint8_T is_c2_Deployment_Dispositivo_Gr;/* '<Root>/Fornello' */
  uint8_T is_FORNELLO;                 /* '<Root>/Fornello' */
  uint8_T is_SELECTOR;                 /* '<Root>/Fornello' */
  uint8_T is_WATCHDOG;                 /* '<Root>/Fornello' */
  uint8_T is_SUPPLIER;                 /* '<Root>/Fornello' */
  uint8_T is_DELAYED_TRIGGER;          /* '<Root>/Fornello' */
  uint8_T is_BUTTON_ON_OFF;            /* '<Root>/Fornello' */
  uint8_T is_BUTTON_UP;                /* '<Root>/Fornello' */
  uint8_T is_BUTTON_DOWN;              /* '<Root>/Fornello' */
  uint8_T is_active_FORNELLO;          /* '<Root>/Fornello' */
  uint8_T is_active_SELECTOR;          /* '<Root>/Fornello' */
  uint8_T is_active_WATCHDOG;          /* '<Root>/Fornello' */
  uint8_T is_active_SUPPLIER;          /* '<Root>/Fornello' */
  uint8_T is_active_DELAYED_TRIGGER;   /* '<Root>/Fornello' */
  uint8_T is_active_BUTTON_ON_OFF;     /* '<Root>/Fornello' */
  uint8_T is_active_BUTTON_UP;         /* '<Root>/Fornello' */
  uint8_T is_active_BUTTON_DOWN;       /* '<Root>/Fornello' */
  boolean_T attivo;                    /* '<Root>/Fornello' */
  boolean_T isNotInit;                 /* '<Root>/Fornello' */
  boolean_T objisempty;                /* '<Root>/Digital Write2' */
  boolean_T objisempty_c;              /* '<Root>/Digital Write1' */
  boolean_T objisempty_k;              /* '<Root>/Digital Write' */
  boolean_T objisempty_h;              /* '<Root>/Digital Read3' */
  boolean_T objisempty_o;              /* '<Root>/Digital Read2' */
  boolean_T objisempty_d;              /* '<Root>/Digital Read1' */
  boolean_T objisempty_j;              /* '<Root>/Digital Read' */
} DW_Deployment_Dispositivo_Gru_T;

/* Parameters (default storage) */
struct P_Deployment_Dispositivo_Grup_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Digital Read1'
                                        */
  real_T DigitalRead2_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Digital Read2'
                                        */
  real_T DigitalRead3_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Digital Read3'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Deployment_Dispositiv_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Deployment_Dispositivo_Grup_T Deployment_Dispositivo_Gruppo_P;

/* Block signals (default storage) */
extern B_Deployment_Dispositivo_Grup_T Deployment_Dispositivo_Gruppo_B;

/* Block states (default storage) */
extern DW_Deployment_Dispositivo_Gru_T Deployment_Dispositivo_Grupp_DW;

/* Model entry point functions */
extern void Deployment_Dispositivo_Gruppo8_initialize(void);
extern void Deployment_Dispositivo_Gruppo8_step(void);
extern void Deployment_Dispositivo_Gruppo8_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Deployment_Dispositi_T *const Deployment_Dispositivo_Grupp_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'Deployment_Dispositivo_Gruppo8'
 * '<S1>'   : 'Deployment_Dispositivo_Gruppo8/Fornello'
 * '<S2>'   : 'Deployment_Dispositivo_Gruppo8/PWM'
 */
#endif                        /* RTW_HEADER_Deployment_Dispositivo_Gruppo8_h_ */
