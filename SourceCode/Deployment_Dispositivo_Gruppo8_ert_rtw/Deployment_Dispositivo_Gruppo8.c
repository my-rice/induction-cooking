/*
 * Deployment_Dispositivo_Gruppo8.c
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

#include "Deployment_Dispositivo_Gruppo8.h"
#include "rtwtypes.h"
#include "Deployment_Dispositivo_Gruppo8_types.h"
#include <math.h>
#include <string.h>

/* Named constants for Chart: '<Root>/Fornello' */
#define D_data_change_in_selected_power (18)
#define Deploy_event_SHORT_PRESS_ON_OFF (4)
#define Deploym_event_LONG_PRESS_ON_OFF (1)
#define Deployme_IN_NO_CHANGE_REQUESTED ((uint8_T)3U)
#define Deployme_event_SHORT_PRESS_DOWN (3)
#define Deploymen_event_LONG_PRESS_DOWN (0)
#define Deployment_D_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Deployment_D_event_change_power (6)
#define Deployment_Di_IN_Applying_power ((uint8_T)2U)
#define Deployment_Di_IN_PENDING_CHANGE ((uint8_T)4U)
#define Deployment_Di_IN_SELECTED_1000W ((uint8_T)2U)
#define Deployment_Di_IN_SELECTED_1500W ((uint8_T)3U)
#define Deployment_Dis_IN_SELECTED_300W ((uint8_T)4U)
#define Deployment_Dis_IN_SELECTED_500W ((uint8_T)5U)
#define Deployment_Disp_event_disattiva (7)
#define Deployment_Dispo_IN_SELECTED_0W ((uint8_T)1U)
#define Deployment_Disposit_IN_DELAYING ((uint8_T)1U)
#define Deployment_Dispositi_CALL_EVENT (-1)
#define Deployment_Dispositiv_IN_DEVICE ((uint8_T)1U)
#define Deployment_Dispositivo_G_IN_LOW ((uint8_T)2U)
#define Deployment_Dispositivo_G_IN_OFF ((uint8_T)1U)
#define Deployment_Dispositivo_Gr_IN_ON ((uint8_T)2U)
#define Deployment_Dispositivo_IN_ERROR ((uint8_T)1U)
#define Deployment_Dispositivo_IN_LOW_2 ((uint8_T)3U)
#define Deployment_Dispositivo__IN_HIGH ((uint8_T)1U)
#define Deployment_Dispositivo__IN_IDLE ((uint8_T)2U)
#define Deployment__IN_Applying_0_power ((uint8_T)1U)
#define Deployment__event_LONG_PRESS_UP (2)
#define Deployment_event_SHORT_PRESS_UP (5)

/* Named constants for Chart: '<Root>/PWM' */
#define Deployment_Dispositivo_G_IN_Off ((uint8_T)1U)
#define Deployment_Dispositivo_Gr_IN_On ((uint8_T)2U)

/* Block signals (default storage) */
B_Deployment_Dispositivo_Grup_T Deployment_Dispositivo_Gruppo_B;

/* Block states (default storage) */
DW_Deployment_Dispositivo_Gru_T Deployment_Dispositivo_Grupp_DW;

/* Real-time model */
static RT_MODEL_Deployment_Dispositi_T Deployment_Dispositivo_Grupp_M_;
RT_MODEL_Deployment_Dispositi_T *const Deployment_Dispositivo_Grupp_M =
  &Deployment_Dispositivo_Grupp_M_;

/* Forward declaration for local functions */
static void Deployment_Disposi_erogaPotenza(real_T power);
static void Deployment_Dispositivo_SUPPLIER(void);
static void Deployment_Disp_DELAYED_TRIGGER(void);
static void Deployment_Dispositivo_SELECTOR(void);
static void Deployment_Dispositivo_FORNELLO(void);
static void broadcast_LONG_PRESS_ON_OFF_c2_(void);
static void broadcast_LONG_PRESS_UP_c2_Depl(void);
static void broadcast_LONG_PRESS_DOWN_c2_De(void);
static void c2_Deployment_Dispositivo_Grupp(void);

/* Function for Chart: '<Root>/Fornello' */
static void Deployment_Disposi_erogaPotenza(real_T power)
{
  if (power == 0.0) {
    Deployment_Dispositivo_Gruppo_B.periodo_led_potenza = 0.0;
    Deployment_Dispositivo_Grupp_DW.attivo = false;
  } else if (power == 300.0) {
    Deployment_Dispositivo_Gruppo_B.periodo_led_potenza = 2.0;
    Deployment_Dispositivo_Grupp_DW.attivo = true;
  } else if (power == 500.0) {
    Deployment_Dispositivo_Gruppo_B.periodo_led_potenza = 1.0;
    Deployment_Dispositivo_Grupp_DW.attivo = true;
  } else if (power == 1000.0) {
    Deployment_Dispositivo_Gruppo_B.periodo_led_potenza = 0.5;
    Deployment_Dispositivo_Grupp_DW.attivo = true;
  } else if (power == 1500.0) {
    Deployment_Dispositivo_Gruppo_B.periodo_led_potenza = 0.25;
    Deployment_Dispositivo_Grupp_DW.attivo = true;
  }
}

/* Function for Chart: '<Root>/Fornello' */
static void Deployment_Dispositivo_SUPPLIER(void)
{
  switch (Deployment_Dispositivo_Grupp_DW.is_SUPPLIER) {
   case Deployment__IN_Applying_0_power:
    Deployment_Dispositivo_Grupp_DW.is_SUPPLIER =
      Deployme_IN_NO_CHANGE_REQUESTED;
    break;

   case Deployment_Di_IN_Applying_power:
    if (!Deployment_Dispositivo_Grupp_DW.attivo) {
      Deployment_Dispositivo_Grupp_DW.is_SUPPLIER =
        Deployment__IN_Applying_0_power;
      Deployment_Disposi_erogaPotenza
        (Deployment_Dispositivo_Grupp_DW.selected_power);
    } else {
      Deployment_Dispositivo_Grupp_DW.is_SUPPLIER =
        Deployme_IN_NO_CHANGE_REQUESTED;
    }
    break;

   case Deployme_IN_NO_CHANGE_REQUESTED:
    if (Deployment_Dispositivo_Grupp_DW.sfEvent ==
        Deployment_D_event_change_power) {
      Deployment_Dispositivo_Grupp_DW.is_SUPPLIER =
        Deployment_Di_IN_PENDING_CHANGE;
    }
    break;

   case Deployment_Di_IN_PENDING_CHANGE:
    if (!Deployment_Dispositivo_Gruppo_B.DigitalRead) {
      Deployment_Dispositivo_Grupp_DW.is_SUPPLIER =
        Deployment_Di_IN_Applying_power;
      Deployment_Disposi_erogaPotenza
        (Deployment_Dispositivo_Grupp_DW.selected_power);
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    Deployment_Dispositivo_Grupp_DW.is_SUPPLIER =
      Deployment_D_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<Root>/Fornello' */
static void Deployment_Disp_DELAYED_TRIGGER(void)
{
  int32_T b_previousEvent;
  switch (Deployment_Dispositivo_Grupp_DW.is_DELAYED_TRIGGER) {
   case Deployment_Disposit_IN_DELAYING:
    if (Deployment_Dispositivo_Grupp_DW.sfEvent ==
        D_data_change_in_selected_power) {
      Deployment_Dispositivo_Grupp_DW.is_DELAYED_TRIGGER =
        Deployment_Disposit_IN_DELAYING;
      Deployment_Dispositivo_Grupp_DW.temporalCounter_i2 = 0U;
    } else if (Deployment_Dispositivo_Grupp_DW.temporalCounter_i2 >= 500U) {
      b_previousEvent = Deployment_Dispositivo_Grupp_DW.sfEvent;
      Deployment_Dispositivo_Grupp_DW.sfEvent = Deployment_D_event_change_power;
      if (Deployment_Dispositivo_Grupp_DW.is_active_SUPPLIER != 0U) {
        Deployment_Dispositivo_SUPPLIER();
      }

      Deployment_Dispositivo_Grupp_DW.sfEvent = b_previousEvent;
      Deployment_Dispositivo_Grupp_DW.is_DELAYED_TRIGGER =
        Deployment_Dispositivo__IN_IDLE;
    }
    break;

   case Deployment_Dispositivo__IN_IDLE:
    if (Deployment_Dispositivo_Grupp_DW.sfEvent ==
        D_data_change_in_selected_power) {
      Deployment_Dispositivo_Grupp_DW.is_DELAYED_TRIGGER =
        Deployment_Disposit_IN_DELAYING;
      Deployment_Dispositivo_Grupp_DW.temporalCounter_i2 = 0U;
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    Deployment_Dispositivo_Grupp_DW.is_DELAYED_TRIGGER =
      Deployment_D_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<Root>/Fornello' */
static void Deployment_Dispositivo_SELECTOR(void)
{
  int32_T c_previousEvent;
  boolean_T guard1 = false;
  boolean_T tmp;
  guard1 = false;
  switch (Deployment_Dispositivo_Grupp_DW.is_SELECTOR) {
   case Deployment_Dispo_IN_SELECTED_0W:
    if ((Deployment_Dispositivo_Grupp_DW.sfEvent ==
         Deployment__event_LONG_PRESS_UP) &&
        (!Deployment_Dispositivo_Gruppo_B.DigitalRead)) {
      Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
        Deployment_Dis_IN_SELECTED_300W;
      Deployment_Dispositivo_Grupp_DW.selected_power = 300.0;
      Deployment_Dispositivo_Grupp_DW.sfEvent = D_data_change_in_selected_power;
      if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
        Deployment_Disp_DELAYED_TRIGGER();
      }

      Deployment_Dispositivo_Grupp_DW.sfEvent = 2;
    }
    break;

   case Deployment_Di_IN_SELECTED_1000W:
    tmp = !Deployment_Dispositivo_Gruppo_B.DigitalRead;
    if ((Deployment_Dispositivo_Grupp_DW.sfEvent ==
         Deployment__event_LONG_PRESS_UP) && tmp) {
      Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
        Deployment_Di_IN_SELECTED_1500W;
      Deployment_Dispositivo_Grupp_DW.selected_power = 1500.0;
      Deployment_Dispositivo_Grupp_DW.sfEvent = D_data_change_in_selected_power;
      if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
        Deployment_Disp_DELAYED_TRIGGER();
      }

      Deployment_Dispositivo_Grupp_DW.sfEvent = 2;
    } else if (Deployment_Dispositivo_Grupp_DW.sfEvent ==
               Deployment_Disp_event_disattiva) {
      Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
        Deployment_Dispo_IN_SELECTED_0W;
      Deployment_Dispositivo_Grupp_DW.selected_power = 0.0;
      Deployment_Dispositivo_Grupp_DW.sfEvent = D_data_change_in_selected_power;
      if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
        Deployment_Disp_DELAYED_TRIGGER();
      }

      Deployment_Dispositivo_Grupp_DW.sfEvent = 7;
    } else if ((Deployment_Dispositivo_Grupp_DW.sfEvent ==
                Deploymen_event_LONG_PRESS_DOWN) && tmp) {
      Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
        Deployment_Dis_IN_SELECTED_500W;
      Deployment_Dispositivo_Grupp_DW.selected_power = 500.0;
      Deployment_Dispositivo_Grupp_DW.sfEvent = D_data_change_in_selected_power;
      if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
        Deployment_Disp_DELAYED_TRIGGER();
      }

      Deployment_Dispositivo_Grupp_DW.sfEvent = 0;
    }
    break;

   case Deployment_Di_IN_SELECTED_1500W:
    if ((Deployment_Dispositivo_Grupp_DW.sfEvent ==
         Deploymen_event_LONG_PRESS_DOWN) &&
        (!Deployment_Dispositivo_Gruppo_B.DigitalRead)) {
      Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
        Deployment_Di_IN_SELECTED_1000W;
      Deployment_Dispositivo_Grupp_DW.selected_power = 1000.0;
      Deployment_Dispositivo_Grupp_DW.sfEvent = D_data_change_in_selected_power;
      if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
        Deployment_Disp_DELAYED_TRIGGER();
      }

      Deployment_Dispositivo_Grupp_DW.sfEvent = 0;
    } else if (Deployment_Dispositivo_Grupp_DW.sfEvent ==
               Deployment_Disp_event_disattiva) {
      Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
        Deployment_Dispo_IN_SELECTED_0W;
      Deployment_Dispositivo_Grupp_DW.selected_power = 0.0;
      Deployment_Dispositivo_Grupp_DW.sfEvent = D_data_change_in_selected_power;
      if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
        Deployment_Disp_DELAYED_TRIGGER();
      }

      Deployment_Dispositivo_Grupp_DW.sfEvent = 7;
    }
    break;

   case Deployment_Dis_IN_SELECTED_300W:
    if (Deployment_Dispositivo_Grupp_DW.sfEvent ==
        Deployment_Disp_event_disattiva) {
      guard1 = true;
    } else {
      tmp = !Deployment_Dispositivo_Gruppo_B.DigitalRead;
      if ((Deployment_Dispositivo_Grupp_DW.sfEvent ==
           Deployment__event_LONG_PRESS_UP) && tmp) {
        Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
          Deployment_Dis_IN_SELECTED_500W;
        Deployment_Dispositivo_Grupp_DW.selected_power = 500.0;
        Deployment_Dispositivo_Grupp_DW.sfEvent =
          D_data_change_in_selected_power;
        if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
          Deployment_Disp_DELAYED_TRIGGER();
        }

        Deployment_Dispositivo_Grupp_DW.sfEvent = 2;
      } else if ((Deployment_Dispositivo_Grupp_DW.sfEvent ==
                  Deploymen_event_LONG_PRESS_DOWN) && tmp) {
        guard1 = true;
      }
    }
    break;

   case Deployment_Dis_IN_SELECTED_500W:
    if (Deployment_Dispositivo_Grupp_DW.sfEvent ==
        Deployment_Disp_event_disattiva) {
      Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
        Deployment_Dispo_IN_SELECTED_0W;
      Deployment_Dispositivo_Grupp_DW.selected_power = 0.0;
      Deployment_Dispositivo_Grupp_DW.sfEvent = D_data_change_in_selected_power;
      if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
        Deployment_Disp_DELAYED_TRIGGER();
      }

      Deployment_Dispositivo_Grupp_DW.sfEvent = 7;
    } else {
      tmp = !Deployment_Dispositivo_Gruppo_B.DigitalRead;
      if ((Deployment_Dispositivo_Grupp_DW.sfEvent ==
           Deploymen_event_LONG_PRESS_DOWN) && tmp) {
        Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
          Deployment_Dis_IN_SELECTED_300W;
        Deployment_Dispositivo_Grupp_DW.selected_power = 300.0;
        Deployment_Dispositivo_Grupp_DW.sfEvent =
          D_data_change_in_selected_power;
        if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
          Deployment_Disp_DELAYED_TRIGGER();
        }

        Deployment_Dispositivo_Grupp_DW.sfEvent = 0;
      } else if ((Deployment_Dispositivo_Grupp_DW.sfEvent ==
                  Deployment__event_LONG_PRESS_UP) && tmp) {
        Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
          Deployment_Di_IN_SELECTED_1000W;
        Deployment_Dispositivo_Grupp_DW.selected_power = 1000.0;
        Deployment_Dispositivo_Grupp_DW.sfEvent =
          D_data_change_in_selected_power;
        if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
          Deployment_Disp_DELAYED_TRIGGER();
        }

        Deployment_Dispositivo_Grupp_DW.sfEvent = 2;
      }
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
      Deployment_D_IN_NO_ACTIVE_CHILD;
    break;
  }

  if (guard1) {
    Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
      Deployment_Dispo_IN_SELECTED_0W;
    Deployment_Dispositivo_Grupp_DW.selected_power = 0.0;
    c_previousEvent = Deployment_Dispositivo_Grupp_DW.sfEvent;
    Deployment_Dispositivo_Grupp_DW.sfEvent = D_data_change_in_selected_power;
    if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
      Deployment_Disp_DELAYED_TRIGGER();
    }

    Deployment_Dispositivo_Grupp_DW.sfEvent = c_previousEvent;
  }
}

/* Function for Chart: '<Root>/Fornello' */
static void Deployment_Dispositivo_FORNELLO(void)
{
  int32_T b_previousEvent;
  switch (Deployment_Dispositivo_Grupp_DW.is_FORNELLO) {
   case Deployment_Dispositivo_G_IN_OFF:
    Deployment_Dispositivo_Gruppo_B.led_stato = false;
    if (Deployment_Dispositivo_Grupp_DW.sfEvent ==
        Deploy_event_SHORT_PRESS_ON_OFF) {
      Deployment_Dispositivo_Grupp_DW.is_FORNELLO =
        Deployment_Dispositivo_Gr_IN_ON;
      Deployment_Dispositivo_Gruppo_B.led_stato = true;
      Deployment_Dispositivo_Grupp_DW.is_active_SELECTOR = 1U;
      Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
        Deployment_Dispo_IN_SELECTED_0W;
      Deployment_Dispositivo_Grupp_DW.selected_power = 0.0;
      Deployment_Dispositivo_Grupp_DW.sfEvent = D_data_change_in_selected_power;
      if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
        Deployment_Disp_DELAYED_TRIGGER();
      }

      Deployment_Dispositivo_Grupp_DW.sfEvent = 4;
      Deployment_Dispositivo_Grupp_DW.is_active_WATCHDOG = 1U;
      Deployment_Dispositivo_Grupp_DW.is_WATCHDOG =
        Deployment_Dispositivo__IN_IDLE;
      Deployment_Dispositivo_Grupp_DW.is_active_SUPPLIER = 1U;
      Deployment_Dispositivo_Grupp_DW.is_SUPPLIER =
        Deployme_IN_NO_CHANGE_REQUESTED;
      Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER = 1U;
      Deployment_Dispositivo_Grupp_DW.is_DELAYED_TRIGGER =
        Deployment_Dispositivo__IN_IDLE;
    }
    break;

   case Deployment_Dispositivo_Gr_IN_ON:
    Deployment_Dispositivo_Gruppo_B.led_stato = true;
    if (Deployment_Dispositivo_Grupp_DW.sfEvent ==
        Deploym_event_LONG_PRESS_ON_OFF) {
      Deployment_Dispositivo_Grupp_DW.is_DELAYED_TRIGGER =
        Deployment_D_IN_NO_ACTIVE_CHILD;
      Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER = 0U;
      Deployment_Dispositivo_Grupp_DW.is_SUPPLIER =
        Deployment_D_IN_NO_ACTIVE_CHILD;
      Deployment_Dispositivo_Grupp_DW.is_active_SUPPLIER = 0U;
      if (Deployment_Dispositivo_Grupp_DW.is_WATCHDOG ==
          Deployment_Dispositivo_IN_ERROR) {
        Deployment_Dispositivo_Gruppo_B.led_errore = false;
        Deployment_Dispositivo_Grupp_DW.is_WATCHDOG =
          Deployment_D_IN_NO_ACTIVE_CHILD;
      } else {
        Deployment_Dispositivo_Grupp_DW.is_WATCHDOG =
          Deployment_D_IN_NO_ACTIVE_CHILD;
      }

      Deployment_Dispositivo_Grupp_DW.is_active_WATCHDOG = 0U;
      Deployment_Dispositivo_Grupp_DW.is_SELECTOR =
        Deployment_D_IN_NO_ACTIVE_CHILD;
      Deployment_Dispositivo_Grupp_DW.is_active_SELECTOR = 0U;
      Deployment_Dispositivo_Grupp_DW.is_FORNELLO =
        Deployment_Dispositivo_G_IN_OFF;
      Deployment_Dispositivo_Gruppo_B.led_stato = false;
      Deployment_Disposi_erogaPotenza(0.0);
    } else {
      if (Deployment_Dispositivo_Grupp_DW.is_active_SELECTOR != 0U) {
        Deployment_Dispositivo_SELECTOR();
      }

      if (Deployment_Dispositivo_Grupp_DW.is_active_WATCHDOG != 0U) {
        switch (Deployment_Dispositivo_Grupp_DW.is_WATCHDOG) {
         case Deployment_Dispositivo_IN_ERROR:
          if ((!Deployment_Dispositivo_Gruppo_B.DigitalRead) ||
              (!Deployment_Dispositivo_Grupp_DW.attivo)) {
            Deployment_Dispositivo_Gruppo_B.led_errore = false;
            Deployment_Dispositivo_Grupp_DW.is_WATCHDOG =
              Deployment_Dispositivo__IN_IDLE;
          } else if (Deployment_Dispositivo_Grupp_DW.temporalCounter_i1_o >=
                     1000U) {
            b_previousEvent = Deployment_Dispositivo_Grupp_DW.sfEvent;
            Deployment_Dispositivo_Grupp_DW.sfEvent =
              Deployment_Disp_event_disattiva;
            if (Deployment_Dispositivo_Grupp_DW.is_active_SELECTOR != 0U) {
              Deployment_Dispositivo_SELECTOR();
            }

            Deployment_Dispositivo_Grupp_DW.sfEvent = b_previousEvent;
            Deployment_Disposi_erogaPotenza(0.0);
          }
          break;

         case Deployment_Dispositivo__IN_IDLE:
          if (Deployment_Dispositivo_Gruppo_B.DigitalRead &&
              Deployment_Dispositivo_Grupp_DW.attivo) {
            Deployment_Dispositivo_Grupp_DW.is_WATCHDOG =
              Deployment_Dispositivo_IN_ERROR;
            Deployment_Dispositivo_Grupp_DW.temporalCounter_i1_o = 0U;
            Deployment_Dispositivo_Gruppo_B.led_errore = true;
          }
          break;

         default:
          /* Unreachable state, for coverage only */
          Deployment_Dispositivo_Grupp_DW.is_WATCHDOG =
            Deployment_D_IN_NO_ACTIVE_CHILD;
          break;
        }
      }

      if (Deployment_Dispositivo_Grupp_DW.is_active_SUPPLIER != 0U) {
        Deployment_Dispositivo_SUPPLIER();
      }

      if (Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER != 0U) {
        Deployment_Disp_DELAYED_TRIGGER();
      }
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    Deployment_Dispositivo_Grupp_DW.is_FORNELLO =
      Deployment_D_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<Root>/Fornello' */
static void broadcast_LONG_PRESS_ON_OFF_c2_(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Deployment_Dispositivo_Grupp_DW.sfEvent;
  Deployment_Dispositivo_Grupp_DW.sfEvent = Deploym_event_LONG_PRESS_ON_OFF;

  /* Chart: '<Root>/Fornello' */
  c2_Deployment_Dispositivo_Grupp();
  Deployment_Dispositivo_Grupp_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Fornello' */
static void broadcast_LONG_PRESS_UP_c2_Depl(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Deployment_Dispositivo_Grupp_DW.sfEvent;
  Deployment_Dispositivo_Grupp_DW.sfEvent = Deployment__event_LONG_PRESS_UP;

  /* Chart: '<Root>/Fornello' */
  c2_Deployment_Dispositivo_Grupp();
  Deployment_Dispositivo_Grupp_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Fornello' */
static void broadcast_LONG_PRESS_DOWN_c2_De(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Deployment_Dispositivo_Grupp_DW.sfEvent;
  Deployment_Dispositivo_Grupp_DW.sfEvent = Deploymen_event_LONG_PRESS_DOWN;

  /* Chart: '<Root>/Fornello' */
  c2_Deployment_Dispositivo_Grupp();
  Deployment_Dispositivo_Grupp_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Fornello' */
static void c2_Deployment_Dispositivo_Grupp(void)
{
  int32_T b_previousEvent;
  uint32_T tmp;
  if (Deployment_Dispositivo_Grupp_DW.is_c2_Deployment_Dispositivo_Gr ==
      Deployment_Dispositiv_IN_DEVICE) {
    if (Deployment_Dispositivo_Grupp_DW.is_active_FORNELLO != 0U) {
      Deployment_Dispositivo_FORNELLO();
    }

    if (Deployment_Dispositivo_Grupp_DW.is_active_BUTTON_ON_OFF != 0U) {
      switch (Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF) {
       case Deployment_Dispositivo__IN_HIGH:
        if (!Deployment_Dispositivo_Gruppo_B.DigitalRead3) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF =
            Deployment_Dispositivo_G_IN_LOW;
          Deployment_Dispositivo_Grupp_DW.temporalCounter_i3 = 0U;
        }
        break;

       case Deployment_Dispositivo_G_IN_LOW:
        /* Constant: '<Root>/Constant3' */
        tmp = (uint32_T)ceil(Deployment_Dispositivo_Gruppo_P.Constant3_Value *
                             100.0);
        if ((Deployment_Dispositivo_Grupp_DW.temporalCounter_i3 >= tmp) &&
            (!Deployment_Dispositivo_Gruppo_B.DigitalRead3)) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF =
            Deployment_D_IN_NO_ACTIVE_CHILD;
          broadcast_LONG_PRESS_ON_OFF_c2_();
          if (Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF ==
              Deployment_D_IN_NO_ACTIVE_CHILD) {
            Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF =
              Deployment_Dispositivo_IN_LOW_2;
          }
        } else if ((Deployment_Dispositivo_Grupp_DW.temporalCounter_i3 < tmp) &&
                   Deployment_Dispositivo_Gruppo_B.DigitalRead3) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF =
            Deployment_D_IN_NO_ACTIVE_CHILD;
          b_previousEvent = Deployment_Dispositivo_Grupp_DW.sfEvent;
          Deployment_Dispositivo_Grupp_DW.sfEvent =
            Deploy_event_SHORT_PRESS_ON_OFF;

          /* Chart: '<Root>/Fornello' */
          c2_Deployment_Dispositivo_Grupp();
          Deployment_Dispositivo_Grupp_DW.sfEvent = b_previousEvent;
          if (Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF ==
              Deployment_D_IN_NO_ACTIVE_CHILD) {
            Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF =
              Deployment_Dispositivo__IN_HIGH;
          }
        } else if ((Deployment_Dispositivo_Grupp_DW.temporalCounter_i3 >= tmp) &&
                   Deployment_Dispositivo_Gruppo_B.DigitalRead3) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF =
            Deployment_D_IN_NO_ACTIVE_CHILD;
          broadcast_LONG_PRESS_ON_OFF_c2_();
          if (Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF ==
              Deployment_D_IN_NO_ACTIVE_CHILD) {
            Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF =
              Deployment_Dispositivo__IN_HIGH;
          }
        }
        break;

       case Deployment_Dispositivo_IN_LOW_2:
        if (Deployment_Dispositivo_Gruppo_B.DigitalRead3) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF =
            Deployment_Dispositivo__IN_HIGH;
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF =
          Deployment_D_IN_NO_ACTIVE_CHILD;
        break;
      }
    }

    if (Deployment_Dispositivo_Grupp_DW.is_active_BUTTON_UP != 0U) {
      switch (Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP) {
       case Deployment_Dispositivo__IN_HIGH:
        if (!Deployment_Dispositivo_Gruppo_B.DigitalRead1) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP =
            Deployment_Dispositivo_G_IN_LOW;
          Deployment_Dispositivo_Grupp_DW.temporalCounter_i4 = 0U;
        }
        break;

       case Deployment_Dispositivo_G_IN_LOW:
        /* Constant: '<Root>/Constant2' */
        tmp = (uint32_T)ceil(Deployment_Dispositivo_Gruppo_P.Constant2_Value *
                             100.0);
        if ((Deployment_Dispositivo_Grupp_DW.temporalCounter_i4 >= tmp) &&
            (!Deployment_Dispositivo_Gruppo_B.DigitalRead1)) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP =
            Deployment_D_IN_NO_ACTIVE_CHILD;
          broadcast_LONG_PRESS_UP_c2_Depl();
          if (Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP ==
              Deployment_D_IN_NO_ACTIVE_CHILD) {
            Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP =
              Deployment_Dispositivo_IN_LOW_2;
          }
        } else if ((Deployment_Dispositivo_Grupp_DW.temporalCounter_i4 < tmp) &&
                   Deployment_Dispositivo_Gruppo_B.DigitalRead1) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP =
            Deployment_D_IN_NO_ACTIVE_CHILD;
          b_previousEvent = Deployment_Dispositivo_Grupp_DW.sfEvent;
          Deployment_Dispositivo_Grupp_DW.sfEvent =
            Deployment_event_SHORT_PRESS_UP;

          /* Chart: '<Root>/Fornello' */
          c2_Deployment_Dispositivo_Grupp();
          Deployment_Dispositivo_Grupp_DW.sfEvent = b_previousEvent;
          if (Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP ==
              Deployment_D_IN_NO_ACTIVE_CHILD) {
            Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP =
              Deployment_Dispositivo__IN_HIGH;
          }
        } else if ((Deployment_Dispositivo_Grupp_DW.temporalCounter_i4 >= tmp) &&
                   Deployment_Dispositivo_Gruppo_B.DigitalRead1) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP =
            Deployment_D_IN_NO_ACTIVE_CHILD;
          broadcast_LONG_PRESS_UP_c2_Depl();
          if (Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP ==
              Deployment_D_IN_NO_ACTIVE_CHILD) {
            Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP =
              Deployment_Dispositivo__IN_HIGH;
          }
        }
        break;

       case Deployment_Dispositivo_IN_LOW_2:
        if (Deployment_Dispositivo_Gruppo_B.DigitalRead1) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP =
            Deployment_Dispositivo__IN_HIGH;
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP =
          Deployment_D_IN_NO_ACTIVE_CHILD;
        break;
      }
    }

    if (Deployment_Dispositivo_Grupp_DW.is_active_BUTTON_DOWN != 0U) {
      switch (Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN) {
       case Deployment_Dispositivo__IN_HIGH:
        if (!Deployment_Dispositivo_Gruppo_B.DigitalRead2) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN =
            Deployment_Dispositivo_G_IN_LOW;
          Deployment_Dispositivo_Grupp_DW.temporalCounter_i5 = 0U;
        }
        break;

       case Deployment_Dispositivo_G_IN_LOW:
        /* Constant: '<Root>/Constant1' */
        tmp = (uint32_T)ceil(Deployment_Dispositivo_Gruppo_P.Constant1_Value *
                             100.0);
        if ((Deployment_Dispositivo_Grupp_DW.temporalCounter_i5 >= tmp) &&
            (!Deployment_Dispositivo_Gruppo_B.DigitalRead2)) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN =
            Deployment_D_IN_NO_ACTIVE_CHILD;
          broadcast_LONG_PRESS_DOWN_c2_De();
          if (Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN ==
              Deployment_D_IN_NO_ACTIVE_CHILD) {
            Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN =
              Deployment_Dispositivo_IN_LOW_2;
          }
        } else if ((Deployment_Dispositivo_Grupp_DW.temporalCounter_i5 < tmp) &&
                   Deployment_Dispositivo_Gruppo_B.DigitalRead2) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN =
            Deployment_D_IN_NO_ACTIVE_CHILD;
          b_previousEvent = Deployment_Dispositivo_Grupp_DW.sfEvent;
          Deployment_Dispositivo_Grupp_DW.sfEvent =
            Deployme_event_SHORT_PRESS_DOWN;

          /* Chart: '<Root>/Fornello' */
          c2_Deployment_Dispositivo_Grupp();
          Deployment_Dispositivo_Grupp_DW.sfEvent = b_previousEvent;
          if (Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN ==
              Deployment_D_IN_NO_ACTIVE_CHILD) {
            Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN =
              Deployment_Dispositivo__IN_HIGH;
          }
        } else if ((Deployment_Dispositivo_Grupp_DW.temporalCounter_i5 >= tmp) &&
                   Deployment_Dispositivo_Gruppo_B.DigitalRead2) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN =
            Deployment_D_IN_NO_ACTIVE_CHILD;
          broadcast_LONG_PRESS_DOWN_c2_De();
          if (Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN ==
              Deployment_D_IN_NO_ACTIVE_CHILD) {
            Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN =
              Deployment_Dispositivo__IN_HIGH;
          }
        }
        break;

       case Deployment_Dispositivo_IN_LOW_2:
        if (Deployment_Dispositivo_Gruppo_B.DigitalRead2) {
          Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN =
            Deployment_Dispositivo__IN_HIGH;
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN =
          Deployment_D_IN_NO_ACTIVE_CHILD;
        break;
      }
    }
  }
}

/* Model step function */
void Deployment_Dispositivo_Gruppo8_step(void)
{
  boolean_T rtb_output;

  /* MATLABSystem: '<Root>/Digital Read3' */
  if (Deployment_Dispositivo_Grupp_DW.obj.SampleTime !=
      Deployment_Dispositivo_Gruppo_P.DigitalRead3_SampleTime) {
    Deployment_Dispositivo_Grupp_DW.obj.SampleTime =
      Deployment_Dispositivo_Gruppo_P.DigitalRead3_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read3' */
  Deployment_Dispositivo_Gruppo_B.DigitalRead3 = MW_digitalIO_read
    (Deployment_Dispositivo_Grupp_DW.obj.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<Root>/Digital Read' */
  if (Deployment_Dispositivo_Grupp_DW.obj_m.SampleTime !=
      Deployment_Dispositivo_Gruppo_P.DigitalRead_SampleTime) {
    Deployment_Dispositivo_Grupp_DW.obj_m.SampleTime =
      Deployment_Dispositivo_Gruppo_P.DigitalRead_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read' */
  Deployment_Dispositivo_Gruppo_B.DigitalRead = MW_digitalIO_read
    (Deployment_Dispositivo_Grupp_DW.obj_m.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<Root>/Digital Read1' */
  if (Deployment_Dispositivo_Grupp_DW.obj_b.SampleTime !=
      Deployment_Dispositivo_Gruppo_P.DigitalRead1_SampleTime) {
    Deployment_Dispositivo_Grupp_DW.obj_b.SampleTime =
      Deployment_Dispositivo_Gruppo_P.DigitalRead1_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read1' */
  Deployment_Dispositivo_Gruppo_B.DigitalRead1 = MW_digitalIO_read
    (Deployment_Dispositivo_Grupp_DW.obj_b.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<Root>/Digital Read2' */
  if (Deployment_Dispositivo_Grupp_DW.obj_o.SampleTime !=
      Deployment_Dispositivo_Gruppo_P.DigitalRead2_SampleTime) {
    Deployment_Dispositivo_Grupp_DW.obj_o.SampleTime =
      Deployment_Dispositivo_Gruppo_P.DigitalRead2_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read2' */
  Deployment_Dispositivo_Gruppo_B.DigitalRead2 = MW_digitalIO_read
    (Deployment_Dispositivo_Grupp_DW.obj_o.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Fornello' */
  if (Deployment_Dispositivo_Grupp_DW.isNotInit) {
    if (Deployment_Dispositivo_Grupp_DW.temporalCounter_i1_o < 1023U) {
      Deployment_Dispositivo_Grupp_DW.temporalCounter_i1_o++;
    }

    if (Deployment_Dispositivo_Grupp_DW.temporalCounter_i2 < 511U) {
      Deployment_Dispositivo_Grupp_DW.temporalCounter_i2++;
    }

    if (Deployment_Dispositivo_Grupp_DW.temporalCounter_i3 < MAX_uint32_T) {
      Deployment_Dispositivo_Grupp_DW.temporalCounter_i3++;
    }

    if (Deployment_Dispositivo_Grupp_DW.temporalCounter_i4 < MAX_uint32_T) {
      Deployment_Dispositivo_Grupp_DW.temporalCounter_i4++;
    }

    if (Deployment_Dispositivo_Grupp_DW.temporalCounter_i5 < MAX_uint32_T) {
      Deployment_Dispositivo_Grupp_DW.temporalCounter_i5++;
    }
  }

  Deployment_Dispositivo_Grupp_DW.isNotInit = true;
  Deployment_Dispositivo_Grupp_DW.sfEvent = Deployment_Dispositi_CALL_EVENT;
  c2_Deployment_Dispositivo_Grupp();

  /* End of Chart: '<Root>/Fornello' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(Deployment_Dispositivo_Grupp_DW.obj_m4.MW_DIGITALIO_HANDLE,
                     Deployment_Dispositivo_Gruppo_B.led_stato);

  /* Chart: '<Root>/PWM' */
  if (Deployment_Dispositivo_Grupp_DW.temporalCounter_i1 < MAX_uint32_T) {
    Deployment_Dispositivo_Grupp_DW.temporalCounter_i1++;
  }

  if (Deployment_Dispositivo_Grupp_DW.is_active_c5_Deployment_Disposi == 0U) {
    Deployment_Dispositivo_Grupp_DW.is_active_c5_Deployment_Disposi = 1U;
    Deployment_Dispositivo_Grupp_DW.is_c5_Deployment_Dispositivo_Gr =
      Deployment_Dispositivo_G_IN_Off;
    Deployment_Dispositivo_Grupp_DW.temporalCounter_i1 = 0U;
    rtb_output = false;
  } else if (Deployment_Dispositivo_Grupp_DW.is_c5_Deployment_Dispositivo_Gr ==
             Deployment_Dispositivo_G_IN_Off) {
    rtb_output = false;
    if ((Deployment_Dispositivo_Grupp_DW.temporalCounter_i1 >= (uint32_T)ceil
         (Deployment_Dispositivo_Gruppo_B.periodo_led_potenza * 100.0)) &&
        (Deployment_Dispositivo_Gruppo_B.periodo_led_potenza != 0.0)) {
      Deployment_Dispositivo_Grupp_DW.is_c5_Deployment_Dispositivo_Gr =
        Deployment_Dispositivo_Gr_IN_On;
      Deployment_Dispositivo_Grupp_DW.temporalCounter_i1 = 0U;
      rtb_output = true;
    }
  } else {
    /* case IN_On: */
    rtb_output = true;
    if (Deployment_Dispositivo_Grupp_DW.temporalCounter_i1 >= (uint32_T)ceil
        (Deployment_Dispositivo_Gruppo_B.periodo_led_potenza * 100.0)) {
      Deployment_Dispositivo_Grupp_DW.is_c5_Deployment_Dispositivo_Gr =
        Deployment_Dispositivo_G_IN_Off;
      Deployment_Dispositivo_Grupp_DW.temporalCounter_i1 = 0U;
      rtb_output = false;
    }
  }

  /* End of Chart: '<Root>/PWM' */

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(Deployment_Dispositivo_Grupp_DW.obj_i.MW_DIGITALIO_HANDLE,
                     rtb_output);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(Deployment_Dispositivo_Grupp_DW.obj_d.MW_DIGITALIO_HANDLE,
                     Deployment_Dispositivo_Gruppo_B.led_errore);
}

/* Model initialize function */
void Deployment_Dispositivo_Gruppo8_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Deployment_Dispositivo_Grupp_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Deployment_Dispositivo_Gruppo_B), 0,
                sizeof(B_Deployment_Dispositivo_Grup_T));

  /* states (dwork) */
  (void) memset((void *)&Deployment_Dispositivo_Grupp_DW, 0,
                sizeof(DW_Deployment_Dispositivo_Gru_T));

  {
    uint32_T pinname;
    mbed_DigitalRead_Deployment_D_T *obj;
    mbed_DigitalWrite_Deployment__T *obj_0;

    /* Start for MATLABSystem: '<Root>/Digital Read3' */
    Deployment_Dispositivo_Grupp_DW.obj.matlabCodegenIsDeleted = false;
    Deployment_Dispositivo_Grupp_DW.objisempty_h = true;
    Deployment_Dispositivo_Grupp_DW.obj.SampleTime =
      Deployment_Dispositivo_Gruppo_P.DigitalRead3_SampleTime;
    obj = &Deployment_Dispositivo_Grupp_DW.obj;
    Deployment_Dispositivo_Grupp_DW.obj.isInitialized = 1;
    pinname = PC_13;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 0);
    Deployment_Dispositivo_Grupp_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    Deployment_Dispositivo_Grupp_DW.obj_m.matlabCodegenIsDeleted = false;
    Deployment_Dispositivo_Grupp_DW.objisempty_j = true;
    Deployment_Dispositivo_Grupp_DW.obj_m.SampleTime =
      Deployment_Dispositivo_Gruppo_P.DigitalRead_SampleTime;
    obj = &Deployment_Dispositivo_Grupp_DW.obj_m;
    Deployment_Dispositivo_Grupp_DW.obj_m.isInitialized = 1;
    pinname = PC_10;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 0);
    Deployment_Dispositivo_Grupp_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read1' */
    Deployment_Dispositivo_Grupp_DW.obj_b.matlabCodegenIsDeleted = false;
    Deployment_Dispositivo_Grupp_DW.objisempty_d = true;
    Deployment_Dispositivo_Grupp_DW.obj_b.SampleTime =
      Deployment_Dispositivo_Gruppo_P.DigitalRead1_SampleTime;
    obj = &Deployment_Dispositivo_Grupp_DW.obj_b;
    Deployment_Dispositivo_Grupp_DW.obj_b.isInitialized = 1;
    pinname = PC_2;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 0);
    Deployment_Dispositivo_Grupp_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read2' */
    Deployment_Dispositivo_Grupp_DW.obj_o.matlabCodegenIsDeleted = false;
    Deployment_Dispositivo_Grupp_DW.objisempty_o = true;
    Deployment_Dispositivo_Grupp_DW.obj_o.SampleTime =
      Deployment_Dispositivo_Gruppo_P.DigitalRead2_SampleTime;
    obj = &Deployment_Dispositivo_Grupp_DW.obj_o;
    Deployment_Dispositivo_Grupp_DW.obj_o.isInitialized = 1;
    pinname = PC_3;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 0);
    Deployment_Dispositivo_Grupp_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    Deployment_Dispositivo_Grupp_DW.obj_m4.matlabCodegenIsDeleted = false;
    Deployment_Dispositivo_Grupp_DW.objisempty_k = true;
    obj_0 = &Deployment_Dispositivo_Grupp_DW.obj_m4;
    Deployment_Dispositivo_Grupp_DW.obj_m4.isInitialized = 1;
    pinname = PA_5;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    Deployment_Dispositivo_Grupp_DW.obj_m4.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    Deployment_Dispositivo_Grupp_DW.obj_i.matlabCodegenIsDeleted = false;
    Deployment_Dispositivo_Grupp_DW.objisempty_c = true;
    obj_0 = &Deployment_Dispositivo_Grupp_DW.obj_i;
    Deployment_Dispositivo_Grupp_DW.obj_i.isInitialized = 1;
    pinname = PA_6;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    Deployment_Dispositivo_Grupp_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    Deployment_Dispositivo_Grupp_DW.obj_d.matlabCodegenIsDeleted = false;
    Deployment_Dispositivo_Grupp_DW.objisempty = true;
    obj_0 = &Deployment_Dispositivo_Grupp_DW.obj_d;
    Deployment_Dispositivo_Grupp_DW.obj_d.isInitialized = 1;
    pinname = PA_7;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    Deployment_Dispositivo_Grupp_DW.obj_d.isSetupComplete = true;
  }

  /* SystemInitialize for Chart: '<Root>/Fornello' */
  Deployment_Dispositivo_Grupp_DW.temporalCounter_i5 = 0U;
  Deployment_Dispositivo_Grupp_DW.temporalCounter_i3 = 0U;
  Deployment_Dispositivo_Grupp_DW.temporalCounter_i4 = 0U;
  Deployment_Dispositivo_Grupp_DW.is_active_DELAYED_TRIGGER = 0U;
  Deployment_Dispositivo_Grupp_DW.is_DELAYED_TRIGGER =
    Deployment_D_IN_NO_ACTIVE_CHILD;
  Deployment_Dispositivo_Grupp_DW.temporalCounter_i2 = 0U;
  Deployment_Dispositivo_Grupp_DW.is_active_SELECTOR = 0U;
  Deployment_Dispositivo_Grupp_DW.is_SELECTOR = Deployment_D_IN_NO_ACTIVE_CHILD;
  Deployment_Dispositivo_Grupp_DW.is_active_SUPPLIER = 0U;
  Deployment_Dispositivo_Grupp_DW.is_SUPPLIER = Deployment_D_IN_NO_ACTIVE_CHILD;
  Deployment_Dispositivo_Grupp_DW.is_active_WATCHDOG = 0U;
  Deployment_Dispositivo_Grupp_DW.is_WATCHDOG = Deployment_D_IN_NO_ACTIVE_CHILD;
  Deployment_Dispositivo_Grupp_DW.temporalCounter_i1_o = 0U;
  Deployment_Dispositivo_Grupp_DW.attivo = false;
  Deployment_Dispositivo_Grupp_DW.selected_power = 0.0;
  Deployment_Dispositivo_Gruppo_B.periodo_led_potenza = 0.0;
  Deployment_Dispositivo_Gruppo_B.led_errore = false;
  Deployment_Dispositivo_Grupp_DW.isNotInit = false;
  Deployment_Dispositivo_Grupp_DW.sfEvent = Deployment_Dispositi_CALL_EVENT;

  /* Chart: '<Root>/Fornello' */
  Deployment_Dispositivo_Grupp_DW.is_c2_Deployment_Dispositivo_Gr =
    Deployment_Dispositiv_IN_DEVICE;
  Deployment_Dispositivo_Grupp_DW.is_active_FORNELLO = 1U;
  Deployment_Dispositivo_Grupp_DW.is_FORNELLO = Deployment_Dispositivo_G_IN_OFF;
  Deployment_Dispositivo_Gruppo_B.led_stato = false;
  Deployment_Disposi_erogaPotenza(0.0);
  Deployment_Dispositivo_Grupp_DW.is_active_BUTTON_ON_OFF = 1U;
  Deployment_Dispositivo_Grupp_DW.is_BUTTON_ON_OFF =
    Deployment_Dispositivo__IN_HIGH;
  Deployment_Dispositivo_Grupp_DW.is_active_BUTTON_UP = 1U;
  Deployment_Dispositivo_Grupp_DW.is_BUTTON_UP = Deployment_Dispositivo__IN_HIGH;
  Deployment_Dispositivo_Grupp_DW.is_active_BUTTON_DOWN = 1U;
  Deployment_Dispositivo_Grupp_DW.is_BUTTON_DOWN =
    Deployment_Dispositivo__IN_HIGH;

  /* SystemInitialize for Chart: '<Root>/PWM' */
  Deployment_Dispositivo_Grupp_DW.temporalCounter_i1 = 0U;
  Deployment_Dispositivo_Grupp_DW.is_active_c5_Deployment_Disposi = 0U;
  Deployment_Dispositivo_Grupp_DW.is_c5_Deployment_Dispositivo_Gr =
    Deployment_D_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void Deployment_Dispositivo_Gruppo8_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read3' */
  if (!Deployment_Dispositivo_Grupp_DW.obj.matlabCodegenIsDeleted) {
    Deployment_Dispositivo_Grupp_DW.obj.matlabCodegenIsDeleted = true;
    if ((Deployment_Dispositivo_Grupp_DW.obj.isInitialized == 1) &&
        Deployment_Dispositivo_Grupp_DW.obj.isSetupComplete) {
      MW_digitalIO_close(Deployment_Dispositivo_Grupp_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!Deployment_Dispositivo_Grupp_DW.obj_m.matlabCodegenIsDeleted) {
    Deployment_Dispositivo_Grupp_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Deployment_Dispositivo_Grupp_DW.obj_m.isInitialized == 1) &&
        Deployment_Dispositivo_Grupp_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close
        (Deployment_Dispositivo_Grupp_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read1' */
  if (!Deployment_Dispositivo_Grupp_DW.obj_b.matlabCodegenIsDeleted) {
    Deployment_Dispositivo_Grupp_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Deployment_Dispositivo_Grupp_DW.obj_b.isInitialized == 1) &&
        Deployment_Dispositivo_Grupp_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close
        (Deployment_Dispositivo_Grupp_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read2' */
  if (!Deployment_Dispositivo_Grupp_DW.obj_o.matlabCodegenIsDeleted) {
    Deployment_Dispositivo_Grupp_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Deployment_Dispositivo_Grupp_DW.obj_o.isInitialized == 1) &&
        Deployment_Dispositivo_Grupp_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close
        (Deployment_Dispositivo_Grupp_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!Deployment_Dispositivo_Grupp_DW.obj_m4.matlabCodegenIsDeleted) {
    Deployment_Dispositivo_Grupp_DW.obj_m4.matlabCodegenIsDeleted = true;
    if ((Deployment_Dispositivo_Grupp_DW.obj_m4.isInitialized == 1) &&
        Deployment_Dispositivo_Grupp_DW.obj_m4.isSetupComplete) {
      MW_digitalIO_close
        (Deployment_Dispositivo_Grupp_DW.obj_m4.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!Deployment_Dispositivo_Grupp_DW.obj_i.matlabCodegenIsDeleted) {
    Deployment_Dispositivo_Grupp_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Deployment_Dispositivo_Grupp_DW.obj_i.isInitialized == 1) &&
        Deployment_Dispositivo_Grupp_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close
        (Deployment_Dispositivo_Grupp_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!Deployment_Dispositivo_Grupp_DW.obj_d.matlabCodegenIsDeleted) {
    Deployment_Dispositivo_Grupp_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Deployment_Dispositivo_Grupp_DW.obj_d.isInitialized == 1) &&
        Deployment_Dispositivo_Grupp_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close
        (Deployment_Dispositivo_Grupp_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */
}
