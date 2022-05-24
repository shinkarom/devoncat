#pragma once
#include "api.hpp"
#include "Bus.hpp"

class CCPU {
	private:
		CBus* bus;
	public:
		CCPU(CBus* b);
		~CCPU();
};