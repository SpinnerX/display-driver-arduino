#pragma once
//! @note Link to the original source that helped give me some ideas on how to get started, https://www.b4x.com/android/forum/threads/ssd1331-library-for-spi-16bit-color-oled.81810/
#include <Arduino.h>
#include <SPI.h>
#include <functional>

namespace std{
    using size_t = long unsigned int;
};

/**
 * These are Notes that I just realized, just clicked
 * 
 * @context Display Protocols
 * @note Communication Protocols that these displays may use.
 * 
 * @context Establish communications
 * @note Comminicating depending on display using I2C, SPI, or even UART.
 * 
 * @context Display Registers
 * @note Now these vary from display devices
 * @note Identify the display registers (which are provided in data sheet)
 * @note These registers control different aspects of the displays
 *      @note Such as display mode, column and row addresses, and pixel data
 * 
 * @context Display Initialization
 * @note Initializing the display
 * @note Which involves sending a sequence of commands. (These sequences of commands involve setting up display for operations)
 *      @note Operations such as display resolution, color depth, and various configurations
 * 
 * @context Implementation Details
 * @note Now for drawing a single pixel to display. (Once initialization is done)
 * @note First it involves setting up column and row addresses before sending pixel data to the appropriate register.
 * @note pixel function should involve DrawPixel(uint8_t x, uint8_t x, uint16_t color);
 *      @note Using a 16 byte color for better readability and easier to modify colors. (Though will have a standard Colors list with it, for this example)
 * 
 * 
*/
//! @note These correspond to the different pin I/O on the Uno board.

/**
 * @context Implementations and API Design
 * 
 * //! @note Whole point of this is to minimize user configurations
 * DisplayDevice::Initialize([](){
 *      DisplayContext context;
 *      context.registers = {.sclk=13, .mosi=11, .cs=10, .rst=9, .dc=8};
 *      return context;
 * });
 * 
 * //! @note This is assuming that the user would  like to initialize the Display with the default parameters (which is dependent on the Display device initialized with)
 * Display<SSD1331>::Initialize();
 * 
 * //! @note Then if users would like to get the context of our current display, probably am considering (Not thinking about the details atm, but just spit balling on the kinds of details I may want to consider)
 * auto& ctx = Display::getContext();
 * 
*/

//! @note These are the column and row addresses commands
//! @param Col Address ----
//! @note Command specifis column starting and ending address for display data RAM.
//! @note This command sets cols address ptr to col starting address.
//! @note Pointer is used for defining reading/write col addr in graphic display data RAM.
//! @note Horizontal address increment mode is enabled by command A0h (which is 0xA0), after finishing reading/writing one column data.
//!       @note It's incremented automatically to next col address
//!       @note Whenever col addr ptr finishes accessing end col address, resets back to col start address

//! @param Row Address ----
//! @note specified row starting and ending address for displaying data RAM.
//! @note pointer used for defining read/write row address in display RAM.
//! @note Vertical increment mode enabled by command A0h (means, 0xA0) after finishing read/write one row data.
//!       @note Incremented automatically to next row address.
//!       @note When row addr ptr finishes accessing col address, resets back to row starting address
//! @note Reference to SSD1331 Datasheet below section 9.1.2. that shows the diagram of the data flow.

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

//! @note These correspond to the different pin I/O on the Uno board.
struct DisplayContext{
    uint8_t scl; // 
    //! @note 
    uint8_t sda; // sck previously
    //! @note Pin is chip select input connecting to MCU
    uint8_t cs;
    //! @note Our reset pin.
    //! @note When pin is low, initialization of chip is executed.
    //! @note Keeping pin as high (i.e connect to V_DDIO) during normal operations
    uint8_t rst;
    //! @note Data/Command control pin connection to the MCU
    //! @note When pin is pulled high (i.e connect to V_DDIO), data at D[15:0] will be interpreted as data
    uint8_t dc;
};

//! @note Writing a sequence of commands to display colors to the display
//! @note digitalWrite - specify pin is set ON
//! @note pinMode - sets pin OUTPUT
//! @note LOW=on, HIGH=off

class DisplayDeviceInterface2{
public:
    DisplayDeviceInterface2(){
        Initialize();
    }

    void Initialize(){
        // displayCtx = function();
        displayCtx.scl = 13;
        displayCtx.sda = 11;
        displayCtx.cs = 10; // 
        displayCtx.rst = 9; // reset pin
        displayCtx.dc = 8; // 

        pinMode(displayCtx.dc, OUTPUT);
        // pinMode(displayCtx.cs, OUTPUT);
        pinMode(displayCtx.sda, OUTPUT);

        SPI.begin();
        SPI.setDataMode(SPI_MODE3);
        pinMode(displayCtx.cs, OUTPUT);
        digitalWrite(displayCtx.cs, LOW);

        if(displayCtx.rst){
            pinMode(displayCtx.rst, OUTPUT);
            digitalWrite(displayCtx.rst, HIGH);
            delay(50);
            digitalWrite(displayCtx.rst, LOW);
            delay(50);
            digitalWrite(displayCtx.rst, HIGH);
            delay(50);
        }

        write_command(DISPLAY_OFF);          //Display Off
        write_command(CLEAR_WINDOW);         //set all RAM to zero

        resetCircuit();


        write_command(MASTER_CURRENT_CONTROL);//master current control
        write_command(12);                     //8
        write_command(SET_PRECHARGE_SPEED_A);//Set Second Pre-change Speed For ColorA
        write_command(0x64);                     //100
        write_command(SET_PRECHARGE_SPEED_B);//Set Second Pre-change Speed For ColorB
        write_command(0x78);                     //120
        write_command(SET_PRECHARGE_SPEED_C);//Set Second Pre-change Speed For ColorC
        write_command(0x64);                     //100
        write_command(SET_REMAP);            //set remap & data format
        write_command(B01110010);                //originale 0x72 (0111 0010)
        write_command(SET_DISPLAY_START_LINE);//Set display Start Line
        write_command(0x0);
        write_command(SET_DISPLAY_OFFSET);   //Set display offset
        write_command(0x0);
        write_command(NORMAL_DISPLAY);       //Set display mode
        write_command(SET_MULTIPLEX_RATIO);  //Set multiplex ratio
        write_command(0x3F);
        write_command(SET_MASTER_CONFIGURE); //Set master configuration
        write_command(0x8E);
        write_command(POWER_SAVE_MODE);      //Set Power Save Mode
        write_command(0x00);                     //0x00
        write_command(PHASE_PERIOD_ADJUSTMENT);//phase 1 and 2 period adjustment
        write_command(0x31);                     //0x31
        write_command(DISPLAY_CLOCK_DIV);    //display clock divider/oscillator frequency
        write_command(0xF0);
        write_command(SET_PRECHARGE_VOLTAGE);//Set Pre-Change Level
        write_command(0x3A);
        write_command(SET_V_VOLTAGE);        //Set vcomH
        write_command(0x3E);
        write_command(DEACTIVE_SCROLLING);   //disable scrolling
        write_command(NORMAL_BRIGHTNESS_DISPLAY_ON);//set display on
        
        write_command(FILL_WINDOW);
        write_command(0x01);
    }


    uint8_t getWidth() const { return OLED_WIDTH; }

    uint8_t getHeight() const { return OLED_HEIGHT; }

    void DrawPixel(uint8_t x, uint8_t y, uint16_t color){
        // Setting the window to be clear
        write_command(CLEAR_WINDOW);

        SetPosition(x, y);

        write_data(color >> 8);
        write_data(color);

        _currentX = x;
        _currentY = y;
    }

    void FillScreen(uint16_t color){
        fillScreen(color);
    }

private:

    void SetPosition(uint8_t x, uint8_t y){

        if((x < 0) || (x > OLED_WIDTH) || (y < 0 || y > OLED_HEIGHT)) return;

        write_command(SET_COLUMN_ADDRESS);
        write_command(x);
        write_command(OLED_WIDTH-1);
        write_command(y);
        write_command(OLED_HEIGHT-1);
    }


    void write_command(uint8_t command){
        uint8_t dc = displayCtx.dc;
        uint8_t cs = displayCtx.cs;

        digitalWrite(dc, LOW);
        digitalWrite(cs, LOW);
        SPI.transfer(command);
        digitalWrite(cs, HIGH);
    }


    void write_data(uint8_t data){
        digitalWrite(displayCtx.dc, HIGH);
        digitalWrite(displayCtx.cs, LOW);
        SPI.transfer(data);
        digitalWrite(displayCtx.cs, HIGH);
    }

    void fillScreen(uint16_t color){
        write_command(FILL_WINDOW);
        write_data(color >> 8);
        write_data(color);
    }


    void resetCircuit(){
        write_command(SET_CONTRAST_A);       //Set contrast for color A
        write_command(0x80);
        write_command(SET_CONTRAST_B);       //Set contrast for color B
        write_command(0x80);
        write_command(SET_CONTRAST_C);       //Set contrast for color C
        write_command(0x80);
    }

private:
    DisplayContext displayCtx;
    uint8_t _currentX = 0;
    uint8_t _currentY = 0;
    //! @note Should not change this, these are the constant dimensions of this specific device.
    static const uint8_t OLED_WIDTH  = 96;
    static const uint8_t OLED_HEIGHT = 64;
};