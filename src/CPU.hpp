#include "api.hpp"

class CCPU : public ICPU {
	private:
		IMemory* mem;
	public:
		CCPU(IMemory* m);
		~CCPU();
};