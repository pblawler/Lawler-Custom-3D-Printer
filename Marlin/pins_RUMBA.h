/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * RUMBA pin assignments
 */

#ifndef __AVR_ATmega2560__
  #error "Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu."
#endif

#if HOTENDS > 3 || E_STEPPERS > 3
  #error "RUMBA supports up to 3 hotends / E-steppers. Comment out this line to continue."
#endif

#define DEFAULT_MACHINE_NAME "A8 Dual Head"
#define BOARD_NAME           "Rumba"

//
// Servos
//
#define SERVO0_PIN         5  //Used by Bltouch on EXP3

//
// Heater Kill Output Pin to power relay for all heaters.  Cannot be used simultaniously with Software SPI
//
#if !ENABLED(TMC_USE_SW_SPI)
  #define SUICIDE_PIN        15   // PIN that has to be turned on right after start, to keep power flowing.
#endif

//
// Limit Switches
//
#define X_MIN_PIN            37
#if X_DRIVER_TYPE == TMC2130     
    #define X_CS_PIN         36
    #define X_MAX_PIN        -1     
#else
  #define X_MAX_PIN          36
#endif

#define Y_MIN_PIN            35
#if Y_DRIVER_TYPE == TMC2130
    #define Y_CS_PIN         34
    #define Y_MAX_PIN        -1
#else
  #define Y_MAX_PIN          34
#endif

#define Z_MIN_PIN            33
#if Z_DRIVER_TYPE == TMC2130
    //
    // Note in this instance Z_MIN_PROBE_PIN variable is useless.  Z_MIN_PIN must be used for probe.
    //
    #define Z_CS_PIN         32
    #define Z2_CS_PIN        14
    #define Z_MAX_PIN        31
    #define Z2_MAX_PIN       30
#else
  //
  // Z Probe (when not Z_MIN_PIN)
  //
  #ifndef Z_MIN_PROBE_PIN
    #define Z_MIN_PROBE_PIN  32
    #define Z_MAX_PIN        -1
  #else
    #define Z_MAX_PIN        32
  #endif
#endif

//
// Steppers
//
#define X_STEP_PIN         17
#define X_DIR_PIN          16
#define X_ENABLE_PIN       48

#define Y_STEP_PIN         54
#define Y_DIR_PIN          47
#define Y_ENABLE_PIN       55

#define Z_STEP_PIN         57
#define Z_DIR_PIN          56
#define Z_ENABLE_PIN       62

#define E0_STEP_PIN        23
#define E0_DIR_PIN         22
#define E0_ENABLE_PIN      24

#define E1_STEP_PIN        26
#define E1_DIR_PIN         25
#define E1_ENABLE_PIN      27

#define Z2_STEP_PIN        29
#define Z2_DIR_PIN         28
#define Z2_ENABLE_PIN      39

/*
 * START SPI
 */

#if ENABLED(TMC_USE_SW_SPI)
    #define TMC_SW_MOSI    31 //  31 on Exp3
    #define TMC_SW_MISO    30 //  30 on Exp3  
    #define TMC_SW_SCK     15 //  15 on Exp3
 #else
    #define TMC_SW_MOSI    51 // on ISP1 
    #define TMC_SW_MISO    50 // on ISP1
    #define TMC_SW_SCK     52  //on ISP1
#endif

/*
 * END  SPI
 */

#if HAS_DRIVER(TMC2208)
  /**
   * TMC2208 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial1
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL  Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  /*
   * Software serial for UART not fully implemented in 1.1.9 cannot use non-interuptable pins for Rx.
  */

  //#define X_SERIAL_TX_PIN    -1
  //#define X_SERIAL_RX_PIN    -1
  //#define X2_SERIAL_TX_PIN   -1
  //#define X2_SERIAL_RX_PIN   -1

  //#define Y_SERIAL_TX_PIN    -1
  //#define Y_SERIAL_RX_PIN    -1
  //#define Y2_SERIAL_TX_PIN   -1
  //#define Y2_SERIAL_RX_PIN   -1

  //#define Z_SERIAL_TX_PIN    -1
  //#define Z_SERIAL_RX_PIN    -1
  //#define Z2_SERIAL_TX_PIN   -1
  //#define Z2_SERIAL_RX_PIN   -1

  //#define E0_SERIAL_TX_PIN   -1
  //#define E0_SERIAL_RX_PIN   -1
  //#define E1_SERIAL_TX_PIN   -1
  //#define E1_SERIAL_RX_PIN   -1
  //#define E2_SERIAL_TX_PIN   -1
  //#define E2_SERIAL_RX_PIN   -1
  //#define E3_SERIAL_TX_PIN   -1
  //#define E3_SERIAL_RX_PIN   -1
  //#define E4_SERIAL_TX_PIN   -1
  //#define E4_SERIAL_RX_PIN   -1
#endif
/* 
 *  END Software serial
*/

//
// Temperature Sensors
//
#if TEMP_SENSOR_0 == TypKThemoAD8495
  #define TEMP_0_PIN        9   // Analog Input (connector *K1* on RUMBA thermocouple ADD ON is used)
#else
  #define TEMP_0_PIN       15   // Analog Input (default connector for thermistor *T0* on rumba board is used)
#endif

#if TEMP_SENSOR_1 == TypKThemoAD8495
  #define TEMP_1_PIN        10   // Analog Input (connector *K2* on RUMBA thermocouple ADD ON is used)
#else
  #define TEMP_1_PIN       14   // Analog Input (default connector for thermistor *T1* on rumba board is used)
#endif

#if TEMP_SENSOR_2 == -1
  #define TEMP_2_PIN        7   // Analog Input (connector *K3* on RUMBA thermocouple ADD ON is used <-- this can't be used when TEMP_SENSOR_BED is defined as thermocouple)
#else
  #define TEMP_2_PIN       13   // Analog Input (default connector for thermistor *T2* on rumba board is used)
#endif

// optional for extruder 4 or chamber:
//#define TEMP_X_PIN         12   // Analog Input (default connector for thermistor *T3* on rumba board is used)
//#define TEMP_CHAMBER_PIN   12   // Analog Input (default connector for thermistor *T3* on rumba board is used)

#if TEMP_SENSOR_BED == -1
  #define TEMP_BED_PIN      7   // Analog Input (connector *K3* on RUMBA thermocouple ADD ON is used <-- this can't be used when TEMP_SENSOR_2 is defined as thermocouple)
#else
  #define TEMP_BED_PIN     11   // Analog Input (default connector for thermistor *THB* on rumba board is used)
#endif

//
// Heaters / Fans
//
#define HEATER_0_PIN        2
#define HEATER_1_PIN        3
#define HEATER_2_PIN        6
#define HEATER_3_PIN        8
#define HEATER_BED_PIN      9

//#define FAN_PIN           7 //  Pin 7 used for hot end cooling. 
#define FAN_PIN           8  // Used as part cooler
//#define FAN1_PIN            8 // Can be defined for independent part coolers for both extruders.

//
// Misc. Functions
//
#define SDSS               53
#define LED_PIN            13
#define PS_ON_PIN          45
#define KILL_PIN           46
#define CASE_LIGHT_PIN     45

//
// M3/M4/M5 - Spindle/Laser Control
//
#ifndef SPINDLE_LASER_PWM_PIN
  #define SPINDLE_LASER_PWM_PIN     4   // MUST BE HARDWARE PWM. Pin 4 interrupts OC0* and OC1* always in use?
#endif
#ifndef SPINDLE_LASER_ENABLE_PIN
  #define SPINDLE_LASER_ENABLE_PIN 14   // Pin should have a pullup!
#endif
#ifndef SPINDLE_DIR_PIN
  #define SPINDLE_DIR_PIN          15
#endif

//
// LCD / Controller
//
#define SD_DETECT_PIN      49
#define BEEPER_PIN         44
#define LCD_PINS_D7        40
#define BTN_EN1            11
#define BTN_EN2            12
#define BTN_ENC            43

#if ENABLED(MKS_12864OLED) || ENABLED(MKS_12864OLED_SSD1306)
  #define LCD_PINS_DC      38 // Set as output on init
  #define LCD_PINS_RS      41 // Pull low for 1s to init
  // DOGM SPI LCD Support
  #define DOGLCD_CS        19
  #define DOGLCD_MOSI      42
  #define DOGLCD_SCK       18
  #define DOGLCD_A0        LCD_PINS_DC
#else
  #define LCD_PINS_RS      19
  #define LCD_PINS_ENABLE  42
  #define LCD_PINS_D4      18
  #define LCD_PINS_D5      38
  #define LCD_PINS_D6      41
#endif
