#pragma once

#include "api.hpp"
#include "Bus.hpp"

extern int16_t audio_buffer[30000];

class CAPU {
	private:
		CBus* bus;
	public:
		CAPU(CBus* b);
		~CAPU();
		void processFrame();
};