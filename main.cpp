#include "TapeEmulator.h"
#include "TapeSorter.h"

#include <iostream>

int main(int argc, char *argv[]) {
	
	std::string input_file(argv[1]), output_file(argv[2]);

	std::cout << argc <<' '<< input_file <<' '<< output_file << std::endl;

	TapeEmulator emulator (input_file, output_file);
	TapeSorter sorter(emulator);

	sorter.sort();
}