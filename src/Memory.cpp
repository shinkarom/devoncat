#include "Memory.hpp"

#include <iostream>
#include <cstring>
#include <fstream>

CMemory::CMemory() {
	memset(&memory, 0, memorySizeKB*1024);
}

CMemory::~CMemory() {
	
}

void CMemory::loadROM(const void* data, size_t size) {
	memcpy(memory, data, size);
}