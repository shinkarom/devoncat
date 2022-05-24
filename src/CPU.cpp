#include "CPU.hpp"

using inttype = uint32_t;

CCPU::CCPU(IMemory* m) : mem(m) {
	auto b = mem->read<uint32_t>(0);
}

CCPU::~CCPU() {
	
}
