// #include "displays.h"
#include "libhal-displays/drivers/ssd1331.h"
// DisplayDeviceInterface displaySSD1331;

hal::display::SSD1331 display1;

void setup() {

  //! @note These are Notes on the ideas for rn
  //! @note As it stands this is going to be what the Initialization's going to look
  //! @note Meaning it'll change, but for not im going to work with how this is going to work
  //! @note Temp idea until I can get a pixel, line, triangle rendering to screen.
  //! @note Once again, I will look into the way how we should handle
  //!       @note Which entails what are things users should be configuring, modifying, and making API calls
  //! @note  Another thing is I want their to also be a API call, where nothing changes on the user-side but the back-end will change
  //! @note Regarding optimizations there is no particular optimizations that I am looking into at the moment.
  //! @note Right now I want to see results, so API Design, End-user API call, and just getting basic shapes to work.
  //! @note Now this note is just for myself, but I think this would be cool to see ray tracing be displayed through this device (lol)


  //! @note As for the initialization we are just going to set the DisplayContext like this for rn
  // displaySSD1331.Initialize([](){
  //     DisplayContext context;
  //     context.scl = 13;
  //     context.sda = 11;
  //     context.cs = 10; // 
  //     context.rst = 9; // reset pin
  //     context.dc = 8; // 
  //     return context;
  // });

  // ! @note 0x001F is hex for color blue
  // displaySSD1331.FillScreen(0x001F);
  // displaySSD1331.FillScreen(0xA020F0);
  // displaySSD1331.FillScreen(0x001F);
  // displaySSD1331.FillScreen(0xFFFF00);
  
  // for(int i = 0; i < displaySSD1331.getWidth(); i++){
  //   for(int j = 0; j < displaySSD1331.getHeight(); j++){
  //     displaySSD1331.DrawPixel(j, i, 0xFFFF00);
  //   }
  // }

  //! @note 0x07E0 is hex for green
  // for(int i = 0; i < 10; i++){
  //   for(int j = 0; j < 10; j++){
  //     // displaySSD1331.DrawPixel(j, i, 0x07E0);
  //     displaySSD1331.DrawPixel(j, i, 0x001F);
  //   }
  // }
  // displaySSD1331.DrawPixel(0, 0, 0x07E0);
  // displaySSD1331.DrawPixel(0, 0, 0xFF0000);
  // displaySSD1331.DrawPixel(0, 0, 0xFFFF00);

  // for(int i = 0; i < displaySSD1331.getWidth(); i++){
  //   for(int j = 0; j < displaySSD1331.getHeight(); j++){
  //     displaySSD1331.DrawPixel(i, j, 0xA020F0);
  //   }
  // }
  // displaySSD1331.DrawPixel(10, 10, 0xA020F0);
}

void loop() {

}
