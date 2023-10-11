#include "TapeSorter.h"

TapeSorter::TapeSorter(TapeEmulator &emulator) {
	this->io_module = emulator;
}

TapeSorter::~TapeSorter() {

}

void TapeSorter::sort() {

}

void TapeSorter::merge() {
	int32_t f1;// = this->io_module.getValue(src1);
	int32_t f2_cur;// = this->io_module.getValue(src2);
	int32_t f2_next;// = this->io_module.getValue(src2);
	
	while (!tmp1.eof() && !tmp2.eof()) {

		if (f1 <= f2_cur) {
			this->io_module.writeValue(dst, f1);
			f1 = this->io_module.getValue(tmp1);
		}
		else {
			this->io_module.writeValue(dst, f2_cur);

			if (f2_cur > f2_next || tmp2.eof()) {
				this->io_module.writeValue(dst, f1);
				f1 = this->io_module.getValue(tmp1);
			}
				
			
		}
	}
}

void TapeSorter::distribute() {

}