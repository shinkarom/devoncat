#pragma once
#include "api.hpp"
#include <vector>

class CMemory {
	public:
		CMemory();
		~CMemory();
		vector<uint8_t> memory;
		uint32_t startAddress = 0;
		bool readOnly = false;
		uint8_t readByte(uint32_t address);
		void writeByte(uint32_t address, uint8_t value);
		void fillWithZeroes();
		void fillWithRandomValues();
};