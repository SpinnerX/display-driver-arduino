#pragma once
#include "Framebuffer.h"
#include "pixel.h"

class DisplayInterface{
    static void DrawPixel(DisplayInterface* display, uint32_t x, uint32_t y, pixel_t color){}
    // static void DrawPixel(Framebuffer* buffer, int x, int y, Color color){}
public:
    virtual void DriverDrawPixel(DisplayInterface* display, uint32_t x, uint32_t y, Color color) = 0;
};

class SSD1331 : public DisplayInterface{
public:
    SSD1331(uint8_t cs){}

private:
    void DriverDrawPixel(DisplayInterface* display, uint32_t x, uint32_t y, Color color) override {

    }
};