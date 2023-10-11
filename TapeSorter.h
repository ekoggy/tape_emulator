#define _TAPE_SORTER_H_
#ifdef _TAPE_SORTER_H_

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
	TapeEmulator io_module;

/// METHODS
public:
	TapeSorter(TapeEmulator& emulator);
	~TapeSorter();
	void sort();
private:
	void merge();
	void distribute();
};
#endif // _TAPE_SORTER_H_