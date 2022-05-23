#include "api.hpp"

class CMemory : public IMemory {
	private:
		uint32_t memory[memorySizeKB * 1024];
	public:
		CMemory();
		~CMemory();
		void loadROM(const void* data, size_t size);
};