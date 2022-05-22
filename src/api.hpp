#pragma once


class CPUinterface {
	public:
		virtual void loadROM(char* fileName) = 0;
};

class PPUinterface {
    public:
       virtual void processFrame() = 0;
};

class APUinterface {
    public:
        virtual void processFrame() = 0;
};