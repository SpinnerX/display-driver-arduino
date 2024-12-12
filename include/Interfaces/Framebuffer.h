#pragma once
#include "DisplayInterface.h"
#include "pixel.h"
#include <cstdint>
#include <array>

namespace std{
    using size_t = long unsigned int;
};

template<std::size_t SIZE>
class Framebuffer{
    class DisplayInterface;
public:
    void* data() { return pixels.data(); }

private:
    //! @note Framebuffer of our pixels
    std::array<pixel_t, SIZE> pixels;
};