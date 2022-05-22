#pragma once

#include <cstdint>
using namespace std;

#include "api.hpp"

constexpr int videoWidth = 256;
constexpr int videoHeight = 224;
constexpr int videoPixels = videoWidth * videoHeight;
constexpr int videoPitch = videoWidth * sizeof(uint32_t);

extern uint32_t frame_buf[videoPixels];

class PPUclass : PPUinterface {
    public:
        PPUclass();
        ~PPUclass();
        void processFrame();
        const void* getFrameBuf();
};
