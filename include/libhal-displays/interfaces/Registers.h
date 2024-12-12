#pragma once
// #include <cstdint>
#include <Arduino.h>
#include <SPI.h>

namespace std{
    using size_t = long unsigned int;
};

typedef unsigned char uint8_t;

//! @note SSD1331 Display Commands
static const uint8_t DRAW_LINE                       = 0x21;
static const uint8_t DRAW_RECTANGLE                  = 0x22;
static const uint8_t COPY_WINDOW                     = 0x23;
static const uint8_t DIM_WINDOW                      = 0x24;
static const uint8_t CLEAR_WINDOW                    = 0x25;
static const uint8_t FILL_WINDOW                     = 0x26;
static const uint8_t DISABLE_FILL                    = 0x00;
static const uint8_t ENABLE_FILL                     = 0x01;
static const uint8_t CONTINUOUS_SCROLLING_SETUP      = 0x27;
static const uint8_t DEACTIVE_SCROLLING              = 0x2E;
static const uint8_t ACTIVE_SCROLLING                = 0x2F;
static const uint8_t SET_COLUMN_ADDRESS              = 0x15; //! @note Our col address
static const uint8_t SET_ROW_ADDRESS                 = 0x75; //! @note Our row address
static const uint8_t SET_CONTRAST_A                  = 0x81; //! @note Contrast A (must be set to 0x80)
static const uint8_t SET_CONTRAST_B                  = 0x82; //! @note Contrast B (must be set to 0x80)
static const uint8_t SET_CONTRAST_C                  = 0x83; //! @note Contrast C (must be set to 0x80)
static const uint8_t MASTER_CURRENT_CONTROL          = 0x87;
static const uint8_t SET_PRECHARGE_SPEED_A           = 0x8A;
static const uint8_t SET_PRECHARGE_SPEED_B           = 0x8B;
static const uint8_t SET_PRECHARGE_SPEED_C           = 0x8C;
static const uint8_t SET_REMAP                       = 0xA0;
static const uint8_t SET_DISPLAY_START_LINE          = 0xA1;
static const uint8_t SET_DISPLAY_OFFSET              = 0xA2;
static const uint8_t NORMAL_DISPLAY                  = 0xA4;
static const uint8_t ENTIRE_DISPLAY_ON               = 0xA5;
static const uint8_t ENTIRE_DISPLAY_OFF              = 0xA6;
static const uint8_t INVERSE_DISPLAY                 = 0xA7;
static const uint8_t SET_MULTIPLEX_RATIO             = 0xA8;
static const uint8_t DIM_MODE_SETTING                = 0xAB;
static const uint8_t SET_MASTER_CONFIGURE            = 0xAD;
static const uint8_t DIM_MODE_DISPLAY_ON             = 0xAC;
static const uint8_t DISPLAY_OFF                     = 0xAE;
static const uint8_t NORMAL_BRIGHTNESS_DISPLAY_ON    = 0xAF;
static const uint8_t POWER_SAVE_MODE                 = 0xB0;
static const uint8_t PHASE_PERIOD_ADJUSTMENT         = 0xB1;
static const uint8_t DISPLAY_CLOCK_DIV               = 0xB3;
static const uint8_t SET_GRAY_SCALE_TABLE            = 0xB8;
static const uint8_t ENABLE_LINEAR_GRAY_SCALE_TABLE  = 0xB9;
static const uint8_t SET_PRECHARGE_VOLTAGE           = 0xBB;
static const uint8_t SET_V_VOLTAGE                   = 0xBE;