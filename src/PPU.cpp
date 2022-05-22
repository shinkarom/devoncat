#include "PPU.hpp"

#include <cstring>
using namespace std;

uint32_t frame_buf[videoPixels];

PPUclass::PPUclass() {
    
}

PPUclass::~PPUclass() {
    
}

void PPUclass::processFrame() {
    memset(frame_buf, 0, videoPixels * sizeof(uint32_t));
}

