#include "PPU.hpp"

#include <cstring>
using namespace std;

PPUclass::PPUclass() {
    frame_buf = new uint8_t[videoPixels*sizeof(uint32_t)]; 
}

PPUclass::~PPUclass() {
    delete[] frame_buf;
}

void PPUclass::processFrame() {
    memset(frame_buf, 0, videoPixels * sizeof(uint32_t));
}

