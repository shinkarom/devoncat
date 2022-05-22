#pragma once

#include "api.hpp"

class APUclass : public APUinterface {
    APUclass();
    ~APUclass();
    void processFrame();
};