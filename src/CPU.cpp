#include "CPU.hpp"
#include <iostream>
#include <cassert>

constexpr int RTypeMask = 0xFE00707F;
constexpr int ISBTypeMask = 0x707F;
constexpr int UJTypeMask = 0x7F;

inttype registers[32];
inttype pc;

int getRd(uint32_t instr) {
	return (instr>>7) & 0x1F;
}

int getRs1(uint32_t instr) {
	return (instr>>15) & 0x1F;
}

int getRs2(uint32_t instr) {
	return (instr>>20) & 0x1F;
}

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
	if((instruction & UJTypeMask) == 0x6F) //JAL
	{
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
	else if((instruction&UJTypeMask)==0x37){ //LUI
		int rd = getRd(instruction); 
		inttype imm = instruction & !UJTypeMask;
		setRegister(rd, imm);
	}
	else if((instruction&UJTypeMask)==0x17){ //AUIPC
		int rd = getRd(instruction); 
		inttype imm = instruction & !UJTypeMask;
		setRegister(rd, imm+pc-4);
	}
	else if ((instruction & RTypeMask) == 0x33) //ADD
	{
		int rd = getRd(instruction);
		int rs1 = getRs1(instruction);
		int rs2 = getRs2(instruction);
		setRegister(rd, getRegister(rs1)+getRegister(rs2));		
	}
	else {
		cout<<"pc was "<<pc<<", instruction was "<<hex<<instruction<<endl;
		throw runtime_error("unknown instruction");
	}
}