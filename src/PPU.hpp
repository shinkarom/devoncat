#pragma once

#include <cstdint>
using namespace std;

#include "api.hpp"
#include "Bus.hpp"

constexpr int videoWidth = 256;
constexpr int videoHeight = 224;
constexpr int videoPixels = videoWidth * videoHeight;
constexpr int videoPitch = videoWidth * sizeof(uint32_t);

extern uint32_t frame_buf[videoPixels];

class CPPU {
	private:
		CBus* bus;
    public:
        CPPU(CBus* b);
        ~CPPU();
        void processFrame();
        const void* getFrameBuf();
};
