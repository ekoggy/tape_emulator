#include "TapeEmulator.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>


TapeEmulator::TapeEmulator(std::string input, std::string output) {
	//read config
	this->readConfig();

	this->input = input;
	this->output = output;
}
TapeEmulator::~TapeEmulator() {

}

void TapeEmulator::readConfig() {
	std::ifstream config("//etc/tape_emulator.conf");
	uint32_t i = 0;
	while (!config.eof()) {
		std::string line;
		std::getline(config, line);
		int space = line.find(' ');
		this->delays[i] = std::atoi(line.substr(space).c_str());
		i++;
	}
	config.close();
}

int32_t TapeEmulator::getValue(std::fstream& src) {
	std::this_thread::sleep_for(std::chrono::milliseconds(this->delays[READ]));
	std::string line;
	src >> line;
	int32_t value = std::atoi(line.c_str());
	this->shiftTape(src);
	return value;
}

void TapeEmulator::writeValue(std::fstream& dst, const int32_t value) {
	std::this_thread::sleep_for(std::chrono::milliseconds(this->delays[WRITE]));
	std::string line = std::to_string(value);
	dst << line << std::endl;
	this->shiftTape(dst);
}

void TapeEmulator::shiftTape(std::fstream& file) {
	std::this_thread::sleep_for(std::chrono::milliseconds(this->delays[SHIFT]));
}

void TapeEmulator::rewindTape(std::fstream& file) {
	std::this_thread::sleep_for(std::chrono::milliseconds(this->delays[REWIND]));
}
