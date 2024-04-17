#include "displays.h"

DisplayDeviceInterface displaySSD1331;

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


  displaySSD1331.Initialize([](){
      DisplayContext context;
      context.scl = 13;
      context.sck = 11;
      context.cs = 10;
      context.rst = 9;
      context.dc = 8;
      return context;
  });

  //! @note 0x07E0 is hex for green
  displaySSD1331.DrawPixel(0, 0, 0x07E0);
}

void loop() {

}
