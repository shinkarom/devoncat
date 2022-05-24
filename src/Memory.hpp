#include "api.hpp"
#include <vector>
#include <cstring>

class CMemory : public IMemory {
	public:
		CMemory();
		~CMemory();
		bool loadROM(const void* data, size_t size);
};