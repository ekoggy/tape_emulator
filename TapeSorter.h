#pragma once
#include "TapeEmulator.h"

#include <string>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>



class TapeSorter
{
/// FIELDS
public:
	TapeEmulator& emulator;

/// METHODS
public:
	TapeSorter(TapeEmulator& other);
	~TapeSorter();
	void sort();

	void merge();
	bool distribute();
};