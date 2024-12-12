#pragma once
#include <cstdint>

struct Color{
    uint8_t r, g, b;
};

struct pixel_t{
    Color color;
    uint8_t x, y;
};