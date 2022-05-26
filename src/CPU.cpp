#include "CPU.hpp"
#include <iostream>
#include <cassert>

constexpr int opcodeMask = 0b1111111;
constexpr int RTypeMask = 0xFE00707F;

inttype registers[32];
inttype pc;

inttype CCPU::getRegister(int regNumber){
	assert(regNumber>0 && regNumber <32);
	return registers[regNumber];
}

void CCPU::setRegister(int regNumber, inttype value){
	assert(regNumber>0 && regNumber <32);
	if(regNumber != 0) {
		registers[regNumber] = value;
	}
}

CCPU::CCPU(CBus* b) : bus(b) {
	pc = 0;
}

CCPU::~CCPU() {
	
}

void CCPU::processFrame() {
	runNInstructions(clockRatePerFrame);
}

void CCPU::runNInstructions(int numInstructions) {
	for(int i = 0; i<numInstructions; i++) {
		runOneInstruction();
	}
}

void CCPU::runOneInstruction() {
	auto instruction = bus->read<uint32_t>(pc);
	pc += 4;
	if((instruction & opcodeMask) == 0x6F) //JAL
	{
		//cout<<"jal"<<endl;
		int rd = (instruction>>7)&0b11111;
		setRegister(rd, pc);
		//shuffle bits
		int imm101 = (instruction>>21)&0b1111111111;
		int imm1912 = (instruction >> 12) & 0b11111111;
		inttype imm = ((instruction>>12) & 0b10000000010000000000)|(imm1912<<11)|imm101;
		//sign-extend
		sinttype signExtendMask = 1 << 19;
		imm = (imm ^ signExtendMask) - signExtendMask;
		imm <<= 1;
		pc += imm;
	}
	else if ((instruction & RTypeMask) == 0x33) //ADD
	{
		//cout<<"add"<<endl;
	}
	else {
		cout<<"pc was "<<pc<<", instruction was "<<hex<<instruction<<endl;
		throw runtime_error("unknown instruction");
	}
}