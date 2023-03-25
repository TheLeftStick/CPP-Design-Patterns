#include <iostream>
#include <string>
#include "classes.h"

int main() {
	Beverage* beverage1 = new DarkRoast;
	Beverage* beverage2 = new Decaf;
	Beverage* beverage3 = new Espresso;

	std::cout << beverage1->getDescription() + " $" + std::to_string(beverage1->cost());
	std::cout << std::endl;
	beverage1 = new Milk(beverage1);
	std::cout << beverage1->getDescription() + " $" + std::to_string(beverage1->cost());
	std::cout << std::endl << std::endl;

	std::cout << beverage2->getDescription() + " $" + std::to_string(beverage2->cost());
	std::cout << std::endl;
	beverage2 = new Mocha(beverage2);
	std::cout << beverage2->getDescription() + " $" + std::to_string(beverage2->cost());
	std::cout << std::endl << std::endl;

	std::cout << beverage3->getDescription() + " $" + std::to_string(beverage3->cost());
	std::cout << std::endl;
	beverage3 = new Mocha(beverage3);
	beverage3 = new Mocha(beverage3);
	beverage3 = new WhippedCream(beverage3);
	std::cout << beverage3->getDescription() + " $" + std::to_string(beverage3->cost());
	std::cout << std::endl << std::endl;

	return EXIT_SUCCESS;
}