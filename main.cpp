#include <TapeEmulator.h>
#include <TapeSorter.h>
#include <iostream>

int main(int argc, char *argv[]) {
	
	TapeEmulator emulator (argv[argc - 2], argv[argc - 1]);
	TapeSorter sorter(emulator);

	sorter.sort();
}