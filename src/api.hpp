#pragma once

#include <cstdint>
using namespace std;

constexpr int memorySizeKB = 4 * 1024;
constexpr int RAMSizeKB = 512;
constexpr int ROMSizeKB = memorySizeKB - RAMSizeKB;

class ICPU {

};

class IMemory {
	public:
		virtual void loadROM(const void* data, size_t size) = 0;
};

class IBus {
	
};

class IPPU {
    public:
       virtual void processFrame() = 0;
};

class IAPU {
    public:
        virtual void processFrame() = 0;
};