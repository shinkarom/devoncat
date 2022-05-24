#include "APU.hpp"

#include <cstdint>
#include <cmath>
#include <cstdio>
using namespace std;

static unsigned phase;
int16_t audio_buffer[30000];

CAPU::CAPU(CBus* b): bus(b) {
   phase = 0;
}

CAPU::~CAPU(){
    
}

void CAPU::processFrame(){
	for (unsigned i = 0; i < 30000 / 60; i++, phase++)
   {
      int16_t val = 0x800 * sinf(2.0f * M_PI * phase * 300.0f / 30000.0f);
	  audio_buffer[i*2] = val;
	  audio_buffer[i*2+1] = val;
   }
   phase %= 100;
}