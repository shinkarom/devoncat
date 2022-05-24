#include "Memory.hpp"

#include <iostream>
#include <cstring>
#include <fstream>

CMemory::CMemory() {
	memory.resize(memorySizeKB*1024);
	memset(memory.data(), 0, memorySizeKB*1024);
}

CMemory::~CMemory() {
	
}

bool CMemory::loadROM(const void* data, size_t size) {
	if(size>ROMSizeKB*1024)
		return false;
	if(size<16)
		return false;
	uint8_t header[16];
	memcpy(header, data, 16);
	string magic_num = "DEVONCAT";
	for(int i = 0; i< 8; i++)
	{
		if(header[i]!=magic_num[i])
			return false;
	}
	memcpy(memory.data(), (uint8_t*)data + 16, size-16);
	return true;
}