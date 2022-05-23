#pragma once

#include <cstdint>
using namespace std;

#include "api.hpp"
#include "libretro.h"

extern int16_t audio_buffer[30000];

class CAPU : public IAPU {
	public:
		CAPU();
		~CAPU();
		void processFrame();
};