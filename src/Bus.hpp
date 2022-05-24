#pragma once
#include "api.hpp"
#include "Memory.hpp"

class CBus {
	private:
		CMemory ROM;
		CMemory RAM;
	public:
		CBus();
		~CBus();
		bool loadROM(const void* data, size_t size);
		uint8_t readByte(uint32_t address);
		void writeByte(uint32_t address, uint8_t value);
		template<class T> T read(uint32_t address) {
			T result;
			uint8_t* t = (uint8_t*)&result;
			for(int i = 0;i<sizeof(T);i++){
				*t = readByte(address+i);
				t++;
			}
			return result;
		}
		
		template<class T> void write(uint32_t address, T value) {
			uint8_t* t = (uint8_t*)&value;
			for(int i = 0;i<sizeof(T);i++){
				writeByte(address+i, *t);
				t++;
			}
		}
};