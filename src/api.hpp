#pragma once

#include <cstdint>
#include <vector>
#include <cstring>
using namespace std;

constexpr int memorySizeKB = 4 * 1024;
constexpr int RAMSizeKB = 512;
constexpr int ROMSizeKB = memorySizeKB - RAMSizeKB;
constexpr int RAMStart = 0 + ROMSizeKB*1024;