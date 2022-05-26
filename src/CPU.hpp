#pragma once
#include "api.hpp"
#include "Bus.hpp"

using inttype = uint32_t;
using sinttype = int32_t;

class CCPU {
	private:
		CBus* bus;
		inttype getRegister(int regNumber);
		void setRegister(int regNumber, inttype value);
	public:
		CCPU(CBus* b);
		~CCPU();
		void processFrame();
		void runNInstructions(int numInstructions);
		void runOneInstruction();
};