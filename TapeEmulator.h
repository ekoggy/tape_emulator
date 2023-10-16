#pragma once
#include <iostream>
#include <fstream>

#define READ 0
#define WRITE 1
#define SHIFT 2
#define REWIND 3

class TapeEmulator
{
// FIELDS
public:
	// file pointers
	std::string input, output;

	// delays
private:
	uint32_t delays[4];


/// METHODS
public:
	TapeEmulator(std::string primal, std::string output);
	~TapeEmulator();
	
	void readConfig();

	int32_t getValue(std::fstream &src);
	void writeValue(std::fstream &dst, const int32_t value);
	void shiftTape(std::fstream &file);
	void rewindTape(std::fstream &file);
};