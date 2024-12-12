#pragma once
// #include <cstdint>
#include "Registers.h"

namespace hal{
    namespace display{
        /**
         * @name DisplayDevice
         * @note Is a interface that will represent our display device
         * @note Any sort of devices that you want to build display support for, will go here
         * @note Any sort of display driver that we want to develop will be derived from this class
         * 
         * @param configure_driver
         * @note  Used for configuring our driver through setting up our
        */
        class DisplayDevice{
        private:
            virtual void configure_driver() = 0;

            // virtual void read() = 0;

            virtual void DriverDrawPixel(uint8_t x, uint8_t y, uint32_t color) = 0;

            //! @note Writing to our specific register
            //! @note This is how the driver will interact to the display
            //! @note Sending commands for display to know what to do.
            //! @note In cases where you'd want to clear the screen, fill, etc.
            // virtual void write(uint8_t register_t) = 0;
        };

        //! @note 16 byte structure for handling rgb values
        struct color{
            uint8_t r, g, b;
        };

        //! @note As of right now I am going to use this to contain the device context
        //! @note This will contain our display context such as pin IO
        struct DisplayDeviceContext{
            uint8_t scl = 0;
            uint8_t sda = 0;
            uint8_t cs = 0;
            uint8_t rst = 0;
            uint8_t dc = 0;
        };
    }; // End of display namespace
};