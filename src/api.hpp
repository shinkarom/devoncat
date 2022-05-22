#pragma once

class PPUinterface {
    public:
       virtual void processFrame() = 0;
};

class APUinterface {
    public:
        virtual void processFrame() = 0;
};