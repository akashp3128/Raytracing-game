#include "framebuffer.h"
#include <cassert>

FrameBuffer::FrameBuffer(const size_t width, const size_t height)
    : w(width), h(height), img(width * height) {}

void FrameBuffer::set_pixel(const size_t x, const size_t y, const uint32_t color) {
    assert(img.size() == w * h && x < w && y < h);
    img[x + y * w] = color;
}

void FrameBuffer::draw_rectangle(const size_t rect_x, const size_t rect_y, const size_t rect_w, const size_t rect_h, const uint32_t color) {
    assert(img.size() == w * h);
    for (size_t i = 0; i < rect_w; i++) {
        for (size_t j = 0; j < rect_h; j++) {
            size_t cx = rect_x + i;
            size_t cy = rect_y + j;
            if (cx < w && cy < h) // no need to check for negative values (unsigned variables)
                set_pixel(cx, cy, color);
        }
    }
}

void FrameBuffer::clear(const uint32_t color) {
    img = std::vector<uint32_t>(w * h, color);
}