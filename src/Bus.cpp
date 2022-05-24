#include "Bus.hpp"
#include <string>

CBus::CBus(){
	ROM.memory.resize(ROMSizeKB*1024);
	ROM.readOnly = true;
	ROM.fillWithZeroes();
	RAM.startAddress = RAMStart;
	RAM.memory.resize(RAMSizeKB*1024);
	RAM.fillWithRandomValues();
}

CBus::~CBus(){
	
}

uint8_t CBus::readByte(uint32_t address){
	address %= memorySizeKB * 1024;
	if(address < RAMStart)
		return ROM.readByte(address);
	else
		return RAM.readByte(address);
}

void CBus::writeByte(uint32_t address, uint8_t value){
	address %= memorySizeKB * 1024;
	if(address < RAMStart)
		ROM.writeByte(address, value);
	else
		RAM.writeByte(address, value);
}

bool CBus::loadROM(const void* data, size_t size) {
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
	memcpy(ROM.memory.data(), (uint8_t*)data + 16, size-16);
	return true;
}