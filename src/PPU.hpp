#pragma once

#include <cstdint>
using namespace std;

#include "api.hpp"

constexpr int videoWidth = 256;
constexpr int videoHeight = 224;
constexpr int videoPixels = videoWidth * videoHeight;
constexpr int videoPitch = videoWidth * sizeof(uint32_t);

static uint8_t *frame_buf;

class PPUclass : PPUinterface {
    public:
        PPUclass();
        ~PPUclass();
        void processFrame();
        const void* getFrameBuf();
};
