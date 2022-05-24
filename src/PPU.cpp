#include "PPU.hpp"

#include <cstring>
using namespace std;

uint32_t frame_buf[videoPixels];

CPPU::CPPU(CBus* b) : bus(b) {
    
}

CPPU::~CPPU() {
    
}

void CPPU::processFrame() {
    memset(frame_buf, 0, videoPixels * sizeof(uint32_t));
}

