#include "libhal-displays/drivers/ssd1331.h"
hal::display::SSD1331 display1;


/**
 * 
 * @name hal::Interfaces::Display
 * 
 * @param TopFramebuffers
 * @param AccessingFramebufferData
 * @note Getting our framebuffer from our driver
 * @note Each display will know about their own framebuffers that can be accessed through `auto framebuffer = display.GetFramebuffer();`
 * @note Or potentially be done by doing `auto framebuffer = Display<Display_t>::CurrentDisplayFramebuffer()`
 * @note Idea that I had behind this was allowing users to get access to read our current displays framebuffer
 * @note Reading pixels from our color buffer. Pixels of our current display
 * @note One thing to consider is that framebuffers often have multiple color images, where there are selectors in framebuffer objects defining which color buffers these operations are read from.
 * 
 * 
 * 
 * @param OnTheNoteOfFramebuffers
 * @note Either we access these framebuffers directly or we can give them an API to read from these framebuffers
 * @note An API I am currently thinking of are `auto pixel = display.Read({*position*})`
 * @note Here are some uses I can think of for display.Read(position);
 * @note #1) Telling users information about our pixels allowing for mouse-picking
 * @note #2) Typically framebuffers just store data about 
 * @note #3) Creating mirrors of our scene
 * @note #3.2) Creating mirrors or of our screen (if we want to support multiple displays)
 * 
 * @param DisplayFormatsToConsider
 * @note 1-bit (2 colors per pixel), 2-bit(4-colors), 4 (16-colors), 8 (256 colors)
 * @note Thinking of something as enum class { RED_INTEGER, RGB, RGBA, RGBA8 }
 * 
 * @note 
 * 
 * @note These formats are driver-details specified by the implementation of the driver itself.
 * 
 * @param DisplayAdapters
 * @note Use-case is enabling users to have adapters to connect to different other displays.
 * @note This could help potentially wanting to put our pixels to a wider screen (laptop, tv, etc.)
*/


void setup(){

  //! @note Since Arduino requires configurations to be set here
  //! @note I will be configuring the ssd1331 driver like this
  //! @note Am thinking this get configured through default construction
  display1.ConfigureDriver();
  // hal::display::DrawPixel(&display1, 0, 0, 0x001F);
  // hal::display::HalSerial::write("Hello");
  // hal::display::HalSerial::write("Hello");

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      hal::display::DrawPixel(&display1, j, i, 0x001D);
    }
    
    Serial.println(' ');
  }
}

void loop() {
}