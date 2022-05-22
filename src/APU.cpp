#include "APU.hpp"

#include <cstdint>
using namespace std;

static int16_t* audio_buffer;

APUclass::APUclass(){
    audio_buffer = new int16_t[2 * 30000 / 60];
}

APUclass::~APUclass(){
    delete[] audio_buffer;
}

void APUclass::processFrame(){

}