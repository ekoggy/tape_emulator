#include "TapeSorter.h"

TapeSorter::TapeSorter(TapeEmulator& other) :emulator(other) {

}

TapeSorter::~TapeSorter() {

}

void TapeSorter::sort() {
	
	std::fstream input(this->emulator.input, std::ios::in);
	std::fstream tmp3("/tmp/tmp_tape_3", std::ios::out | std::ios::trunc);
	while (!input.eof()) {
		int32_t a = this->emulator.getValue(input);
		this->emulator.writeValue(tmp3, a);
	}
	this->emulator.rewindTape(tmp3);
	input.close();
	tmp3.close();


	while (this->distribute()) {
		this->merge();
	}


	tmp3.open("/tmp/tmp_tape_3", std::ios::in);
	this->emulator.rewindTape(tmp3);
	std::fstream output(this->emulator.output, std::ios::out | std::ios::trunc);

	while (1) {
		int32_t a = this->emulator.getValue(tmp3);
		if (!tmp3.eof())
			this->emulator.writeValue(output, a);
		else
			break;
	}
}

void TapeSorter::merge() {
	std::fstream tmp[3];
	tmp[0].open("/tmp/tmp_tape_1", std::ios::in);
	tmp[1].open("/tmp/tmp_tape_2", std::ios::in);
	tmp[2].open("/tmp/tmp_tape_3", std::ios::out | std::ios::trunc);

	int32_t a1 = this->emulator.getValue(tmp[0]);
	int32_t a2 = this->emulator.getValue(tmp[1]);


	
	while (!(tmp[0].eof() && tmp[1].eof())) {

		if (a1 <= a2) {
			if (!tmp[0].eof()) {
				this->emulator.writeValue(tmp[2], a1);
				a1 = this->emulator.getValue(tmp[0]);
				
			}
			else
				a1 = INT32_MAX;
		}
		else {
			if (!tmp[1].eof()) {
				this->emulator.writeValue(tmp[2], a2);
				a2 = this->emulator.getValue(tmp[1]);
				
			}
			else
				a2 = INT32_MAX;
		}
	}

	this->emulator.rewindTape(tmp[2]);
	this->emulator.rewindTape(tmp[0]);
	this->emulator.rewindTape(tmp[1]);

	tmp[0].close();
	tmp[1].close();
	tmp[2].close();
}

bool TapeSorter::distribute() {
	std::fstream tmp[3];
	tmp[0].open("/tmp/tmp_tape_1", std::ios::out | std::ios::trunc);
	tmp[1].open("/tmp/tmp_tape_2", std::ios::out | std::ios::trunc);
	tmp[2].open("/tmp/tmp_tape_3", std::ios::in);

	int32_t a = this->emulator.getValue(tmp[2]);
	int32_t a_next = a;
	int8_t index = 0;
	bool status = false;

	while (1) {
		a = a_next;
		a_next = this->emulator.getValue(tmp[2]);

		if (tmp[2].eof()) {
			this->emulator.writeValue(tmp[index], a);
			break;
		}

		if (a <= a_next) {
			this->emulator.writeValue(tmp[index], a);
		}
		else {
			status = true;
			this->emulator.writeValue(tmp[index], a);
			index ? index = 0 : index = 1;
		}
	}

	

	this->emulator.rewindTape(tmp[2]);
	this->emulator.rewindTape(tmp[0]);
	this->emulator.rewindTape(tmp[1]);

	tmp[0].close();
	tmp[1].close();
	tmp[2].close();
	return status;

}