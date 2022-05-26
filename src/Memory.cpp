#include "Memory.hpp"

#include <iostream>
#include <algorithm>
#include <random>

CMemory::CMemory() {
	
}

CMemory::~CMemory() {
	
}

uint8_t CMemory::readByte(uint32_t address){
	return memory[address];
}

void CMemory::writeByte(uint32_t address, uint8_t value){
	if(!readOnly)
		memory[address] = value;
}

void CMemory::fillWithZeroes(){
	fill(memory.begin(), memory.end(), 0);
}

void CMemory::fillWithRandomValues(){
	random_device r;
	default_random_engine engine(r());
	uniform_int_distribution<uint8_t> distribution(0, 255);
	for(int i = 0; i < memory.size(); i++){
		memory[i] = distribution(engine);
	}
}