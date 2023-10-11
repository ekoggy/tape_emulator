#include "TapeEmulator.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>


TapeEmulator::TapeEmulator(std::string primary, std::string output) {
	//read config
	this->readConfig();

	//open files
	this->primary.open(primary, std::ios::in | std::ios::out | std::ios::app);
	this->tmp1.open("/tmp/tmp_tape_1", std::ios::in | std::ios::out | std::ios::app);
	this->tmp2.open("/tmp/tmp_tape_2", std::ios::in | std::ios::out | std::ios::app);
	this->output.open(output, std::ios::out);

}
TapeEmulator::~TapeEmulator() {
	this->primary.close();
	this->tmp1.close();
	this->tmp2.close();
	this->output.close();
}

void TapeEmulator::readConfig() {
	std::ifstream config("/etc/tape_emulator.conf");
	uint32_t i = 0;
	while (!config.eof()) {
		std::string line;
		std::getline(config, line);
		int space = line.find(' ');
		this->delays[i] = std::atoi(line.substr(space).c_str());
	}
	config.close();
}

int32_t TapeEmulator::getValue(std::fstream src) {
	std::this_thread::sleep_for(std::chrono::milliseconds(this->delays[READ]));
	std::string line;
	src >> line;
	int32_t value = std::atoi(line.c_str());
	return value;
}

void TapeEmulator::writeValue(std::fstream dst, const int32_t value) {
	std::this_thread::sleep_for(std::chrono::milliseconds(this->delays[WRITE]));
	std::string line = std::to_string(value);
	dst << line << std::endl;
}

void TapeEmulator::shiftTape(std::fstream file) {
	std::this_thread::sleep_for(std::chrono::milliseconds(this->delays[SHIFT]));
	file.seekg((int)file.tellg()+1);
}

void TapeEmulator::rewindTape(std::fstream file) {
	std::this_thread::sleep_for(std::chrono::milliseconds(this->delays[REWIND]));
	file.seekg(0);
}

void TapeEmulator::operator= (TapeEmulator& other) {
	
	this->primary.swap(other.primary);
	this->tmp1.swap(other.tmp1);
	this->tmp2.swap(other.tmp2);
	this->output.swap(other.output);

	this->delays[READ] = other.delays[READ];
	this->delays[WRITE] = other.delays[WRITE];
	this->delays[SHIFT] = other.delays[SHIFT];
	this->delays[REWIND] = other.delays[REWIND];
}