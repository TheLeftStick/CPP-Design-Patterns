#include <iostream>
#include <string>
#include "Header.h"

int main() {
	// Setup Chain of Responsibility
	HotelRoom* suite = new Suite();
	HotelRoom* deluxe = new Deluxe();
	HotelRoom* standard = new Standard();

	suite->setSuccessor(deluxe);
	deluxe->setSuccessor(standard);

	// Generate and process request
	std::string choice = "Y";
	double value;

	do {
		if (choice != "Y") {
			std::cout << "Invalid Input. Would you like to input a new bid? (Y/N): ";
			std::cin >> choice;
			std::cout << std::endl;
		}
		if (choice == "Y") {
			std::cout << "Enter in a bid for a hotel room: $";
			std::cin >> value;
			suite->handleRequest(value);
			
			std::cout << std::endl;
			std::cout << "Would you like to input a new bid? (Y/N): ";
			std::cin >> choice;
			std::cout << std::endl;
		}
	} while (choice != "N");

	return EXIT_SUCCESS;
}