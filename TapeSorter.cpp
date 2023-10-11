#include "TapeSorter.h"

TapeSorter::TapeSorter(TapeEmulator &emulator) {
	this->io_module = emulator;
}

TapeSorter::~TapeSorter() {

}

void TapeSorter::sort() {

}

void TapeSorter::merge(std::fstream src1, std::fstream src2, std::fstream dst) {
	int32_t f1 = this->io_module.getValue(src1);
	int32_t f2_cur = this->io_module.getValue(src2);
	int32_t f2_next = this->io_module.getValue(src2);
}

void TapeSorter::distribute() {

}