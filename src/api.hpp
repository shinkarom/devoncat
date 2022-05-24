#pragma once

#include <cstdint>
#include <vector>
#include <cstring>
using namespace std;

constexpr int memorySizeKB = 4 * 1024;
constexpr int RAMSizeKB = 512;
constexpr int ROMSizeKB = memorySizeKB - RAMSizeKB;

class ICPU {

};

class IMemory {
	protected:
		vector<uint8_t> memory;
	public:
		virtual bool loadROM(const void* data, size_t size) = 0;
		template<class T> T read(uint32_t address) {
			T result;
			memcpy(&result, &memory[address], sizeof(T));
			return result;
		}
		template<class T> void write(T value, uint32_t address) {
			memcpy(&memory[address], &value, sizeof(T));
		}
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