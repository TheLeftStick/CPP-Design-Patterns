#include <iostream>
#include <string>
#include "classes.h"

int main() {
	TS* ts1 = new TS1;
	TS* ts2 = new TS2;

	TSAdapter* ts3 = new TSAdapter;

	std::cout << ts1->getTemp() << std::endl << std::endl;

	std::cout << ts2->getTemp() << std::endl << std::endl;

	std::cout << ts3->getTemp() << std::endl << std::endl;




	return EXIT_SUCCESS;
}