#pragma once
#include "libhal-displays/interfaces/DisplayDevice.h"
#include "libhal-displays/interfaces/InitializerList.h"


namespace hal::display{
    //! @note Just some SPI SerialCommunication Communication Read/Writing to SSD1331 display for prototyping
    namespace SerialCommunication{

        void write_data(const DisplayDeviceContext& ctx, uint8_t data){
            digitalWrite(ctx.dc, HIGH);
            digitalWrite(ctx.cs, LOW);
            SPI.transfer(data);
            digitalWrite(ctx.cs, HIGH);
        }

        void write_command(const DisplayDeviceContext& ctx, uint8_t command){
            uint8_t dc = ctx.dc;
            uint8_t cs = ctx.cs;

            digitalWrite(dc, LOW);
            digitalWrite(cs, LOW);
            SPI.transfer(command);
            digitalWrite(cs, HIGH);
        }
    };

    /**
     * @name SSD1331
     * @note Driver for the SSD1331 display device
     * @param ConfigureDriver
     * @note Initiating this driver for configuring the SSD1331 display, preparing for read/write operations 
    */
    class SSD1331 : public DisplayDevice {
    public:

        void ConfigureDriver(){
            // HalSerial::InitializeSerial();
            Serial.begin(115200);

            configure_driver();
        }

        void DrawPixel(uint8_t x, uint8_t y, uint32_t pixel){
            DriverDrawPixel(x, y, pixel);
        }

        uint32_t GetScreenWidth() const { return SSD1331_WIDTH; }

        uint32_t GetScreenHeight() const { return SSD1331_HEIGHT; }

    private:
        void configure_driver() override{
            ctx.scl = 13;
            ctx.sda = 11;
            ctx.cs = 10; // 
            ctx.rst = 9; // reset pin
            ctx.dc = 8;

            pinMode(ctx.dc, OUTPUT);
            pinMode(ctx.sda, OUTPUT);

            SPI.begin();
            SPI.setDataMode(SPI_MODE3);
            pinMode(ctx.cs, OUTPUT);
            digitalWrite(ctx.cs, LOW);

            if(ctx.rst){
                pinMode(ctx.rst, OUTPUT);
                digitalWrite(ctx.rst, HIGH);
                delay(50);
                digitalWrite(ctx.rst, LOW);
                delay(50);
                digitalWrite(ctx.rst, HIGH);
                delay(50);
            }

            SerialCommunication::write_command(ctx, DISPLAY_OFF);          //Display Off
            SerialCommunication::write_command(ctx, CLEAR_WINDOW);         //set all RAM to zero

            reset(); //! @note Reset Circuit


            SerialCommunication::write_command(ctx, MASTER_CURRENT_CONTROL); // master current control
            SerialCommunication::write_command(ctx, 12);                     // 8
            SerialCommunication::write_command(ctx, SET_PRECHARGE_SPEED_A);// Set Second Pre-change Speed For ColorA
            SerialCommunication::write_command(ctx, 0x64);                     //100
            SerialCommunication::write_command(ctx, SET_PRECHARGE_SPEED_B);// Set Second Pre-change Speed For ColorB
            SerialCommunication::write_command(ctx, 0x78);                     // 120
            SerialCommunication::write_command(ctx, SET_PRECHARGE_SPEED_C);// Set Second Pre-change Speed For ColorC
            SerialCommunication::write_command(ctx, 0x64);                     // 100
            SerialCommunication::write_command(ctx, SET_REMAP);            // set remap & data format
            SerialCommunication::write_command(ctx, B01110010);                //originale 0x72 (0111 0010)
            SerialCommunication::write_command(ctx, SET_DISPLAY_START_LINE);//Set display Start Line
            SerialCommunication::write_command(ctx, 0x0);
            SerialCommunication::write_command(ctx, SET_DISPLAY_OFFSET);   //Set display offset
            SerialCommunication::write_command(ctx, 0x0);
            SerialCommunication::write_command(ctx, NORMAL_DISPLAY);       //Set display mode
            SerialCommunication::write_command(ctx, SET_MULTIPLEX_RATIO);  //Set multiplex ratio
            SerialCommunication::write_command(ctx, 0x3F);
            SerialCommunication::write_command(ctx, SET_MASTER_CONFIGURE); //Set master configuration
            SerialCommunication::write_command(ctx, 0x8E);
            SerialCommunication::write_command(ctx, POWER_SAVE_MODE);      //Set Power Save Mode
            SerialCommunication::write_command(ctx, 0x00);                     //0x00
            SerialCommunication::write_command(ctx, PHASE_PERIOD_ADJUSTMENT);//phase 1 and 2 period adjustment
            SerialCommunication::write_command(ctx, 0x31);                     //0x31
            SerialCommunication::write_command(ctx, DISPLAY_CLOCK_DIV);    //display clock divider/oscillator frequency
            SerialCommunication::write_command(ctx, 0xF0);
            SerialCommunication::write_command(ctx, SET_PRECHARGE_VOLTAGE);//Set Pre-Change Level
            SerialCommunication::write_command(ctx, 0x3A);
            SerialCommunication::write_command(ctx, SET_V_VOLTAGE);        //Set vcomH
            SerialCommunication::write_command(ctx, 0x3E);
            SerialCommunication::write_command(ctx, DEACTIVE_SCROLLING);   //disable scrolling
            SerialCommunication::write_command(ctx, NORMAL_BRIGHTNESS_DISPLAY_ON);//set display on
            
            SerialCommunication::write_command(ctx, FILL_WINDOW);
            SerialCommunication::write_command(ctx, 0x01);

        }

        void DriverDrawPixel(uint8_t x, uint8_t y, uint32_t color) override {
            SerialCommunication::write_command(ctx, CLEAR_WINDOW);

            SetPosition(x, y);

            SerialCommunication::write_data(ctx, color >> 8);
            SerialCommunication::write_data(ctx, color);

            currentX = x;
            currentY = y;
        }

        void SetPosition(uint8_t x, uint8_t y){
            if((x < 0) || (x > SSD1331_WIDTH) || (y < 0) || (y > SSD1331_HEIGHT)) return;

            SerialCommunication::write_command(ctx, SET_COLUMN_ADDRESS);
            SerialCommunication::write_command(ctx, x);
            SerialCommunication::write_command(ctx, SSD1331_WIDTH-1);
            SerialCommunication::write_command(ctx, y);
            SerialCommunication::write_command(ctx, SSD1331_HEIGHT-1);
        }

        //! @note In the case that the device may need to reset
        //! @note This function will provide that to the driver.
        void reset(){
            SerialCommunication::write_command(ctx, SET_CONTRAST_A); // Set contrast for color A
            SerialCommunication::write_command(ctx, 0x80);
            SerialCommunication::write_command(ctx, SET_CONTRAST_B); // Set contrast for color B
            SerialCommunication::write_command(ctx, 0x80);
            SerialCommunication::write_command(ctx, SET_CONTRAST_C); // Set contrast for color C
            SerialCommunication::write_command(ctx, 0x80);
        }


    private:
        DisplayDeviceContext ctx{};
        uint8_t currentX = 0, currentY = 0;
        //! @note Should not be modified
        static const uint32_t SSD1331_WIDTH = 96;
        static const uint8_t SSD1331_HEIGHT = 64;
    };
    template<typename T>
    void DrawPixel(T* device, uint8_t x, uint8_t y, uint16_t color){
        device->DrawPixel(x, y, color);
    }
};